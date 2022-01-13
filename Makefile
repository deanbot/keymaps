.PHONY: ferris naked48

# qmk flash -kb ferris/0_2/bling -km deanbot -bl dfu
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

install:
	# init submodule
	git submodule update --init --recursive

unlink:
	rm ./qmk_firmware/users/deanbot
	rm ./qmk_firmware/keyboards/naked48/keymaps/deanbot
	rm ./qmk_firmware/keyboards/ferris/keymaps/deanbot

clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex
