#include "perceptionatom.h"

#include "perceptionatomprivate.h"

using namespace BehaviorTree;

PerceptionAtom::PerceptionAtom(QObject* parent): Component(parent)
{
	d = new PerceptionAtomPrivate();
}

PerceptionAtom::PerceptionAtom(const PerceptionAtom& other, QObject* parent)
	: Component(parent)
	, d(other.d)
{

}

PerceptionAtom::~PerceptionAtom()
{

}

Q_EXPORT_PLUGIN2(gluon_plugin_component_perceptionatom, BehaviorTree::PerceptionAtom)

#include "perceptionatom.moc"