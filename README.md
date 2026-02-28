Designed and implemented a secure steganography system in C++17 supporting encrypted payload embedding in PNG images, with randomized pixel distribution and integrity verification. Evaluated resistance against basic statistical steganalysis.

Features:
- Embed file into PNG
- Extract file from PNG
- Encrypt payload with password
- Randomize pixel positions using key
- Clean architecture

Week Plan
Day 1
- Learn how PNG stores pixels
- Load + save PNG
- Print pixel buffer info
Day 2
- Implement basic LSB embed (no encryption)
- Implement extract
Day 3
- Add file support (not just text)
- Add length header inside image
Day 4
- Add password → derive key
- Encrypt payload before embedding
Day 5
- Randomize pixel order using key-seeded PRNG
Day 6
- Error handling
- Capacity checks
- Clean CLI
Day 7
- Write README explaining:
    - Why encryption is needed
    - How LSB works
    - Limitations
    - Security considerations
