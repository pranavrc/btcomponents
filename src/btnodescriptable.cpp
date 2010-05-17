#include "btnodescriptable.h"

#include <QtScript/QScriptEngine>
#include <QtCore/QMimeData>
#include <engine/gameobject.h>
#include <QtCore/QDebug>
#include <engine/game.h>
#include "btcharacterscriptable.h"
#include "character.h"

using namespace BehaviorTree;

Q_DECLARE_METATYPE(btNode::status)

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
        Character * character;
};

btNodeScriptable::btNodeScriptable(Character * character)
{
	d = new btNodeScriptablePrivate();
    d->character = character;
}

btNodeScriptable::~btNodeScriptable()
{
	delete d;
}

btNode::status btNodeScriptable::run(btCharacter* self)
{
	QScriptValue character = d->engine.newQObject(qobject_cast<btCharacterScriptable*>(self), QScriptEngine::QtOwnership, QScriptEngine::AutoCreateDynamicProperties);
	d->engine.globalObject().setProperty("Character", character);
    
    
    QScriptValue btnode = d->engine.newQObject(qobject_cast<btNodeScriptable*>(this), QScriptEngine::QtOwnership, QScriptEngine::AutoCreateDynamicProperties);
    d->engine.globalObject().setProperty("Node", btnode);
    
    QScriptValue game = d->engine.newQObject(GluonEngine::Game::instance(), QScriptEngine::QtOwnership, QScriptEngine::AutoCreateDynamicProperties);
    d->engine.globalObject().setProperty("Game", game);
	
	if(d->runFunc.isFunction())
	{
		d->runFunc.call();
		if (d->engine.uncaughtException().isValid())
        {
            d->character->debug(QString("%1: %2").arg(d->engine.uncaughtException().toString()).arg(d->engine.uncaughtExceptionBacktrace().join(" ")));
        }
	}
	
	qDebug() <<"stuf " << this->property(QString("status").toUtf8());
	return this->property(QString("status").toUtf8()).value<btNode::status>();
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
            d->character->debug(QString("%1: %2").arg(d->engine.uncaughtException().toString()).arg(d->engine.uncaughtExceptionBacktrace().join(" ")));
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
