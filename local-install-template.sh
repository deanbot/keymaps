#!/bin/sh

# some folk don't have their keyboards in the master branch

# cannonball
mkdir -p $HOME/path/to/keymaps/qmk_firmware/keyboards/tarohayashi
test -L $HOME/path/to/keymaps/qmk_firmware/keyboards/tarohayashi/cannonball || ln -s $HOME/src/Taro-Hayashi/qmk_firmware/keyboards/tarohayashi/cannonball $HOME/path/to/keymaps/qmk_firmware/keyboards/tarohayashi/cannonball

# ffkb
mkdir -p $HOME/path/to/keymaps/qmk_firmware/keyboards/fingerpunch
test -L $HOME/path/to/keymaps/qmk_firmware/keyboards/fingerpunch/ffkb || ln -s $HOME/src/sadekbaroudi/qmk_firmware/keyboards/fingerpunch/ffkb $HOME/path/to/keymaps/qmk_firmware/keyboards/fingerpunch/ffkb

# oxymoron
mkdir -p $HOME/src/deanbot/keymaps/qmk_firmware/keyboards/rainkeebs
test -L $HOME/path/to/keymaps/qmk_firmware/keyboards/rainkeebs/oxymoron || ln -s $HOME/src/rainkeebs/oxymoron_source/oxymoron $HOME/path/to/keymaps/qmk_firmware/keyboards/rainkeebs/oxymoron
