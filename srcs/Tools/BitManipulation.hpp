#ifndef BITMANIPULATION_HPP
#define BITMANIPULATION_HPP

class   BitManipulation {
    public:
        // Least Significant Bit
        static unsigned char setLSB(unsigned char byte, bool value) {
            return ((byte & 0xFE) | (value ? 1 : 0));
        }
        static bool getLSB(unsigned char byte)  {
            return (byte & 1);
        }
};

#endif