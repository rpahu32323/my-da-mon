//
// Base.h
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// only inlcude the header once
#ifndef SRC_RPAHU_UTILS_BASE_H_
#define SRC_RPAHU_UTILS_BASE_H_

// c++ library
#include <string>

// put into the rpahu::utils namespace
namespace rpahu {
namespace utils {

// class definition
class Base
{
	// data members
	private:

		// log verbosity
		static	int	LogLevel;

	// public methods
	public:

		// set the log verbose level
        void    SetLogLevel( int NewLevel );

	// protected methods
	protected:

        // log an error message
        static void LogError( std::string Message, int ErrorNumber = 0 );

        // log a regular message
        static void LogMessage( std::string Message, int LogLevel = 99 );

        // throw exceptions
        void ThrowException( std::string Message, int ErrorNumber = 0 );

	// private methods
	private:

		// get a timestamp
		static std::string GetTimestamp();
};

} /* namespace utils */
} /* namespace rpahu */

#endif /* SRC_RPAHU_UTILS_BASE_H_ */
