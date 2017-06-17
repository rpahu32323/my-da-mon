//
// Base.cpp
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// application includes
#include "Base.h"

// library includes
#include <chrono>
#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>

// put into the raphu::utils namespace
namespace rpahu {
namespace utils {

// default log level
std::atomic<Base::LogLevel>	Base::CurrLogLevel	=	{ Base::LogLevel::IMPORTANT };
std::mutex		Base::LogMutex;

// get the time
std::string Base::GetTimestamp()
{
    // get the current and local date/time
    auto        CurrentTime =   std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
    struct tm   LocalTime;
    localtime_r( &CurrentTime, &LocalTime );

    // build the time stamp
    std::stringstream   Timestamp;
    Timestamp<<std::put_time( &LocalTime, "[%Y-%m-%d %H:%M:%S]" );

    // return it
    return( Timestamp.str() );
}

// write messages to a stream
void Base::WriteMessages( std::ostream &Stream, const std::list<std::string>& Messages, const std::string& Timestamp )
{
	// write the messages
	for( auto Message : Messages )
	{
		// add timestamp if there is one
		if ( !Timestamp.empty() )
			Stream<<Timestamp<<" ";
		Stream<<Message<<std::endl;
	}
	Stream<<std::flush;

	// return finished
	return;
}

// log a message
void Base::LogMessages( const std::list<std::string>& Messages, const LogLevel Level )
{
	// use a mutex for better output
	//		with threads
	std::lock_guard<std::mutex>		Lock( LogMutex );

    // write the messages based on
	//		the logging level
    if ( Level <= CurrLogLevel )
    	WriteMessages( std::cout, Messages, GetTimestamp() );

    // return finished
    return;
}

// log an error
void Base::LogErrors( std::list<std::string> Messages, const int ErrorNumber )
{
	// use a mutex for better output
	//		with threads
	std::lock_guard<std::mutex>		Lock( LogMutex );

    // check for an error number
	//		and add the message
    if ( ErrorNumber != 0 )
        Messages.push_back( "   Error Number: " + std::to_string( ErrorNumber ) + " - " + strerror( ErrorNumber ) );

    // add error identifiers
    for( auto &Message : Messages )
    	Message	=	"ERROR: " + Message;

    // write to cerr
    WriteMessages( std::cerr, Messages );

    // and then to the cout
    if ( LogLevel::IMPORTANT <= CurrLogLevel )
    	WriteMessages( std::cout, Messages, GetTimestamp() );

    // return finished
    return;
}

} /* namespace utils */
} /* namespace rpahu */
