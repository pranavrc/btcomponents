#include "btcomponents-testapp.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QUrl>

#include <gluon/gluonobjectfactory.h>
#include <gluon/gameproject.h>
#include <gluon/game.h>
#include <gluon/gdlhandler.h>

btcomponentstestapp::btcomponentstestapp()
{
    Gluon::GluonObjectFactory::instance()->loadPlugins();
}

btcomponentstestapp::~btcomponentstestapp()
{}

void
btcomponentstestapp::run(QUrl gdlFile)
{
    Gluon::GameProject *gameProject = new Gluon::GameProject(QCoreApplication::instance());
    gameProject->loadFromFile(gdlFile);
    
    Gluon::Game::instance()->setParent(QCoreApplication::instance());
    Gluon::Game::instance()->setGameProject(gameProject);
    
    //qDebug() << "The gameProject turned into GDL:" << gameProject->toGDL();
    
    // Run the game at severely reduced speed (one frame per second) so we can
    // actually see what's happening
    Gluon::Game::instance()->runGameFixedTimestep(1);
}

#include "btcomponents-testapp.moc"
