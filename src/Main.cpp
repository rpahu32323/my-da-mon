//
// Main.cpp
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// application includes
#include "MyDAMon.h"

#include <iostream>

// my-da-mon starting point
int main( int argc, char **argv )
{

	// catch unhandled exceptions
	try
	{
		// create an instance of the application
		// e	and xecute it (maybe)
		//		and return the result
		auto 	Application	=	MyDAMon::Create( argc, argv );
		int	RetVal = Application ? Application->Run() : -1;
		return( RetVal );
	}
	// catch unhandled exceptions
	catch( ... )
	{
		// update the user
		std::cerr<<"Unhandled exception caught"<<std::endl;
	}

	// return unsuccessful
	//		can only get here with an exception
	return( -1 );
}


