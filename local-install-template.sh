#!/bin/sh

# add cannonball keyboard to submodule
mkdir -p $HOME/path/to/keymaps/qmk_firmware/keyboards/tarohayashi
test -L $HOME/path/to/keymaps/qmk_firmware/keyboards/tarohayashi/cannonball || ln -s $HOME/src/Taro-Hayashi/qmk_firmware/keyboards/tarohayashi/cannonball $HOME/path/to/keymaps/qmk_firmware/keyboards/tarohayashi/cannonball

# add ffkb keyboard to submodule
mkdir -p $HOME/path/to/keymaps/qmk_firmware/keyboards/fingerpunch
test -L $HOME/path/to/keymaps/qmk_firmware/keyboards/fingerpunch/ffkb || ln -s $HOME/src/sadekbaroudi/qmk_firmware/keyboards/fingerpunch/ffkb $HOME/path/to/keymaps/qmk_firmware/keyboards/fingerpunch/ffkb
