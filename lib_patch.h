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

#ifndef SHRUTHI_PATCH_H
#define SHRUTHI_PATCH_H
#include "lib_labels.h"
#include <vector>

// ******************************************
struct param_t {
// ******************************************
    QString name;
    QString short_name;
    int min;
    int max;
    QStringList* dropdown;
    QString (*formatter)(int);
    int cc;
};


// ******************************************
static const param_t param_blank = {NULL, NULL, 0, 0, NULL, NULL, -1};
// ******************************************


// ******************************************
class Patch {
// ******************************************
    private:
        QString name;
        int data[110];
        unsigned char version;

        static const param_t parameter84[];
        static const param_t parameter85[];
        static const param_t parameter92[];
        static const param_t parameter93[];

    public:
        static const unsigned char parameterCount;
        static const unsigned char filterBoardCount;
        static const unsigned char INIT_PATCH[];
        static const unsigned char INIT_PATCH_PRE100[];
        static bool enabled(const int &id);
        static bool hasUI(const int &id);
        static bool sendAsNRPN(const int &id);

        static const param_t parameters[]; // use this with caution
        static param_t parameter(int id, int filter = 0);

        Patch();

        void setParam(int id, int value);
        int getParam(int id);
        QString getParamFancy(int id);
        static QString formatParameterValue(int id, int value, int filter = 0);
        void setName(QString name);
        QString getName();
        QString getVersionString();

        void printPatch();
        void resetPatch(unsigned int version = 1000);
        void randomizePatch(const int &filter);

        bool unpackData(const unsigned char *sysex);
        void packData(unsigned char res[]);
        bool parseSysex(const std::vector<unsigned char> *message);
        void generateSysex(std::vector<unsigned char> *message);

        bool equals(const Patch &other);

        static unsigned char ccToId(const unsigned char &cc, const int &filter);
        static int convertCCValue(const unsigned int &val, int &id, const int &filter);
};
#endif
