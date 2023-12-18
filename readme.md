# Flash

Link keyboards & userspace in separate qmk_firmware repo

## Flash supported keyboards

Enter `make <keyboard>`

Supported keyboards:

- [naked48](https://github.com/qmk/qmk_firmware/tree/master/keyboards/naked48)
- [ferris](https://github.com/qmk/qmk_firmware/tree/master/keyboards/ferris)
- [ffkb](https://github.com/sadekbaroudi/qmk_firmware/tree/master/keyboards/fingerpunch/ffkb)
- [sweeeeep](https://github.com/sadekbaroudi/qmk_firmware/tree/master/keyboards/fingerpunch/sweeeeep)
- [lesovoz](https://github.com/Tsquash/vial-qmk/tree/lesovoz/keyboards/lesovoz)
- [draculad](https://github.com/qmk/qmk_firmware/tree/master/keyboards/draculad)
- [reviung41](https://github.com/qmk/qmk_firmware/tree/master/keyboards/reviung/reviung41)
- [cannonball](https://github.com/Taro-Hayashi/qmk_firmware/tree/tarohayashi/keyboards/tarohayashi/cannonball)
- oxymoron

To support:
- [fflx](https://github.com/sadekbaroudi/qmk_firmware/tree/master/keyboards/fingerpunch/fflx)
- [rex60]

### Fingerpunch

Link keyboards & userspace in sadek's qmk_firmware.

Install: `./local-install-sadek.sh`
Uninstall: `./local-uninstall.sadek.sh`

- Run `git submodule update --init --recursive` sadek's qmk_firmware.
- Use `develop_fingerpunch` branch (fflx cirque required this)

Enter make commands in sadek's qmk_firmware:

- ffkb: `make fingerpunch/ffkb/atmega/v1:deanbot PIMORONI_TRACKBALL_ENABLE=no OLED_ENABLE=no FP_EC11_CENTER=yes FP_EVQ_UNDER_PALMS=yes RGBLIGHT_ENABLE=yes`
- fflx: `make fingerpunch/fflx:deanbot CIRQUE_ENABLE=yes RGBLIGHT_ENABLE=no FP_EC11_UNDER_PALMS=no FP_EVQ_UNDER_PALMS=yes CONVERT_TO=stemcell`
-- double tap reset to enter bootloader mode, drag `fingerpunch_fflx_deanbot_stemcell.uf2` to stemcell usb device

## Update qmk firmware

```sh
./update.sh
```

## Unlink

Remove symlinks in qmk firmware:

```sh
make unlink
```

# Install

1. Install qmk & qmk cli: https://qmk.github.io/qmk_mkdocs/master/en/tutorial_getting_started/
2. Clone qmk_firmware somewhere (i.e. `~/src/qmk_firmware`).
3. Set qmk config
  ```sh
  qmk config user.qmk_home=~/path/to/keymaps/qmk_firmware
  ```
4. Verify with `qmk doctor`
5. Clone out of tree sources 
  - [fingerpunch](https://github.com/sadekbaroudi/qmk_firmware) and checkout `develop_fingerpunch` branch
  - [oxymoron](https://github.com/deanbot/oxymoron)
  - [cannonball](https://github.com/Taro-Hayashi/qmk_firmware) and checkout `tarohayashi` branch
  - [lesovoz](https://github.com/deanbot/lesovoz)
6. Rename `local-install-template.sh` as `local-install.sh` and update paths.

# Reference

- (Article) [Separate keymap repo for QMK](https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd)
- Keymap/features/userspace
  - [alterecco/machine](https://github.com/alterecco/machine/tree/main/qmk)
  - [callum-oakley/qmk_firmware](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum)
  - [jurgen-kluft/qmk_keymaps](https://github.com/jurgen-kluft/qmk-keyboards/tree/master/kyria/keymaps/jurgen-kluft)
  - [Vermoot/qmk_keymaps](https://github.com/Vermoot/qmk_keymaps/blob/master/kyria/keymaps/Vermoot/)
  - [keyboards/ferris](https://github.com/qmk/qmk_firmware/tree/master/keyboards/ferris/keymaps/default)
  - [manna-harbour/miryoku_qmk](https://github.com/manna-harbour/miryoku_qmk/tree/miryoku/users/manna-harbour_miryoku)
- Keymap Visualization
  - [BrokenFlows/keymap](https://github.com/BrokenFlows/keymap)