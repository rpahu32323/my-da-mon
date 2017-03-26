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
Base::LogLevel	Base::CurrLogLevel	=	Base::LogLevel::IMPORTANT;

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

// log a message
void Base::LogMessage( std::string Message, LogLevel Level )
{
    // check the level
    if ( Level <= CurrLogLevel )
        // output the message
        std::cout<<GetTimestamp()<<" "<<Message<<std::endl<<std::flush;

    // return finished
    return;
}

// log an error
void Base::LogError( std::string Message, int ErrorNumber )
{
    // build the error message
    std::string ErrorMessage    =   "ERROR: " + Message;

    // log the error
	LogMessage( ErrorMessage, LogLevel::IMPORTANT );

    // output the message to cerr
    std::cerr<<Message<<std::endl<<std::flush;

    // check for an error number
    if ( ErrorNumber != 0 )
    {
        // add the error number line
        ErrorMessage	=	"   Number: " + std::to_string( ErrorNumber ) + " - " + strerror( ErrorNumber );

        // log the second message
    	LogMessage( ErrorMessage, LogLevel::IMPORTANT );

        // output the message to cerr
        std::cerr<<ErrorMessage<<std::endl<<std::flush;
    }

    // return finished
    return;
}

} /* namespace utils */
} /* namespace rpahu */
