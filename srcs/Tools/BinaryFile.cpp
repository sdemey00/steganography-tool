#include "BinaryFile.hpp"

BinaryFile::BinaryFile(const std::string& path) {
    std::ifstream file(path.c_str(), std::ios::binary);
    if (!file)
        throw std::exception();

    char    byte;
    while (file.get(byte))
        _buffer.push_back(static_cast<unsigned char>(byte));
}

std::vector<unsigned char>&         BinaryFile::buffer() { return (_buffer); }
const std::vector<unsigned char>&   BinaryFile::buffer() const { return (_buffer); }

void BinaryFile::save(const std::string& path) {
    std::ofstream file(path.c_str(), std::ios::binary);
    if (!file)
        throw std::exception();

    file.write(reinterpret_cast<const char*>(&_buffer[0]), _buffer.size());
}