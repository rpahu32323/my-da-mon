//
// Group.h
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// only inlcude the definition once
#ifndef SRC_RPAHU_DOCKAPPS_MONITORS_GROUP_H_
#define SRC_RPAHU_DOCKAPPS_MONITORS_GROUP_H_

// application includes
#include "Monitor.h"
#include "../widgets/Label.h"

// put into the raphu::dockapps namespace
namespace rpahu {
namespace dockapps {

// class definition
class Group : public Monitor
{
	// data members
	private:

		// pointer to possible label widget
		std::unique_ptr<Label>		Heading	=	nullptr;

	// constructors and destructors
	public:

		// main constructor
		Group( const std::string& Name, const std::string& Parameters );
};

} /* namespace dockapps */
} /* namespace rpahu */

#endif /* SRC_RPAHU_DOCKAPPS_MONITORS_GROUP_H_ */
