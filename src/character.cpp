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
#include <core/debughelper.h>
#include <smarts/btcharacter.h>
#include "character.h"
#include "characterprivate.h"
#include "tree.h"

REGISTER_OBJECTTYPE(BehaviorTree,Character)

using namespace BehaviorTree;

Character::Character(QObject * parent)
    : Component(parent)
{
    d = new CharacterPrivate;
    
    #warning Q_PROPERTY does not currently handle namespaced types - see bugreports.qt.nokia.com/browse/QTBUG-2151
    setTree(NULL);
    d->self = new btCharacter();
}

Character::Character(const Character &other, QObject * parent)
    : Component(parent)
    , d(other.d)
{
}

Character::~Character()
{
}

void
Character::update(int elapsedMilliseconds)
{
    //debug(QString("Updating Character"));
    if(autoThink())
        think();
    Component::update(elapsedMilliseconds);
}

bool
Character::think()
{
    //debug(QString("Thinking..."));
    QString debugText;
    if(tree())
    {
        if(tree()->behaviorTree())
        {
		
		if(tree()->behaviorTree()->run(d->self) == btNode::Succeeded)
		{
			debugText += "Thought successfully!";
			// SUCCESS!!
		}
		else
		{
			debugText += "Failed at thinking :P";
			// FAILURE!
		}
        }
        else
            debugText += "Thinking not possible - behavoirTree not set!";
    }
    else
        debugText += "Thinking not possible - no tree!";
    //debug(debugText);
}

void
Character::treeReplaced(Tree* newTree)
{
    setTree(newTree);
}

void
Character::setTree(Tree* newAsset)
{
    DEBUG_BLOCK
    if(newAsset) { DEBUG_TEXT(QString("Setting tree to %1").arg(newAsset->name())) }

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
    //return d->tree;
    Tree* returnTree = NULL;
    GluonObject* theTree = this->property("tree").value<GluonObject*>();
    if(qobject_cast<Tree*>(theTree))
        returnTree = qobject_cast<Tree*>(theTree);
    return returnTree;
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

Q_EXPORT_PLUGIN2(gluon_plugin_component_behaviortree, BehaviorTree::Character)

#include "character.moc"
