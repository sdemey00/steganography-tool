#ifndef BINARYFILE_HPP
#define BINARYFILE_HPP

#include <vector>
#include <string>
#include <fstream>
#include <exception>

class BinaryFile {
    private:
        std::vector<unsigned char>  _buffer;

    public:
        BinaryFile(const std::string& path);

        std::vector<unsigned char>&         buffer();
        const std::vector<unsigned char>&   buffer() const;

        void save(const std::string& path);
};

#endif