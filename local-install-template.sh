#!/bin/sh
# 
# Some folk don't have their keyboards in the master branch

KEYMAPS=$HOME/path/to/keymaps
QMK=$HOME/src/qmk_firmware

# TaroHayashi
#
# copy cannonball from taro qmk to deanbot qmk
mkdir -p $QMK/keyboards/tarohayashi
TARO_QMK=$HOME/src/Taro-Hayashi/qmk_firmware
test -L $QMK/keyboards/tarohayashi/cannonball || ln -s $TARO_QMK/keyboards/tarohayashi/cannonball $QMK/keyboards/tarohayashi/cannonball

# tsquash
#
# copy lesovoz from tsquash vial-qmk to deanbot qmk
mkdir -p $QMK/keyboards/tsquash
TSQUASH_QMK=$HOME/src/Tsquash/vial-qmk
test -L $QMK/keyboards/tsquash/lesovoz || ln -s $TSQUASH_QMK/keyboards/lesovoz $QMK/keyboards/tsquash/lesovoz

# fingerpunch
# 
# copy fingerpunch boards from sadek qmk to deanbot qmk
mkdir -p $QMK/keyboards/fingerpunch
SADEK_QMK=$HOME/src/sadekbaroudi/qmk_firmware
test -L $QMK/keyboards/fingerpunch/src || ln -s $SADEK_QMK/keyboards/fingerpunch/src $QMK/keyboards/fingerpunch/src
test -L $QMK/keyboards/fingerpunch/ffkb || ln -s $SADEK_QMK/keyboards/fingerpunch/ffkb $QMK/keyboards/fingerpunch/ffkb
test -L $QMK/keyboards/fingerpunch/sweeeeep || ln -s $SADEK_QMK/keyboards/fingerpunch/sweeeeep $QMK/keyboards/fingerpunch/sweeeeep

# rainkeebs
# 
# copy oxymoron source (one off repo) to deanbot qmk
mkdir -p $QMK/keyboards/rainkeebs
test -L $QMK/keyboards/rainkeebs/oxymoron || ln -s $HOME/path/to/oxymoron $QMK/keyboards/rainkeebs/oxymoron