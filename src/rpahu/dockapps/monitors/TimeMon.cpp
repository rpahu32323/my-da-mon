//
// Time.cpp
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// application includes
#include "TimeMon.h"

// c++ library includes
#include <thread>
#include <chrono>
#include <iomanip>

// put into the raphu::dockapps namespace
namespace rpahu {
namespace dockapps {

// main constructor
TimeMon::TimeMon( const std::string& Name, const std::string& Parameters )
	:	Monitor( "Time", Name )
{
	// set up the label to show the time
	// 		and add it to the monitor
	Time.set_name( "Time" );
	this->add( Time );
}

// run the monitor
void TimeMon::Run( std::shared_ptr<Glib::Dispatcher> Dispatcher )
{
	// run for a while
	while( true )
	{
		// get the start time of the update
		//		used to account for processing time
		//		when sleeping until next update
		auto	StartTime	=	std::chrono::steady_clock::now();

		// get the current time
		auto		CurrentTime	=	std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
		struct tm	LocalTime;
		localtime_r( &CurrentTime, &LocalTime );

	    // build the time markup
	    std::stringstream   Markup;
	    Markup<<( LocalTime.tm_hour > 12 ? LocalTime.tm_hour - 12 : LocalTime.tm_hour )
	          <<":"
	          <<std::setw(2)<<std::setfill('0')<<LocalTime.tm_min
	          <<":"
	          <<std::setw(2)<<std::setfill('0')<<LocalTime.tm_sec
	          ;

	    // use a code block so that lock_guard can be used
	    {
	    	// create the lock guard
	    	std::lock_guard<std::mutex>	UpdateLock( UpdateMutex );

	    	// update the markup on the time label
	    	Time.SetCenterMarkup( Markup.str() );

	    	// the lock guard is release when this
	    	//		block goes out of scope
	    }

		// call emit to cause the main thread
		//		to update the monitor on the screen
		Dispatcher->emit();

		// compute the sleep time
		auto	SleepTime	=	std::chrono::duration_cast<std::chrono::milliseconds>( StartTime + std::chrono::seconds(1) - std::chrono::steady_clock::now() );

		// sleep for the time
		//		if it is not negative
		if ( SleepTime > std::chrono::milliseconds( 0 ) )
			std::this_thread::sleep_for( SleepTime );
	}

	// return finished
	return;
}

} /* namespace dockapps */
} /* namespace rpahu */
