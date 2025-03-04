# SUMMARY
Kwin plugin for switching languages ​​using Alt-Shift (Wayland).

This is Wayland-only plugin. For X11 use: https://github.com/Azq2/alt-shift-kbd-layout-switcher

# INSTALL
```
yay -S kwin-alt-shift-plugin-git
```

# BUILD
```sh
cmake -B build -DCMAKE_INSTALL_PREFIX=/usr
cmake --build build
cmake --install build
```

# LINKS
KDE bug: https://bugs.kde.org/show_bug.cgi?id=484439

# CREDITS

Big thanks [@zvova7890](https://github.com/zvova7890) for example with KWin InputEventSpy.
