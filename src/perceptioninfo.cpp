#include "perceptioninfo.h"

#include "perceptioninfoprivate.h"

using namespace BehaviorTree;

PerceptionInfo::PerceptionInfo(QObject* parent)
	: Component(parent)
{

}

PerceptionInfo::PerceptionInfo(const PerceptionInfo& other, QObject* parent)
	: Component(parent)
	, d(other.d)
{

}

PerceptionInfo::~PerceptionInfo()
{

}

Q_EXPORT_PLUGIN2(gluon_plugin_component_perceptioninfo, BehaviorTree::PerceptionInfo)

#include "perceptioninfo.moc"