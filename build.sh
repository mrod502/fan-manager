SRC_FILES=$(find . -iname "*.cpp")
WIRINGPI_FILES = $(find ./WiringPi -iname "*.c")

g++ --std=c++17 -o fanmgr $SRC_FILES $WIRINGPI_FILES
