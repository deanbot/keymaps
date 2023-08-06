#!/bin/sh
( 
    cd ~/src/qmk_firmware
    git pull
    git submodule foreach git pull origin master
)
