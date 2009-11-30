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

#include "asset.h"
#include "assetprivate.h"
#include "tree.h"

#include <btbrain.h>
#include <QtCore/QVariant>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QMap>
#include <QtCore/QDebug>

Q_DECLARE_METATYPE(btNode*)

REGISTER_OBJECTTYPE(BehaviorTree,Asset)

using namespace BehaviorTree;

Asset::Asset(QObject * parent)
    : Gluon::Asset(parent)
{
    d = new AssetPrivate;
    qRegisterMetaType<btNode*>("btNode*");
}

Asset::~Asset()
{
    delete(d);
}

Asset *
Asset::instantiate()
{
    return new Asset(this);
}

void
Asset::setFile(const QUrl &newFile)
{
    qDebug() << "Attempting to load" << newFile.toLocalFile();
    QFile *brainFile = new QFile(newFile.toLocalFile());
    if(!brainFile->open(QIODevice::ReadOnly))
        return;
    
    qDebug() << "File opened, attempting to create brain";
    QTextStream brainReader(brainFile);
    btBrain* newBrain = new btBrain(brainReader.readAll());
    brainFile->close();
    delete(brainFile);
    
    if(!newBrain)
        return;
    
    qDebug() << "Brain loaded, replacing old brain and creating" << newBrain->behaviorTreesCount() << "sub-assets";
    //delete(d->brain);
    d->brain = newBrain;
    
    const QObjectList& oldChildren = children();
    QList<Tree*> newChildren;
    for(int i = 0; i < newBrain->behaviorTreesCount(); ++i)
    {
        Tree* newTree = new Tree(this);
        this->addChild(newTree);
        newTree->setBehaviorTree(newBrain->getBehaviorTree(i));
        newTree->setName(newTree->behaviorTree()->name());
        newChildren.append(newTree);
    }
    
    // Run through all old children
    foreach(QObject* oldChild, oldChildren)
    {
        Tree* theNewChild = NULL;
        Tree* theOldChild = qobject_cast<Tree*>(oldChild);
        // Find a tree with the same name in the new children
        foreach(Tree* newChild, newChildren)
        {
            if(newChild->name() == theOldChild->name())
                theNewChild = newChild;
        }
        // Tell old child that new child is the tree that should be used
        // If no new child could be found, inform the oldChild that it should be removed
        emit theOldChild->treeChanged(theNewChild);
    }
    
    qDebug() << "Brain successfully loaded! Number of sub-assets created:" << this->children().count();
    
//    qDeleteAll(oldChildren);
    
    Gluon::Asset::setFile(newFile);
}

Q_EXPORT_PLUGIN2(asset_behaviortree, BehaviorTree::Asset)

#include "asset.moc"
