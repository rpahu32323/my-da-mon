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
#include <list>
#include <mutex>
#include <atomic>

// put into the rpahu::utils namespace
namespace rpahu {
namespace utils {

// class definition
class Base
{
	// enumerations
	public:

		// log level enumerations
		enum class LogLevel { SILENT, IMPORTANT, NORMAL, DEBUG };

	// data members
	private:

		// log verbosity
		static	std::atomic<Base::LogLevel>		CurrLogLevel;

		// log mutex
		static	std::mutex	LogMutex;

	// public methods
	public:

		// set the log verbose level
        void    SetLogLevel( LogLevel NewLevel )		{ CurrLogLevel = NewLevel; return; };

	// protected methods
	protected:

        // write messages
        static void WriteMessages( std::ostream &Stream, std::list<std::string> Messsages, std::string Timestamp = "" );

        // log an error message
        static void LogErrors( std::list<std::string> Messages, int ErrorNumber = 0 );

        // log a regular message
        static void LogMessages( std::list<std::string> Messages, LogLevel Level = LogLevel::NORMAL );

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
