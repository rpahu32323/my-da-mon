/*
 * Label.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: rpahu
 */

// application includes
#include "Label.h"

// put into the raphu::dockapps namespace
namespace rpahu {
namespace dockapps {

// constructor
Label::Label()
	:	Widget( "Label" ),
		LeftMarkup( "" ),
		CenterMarkup( "" ),
		RightMarkup( "" )
{

}

// set the left markup
void Label::SetLeftMarkup( std::string Markup )
{
    // check for a change
    if ( Markup != LeftMarkup )
        // save it
        LeftMarkup  = 	Markup;

    // return finished
    return;
}

// set the center markup
void Label::SetCenterMarkup( std::string Markup )
{
	// check for a change
	if ( Markup != CenterMarkup )
        // save it
		CenterMarkup    = 	Markup;

	// return finished
	return;
}

// set the right markup
void Label::SetRightMarkup( std::string Markup )
{
    // check for a change
    if ( Markup != RightMarkup )
        // save it
        RightMarkup     = 	Markup;


    // return finished
    return;
}

// override of drawing routine
bool Label::on_draw( const Cairo::RefPtr<Cairo::Context> &Context )
{
	// get the current height and width
	int     Width       =   this->get_allocation().get_width();
	int     Height      =   this->get_allocation().get_height();
	int     NewHeight   =   Height;
	int     TextWidth;
	int     TextHeight;

	// create a pango layout for the text
	auto layout = this->create_pango_layout( "" );

	// check for left markup to display
	if ( !LeftMarkup.empty() )
	{
		layout->set_markup( LeftMarkup );
		layout->get_pixel_size( TextWidth, TextHeight );
		NewHeight = std::max( NewHeight, TextHeight + 2 );
		Context->move_to( 1, ( Height - TextHeight ) / 2 );
		layout->show_in_cairo_context( Context );
		Context->stroke();
	}

	// check for center markup to display
	if ( !CenterMarkup.empty() )
	{
		layout->set_markup( CenterMarkup );
		layout->get_pixel_size( TextWidth, TextHeight );
		NewHeight = std::max( NewHeight, TextHeight + 2 );
		Context->move_to(( Width - TextWidth ) / 2, ( Height - TextHeight ) / 2 );
		layout->show_in_cairo_context( Context );
		Context->stroke();
	}

	// check for left markup to display
	if ( !RightMarkup.empty() )
	{
		layout->set_markup( RightMarkup );
		layout->get_pixel_size( TextWidth, TextHeight );
		NewHeight = std::max( NewHeight, TextHeight + 2 );
		Context->move_to( Width - TextWidth  - 1, ( Height - TextHeight ) / 2 );
		layout->show_in_cairo_context( Context );
		Context->stroke();
	}

	// update the size
	if ( NewHeight != Height )
	{
		// get the current size request
		int RequestWidth;
		int RequestHeight;
		this->get_size_request( RequestWidth, RequestHeight );

		// update the size request with the new height
		this->set_size_request( RequestWidth, NewHeight );
	}

    // return successful
    return( true );
}

} /* namespace dockapp */
} /* namespace rpahu */
