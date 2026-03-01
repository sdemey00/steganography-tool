#pragma once

class   CodecCreate {
    public:
        // static ISteganographyCodec* createBMP();
        // static ISteganographyCodec* createPNG();
};

// Bad:
// Codec* c = new BMPCodec();
// Better:
// Codec* c = CodecCreate::createBMP();