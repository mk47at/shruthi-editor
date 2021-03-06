// Shruthi-Editor: An unofficial Editor for the Shruthi hardware synthesizer. For
// informations about the Shruthi, see <http://www.mutable-instruments.net/shruthi1>.
//
// Copyright (C) 2011-2019 Manuel Krönig
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


#ifndef SHRUTHI_SEQUENCE_H
#define SHRUTHI_SEQUENCE_H


#include "message.h"
#include "sequence_parameter.h"


class Sequence {
    public:
        Sequence();

        void unpackData(const unsigned char *data);
        void packData(unsigned char data[]) const;
        bool parseSysex(const Message *message);
        void generateSysex(Message *message) const;

        const int &getValue(const int &step, const SequenceParameter::SequenceParameter &sp) const;
        void setValue(const int &step, const SequenceParameter::SequenceParameter &sp, const int &val);
        void setValueById(const int &id, const int &val);
        static int calculateParamId(const int &step, const SequenceParameter::SequenceParameter &sp);
        void reset();

        bool equals(const Sequence &other) const;
        void set(const Sequence &other);

        static const int NUMBER_OF_STEPS = 16;
        static const int ERROR_RETURN;

    private:
        void print() const;

        int mActive[16];
        int mNote[16];
        int mTie[16];
        int mVelocity[16];
        int mValue[16];
        static unsigned char INIT_SEQUENCE[];
};


#endif // SHRUTHI_SEQUENCE_H
