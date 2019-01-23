cd ${1};
rm -fr build;
mkdir build;
cd build;
cmake ..;
make;
