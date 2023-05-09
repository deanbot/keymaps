# Flash

Flash: `make <keyboard>`

Supported keyboards:

- [naked48](https://github.com/qmk/qmk_firmware/tree/master/keyboards/naked48)
- [ferris](https://github.com/qmk/qmk_firmware/tree/master/keyboards/naked48)
- [ffkb](https://github.com/sadekbaroudi/qmk_firmware/tree/master/keyboards/fingerpunch/ffkb)
- [cannonball](https://github.com/Taro-Hayashi/qmk_firmware/tree/tarohayashi/keyboards/tarohayashi/cannonball)
- oxymoroon

# Install

1. Install qmk & qmk cli: https://qmk.github.io/qmk_mkdocs/master/en/tutorial_getting_started/
2. Initialize firmware submodule:
  ```sh
  cd /path/to/keymaps;
  git submodule update --init --recursive
  ```
3. Set qmk config
  ```sh
  qmk config user.qmk_home=~/path/to/keymaps/qmk_firmware
  ```
4. Verify with `qmk doctor`
5. clone [fingerpunch fork](https://github.com/sadekbaroudi/qmk_firmware) for ffkb and [Taro Hayashi fork](https://github.com/Taro-Hayashi/qmk_firmware) (ensure you check out taroyahashi branch) for cannonball.
6. Rename `local-install-template.sh` as `local-install.sh` and update paths.

# Keymap

TODO

# Mentions

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

# Development

## Update qmk firmware

```sh
git submodule foreach git pull origin master
```

## Unlink

Remove symlinks in qmk firmware:

```sh
make unlink
```
