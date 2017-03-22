//
// Main.cpp
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// application includes
#include "rpahu/dockapps/apps/MyDAMon.h"

// c++ library includes
#include <iostream>

// my-da-mon starting point
int main( int argc, char **argv )
{

	// catch unhandled exceptions
	try
	{
		// create an instance of the application
		// 		and execute it (maybe)
		//		and return the result
		auto 	Application	=	rpahu::dockapps::MyDAMon::Create( argc, argv );
		//int		RetVal 		= 	Application ? Application->Run() : 1;
		int		RetVal		=	Application->Run();
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
	return( 1 );
}


