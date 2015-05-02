// Shruthi-Editor: An unofficial Editor for the Shruthi hardware synthesizer. For
// informations about the Shruthi, see <http://www.mutable-instruments.net/shruthi1>.
//
// Copyright (C) 2011-2015 Manuel Krönig
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


#ifndef LIBRARY_H
#define LIBRARY_H

#import <vector>
#import "lib_patch.h"
#import "lib_sequence.h"
#import "lib_midiout.h"

class QString;

// ******************************************
class Library {
// ******************************************

    public:
        Library(MidiOut *out);
        ~Library();

        const Patch &recallPatch(const int &id);
        void storePatch(const int &id, const Patch &patch);
        void listPatches();
        void movePatch(const int &from, const int &to);

        const Sequence &recallSequence(const int &id);
        void storeSequence(const int &id, const Sequence &sequence);
        void listSequences();
        void moveSequence(const int &from, const int &to);

        bool fetch(const int &from, const int &to);
        void abortFetching();

        bool fetchPatches(const int &from, const int &to);
        bool receivedPatch(const unsigned char *sysex);
        bool isFetchingPatches();

        bool fetchSequences(const int &from, const int &to);
        bool receivedSequence(const unsigned char *seq);
        bool isFetchingSequences();

        bool saveLibrary(const QString &path);
        bool loadLibrary(const QString &path);

        void setNumberOfPrograms(const unsigned int &num);

    private:
        bool keepFetching();

        std::vector<Patch> patches;
        std::vector<bool> patchMoved;
        std::vector<bool> patchEdited;

        std::vector<Sequence> sequences;
        std::vector<bool> sequenceMoved;
        std::vector<bool> sequenceEdited;

        const Sequence init_sequence;

        void growPatchVectors(const int &amount);
        void growSequenceVectors(const int &amount);

        MidiOut *midiout;

        bool fetchPatchMode;
        bool fetchSequenceMode;

        unsigned int fetchEnd;
        unsigned int fetchNextIncomingPatch;
        unsigned int fetchNextPatchRequest;

        unsigned int fetchNextIncomingSequence;
        unsigned int fetchNextSequenceRequest;


        int numberOfPrograms;
};

#endif // LIBRARY_H
