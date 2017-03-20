//
// MyDAMon.cpp
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// application includes
#include "MyDAMon.h"

// c++ library includes
#include <iostream>

// main constructor
MyDAMon::MyDAMon( int argc, char **argv )
{

}

// create an instance of the application
std::unique_ptr<MyDAMon> MyDAMon::Create( int argc, char **argv )
{
	// catch exceptions
	try
	{
		// create the instance
		std::unique_ptr<MyDAMon> Application = std::make_unique<MyDAMon>( argc, argv );

		// return the instance
		return( Application );
	}
	// catch standard exceptions
	catch( std::exception & Exception )
	{
		// update the user
		std::cerr<<Exception.what()<<std::endl;
	}

	// return nothing
	//		can only get here with an exception
	return( nullptr );
}

// run the application
int MyDAMon::Run()
{
	// catch exceptions
	try
	{
		// can get here from a null pointer
		//		check and throw an exception
		if ( this == nullptr )
			ThrowException( "Executing application with nullptr" );

		// output something
		std::cout<<"Hello World"<<std::endl;
	}
	// catch standard exceptions
	catch( std::exception & Exception )
	{
		// nothing to do
		//		messages sent in ThrowException
	}

	// return unsuccessful
	//		can only get here with an exception
	return( -1 );
}

