#ifndef PERCEPTIONINFOPRIVATE_H
#define PERCEPTIONINFOPRIVATE_H

#include <QtCore/QSharedData>
#include <engine/asset.h>
#include <QtScript/QScriptEngine>
#include <QtCore/QDebug>

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
			QScriptEngine engine;

			QScriptValue drawFunc;
			QScriptValue updateFunc;

			GluonEngine::Asset* script;
	};
}

#endif