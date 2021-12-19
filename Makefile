.PHONY: naked48
naked48: setup

	# run lint check
	cd qmk_firmware; qmk lint -kb naked48 -km deanbot --strict

	# run build
	# make BUILD_DIR=$(shell pwd) -j1 -C qmk_firmware naked48:deanbot:dfu
	qmk flash -kb naked48 -km deanbot -bl dfu

setup: install
	test -L ./qmk_firmware/users/deanbot || ln -s $(shell pwd)/user ./qmk_firmware/users/deanbot
	test -L ./qmk_firmware/keyboards/naked48/keymaps/deanbot || ln -s $(shell pwd)/naked48 ./qmk_firmware/keyboards/naked48/keymaps/deanbot

install:
	# init submodule
	git submodule update --init --recursive

unlink:
	rm ./qmk_firmware/users/deanbot
	rm ./qmk_firmware/keyboards/naked48/keymaps/deanbot

clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex
