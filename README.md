# Ubuntu

> Installing Dependencies

```
sudo apt install git zsh cmake mingw-w64
```

> Installing Magic_Recode

```
git clone https://github.com/qwertyuiop3/Magic_Recode.git --recursive

cd Magic_Recode

./Build.sh
```

# Arch Linux

> Installing Dependencies

```
su root

pacman -S git zsh cmake gcc mingw-w64-gcc make
```

> Installing Magic_Recode

```
git clone https://github.com/qwertyuiop3/Magic_Recode.git --recursive

cd Magic_Recode

./Build.sh
```

# Void Linux

> Installing Dependencies

```
su root

xbps-install -S git zsh cmake gcc cross-i686-w64-mingw32 make
```

> Installing Magic_Recode

```
git clone https://github.com/qwertyuiop3/Magic_Recode.git --recursive

cd Magic_Recode

./Build.sh
```

# Gentoo

> Installing Dependencies

```
su root

emerge dev-vcs/git app-shells/zsh dev-util/cmake sys-devel/binutils sys-devel/crossdev

crossdev --target i686-w64-mingw32
```

> Installing Magic_Recode

```
git clone https://github.com/qwertyuiop3/Magic_Recode.git --recursive

cd Magic_Recode

./Build.sh
```

# Windows

> Installing Dependencies

```
Git

CMake

MinGW-W64

Make
```

> Installing Magic_Recode

```
git clone https://github.com/qwertyuiop3/Magic_Recode.git --recursive

cd Magic_Recode

Build.bat
```
