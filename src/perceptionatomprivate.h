#ifndef PERCEPTIONATOMPRIVATE_H
#define PERCEPTIONATOMPRIVATE_H

#include <QtCore/QSharedData>

namespace BehaviorTree
{
	class PerceptionAtomPrivate : public QSharedData
	{
		public:
			PerceptionAtomPrivate();
			PerceptionAtomPrivate(const PerceptionAtomPrivate& other );
			~PerceptionAtomPrivate();
	};
}

#endif