//
// Monitor.h
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// only include the definition once
#ifndef SRC_RPAHU_DOCKAPPS_MONITORS_MONITOR_H_
#define SRC_RPAHU_DOCKAPPS_MONITORS_MONITOR_H_

// application includes
#include "../../utils/Base.h"

// gtk library includes
#include <gtkmm.h>

// put into the rpahu::dockapps namespace
namespace rpahu {
namespace dockapps {

// class definition
class Monitor : public Gtk::VBox, public rpahu::utils::Base
{
	// protected data members
	protected:

		// update mutex
		std::mutex		UpdateMutex;

    // constructors and destructors
	public:

		// main constructor
		Monitor( const std::string& Class, const std::string& Name );

	// public methods
	public:

		// create monitors
		static std::unique_ptr<rpahu::dockapps::Monitor>	Create( const std::string& Name, const std::string& Parameters );

		// run the monitor
		virtual void	Run( std::shared_ptr<Glib::Dispatcher> Dispatcher ) = 0;

		// update the monitor display
		void	Update();
};

} /* namespace dockapps */
} /* namespace rpahu */

#endif /* SRC_RPAHU_DOCKAPPS_MONITORS_MONITOR_H_ */
