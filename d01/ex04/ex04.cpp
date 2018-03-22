#include <iostream>

int main(void) {
 std::string str = "HI THIS IS BRAIN";

 std::string *ptr = &str;
 std::string &ref = str;

 std::cout << "string: " << str << std::endl;   
 std::cout << "ptr: " << str << std::endl;   
 std::cout << "ref: " << str << std::endl;   

 return (0);
}