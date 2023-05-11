#!/bin/sh

KEYMAPS=$HOME/path/to/keymaps

# some folk don't have their keyboards in the master branch

# cannonball
mkdir -p $KEYMAPS/qmk_firmware/keyboards/tarohayashi
TARO_QMK=$HOME/src/Taro-Hayashi/qmk_firmware
test -L $KEYMAPS/qmk_firmware/keyboards/tarohayashi/cannonball || ln -s $TARO_QMK/keyboards/tarohayashi/cannonball $KEYMAPS/qmk_firmware/keyboards/tarohayashi/cannonball

# fp
mkdir -p $KEYMAPS/qmk_firmware/keyboards/fingerpunch
SADEK_QMK=$HOME/src/sadekbaroudi/qmk_firmware
test -L $KEYMAPS/qmk_firmware/keyboards/fingerpunch/src || ln -s $SADEK_QMK/keyboards/fingerpunch/src $KEYMAPS/qmk_firmware/keyboards/fingerpunch/src
test -L $KEYMAPS/qmk_firmware/keyboards/fingerpunch/ffkb || ln -s $SADEK_QMK/keyboards/fingerpunch/ffkb $KEYMAPS/qmk_firmware/keyboards/fingerpunch/ffkb
test -L $KEYMAPS/qmk_firmware/keyboards/fingerpunch/sweeeeep || ln -s $SADEK_QMK/keyboards/fingerpunch/sweeeeep $KEYMAPS/qmk_firmware/keyboards/fingerpunch/sweeeeep

# oxymoron
mkdir -p $HOME/src/deanbot/keymaps/qmk_firmware/keyboards/rainkeebs
test -L $KEYMAPS/qmk_firmware/keyboards/rainkeebs/oxymoron || ln -s $HOME/src/rainkeebs/oxymoron_source/oxymoron $KEYMAPS/qmk_firmware/keyboards/rainkeebs/oxymoron