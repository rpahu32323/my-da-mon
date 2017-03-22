//
// MyDAMon.cpp
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// application includes
#include "MyDAMon.h"

// put into the rpahu::dockapps namespace
namespace rpahu {
namespace dockapps {

// main constructor
MyDAMon::MyDAMon( int argc, char **argv )
	:	Gtk::Application( argc, argv ),
		rpahu::utils::Base(),
		ConfigFileName( "" ),
		CSSFileName( "" )
{
	// add command line options
	//		log level
	this->add_main_option_entry( Gio::Application::OPTION_TYPE_STRING, "loglevel", '\0', "Log Verbosity Level", "LEVEL", 0 );
	// 		config file
	this->add_main_option_entry( Gio::Application::OPTION_TYPE_STRING, "config", '\0', "Configuration File", "FILE", 0 );
	//		css file
	this->add_main_option_entry( Gio::Application::OPTION_TYPE_STRING, "css", '\0', "CSS File", "FILE", 0 );
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

// handle the on activate
void MyDAMon::on_activate()
{
	// do some temporary window stuff
	MainWindow.set_wmclass( "res_class", "DockApp" );
	MainWindow.set_size_request( 64, -1 );
	Gtk::Button	*Button = Gtk::manage( new Gtk::Button( "HELLO" ));
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
