//
// MyDAMon.cpp
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// application includes
#include "MyDAMon.h"

// c++ library includes
#include <fstream>

// put into the rpahu::dockapps namespace
namespace rpahu {
namespace dockapps {

// main constructor
MyDAMon::MyDAMon( int argc, char **argv )
	:	Gtk::Application( argc, argv ),
		rpahu::utils::Base(),
		ConfigFileName( "" ),
		CSSFileName( "" ),
		Config( { "Group=Time",
				  "TimeMon=Time",
				  "Group=Date",
				  "DateMon=Date" } )
{
	// add command line options
	//		log level
	this->add_main_option_entry( Gio::Application::OPTION_TYPE_STRING, "loglevel", '\0', "Log Verbosity Level (1, 2, or 3)", "LEVEL", 0 );
	// 		config file
	this->add_main_option_entry( Gio::Application::OPTION_TYPE_STRING, "config", '\0', "Configuration File", "FILE", 0 );
	//		css file
	this->add_main_option_entry( Gio::Application::OPTION_TYPE_STRING, "css", '\0', "CSS File", "FILE", 0 );

	// connect the handler to the local options signal
	//		needed to process the options above
	this->signal_handle_local_options().connect( sigc::mem_fun( *this, &MyDAMon::GetLocalOptions ), false );

	// set up the window as a dockapp
	MainWindow.set_name( "my-da-mon" );
	MainWindow.set_border_width( 2 );
	MainWindow.set_decorated( false );
	MainWindow.set_wmclass( "res_class", "DockApp" );
	MainWindow.set_size_request( 64, -1 );
}

// create an instance of the application
std::unique_ptr<MyDAMon> MyDAMon::Create( int argc, char **argv )
{
	// catch exceptions
	try
	{
		// create the instance
		std::unique_ptr<MyDAMon> Application = std::make_unique<MyDAMon>( argc, argv );

		// return the instance
		return( Application );
	}
	// catch standard exceptions
	catch( std::exception & Exception )
	{
		// log the exception
		LogError( Exception.what() );
	}

	// return nothing
	//		can only get here with an exception
	return( nullptr );
}

// handle local command line options
//		matches add_main_option_entry calls
//			in the constructor
int MyDAMon::GetLocalOptions( const Glib::RefPtr<Glib::VariantDict>& Options )
{
	// maybe get a new log level from a
	//		command line option
	Glib::ustring	LevelOption;
	if ( Options->lookup_value( "loglevel", LevelOption ) )
	{
		// set the log level
		LogLevel	Level	=	LogLevel::NORMAL;
		if ( "0" == LevelOption )
			Level	=	LogLevel::SILENT;
		else if ( "1" == LevelOption )
			Level	=	LogLevel::IMPORTANT;
		else if ( "2" == LevelOption )
			Level	=	LogLevel::NORMAL;
		else if ( "3" == LevelOption )
			Level	=	LogLevel::DEBUG;
		SetLogLevel( Level );

		// log a message
		LogMessage( "Log level set to " + LevelOption.raw() );
	}

	// maybe get a config file from a
	//		command line option
	Glib::ustring	ConfigOption;
	if ( Options->lookup_value( "config", ConfigOption ) )
	{
		// log a message
		LogMessage( "Using config file: '" + ConfigOption.raw() + "'" );
	}

	// load the config file
	// 		this works because lookup_value sets
	// 		option to return and empty string
	//		with raw when the option is not found
	LoadConfig( ConfigOption.raw() );

	// maybe get a css file from a
	//		command line option
	Glib::ustring	CSSOption;
	if ( Options->lookup_value( "css", CSSOption ) )
	{
		// log a message
		LogMessage( "Using css file:  '" + CSSOption.raw() + "'" );
	}

	// return -1 to continue normal processing
	return( -1 );
}

// get the config
void MyDAMon::LoadConfig( std::string FileName )
{
	// what config is used
	bool	InternalConfig	=	true;

	// don't process if empty file name
	if ( !FileName.empty() )
	{
		// open the config file
		std::fstream	ConfigFile( FileName, std::fstream::in );

		// check for good open
		if ( ConfigFile.is_open() )
		{
			// clear the default config
			Config.clear();

			// read in the config
			while( !ConfigFile.eof() )
			{
				// init the line
				std::string		Line	=	"";

				// read and merge lines
				while( !ConfigFile.eof() )
				{
					// get a part (maybe)
					std::string		Part;
					std::getline( ConfigFile, Part );

					// skip if empty or comment
					if ( Part.empty() )
						continue;

					// trim it of beginning and ending spaces
					auto	start	=	Part.find_first_not_of( ' ' );
					auto	end		=	Part.find_last_not_of( ' ' );
					Part			=	Part.substr( start, end - start + 1 );

					// skip if a comment
					if ( *Part.begin() == '#' )
						continue;

					// add to the line
					Line	+=	Part;

					// check for continuation
					if ( Line.back() == '\\' )
					{
						// replace the end with a space
						Line.replace(Line.end() - 1, Line.end(), " " );
						continue;
					}

					// end of merged line
					break;
				}

				// add to vector if not empty
				//		and not a comment
				if (( !Line.empty() ) && ( *Line.begin() != '#' ))
					Config.push_back( Line );
			}

			// close the file
			ConfigFile.close();

			// not using default config
			InternalConfig	=	false;
		}
		else
		{
			// log a message
			LogError( "Cannot open config file: '" + FileName + "'", errno );
		}
	}

	// log a message if the default config is used
	if ( InternalConfig )
		LogMessage( "Using default config" );

	// log the config
	LogMessage( "Using this config:", LogLevel::DEBUG );
	LogMessage( "", LogLevel::DEBUG );
	for( auto Line : Config )
		LogMessage( Line, LogLevel::DEBUG );
	LogMessage( "", LogLevel::DEBUG );

	// return finished
	return;
}

// handle the on activate
void MyDAMon::on_activate()
{
	// do some temporary window stuff
	Gtk::Button	*Button = Gtk::manage( new Gtk::Button( "BYE" ));
	Button->set_name( "my-button" );
	MainWindow.add( *Button );
	MainWindow.show_all_children( true );

	// return finished
	return;
}

// run the application
int MyDAMon::Run()
{
	// catch exceptions
	try
	{
		// can get here from a null pointer
		//		check and throw an exception
		if ( this == nullptr )
			throw( std::runtime_error( "Executing application with nullptr" ));

		// run the application
		int RetVal	=	this->run( MainWindow );

		// check for a bad return
		if ( RetVal != 0 )
			throw( std::runtime_error( "Bad return value from application (" + std::to_string( RetVal ) + ")" ));

		// return success
		return( 0 );
	}
	// catch standard exceptions
	catch( std::exception & Exception )
	{
		// log the exception
		LogError( Exception.what(), errno );
	}

	// return unsuccessful
	//		can only get here with an exception
	return( 1 );
}

} /* namespace dockapps */
} /* namespace rpahu */
