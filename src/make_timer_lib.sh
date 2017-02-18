#!bin/sh
if [ "$(id -u)" != "0" ]; then
echo "Please run with sudo !"
exit 1
fi

cmake -G "Unix Makefiles" CMakeLists.txt
make all

rm cmake_install.cmake
rm CMakeCache.txt
rm -R -f CMakeFiles

make clean
