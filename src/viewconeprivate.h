#ifndef VIEWCONEPRIVATE_H
#define VIEWCONEPRIVATE_H

#include <QtCore/QSharedData>

namespace BehaviorTree
{
    class ViewConePrivate : public QSharedData
    {
	    public:
		ViewConePrivate();
		ViewConePrivate(const QSharedData& other);
		~ViewConePrivate();
    };
}

#endif