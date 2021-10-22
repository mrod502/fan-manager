SRC_FILES=`find . -iname "*.cpp"`

g++ -lwiringPi -o fanmgr $SRC_FILES