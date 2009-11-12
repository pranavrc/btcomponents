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

#include "brain.h"
#include "brainprivate.h"
#include "asset.h"

using namespace BehaviorTree;

REGISTER_OBJECTTYPE(Brain)

Brain::Brain(QObject * parent)
    : Component(parent)
{
    d = new BrainPrivate;
}

Brain::Brain(const Brain &other, QObject * parent)
    : Component(parent)
    , d(other.d)
{
}

Brain::~Brain()
{
}

void
Brain::brainChanged()
{
    Asset* theSender = qobject_cast<Asset*>(QObject::sender());
    if(theSender)
    {
    }
}

void
Brain::setBrain(Asset* newAsset)
{
    if(d->behaviorTree)
        disconnect(d->behaviorTree, SIGNAL(dataChanged()), this, SLOT(btChanged()));
    d->brain = newAsset;
    connect(d->behaviorTree, SIGNAL(dataChanged()), this, SLOT(btChanged()));
}

Asset*
Brain::brain() const
{
    return d->brain;
}

#include "brain.moc"
