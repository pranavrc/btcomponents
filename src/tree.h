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

#ifndef BEHAVIORTREE_TREE_H
#define BEHAVIORTREE_TREE_H

#include "bt_export.h"
#include <gluon/asset.h>
#include <btnode.h>

namespace BehaviorTree
{
    class Asset;
    class TreePrivate;
    
    class BTCOMPONENT_EXPORT Tree : public Gluon::Asset
    {
        Q_OBJECT
        Q_INTERFACES(Gluon::Asset)
        Q_PROPERTY(btNode* behaviorTree READ behaviorTree WRITE setBehaviorTree)
        
        public:
            friend class BehaviorTree::Asset;
            
            Tree(QObject * parent = 0);
            ~Tree();
            
            virtual Tree * instantiate();
            
            void setBehaviorTree(btNode* newBehaviorTree);
            btNode* behaviorTree() const;
            
        Q_SIGNALS:
            void treeChanged(Tree* newTree);
            
        private:
            QSharedDataPointer<TreePrivate> d;
    };
}

#endif // BEHAVIORTREE_TREE_H
