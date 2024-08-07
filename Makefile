.PHONY: fflx

#qmk lint -kb haizeus0411/infernum -km deanbot --strict
infernum: setup

	cd ~/src/qmk_firmware;
	
	qmk flash -kb haizeus0411/infernum -km deanbot

#qmk lint -kb fingerpunch/sweeeeep/rgblight_oled -km deanbot --strict
sweeeeep: setup

	cd ~/src/qmk_firmware;

	qmk flash -kb fingerpunch/sweeeeep/rgblight_oled -km deanbot

# qmk lint -kb fingerpunch/ffkb/atmega/v1 -km deanbot --strict;
# RGBLIGHT_ENABLE=yes RGB_MATRIX_ENABLE=yes
ffkb: setup

	cd ~/src/qmk_firmware;

	make fingerpunch/ffkb/atmega/v1:deanbot PIMORONI_TRACKBALL_ENABLE=no OLED_ENABLE=no FP_EC11_CENTER=yes FP_EVQ_UNDER_PALMS=yes RGBLIGHT_ENABLE=yes

# cd ~/src/qmk_firmware;e
fflx: 

	cd ~/src/sadekbaroudi/qmk_firmware

	make fingerpunch/fflx:deanbot CIRQUE_ENABLE=yes RGBLIGHT_ENABLE=no FP_EC11_UNDER_PALMS=no FP_EVQ_UNDER_PALMS=yes CONVERT_TO=stemcell

draculad: setup

	cd ~/src/qmk_firmware;

	qmk lint -kb draculad -km deanbot --strict

	qmk flash -kb draculad -km deanbot

lesovoz: setup

	cd ~/src/qmk_firmware;

	qmk flash -kb tsquash/lesovoz -km deanbot

cannonball: setup

	cd ~/src/qmk_firmware; 
	
	qmk lint -kb tarohayashi/cannonball -km deanbot --strict

	qmk flash -kb tarohayashi/cannonball -km deanbot

cannonball-solo: setup

	cd ~/src/qmk_firmware; qmk lint -kb tarohayashi/cannonball -km solo --strict

	qmk flash -kb tarohayashi/cannonball -km solo

# rex60: setup
	
# 	cd ~/src/qmk_firmware;

# qmk lint -kb rainkeebs/oxymoron -km deanbot --strict
oxymoron: setup

	cd ~/src/qmk_firmware;

	qmk flash -kb rainkeebs/oxymoron -km deanbot

# qmk lint -kb ferris/0_2/bling -km deanbot --strict
ferris: setup

	cd ~/src/qmk_firmware; 

	qmk flash -kb ferris/0_2/bling -km deanbot

# qmk flash -kb naked48 -km deanbot -bl dfu
naked48: setupDSKDSLkfl;s;SDFKsdkfl;a;D]fs'l;fksfs]fs]]]s[s[[s[[s]]]]]

	cd ~/src/qmk_firmware; qmk lint -kb naked48 -km deanbot --strict

	qmk flash -kb naked48 -km deanbot

# qmk lint -kb dz60 -km deanbot --strict
dz60: setup

	cd ~/src/qmk_firmware; 

	qmk flash -kb dz60 -km deanbot

reviung41: setup

	cd ~/src/qmk_firmware; qmk lint -kb reviung/reviung41 -km deanbot --strict

	qmk flash -kb reviung/reviung41 -km deanbot

setup: install
	test -L ~/src/qmk_firmware/users/deanbot || ln -s $(shell pwd)/user ~/src/qmk_firmware/users/deanbot

	test -L ~/src/qmk_firmware/keyboards/draculad/keymaps/deanbot || ln -s $(shell pwd)/draculad ~/src/qmk_firmware/keyboards/draculad/keymaps/deanbot
	test -L ~/src/qmk_firmware/keyboards/reviung/reviung41/keymaps/deanbot || ln -s $(shell pwd)/reviung41 ~/src/qmk_firmware/keyboards/reviung/reviung41/keymaps/deanbot
	test -L ~/src/qmk_firmware/keyboards/salicylic_acid3/naked48/keymaps/deanbot || ln -s $(shell pwd)/naked48 ~/src/qmk_firmware/keyboards/salicylic_acid3/naked48/keymaps/deanbot
	test -L ~/src/qmk_firmware/keyboards/ferris/keymaps/deanbot || ln -s $(shell pwd)/ferris ~/src/qmk_firmware/keyboards/ferris/keymaps/deanbot

	test -L ~/src/qmk_firmware/keyboards/tarohayashi/cannonball/keymaps/deanbot || ln -s $(shell pwd)/cannonball ~/src/qmk_firmware/keyboards/tarohayashi/cannonball/keymaps/deanbot
	test -L ~/src/qmk_firmware/keyboards/tarohayashi/cannonball/keymaps/solo || ln -s $(shell pwd)/cannonball-solo ~/src/qmk_firmware/keyboards/tarohayashi/cannonball/keymaps/solo

	test -L ~/src/qmk_firmware/keyboards/tsquash/lesovoz/keymaps/deanbot || ln -s $(shell pwd)/lesovoz ~/src/qmk_firmware/keyboards/tsquash/lesovoz/keymaps/deanbot
	
	test -L ~/src/qmk_firmware/keyboards/haizeus0411/infernum/keymaps/deanbot || ln -s $(shell pwd)/infernum ~/src/qmk_firmware/keyboards/haizeus0411/infernum/keymaps/deanbot
	
	test -L ~/src/qmk_firmware/keyboards/fingerpunch/ffkb/atmega/v1/keymaps/deanbot || ln -s $(shell pwd)/ffkb ~/src/qmk_firmware/keyboards/fingerpunch/ffkb/atmega/v1/keymaps/deanbot
	test -L ~/src/qmk_firmware/keyboards/fingerpunch/fflx/keymaps/deanbot || ln -s $(shell pwd)/fflx ~/src/qmk_firmware/keyboards/fingerpunch/fflx/keymaps/deanbot
	test -L ~/src/qmk_firmware/keyboards/fingerpunch/sweeeeep/keymaps/deanbot || ln -s $(shell pwd)/sweeeeep ~/src/qmk_firmware/keyboards/fingerpunch/sweeeeep/keymaps/deanbot
	
	test -L ~/src/qmk_firmware/keyboards/rainkeebs/oxymoron/keymaps/deanbot || ln -s $(shell pwd)/oxymoron ~/src/qmk_firmware/keyboards/rainkeebs/oxymoron/keymaps/deanbot

	test -L ~/src/qmk_firmware/keyboards/dz60/keymaps/deanbot || ln -s $(shell pwd)/dz60 ~/src/qmk_firmware/keyboards/dz60/keymaps/deanbot

install:
	# init submodule
	# git submodule update --init --recursive
	./local-install.sh

installSadek:
	./local-install-sadek.sh

unlink:
	rm -rf ~/src/qmk_firmware/keyboards/tarohayashi/
	rm -rf ~/src/qmk_firmware/keyboards/fingerpunch/
	rm -rf ~/src/qmk_firmware/keyboards/rainkeebs/oxymoron
	rm -rf ~/src/qmk_firmware/keyboards/haizeus0411
	rm -rf ~/src/qmk_firmware/keyboards/tsquash
	rm ~/src/qmk_firmware/keyboards/draculad/keymaps/deanbot
	rm ~/src/qmk_firmware/keyboards/reviung/reviung41/keymaps/deanbot
	rm ~/src/qmk_firmware/keyboards/ferris/keymaps/deanbot
	rm ~/src/qmk_firmware/keyboards/salicylic_acid3/naked48/keymaps/deanbot
	rm ~/src/qmk_firmware/users/deanbot

clean:
	rm -rf ~/src/qmk_firmware/obj_*
	rm -f ~/src/qmk_firmware/*.elf
	rm -f ~/src/qmk_firmware/*.map
	rm -f ~/src/qmk_firmware/*.hex
