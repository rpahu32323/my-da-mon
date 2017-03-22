//
// MyDAMon.h
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// only include the header once
#ifndef SRC_MYDAMON_H_
#define SRC_MYDAMON_H_

// application includes
#include <src/rpahu/utils/Base.h>

// gtkmm include
#include <gtkmm.h>

// put into the rpahu::dockapps namespace
namespace rpahu {
namespace dockapps {

// class definition
class MyDAMon : public Gtk::Application, public rpahu::utils::Base
{
	// data members
	private:

		// config and css file names
		std::string		ConfigFileName;
		std::string		CSSFileName;

		// application main window
		Gtk::ApplicationWindow		MainWindow;
		//		temporary stuff
		Gtk::Button					Button;

	// constructors and destructors
	public:

		// main constructors
		MyDAMon( int argc, char **argv );

	// public methods
	public:

		// create an instance of the application
		static std::unique_ptr<MyDAMon>	Create( int argc, char **argv );

		// run the application
		int	Run();


	// overrides on gtk::application
	private:
		// activate event
		void	on_activate();
};

} /* namespace dockapps */
} /* namespace rpahu */

#endif /* SRC_MYDAMON_H_ */
