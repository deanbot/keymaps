.PHONY: ffkb

ffkb: setup

	cd qmk_firmware; qmk lint -kb fingerpunch/ffkb/pimoroni_evq -km deanbot --strict;

	qmk flash -kb fingerpunch/ffkb/pimoroni_evq -km deanbot

cannonball: setup

	cd qmk_firmware; qmk lint -kb tarohayashi/cannonball -km deanbot --strict

	qmk flash -kb tarohayashi/cannonball -km deanbot

cannonball-solo: setup

	cd qmk_firmware; qmk lint -kb tarohayashi/cannonball -km solo --strict

	qmk flash -kb tarohayashi/cannonball -km solo

ferris: setup

	cd qmk_firmware; qmk lint -kb ferris/0_2/bling -km deanbot --strict

	qmk flash -kb ferris/0_2/bling -km deanbot

# qmk flash -kb naked48 -km deanbot -bl dfu
naked48: setup

	cd qmk_firmware; qmk lint -kb naked48 -km deanbot --strict

	qmk flash -kb naked48 -km deanbot

setup: install
	test -L ./qmk_firmware/users/deanbot || ln -s $(shell pwd)/user ./qmk_firmware/users/deanbot
	test -L ./qmk_firmware/keyboards/naked48/keymaps/deanbot || ln -s $(shell pwd)/naked48 ./qmk_firmware/keyboards/naked48/keymaps/deanbot
	test -L ./qmk_firmware/keyboards/ferris/keymaps/deanbot || ln -s $(shell pwd)/ferris ./qmk_firmware/keyboards/ferris/keymaps/deanbot
	test -L ./qmk_firmware/keyboards/fingerpunch/ffkb/keymaps/deanbot || ln -s $(shell pwd)/ffkb ./qmk_firmware/keyboards/fingerpunch/ffkb/keymaps/deanbot
	test -L ./qmk_firmware/keyboards/tarohayashi/cannonball/keymaps/deanbot || ln -s $(shell pwd)/cannonball ./qmk_firmware/keyboards/tarohayashi/cannonball/keymaps/deanbot
	test -L ./qmk_firmware/keyboards/tarohayashi/cannonball/keymaps/solo || ln -s $(shell pwd)/cannonball-solo ./qmk_firmware/keyboards/tarohayashi/cannonball/keymaps/solo

install:
	# init submodule
	git submodule update --init --recursive
	./local-install.sh

unlink:
	rm ./qmk_firmware/users/deanbot
	rm ./qmk_firmware/keyboards/naked48/keymaps/deanbot
	rm ./qmk_firmware/keyboards/ferris/keymaps/deanbot
	rm -rf ./qmk_firmware/keyboards/tarohayashi/
	rm -rf ./qmk_firmware/keyboards/fingerpunch/

clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex
