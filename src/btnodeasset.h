#ifndef BTNODEASSET_H
#define BTNODEASSET_H

#include "bt_export.h"
#include <engine/asset.h>

namespace BehaviorTree
{	
	class BTCOMPONENT_EXPORT btNodeAsset : public GluonEngine::Asset
	{
		Q_OBJECT
        GLUON_OBJECT(BehaviorTree::btAsset)
        Q_INTERFACES(GluonEngine::Asset)
        
		public:
			btNodeAsset(QObject* parent = 0);
			~btNodeAsset();
			
			virtual void setFile(const QUrl &newFile);
			virtual const QStringList supportedMimeTypes() const;
			
		private:
			class btNodeAssetPrivate;
			btNodeAssetPrivate * d;
	};
}

Q_DECLARE_METATYPE(BehaviorTree::btNodeAsset)
Q_DECLARE_METATYPE(BehaviorTree::btNodeAsset*)

#endif