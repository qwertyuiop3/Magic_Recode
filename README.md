# Fedora Linux

> Installing Dependencies

```
sudo dnf install git cmake g++ mingw32-gcc-c++ mingw32-winpthreads-static
```

> Installing Magic_Recode

```
git clone https://github.com/qwertyuiop3/Magic_Recode.git --recursive

cd Magic_Recode

./Build.sh
```

# Ubuntu

> Installing Dependencies

```
sudo apt install git cmake g++ mingw-w64
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

pacman -S git cmake gcc mingw-w64-gcc make
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

xbps-install -S git cmake make gcc cross-i686-w64-mingw32
```

> Installing Magic_Recode

```
git clone https://github.com/qwertyuiop3/Magic_Recode.git --recursive

cd Magic_Recode

./Build.sh
```

# Gentoo Linux

> Installing Dependencies

```
su root

emerge dev-vcs/git dev-util/cmake sys-devel/binutils sys-devel/crossdev

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
