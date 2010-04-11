#ifndef PERCEPTIONINFO_H
#define PERCEPTIONINFO_H

#include "bt_export.h"

#include <QtCore/QObject>
#include <engine/component.h>
#include <QtCore/QSharedData>

class QVector3D;
class btPerceptionInfo;

namespace BehaviorTree
{
	class PerceptionInfoPrivate;
	
	class BTCOMPONENT_EXPORT PerceptionInfo : public GluonEngine::Component
	{
		Q_OBJECT
		GLUON_OBJECT(BehaviorTree::PerceptionInfo)
		Q_INTERFACES(GluonEngine::Component)
		Q_PROPERTY(QVector3D position READ position WRITE setPosition NOTIFY positionUpdated)
		Q_PROPERTY(qreal radius READ radius WRITE setRadius NOTIFY radiusUpdated)
        
		public:
			PerceptionInfo(QObject* parent = 0);
			PerceptionInfo(const PerceptionInfo& other, QObject* parent = 0);
			~PerceptionInfo();
			
			QVector3D position() const;
			void setPosition(const QVector3D& newPosition);
        
			qreal radius() const;
			void setRadius(const qreal& newRadius);
			
			btPerceptionInfo * getBtPerceptionInfo();

		private:
			QSharedDataPointer<PerceptionInfoPrivate> d;
	};
}

Q_DECLARE_METATYPE(BehaviorTree::PerceptionInfo)
Q_DECLARE_METATYPE(BehaviorTree::PerceptionInfo*)

#endif