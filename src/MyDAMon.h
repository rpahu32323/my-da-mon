//
// MyDAMon.h
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// only include the header once
#ifndef SRC_MYDAMON_H_
#define SRC_MYDAMON_H_

// c++ library includes
#include <memory>

// class definition
class MyDAMon
{
	// constructors and destructors
	public:

		// main constructors
		MyDAMon( int argc, char **argv );

		// main destructor
		virtual ~MyDAMon()	=	default;

	// public methods
	public:

		// create an instance of the application
		static std::unique_ptr<MyDAMon>	Create( int argc, char **argv );

		// run the application
		int	Run();
};

#endif /* SRC_MYDAMON_H_ */
