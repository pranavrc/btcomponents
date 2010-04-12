#ifndef PERCEPTIONINFOPRIVATE_H
#define PERCEPTIONINFOPRIVATE_H

#include <QtCore/QSharedData>

namespace BehaviorTree
{
	class btPerceptionInfoScriptable;
	
	class PerceptionInfoPrivate : public QSharedData
	{
		public:
			PerceptionInfoPrivate();
			PerceptionInfoPrivate(const PerceptionInfoPrivate& other );
			~PerceptionInfoPrivate();
			
			btPerceptionInfoScriptable * info;
	};
}

#endif