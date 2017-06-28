//
// MyDAMon.h
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// only include the header once
#ifndef SRC_RPAHU_DOCKAPPS_APPS_MYDAMON_H_
#define SRC_RPAHU_DOCKAPPS_APPS_MYDAMON_H_

// application includes
#include "../../utils/Base.h"
#include "../monitors/Monitor.h"

// gtkmm include
#include <gtkmm.h>

// c++ library includes
#include <thread>

// put into the rpahu::dockapps namespace
namespace rpahu {
namespace dockapps {

// class definition
class MyDAMon : public Gtk::Application, public rpahu::utils::Base
{

	// monitor lists
	private:

		// items for the monitor list
		typedef struct
		{
			std::unique_ptr<rpahu::dockapps::Monitor>	Monitor;
			std::shared_ptr<Glib::Dispatcher>			Dispatcher;
			std::unique_ptr<std::thread>				Process;
		} MonitorItem;

	// data members
	private:

		// config and css file names
		std::string		ConfigFileName;
		std::string		CSSFileName;

		// configureation
		std::list<std::string>				Config;

		// application main window
		Gtk::ApplicationWindow				MainWindow;

		// list of monitors
		std::list<MyDAMon::MonitorItem>		MonitorList;

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

	// private methods
	private:

		// handle the local options
		int GetLocalOptions( const Glib::RefPtr<Glib::VariantDict>& Options );

		// load the config
		void LoadConfig( const std::string& FileName );

	// overrides on gtk::application
	private:
		// activate event
		void	on_activate();
};

} /* namespace dockapps */
} /* namespace rpahu */

#endif /* SRC_MYDAMON_H_ */
