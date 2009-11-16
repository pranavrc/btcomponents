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

#include <btbrain.h>
#include <QtCore/QVariant>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QMap>

Q_DECLARE_METATYPE(btNode*)

using namespace BehaviorTree;

REGISTER_OBJECTTYPE(Asset)

Asset::Asset(QObject * parent)
    : Gluon::Asset(parent)
{
    qRegisterMetaType<btNode*>("btNode*");
}

Asset *
Asset::instantiate()
{
    return new Asset(this);
}

void
Asset::setFile(const QString &newFile)
{
    QFile *brainFile = new QFile(newFile);
    if(!brainFile->open(QIODevice::ReadOnly))
        return;
    
    QTextStream brainReader(brainFile);
    btBrain* newBrain = new btBrain(brainReader.readAll());
    brainFile->close();
    delete(brainFile);
    
    if(!newBrain)
        return;
    
    delete(d->brain);
    d->brain = newBrain;
    
    d->behaviorTrees.clear();
    int typeID = QMetaType::type("btNode");
    for(int i = 0; i < newBrain->behaviorTreesCount(); ++i)
       d->behaviorTrees[newBrain->getBehaviorTree(i)->name()] = QVariant(typeID, newBrain->getBehaviorTree(i));
    
    Gluon::Asset::setFile(newFile);
}

QMap<QString, QVariant>
Asset::behaviorTrees() const
{
    return d->behaviorTrees;
}

btNode*
Asset::behaviorTree(QString name) const
{
    QVariant variant = d->behaviorTrees[name];
    if(variant.canConvert<btNode*>())
        return qVariantValue<btNode*>(d->behaviorTrees[name]);
    return NULL;
}

Q_EXPORT_PLUGIN2(asset_behaviortree, BehaviorTree::Asset)

#include "asset.moc"
