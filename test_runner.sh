#!/bin/bash

make clean
make
./PasswordTest
gcov -rbc Password.cpp
cat Password.cpp.gcov