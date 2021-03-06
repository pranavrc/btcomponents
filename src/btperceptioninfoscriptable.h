#ifndef BTPERCEPTIONINFOSCRIPTABLE_H
#define BTPERCEPTIONINFOSCRIPTABLE_H

#include "bt_export.h"
#include <smarts/btperceptioninfo.h>

namespace BehaviorTree
{
	class BTCOMPONENT_EXPORT btPerceptionInfoScriptable : public btPerceptionInfo
	{
		Q_OBJECT
		public:
			btPerceptionInfoScriptable(QObject* parent);
			~btPerceptionInfoScriptable();
			
			virtual QVariant getAdjustedValue(qreal precision) const;
	};
}

#endif