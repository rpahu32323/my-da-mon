//
// Monitor.cpp
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// application includes
#include "Monitor.h"
#include "Group.h"
#include "TimeMon.h"

// put into the rpahu::dockapps namespace
namespace rpahu {
namespace dockapps {

// create an instance of a monitor
std::unique_ptr<rpahu::dockapps::Monitor> Monitor::Create( const std::string& Type, const std::string& InitString )
{
	// create something to return
	std::unique_ptr<Monitor>		NewMonitor;

	// parse the init string
	//		into name and parameters
	std::stringstream	Work( InitString );
	std::string			Name;
	std::string			Parameters;
	Work>>Name>>Parameters;

	// group
	if ( "Group" == Type )
		NewMonitor.reset( new Group( Name, Parameters ) );
	// time monitor
	else if ( "TimeMon" == Type )
		NewMonitor.reset( new TimeMon( Name, Parameters ) );
	// monitor not supported
	else
		NewMonitor	=	nullptr;

	// return what was created
	return( NewMonitor );
}

// main constructor
Monitor::Monitor( const std::string& Class, const std::string& Name )
{
    // give it a class and a name for styling
    auto Context = this->get_style_context();
    Context->add_class( Class );
    this->set_name( Name );
}

// update the display
void Monitor::Update()
{
	// get the current window
	auto	Window	=	this->get_window();

	// if there is one, redraw
	if ( Window )
	{
		// lock the update mutex
		//		to prevent overlapping access
		//		to the monitor widgets
		std::lock_guard<std::mutex>		UpdateLock( UpdateMutex );

		// get the area to redraw
		Gdk::Rectangle	Area( this->get_allocation().get_x(),
							  this->get_allocation().get_y(),
							  this->get_allocation().get_width(),
							  this->get_allocation().get_height() );

		// force the redraw
		Window->invalidate_rect( Area, false );

		// the lock guard will be released
		//		when this code block goes out
		//		of scope
	}

	// return finished
	return;
}

} /* namespace dockapps */
} /* namespace rpahu */
