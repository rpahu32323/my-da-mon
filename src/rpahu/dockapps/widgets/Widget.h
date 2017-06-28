//
// Widget.h
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// only include the definition onece
#ifndef SRC_RPAHU_DOCKAPPS_WIDGETS_WIDGET_H_
#define SRC_RPAHU_DOCKAPPS_WIDGETS_WIDGET_H_

// gtkmm includes
#include <gtkmm.h>

// put into the raphu::dockapps namespace
namespace rpahu {
namespace dockapps {

// definition
class Widget : public Gtk::DrawingArea
{

	// constructors and destructors
	public:

		// main constructor
		Widget( const std::string& Class );
};

} /* namespace dockapp */
} /* namespace rpahu */

#endif /* SRC_RPAHU_DOCKAPP_WIDGETS_WIDGET_H_ */
