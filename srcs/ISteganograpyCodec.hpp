#pragma once
#include <iostream>

class   ISteganographyCodec {
    public:
        ISteganographyCodec (void){};
        ~ISteganographyCodec (void){};
        virtual void        encode(const std::string& inputImage, const std::string& message, const std::string& outputImage) = 0;
        virtual std::string decode(const std::string& imagePath) = 0;
};
