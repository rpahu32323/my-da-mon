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

// put into the rpahu::dockapps namespace
namespace rpahu {
namespace dockapps {

// create an instance of a monitor
Monitor* Monitor::Create( const std::string& Type, const std::string& InitString )
{
	// create something to return
	Monitor*	NewMonitor	=	nullptr;

	// parse the init string
	//		into name and parameters
	std::stringstream	Work( InitString );
	std::string			Name;
	std::string			Parameters;
	Work>>Name>>Parameters;

	// group
	if ( "Group" == Type )
		NewMonitor	=	new Group( Name, Parameters );

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

} /* namespace dockapps */
} /* namespace rpahu */
