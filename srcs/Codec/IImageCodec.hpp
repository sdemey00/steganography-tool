#ifndef IIMAGECODEC_HPP
#define IIMAGECODEC_HPP

#include <iostream>

class   IImageCodec {
    public:
        IImageCodec (void){};
        virtual ~IImageCodec (void){};

        virtual void        encode(const std::string& inputImage, const std::string& payload, const std::string& outputImage) = 0;
        virtual std::string decode(const std::string& imagePath) = 0;
};

#endif