#ifndef BMPCODEC_HPP
#define BMPCODEC_HPP

#include <vector>

#include "IImageCodec.hpp"

class BMPCodec : public IImageCodec {
    private:
        static const size_t HEADER_SIZE = 54;
        static const int    BITS_PER_BYTE = 8; 
        static const int    CHANNELS = 3;

        void            encodeMessageLength();
        unsigned int    decodeMessageLength();

    public:
        void        encode(const std::string& inputImage, const std::string& payload, const std::string& outputImage);
        std::string decode(const std::string& imagePath);
};

#endif