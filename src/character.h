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

#ifndef BRAIN_H
#define BRAIN_H

#include <component.h>
#include <btbrain.h>
#include "bt_export.h"

namespace BehaviorTree
{
    class CharacterPrivate;
    class Tree;

    class BTCOMPONENT_EXPORT Character : public Gluon::Component
    {
        Q_OBJECT
        Q_INTERFACES(Gluon::Component)
        Q_PROPERTY(bool autoThink READ autoThink WRITE setAutoThink)
        //Q_PROPERTY has problems with namespaced types - workaround in constructor, setBrain and brain
        //Q_PROPERTY(BehaviorTree::Tree* tree READ tree WRITE setTree)
        
        public:
            Character(QObject * parent = 0);
            Character(const Character &other, QObject * parent = 0);
            ~Character();
            
            virtual Character* instantiate();
            virtual void update(int elapsedMilliseconds);
            
            bool think();
            
            void setTree(Tree* newAsset);
            Tree* tree() const;
            
            void setAutoThink(bool newAutoThink);
            bool autoThink() const;
        
        private Q_SLOTS:
            void treeReplaced(Tree* newTree);
            
        private:
            QSharedDataPointer<CharacterPrivate> d;
    };
}

#endif // BRAIN_H
