//
// Group.cpp
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// application includes
#include "Group.h"

// put into the rpahu::dockapps namespace
namespace rpahu {
namespace dockapps {

// main constructor
Group::Group( const std::string& Name, const std::string& Parameters )
	:	Monitor( "Group", Name )
{
	// get the heading
	std::stringstream	Work( Parameters );
	std::string			Text( "" );
	Work>>Text;

	// create the label if needed
	if ( !Text.empty() )
	{
		// create a new label
		Heading.reset( new Label );
		Heading->set_name( "Heading" );

		// add the text
		Heading->SetCenterMarkup( Text );

		// add the label to the group
		this->add( *Heading );
	}
}

} /* namespace dockapps */
} /* namespace rpahu */
