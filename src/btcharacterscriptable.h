#ifndef BTCHARACTERSCRIPTABLE_H
#define BTCHARACTERSCRIPTABLE_H

#include "bt_export.h"

#include <smarts/btcharacter.h>

namespace BehaviorTree
{
	class BTCOMPONENT_EXPORT btCharacterScriptable : public btCharacter
	{
		Q_OBJECT
		public:
			btCharacterScriptable(QObject * parent = 0);
			~btCharacterScriptable();
			
			Q_INVOKABLE virtual QVector3D position() const;
			Q_INVOKABLE virtual void setPosition(const QVector3D& newPosition);

			Q_INVOKABLE virtual QQuaternion orientation() const;
			Q_INVOKABLE virtual void setOrientation(const QQuaternion& newOrientation);

			Q_INVOKABLE virtual btPerception* perception();
	};
}

#endif