#include <iostream>
#include<fstream>

int main(){
    std::string a="hola";
    std::fstream arc("hello.bin",std::ios::binary | std::ios::app);
    arc.write((char*)&a,sizeof(std::string));

    return 0;
}