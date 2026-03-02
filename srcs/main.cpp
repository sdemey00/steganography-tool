#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// BMP file format
const int HEADER_SIZE = 54; 
const int BITS_PER_BYTE = 8; 
const int CHANNELS = 3;      

void encode(const std::string& inPath, const std::string& message, const std::string& outPath) {
    std::ifstream   input(inPath, std::ios::binary);
    std::ofstream   output(outPath, std::ios::binary);
    if (!input || !output) {
        std::cerr << "Error: Cannot open files." << std::endl;
        return ;
    }
    std::vector<char> header(HEADER_SIZE);
    input.read(header.data(), HEADER_SIZE);
    output.write(header.data(), HEADER_SIZE);
    size_t  len = message.length();
    for (int i = 0; i < 32; i++) {
        char pixel[CHANNELS];
        input.read(pixel, CHANNELS);
        pixel[0] = (pixel[0] & 0xFE) | ((len >> i) & 1);
        output.write(pixel, CHANNELS);
    }
    size_t  pos = 0;
    int     bit = 0;
    while (pos < len) {
        char pixel[CHANNELS];
        input.read(pixel, CHANNELS);
        pixel[0] = (pixel[0] & 0xFE) | ((message[pos] >> bit) & 1);
        bit++;
        if (bit == BITS_PER_BYTE) {
            bit = 0;
            pos++;
        }
        output.write(pixel, CHANNELS);
    }
    char    buffer[CHANNELS];
    while (input.read(buffer, CHANNELS)) {
        output.write(buffer, CHANNELS);
    }
}

std::string decode(const std::string& path) {
    std::ifstream   input(path, std::ios::binary);
    if (!input) {
        std::cerr << "Error: Cannot open file." << std::endl;
        exit(1);
    }
    input.seekg(HEADER_SIZE); // Skip the header
    size_t  len = 0;
    for (int i = 0; i < 32; i++) {
        char pixel[CHANNELS];
        input.read(pixel, CHANNELS);
        len |= ((pixel[0] & 1) << i);
    }
    std::string message;
    message.reserve(len);
    size_t  pos = 0;
    char    byte = 0;
    int     bit = 0;
    while (pos < len) {
        char pixel[CHANNELS];
        input.read(pixel, CHANNELS);
        byte |= ((pixel[0] & 1) << bit);
        bit++;
        if (bit == BITS_PER_BYTE) {
            message.push_back(byte);
            byte = 0;
            bit = 0;
            pos++;
        }
    }
    return (message);
}

std::string crypt(const std::string& input, const std::string& key) {
    std::string output = input;
    size_t      keyLen = key.length();
    for (size_t i = 0; i < input.length(); i++) {
        output[i] ^= key[i % keyLen];
    }
    return (output);
}

int main(void) {
    std::cout << "Welcome to BMP Steganography Tool!" << std::endl;
    std::cout << "1. Encode a message\n2. Decode a message\nChoose an option: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1) {
        std::string inPath, message, outPath, key;
        std::cout << "Input path: ";
        std::getline(std::cin, inPath);
        std::cout << "Message: ";
        std::getline(std::cin, message);
        std::cout << "Key: ";
        std::getline(std::cin, key);
        std::cout << "Output path: ";
        std::getline(std::cin, outPath);
        std::string encryptedMessage = crypt(message, key);
        encode(inPath, encryptedMessage, outPath);
        std::cout << "Message encoded successfully!" << std::endl;
    } else if (choice == 2) {
        std::string path, key;
        std::cout << "BMP path: ";
        std::getline(std::cin, path);
        std::cout << "key: ";
        std::getline(std::cin, key);
        std::string encryptedMessage = decode(path);
        std::string decryptedMessage = crypt(encryptedMessage, key);
        std::cout << "Decoded Message: " << decryptedMessage << std::endl;
    }
    return (0);
}
