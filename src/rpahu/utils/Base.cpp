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
int		Base::LogLevel	=	0;

// set the log level
void Base::SetLogLevel( int NewLevel )
{
    // save the new level
    LogLevel = NewLevel;

    // build a message
    std::stringstream   Message;
    Message<<"Setting log level to: "<<NewLevel;

    // and log it
    LogMessage( Message.str(), 0 );

    // return finished
    return;
};


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
void Base::LogMessage( std::string Message, int Level )
{
    // check the level
    if ( Level <= LogLevel )
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

    // output the message to cerror
    std::cerr<<ErrorMessage<<std::endl<<std::flush;

    // add to the log
    LogMessage( ErrorMessage, 0 );

    // check for an error number
    if ( ErrorNumber != 0 )
    {
        // build a message with the number
        ErrorMessage    =   "   Number: " + std::to_string( ErrorNumber ) + " - " + strerror( ErrorNumber );

        // output the message to cerror
        std::cerr<<"ERROR: "<<ErrorMessage<<std::endl<<std::flush;

        // log the error
        LogMessage( ErrorMessage, 0 );
    }

    // return finished
    return;
}

// throw an exception
void Base::ThrowException( std::string Message, int ErrorNumber )
{
    // log the error
    LogError( Message, ErrorNumber );

    // throw an exception
    throw( std::runtime_error( Message ) );

    // return finished
    //      note - will never get here
    return;
}

} /* namespace utils */
} /* namespace rpahu */
