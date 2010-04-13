#ifndef BTNODESCRIPTABLE_H
#define BTNODESCRIPTABLE_H

#include "bt_export.h"
#include <smarts/btlib.h>
#include <engine/asset.h>
#include "asset.h"

namespace BehaviorTree
{
	class BTCOMPONENT_EXPORT btNodeScriptable : public btNode
	{
		Q_OBJECT
		public:
			Q_INVOKABLE btNodeScriptable();
			~btNodeScriptable();
			
			void setScriptAsset(GluonEngine::Asset * asset);
			
			virtual status run(btCharacter * self);
			
		private:
			class btNodeScriptablePrivate;
			btNodeScriptablePrivate * d;
	};
}

#endif