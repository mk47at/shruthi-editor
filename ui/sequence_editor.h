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


#ifndef SEQUENCEEDITOR_H
#define SEQUENCEEDITOR_H


#include <QDialog>
#include "queueitem.h"
namespace Ui { class SequenceEditor; }


class SequenceEditor : public QDialog {
        Q_OBJECT

    public:
        explicit SequenceEditor(QWidget *parent = 0);
        ~SequenceEditor();

    private:
        SequenceEditor(const SequenceEditor&); //forbid copying
        SequenceEditor &operator=(const SequenceEditor&); //forbid assignment

        void sendSequenceUpdate();

        Ui::SequenceEditor *ui;

    public slots:
        void redrawPatchParameter(int id, int value);
        void redrawSequenceStep(int id, int active, int note, int tie, int velocity, int value);

    private slots:
        void activeChanged(int step, int value);
        void noteChanged(int step, int value);
        void valueChanged(int step, int value);
        void tieChanged(int step, int value);
        void velocityChanged(int step, int velocity);

        void comboBoxChanged(int value);
        void dialChanged(int id, int value);

    signals:
        void enqueue(QueueItem);
};

#endif // SEQUENCEEDITOR_H
