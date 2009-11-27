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

#include "character.h"
#include "characterprivate.h"
#include "tree.h"

REGISTER_OBJECTTYPE(BehaviorTree,Character)

using namespace BehaviorTree;

Character::Character(QObject * parent)
    : Component(parent)
{
    d = new CharacterPrivate;
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
    if(d->tree)
        connect(d->tree, SIGNAL(treeChanged(Tree*)), this, SLOT(treeReplaced(Tree*)));
}

Tree*
Character::tree() const
{
    return d->tree;
}

#include "character.moc"
