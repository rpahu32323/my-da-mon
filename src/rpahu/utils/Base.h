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
	// enumerations
	public:

		// log level enumerations
		enum class LogLevel { IMPORTANT, NORMAL, DEBUG };

	// data members
	private:

		// log verbosity
		static	LogLevel	CurrLogLevel;

	// public methods
	public:

		// set the log verbose level
        void    SetLogLevel( LogLevel NewLevel )		{ CurrLogLevel = NewLevel; return; };

	// protected methods
	protected:

        // log an error message
        static void LogError( std::string Message, int ErrorNumber = 0 );

        // log a regular message
        static void LogMessage( std::string Message, LogLevel Level = LogLevel::DEBUG );

	// private methods
	private:

        // build an error message
        static std::string BuildError( std::string Message, int ErrorNumber = 0 );

		// get a timestamp
		static std::string GetTimestamp();
};

} /* namespace utils */
} /* namespace rpahu */

#endif /* SRC_RPAHU_UTILS_BASE_H_ */
