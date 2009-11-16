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

#include "tree.h"
#include "treeprivate.h"

using namespace BehaviorTree;

REGISTER_OBJECTTYPE(Tree)

Tree::Tree(QObject * parent)
{
    d = new TreePrivate();
}

Tree::~Tree()
{
}

Tree *
Tree::instantiate()
{
    return new Tree(this);
}

void Tree::update(int elapsedMilliseconds)
{
    Q_UNUSED(elapsedMilliseconds)
}

void
Tree::setBehaviorTree(btNode* newBehaviorTree)
{
    d->behaviorTree = newBehaviorTree;
}

btNode*
Tree::behaviorTree() const
{
    return d->behaviorTree;
}

Q_EXPORT_PLUGIN2(component_behaviortree, BehaviorTree::Tree)


#include "tree.moc"
