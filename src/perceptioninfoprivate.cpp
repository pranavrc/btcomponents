#include "perceptioninfoprivate.h"

#include "btperceptioninfoscriptable.h"

using namespace BehaviorTree;

PerceptionInfoPrivate::PerceptionInfoPrivate()
{
	
	QScriptValue extensionObject = engine.globalObject();
	script = 0;
}

PerceptionInfoPrivate::PerceptionInfoPrivate(const PerceptionInfoPrivate& other)
	: QSharedData(other)
	, info(other.info)
{
}

PerceptionInfoPrivate::~PerceptionInfoPrivate()
{
}