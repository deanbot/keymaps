# Flash

Flash a keyboard which has a same-named keymap folder and config added to Makefile.

```sh
make naked48
```

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

# Development

## Update firmware

TODO
