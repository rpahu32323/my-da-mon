//
// Label.h
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// only include once
#ifndef SRC_RPAHU_DOCKAPPS_WIDGETS_LABEL_H_
#define SRC_RPAHU_DOCKAPPS_WIDGETS_LABEL_H_

// application includes
#include "Widget.h"

// put into the raphu::dockapps namespace
namespace rpahu {
namespace dockapps {

// class definition
class Label : public Widget
{

	// data members
	private:

		// markup
		std::string     LeftMarkup;
		std::string     CenterMarkup;
		std::string     RightMarkup;


	// constructors and destructors
	public:

		// main constructor
		Label();

	// protected methods
	protected:

		// override the gtk::drawingarea draw event
		bool	on_draw( const Cairo::RefPtr<Cairo::Context> &Context ) override;

	// settors
	public:

		// set the markups
		void    SetLeftMarkup( std::string Markup );
		void    SetCenterMarkup( std::string Markup );
		void    SetRightMarkup( std::string Markup );

};

} /* namespace dockapp */
} /* namespace rpahu */

#endif /* SRC_RPAHU_DOCKAPP_WIDGETS_LABEL_H_ */
