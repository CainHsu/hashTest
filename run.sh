cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j8
echo "----------------------------------------------------------------------------------------"
./test
cd ..