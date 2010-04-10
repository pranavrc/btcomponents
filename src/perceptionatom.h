#ifndef PERCEPTIONATOM_H
#define PERCEPTIONATOM_H
#include "asset.h"

#include "bt_export.h"

#include <engine/component.h>
#include <QtCore/QObject>
#include <QtCore/QSharedData>

namespace BehaviorTree
{
	class PerceptionAtomPrivate;
	
	class BTCOMPONENT_EXPORT PerceptionAtom : public GluonEngine::Component
	{
		Q_OBJECT
		GLUON_OBJECT(BehaviorTree::PerceptionAtam)
		Q_INTERFACES(GluonEngine::Component)
		
		public:
			PerceptionAtom(QObject* parent = 0);
			PerceptionAtom(const PerceptionAtom& other, QObject* parent = 0);
			~PerceptionAtom();
		private:
			QSharedDataPointer<PerceptionAtomPrivate> d;
	};
}

Q_DECLARE_METATYPE(BehaviorTree::PerceptionAtom)
Q_DECLARE_METATYPE(BehaviorTree::PerceptionAtom*)

#endif