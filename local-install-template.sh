#!/bin/sh

KEYMAPS=$HOME/path/to/keymaps

# some folk don't have their keyboards in the master branch

# cannonball
mkdir -p $KEYMAPS/qmk_firmware/keyboards/tarohayashi
test -L $KEYMAPS/qmk_firmware/keyboards/tarohayashi/cannonball || ln -s $HOME/src/Taro-Hayashi/qmk_firmware/keyboards/tarohayashi/cannonball $KEYMAPS/qmk_firmware/keyboards/tarohayashi/cannonball

# ffkb
mkdir -p $KEYMAPS/qmk_firmware/keyboards/fingerpunch
test -L $KEYMAPS/qmk_firmware/keyboards/fingerpunch/ffkb || ln -s $HOME/src/sadekbaroudi/qmk_firmware/keyboards/fingerpunch/ffkb $KEYMAPS/qmk_firmware/keyboards/fingerpunch/ffkb

# oxymoron
mkdir -p $HOME/src/deanbot/keymaps/qmk_firmware/keyboards/rainkeebs
test -L $KEYMAPS/qmk_firmware/keyboards/rainkeebs/oxymoron || ln -s $HOME/src/rainkeebs/oxymoron_source/oxymoron $KEYMAPS/qmk_firmware/keyboards/rainkeebs/oxymoron
