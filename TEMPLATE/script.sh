#!/bin/zsh
if [ "$2" == "home" ]; then
    path="/Users/abarriel/piscine_cpp/cpp/O/"
else
    path="/Users/abarriel/piscine_cpp/remote/TEMPLATE/"
fi
rm -rf $path/to_move
mkdir $path/to_move
cp $path/{Contact.cpp,Contact.hpp,main.cpp,Makefile} $path/to_move
upper=$(echo "$1" | tr '[:lower:]' '[:upper:]')
echo "$path/to_move/Contact.cpp $path/to_move/Contact.hpp $path/to_move/main.cpp $path/to_move/Makefile" | xargs sed -i "" "s/Contact/$1/g"
echo "$path/to_move/Contact.cpp $path/to_move/Contact.hpp $path/to_move/main.cpp $path/to_move/Makefile" | xargs sed -i "" "s/CONTACT/$upper/g"
rename "s/Contact/$1/" $path/to_move/Contact.cpp $path/to_move/Contact.hpp
mv $path/to_move/* ./
# rm -rf $path/to_move