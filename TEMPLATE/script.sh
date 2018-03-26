#!/bin/sh
if [ "$2" == "home" ]; then
    path="/Users/abarriel/piscine_cpp/cpp/O/"
else
    path="/Users/abarriel/piscine_cpp/cpp/TEMPLATE/"
fi
mkdir $path/to_move
cp $path/{ClassContact.cpp,ClassContact.hpp,main.cpp,Makefile}  $path/to_move

echo "$path/to_move/ClassContact.cpp $path/to_move/ClassContact.hpp $path/to_move/main.cpp $path/to_move/Makefile" | xargs sed -i "" "s/Contact/$1/g"
rename "s/Contact/$1/" $path/to_move/ClassContact.cpp $path/to_move/ClassContact.hpp
mv $path/to_move/* ./
rm -rf $path/to_move