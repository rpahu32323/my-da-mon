//
// Time.h
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// only include the header once
#ifndef SRC_RPAHU_DOCKAPPS_MONITORS_TIMEMON_H_
#define SRC_RPAHU_DOCKAPPS_MONITORS_TIMEMON_H_

// application includes
#include "Monitor.h"
#include "../widgets/Label.h"

// put into the raphu::dockapps namespace
namespace rpahu {
namespace dockapps {

// class definition
class TimeMon : public Monitor
{
		
	// data members
	private:

		// pointer to possible label widget
		rpahu::dockapps::Label		Time;

	// constructors and destructors
	public:

		// main constructor
		TimeMon( const std::string& Name, const std::string& Parameters );

	// public methods
	public:

		// run the monitor
		void	Run( std::shared_ptr<Glib::Dispatcher> Dispatcher )	override;
			
};

} /* namespace dockapps */
} /* namespace rpahu */

#endif /* SRC_RPAHU_DOCKAPPS_MONITORS_TIMEMON_H_ */
