/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <QtCore/QVariant>
#include <QtCore/QDebug>
#include "character.h"
#include "characterprivate.h"
#include "tree.h"

Q_DECLARE_METATYPE(BehaviorTree::Tree*)

REGISTER_OBJECTTYPE(BehaviorTree,Character)

using namespace BehaviorTree;

Character::Character(QObject * parent)
    : Component(parent)
{
    d = new CharacterPrivate;
    
    #warning Q_PROPERTY does not currently handle namespaced types - see bugreports.qt.nokia.com/browse/QTBUG-2151
    QVariant somethingEmpty;
    Tree * theObject = NULL;
    somethingEmpty.setValue<Tree*>(theObject);
    setProperty("entryPoint", somethingEmpty);
}

Character::Character(const Character &other, QObject * parent)
    : Component(parent)
    , d(other.d)
{
}

Character::~Character()
{
}

Character*
Character::instantiate()
{
    return new Character(this);
}

void
Character::update(int elapsedMilliseconds)
{
    qDebug() << "Updating Character";
    if(autoThink())
        think();
    Component::update(elapsedMilliseconds);
}

bool
Character::think()
{
    qDebug() << "Thinking...";
    if(tree()->behaviorTree()->runBehavior())
    {
        qDebug() << "Thought successfully!";
        // SUCCESS!!
    }
    else
    {
        qDebug() << "Failed at thinking :P";
        // FAILURE!
    }
}

void
Character::treeReplaced(Tree* newTree)
{
    setTree(newTree);
}

void
Character::setTree(Tree* newAsset)
{
    if(d->tree)
        disconnect(d->tree, SIGNAL(treeChanged(Tree*)), this, SLOT(treeReplaced(Tree*)));
    d->tree = newAsset;
    
    QVariant theNewValue;
    theNewValue.setValue<Tree*>(newAsset);
    setProperty("tree", theNewValue);
    
    if(d->tree)
        connect(d->tree, SIGNAL(treeChanged(Tree*)), this, SLOT(treeReplaced(Tree*)));
}

Tree*
Character::tree() const
{
    return d->tree;
}

void
Character::setAutoThink(bool newAutoThink)
{
    d->autoThink = newAutoThink;
}

bool
Character::autoThink() const
{
    return d->autoThink;
}


Q_EXPORT_PLUGIN2(component_behaviortree, BehaviorTree::Character)

#include "character.moc"
