#include <iostream>
#include <fstream>
#include <cassert>

int memory_size = 0x10000; // 
uint8_t* memory = new uint8_t[memory_size];

void load_sector(std::fstream file, unsigned long baseSector, unsigned long sectorCount, unsigned long loadAddress)
{
    if (!file.is_open())
    {
        std::cout << "load_sector(): File isn't open.\n";

        return;
    }

    file.seekg(baseSector * 512);
    file.read((char*)memory[loadAddress], sectorCount * 512);
}

int main(int argc, char** argv)
{
    std::fstream file("test.txt", std::ios::binary);

    delete[] memory;
    return 0;
}