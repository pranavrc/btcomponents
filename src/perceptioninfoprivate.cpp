#include "perceptioninfoprivate.h"

#include <smarts/btperceptioninfo.h>

using namespace BehaviorTree;

PerceptionInfoPrivate::PerceptionInfoPrivate()
{
}

PerceptionInfoPrivate::PerceptionInfoPrivate(const PerceptionInfoPrivate& other)
	: QSharedData(other)
	, info(other.info)
{
}

PerceptionInfoPrivate::~PerceptionInfoPrivate()
{
}