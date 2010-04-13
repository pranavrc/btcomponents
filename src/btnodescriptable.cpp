#include "btnodescriptable.h"

#include <QtScript/QScriptEngine>
#include <QtCore/QMimeData>
#include <engine/gameobject.h>
#include <QtCore/QDebug>
#include <engine/game.h>
#include "btcharacterscriptable.h"

using namespace BehaviorTree;

REGISTER_NODETYPE(btNodeScriptable)

class btNodeScriptable::btNodeScriptablePrivate
{
	public:
		btNodeScriptablePrivate()
		{
		}
		
		~btNodeScriptablePrivate()
		{
		}
		
		QScriptEngine engine;
		GluonEngine::Asset * script;
		QScriptValue runFunc;
};

btNodeScriptable::btNodeScriptable()
{
	d = new btNodeScriptablePrivate();
}

btNodeScriptable::~btNodeScriptable()
{
	delete d;
}

btNode::status btNodeScriptable::run(btCharacter* self)
{
	QScriptValue character = d->engine.newQObject(qobject_cast<btCharacterScriptable*>(self));
	d->engine.globalObject().setProperty("character", character);
	
	if(d->runFunc.isFunction())
	{
		d->runFunc.call();
		if (d->engine.uncaughtException().isValid())
        {
            qDebug() << d->engine.uncaughtException().toString();
            qDebug() << d->engine.uncaughtExceptionBacktrace().join(" ");
        }
	}
}

void btNodeScriptable::setScriptAsset(GluonEngine::Asset * asset)
{
	d->script = asset;

    d->script->load();

    if (d->script->data()->hasText())
    {
        d->engine.evaluate(d->script->data()->text(), this->className());
        if (d->engine.uncaughtException().isValid())
        {
            qDebug() << d->engine.uncaughtException().toString();
            qDebug() << d->engine.uncaughtExceptionBacktrace().join(" ");
            return;
        }

        QScriptValue btnode = d->engine.newQObject(this);
		d->engine.globalObject().setProperty("btNode", btnode);

        QScriptValue game = d->engine.newQObject(GluonEngine::Game::instance(), QScriptEngine::QtOwnership, QScriptEngine::AutoCreateDynamicProperties);
        d->engine.globalObject().setProperty("Game", game);

        d->runFunc = d->engine.globalObject().property("run");
    }
}

#include "btnodescriptable.moc"