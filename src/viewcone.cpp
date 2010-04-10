#include "viewcone.h"

#include "viewconeprivate.h"
#include "perceptionatom.h"

using namespace BehaviorTree;

ViewCone::ViewCone(QObject * parent)
	: Component(parent)
{
	d = new ViewConePrivate();
}

ViewCone::ViewCone(const ViewCone &other, QObject* parent)
	: Component(parent)
	, d(other.d)
{
	
}

ViewCone::~ViewCone()
{
}

void ViewCone::update(int elapsedMilliseconds)
{
	#warning update perception view cones here
	
	Component::update(elapsedMilliseconds);
}

Q_EXPORT_PLUGIN2(gluon_plugin_component_viewcone, BehaviorTree::ViewCone)

#include "viewcone.moc"