
rd /S /Q build
md build
cd build
cmake .. -G "MinGW Makefiles"

make

cd ..
