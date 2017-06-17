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
	:	Redraw( false )
{
	// set the class for css styling
	auto Context	=	this->get_style_context();
	Context->add_class( Class );
}

// update the widget
void Widget::Update()
{
	// check to force a redraw
	if ( Redraw )
	{
		// get the current window
		auto	Window	=	this->get_window();

		// if there is one, redraw
		if ( Window )
		{
			// get the area to redraw
			Gdk::Rectangle	Area( 0, 0, this->get_allocation().get_width(), this->get_allocation().get_height() );

			// force the redraw
			Window->invalidate_rect( Area, false );
		}

		// did the redraw - reset the flag
		Redraw	=	false;
	}

	// return finished
	return;
}

} /* namespace dockapp */
} /* namespace rpahu */
