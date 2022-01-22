# Flash

Flash: `make <keyboard>`

Supported keyboards:

- [naked48](https://github.com/qmk/qmk_firmware/tree/master/keyboards/naked48)
- [ferris](https://github.com/qmk/qmk_firmware/tree/master/keyboards/naked48)

# Install

1. Install qmk & qmk cli: https://beta.docs.qmk.fm/tutorial/newbs_getting_started
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

# Keymap

TODO

# Mentions

- (Article) [Separate keymap repo for QMK](https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd)
- Keymap/features/userspace
  - [alterecco/machine](https://github.com/alterecco/machine/tree/main/qmk)
  - [callum-oakley/qmk_firmware](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum)
  - [keymaps/jurgen-kluft](https://github.com/jurgen-kluft/qmk_firmware/blob/jurgen/keyboards/kyria/keymaps/jurgen-kluft/)
  - [keymaps/Vermoot](https://github.com/Vermoot/qmk_keymaps/blob/master/kyria/keymaps/Vermoot/)

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
