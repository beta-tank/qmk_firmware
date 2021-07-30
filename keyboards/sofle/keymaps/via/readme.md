# VIA keymap for Sofle

Layout in [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/#/gists/76efb423a46cbbea75465cb468eef7ff) and [adjust layer](http://www.keyboard-layout-editor.com/#/gists/4bcf66f922cfd54da20ba04905d56bd4)


Features:

- Symmetric modifiers (CMD/Super, Alt/Opt, Ctrl, Shift)
- Modes for Qwerty and Colemak support
- The OLED on master half shows selected mode and caps lock state and is rotated.
- Left encoder controls volume up/down/mute. Right encoder PGUP/PGDOWN.
- Via support
- RGB underglow support

# Develop

## Build

```
qmk compile -kb sofle/rev1 -km via
```

## Configure main QMK upstream

Add

```
git remote add upstream https://github.com/qmk/qmk_firmware.git
```

Check

```
$ git remote -v
origin  https://github.com/<your_username>/qmk_firmware.git (fetch)
origin  https://github.com/<your_username>/qmk_firmware.git (push)
upstream        https://github.com/qmk/qmk_firmware.git (fetch)
upstream        https://github.com/qmk/qmk_firmware.git (push)
```

Update

```
git checkout master
git fetch upstream
git pull upstream master
git push origin master
```

Create new branch

```
git checkout -b dev_branch
git push -u origin dev_branch
```


