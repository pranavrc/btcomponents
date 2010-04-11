#include "perceptioninfo.h"

#include "perceptioninfoprivate.h"

#include <smarts/btperceptioninfo.h>

REGISTER_OBJECTTYPE(BehaviorTree, PerceptionInfo)

using namespace BehaviorTree;

PerceptionInfo::PerceptionInfo(QObject* parent)
	: Component(parent)
{
	d = new PerceptionInfoPrivate();
	d->info = new btPerceptionInfo();
}

PerceptionInfo::PerceptionInfo(const PerceptionInfo& other, QObject* parent)
	: Component(parent)
	, d(other.d)
{

}

PerceptionInfo::~PerceptionInfo()
{

}

QVector3D PerceptionInfo::position() const
{
	return d->info->position();
}
void PerceptionInfo::setPosition(const QVector3D& newPosition)
{
	d->info->setPosition(newPosition);
}
        
qreal PerceptionInfo::radius() const
{
	return d->info->radius();
}

void PerceptionInfo::setRadius(const qreal& newRadius)
{
	d->info->setRadius(newRadius);
}

btPerceptionInfo* PerceptionInfo::getBtPerceptionInfo()
{
	return d->info;
}

Q_EXPORT_PLUGIN2(gluon_plugin_component_perceptioninfo, BehaviorTree::PerceptionInfo)

#include "perceptioninfo.moc"