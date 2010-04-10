#ifndef PERCEPTIONINFO_H
#define PERCEPTIONINFO_H

#include "bt_export.h"

#include <QtCore/QObject>
#include <engine/component.h>
#include <QtCore/QSharedData>

namespace BehaviorTree
{
	class PerceptionInfoPrivate;
	
	class BTCOMPONENT_EXPORT PerceptionInfo : public GluonEngine::Component
	{
		Q_OBJECT
		GLUON_OBJECT(BehaviorTree::PerceptionInfo)
		Q_INTERFACES(GluonEngine::Component)
		public:
			PerceptionInfo(QObject* parent = 0);
			PerceptionInfo(const PerceptionInfo& other, QObject* parent = 0);
			~PerceptionInfo();
		private:
			QSharedDataPointer<PerceptionInfoPrivate> d;
	};
}

Q_DECLARE_METATYPE(BehaviorTree::PerceptionInfo)
Q_DECLARE_METATYPE(BehaviorTree::PerceptionInfo*)

#endif