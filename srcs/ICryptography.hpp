#pragma once
#include <iostream>

class   ICryptography {
    public:
        ICryptography (void){};
        virtual ~ICryptography (void){};
        virtual std::string encrypt(const std::string& data, const std::string& key) = 0;
        virtual std::string decrypt(const std::string& data, const std::string& key) = 0;
};

// LSB
// AES