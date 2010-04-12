#include "btperceptioninfoscriptable.h"

#include <QtGui/QVector3D>

using namespace BehaviorTree;

BehaviorTree::btPerceptionInfoScriptable::btPerceptionInfoScriptable(QObject* parent)
	: btPerceptionInfo(parent)
{
	setPosition(QVector3D());
	setRadius(0);
}

btPerceptionInfoScriptable::~btPerceptionInfoScriptable()
{

}

QVariant BehaviorTree::btPerceptionInfoScriptable::getAdjustedValue(qreal precision) const
{

}

#include "btperceptioninfoscriptable.moc"