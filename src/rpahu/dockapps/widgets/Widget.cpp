//
// Widget.cpp
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// application includes
#include "Widget.h"

// put into the raphu::dockapps namespace
namespace rpahu {
namespace dockapps {

// main constructor
Widget::Widget( const std::string& Class )
{
	// set the class for css styling
	auto Context	=	this->get_style_context();
	Context->add_class( Class );
}

} /* namespace dockapp */
} /* namespace rpahu */
