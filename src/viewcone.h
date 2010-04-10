#ifndef VIEWCONE_H
#define VIEWCONE_H

#include "bt_export.h"

#include <QtCore/QObject>
#include <engine/component.h>

namespace BehaviorTree
{
	class ViewConePrivate;
	
	class BTCOMPONENT_EXPORT ViewCone : public GluonEngine::Component
	{
		Q_OBJECT
		GLUON_OBJECT(BehaviorTree::ViewCone)
		Q_INTERFACES(GluonEngine::Component)
		public:
			ViewCone(QObject * parent = 0);
			ViewCone(const ViewCone& other, QObject* parent = 0);
			~ViewCone();
			
							virtual void update(int elapsedMilliseconds);
			
		private:
			QSharedDataPointer<ViewConePrivate> d;
	};
}

Q_DECLARE_METATYPE(BehaviorTree::ViewCone)
Q_DECLARE_METATYPE(BehaviorTree::ViewCone*)

#endif