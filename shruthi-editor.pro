# Shruthi-Editor: An unofficial Editor for the Shruthi hardware synthesizer. For 
# informations about the Shruthi, see <http:#www.mutable-instruments.net/shruthi1>. 
#
# Copyright (C) 2011-2015 Manuel Krönig
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.


#
# Source files
#


HEADERS = \
    RtMidi.h \
    lib_config.h \
    lib_editor.h \
    lib_fileio.h \
    lib_labels.h \
    lib_library.h \
    lib_midi.h \
    lib_midiin.h \
    lib_midiout.h \
    lib_patch.h \
    lib_sequence.h \
    lib_signalrouter.h \
    ui/keyboard_dialog.h \
    ui/keyboard_widget.h \
    ui/library_dialog.h \
    ui/sequence_editor.h \
    ui/sequence_step.h \
    ui/settings_dialog.h \
    ui/shruthi_editor.h \
    ui/shruthi_editor_dial.h

SOURCES = \
    RtMidi.cpp \
    main.cpp \
    lib_config.cpp \
    lib_editor.cpp \
    lib_fileio.cpp \
    lib_labels.cpp \
    lib_library.cpp \
    lib_midi.cpp \
    lib_midiin.cpp \
    lib_midiout.cpp \
    lib_patch.cpp \
    lib_sequence.cpp \
    lib_signalrouter.cpp \
    ui/keyboard_dialog.cpp \
    ui/keyboard_widget.cpp \
    ui/library_dialog.cpp \
    ui/sequence_editor.cpp \
    ui/sequence_step.cpp \
    ui/settings_dialog.cpp \
    ui/shruthi_editor.cpp \
    ui/shruthi_editor_dial.cpp

FORMS = \
    ui/keyboard_dialog.ui \
    ui/library_dialog.ui \
    ui/sequence_editor.ui \
    ui/sequence_step.ui \
    ui/settings_dialog.ui \
    ui/shruthi_editor.ui \
    ui/shruthi_editor_dial.ui

RESOURCES = \
    ui/shruthi_editor.qrc


#
# Settings
#


QT += widgets

CONFIG += qt

#DEFINES += DEBUGMSGS

# Uncomment the following line if you use a firmware version prior to 0.94
#DEFINES += PRE094SYSEXHEADER

LIBS += -L. 
target.path = release/

# Comment the following line if you don't want to force the Fusion style
DEFINES += FUSION

unix {
    message(RtMidi will use linux alsaseq.)
    # alsa:
    DEFINES += __LINUX_ALSA__
    LIBS += -lasound
    # jack:
    #DEFINES += __LINUX_JACK__
    #LIBS += -ljack
}

macx {
    message(RtMidi will use macosx core.)
    DEFINES += __MACOSX_CORE__
    LIBS += -framework CoreMidi -framework CoreAudio -framework CoreFoundation
    ICON = ui/shruthi_editor.icns
}

win32 {
    message(RtMidi will use windows mm.)
    DEFINES += __WINDOWS_MM__
    LIBS += -lwinmm
    RC_FILE = ui/shruthi_editor.rc
}


# install
INSTALLS += target
