#include "btcharacterscriptable.h"

#include "character.h"
#include <engine/gameobject.h>

using namespace BehaviorTree;

BehaviorTree::btCharacterScriptable::btCharacterScriptable(QObject * parent)
	: btCharacter()
{
    this->setParent(parent);
}

BehaviorTree::btCharacterScriptable::~btCharacterScriptable()
{
}

QVector3D BehaviorTree::btCharacterScriptable::position() const
{
    Character * character = qobject_cast< Character* >(this->parent());
    return character->gameObject()->position();
}

void BehaviorTree::btCharacterScriptable::setPosition(const QVector3D& newPosition)
{
    Character * character = qobject_cast< Character* >(this->parent());
    character->gameObject()->setPosition(newPosition);
}

QQuaternion BehaviorTree::btCharacterScriptable::orientation() const
{
    Character * character = qobject_cast< Character* >(this->parent());
    return character->gameObject()->orientation();
}

void BehaviorTree::btCharacterScriptable::setOrientation(const QQuaternion& newOrientation)
{
    Character * character = qobject_cast< Character* >(this->parent());
    character->gameObject()->setOrientation(newOrientation);
}

btPerception* BehaviorTree::btCharacterScriptable::perception()
{
    Character * character = qobject_cast< Character* >(this->parent());
    return this->perception();
}
