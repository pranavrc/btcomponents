#ifndef PERCEPTIONINFOPRIVATE_H
#define PERCEPTIONINFOPRIVATE_H
#include "asset.h"

#include <QtCore/QSharedData>

namespace BehaviorTree
{
	class PerceptionInfoPrivate : public QSharedData
	{
		public:
			PerceptionInfoPrivate();
			PerceptionInfoPrivate(const PerceptionInfoPrivate& other );
			~PerceptionInfoPrivate();
	};
}

#endif