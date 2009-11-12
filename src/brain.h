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

namespace BehaviorTree
{
    class BrainPrivate;
    class Asset;

    class Brain : public Gluon::Component
    {
        Q_OBJECT
        Q_INTERFACES(Gluon::Component)
        Q_PROPERTY(Asset * brain READ brain WRITE setBrain)
        
        public:
            Brain(QObject * parent = 0);
            Brain(const Brain &other, QObject * parent = 0);
            ~Brain();
            
            void setBrain(Asset* newAsset);
            Asset* brain() const;
        
        private Q_SLOTS:
            void brainChanged();
            
        private:
            QSharedDataPointer<BrainPrivate> d;
    };
}

#endif // BRAIN_H
