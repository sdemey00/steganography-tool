#include <stdio.h>
#include <string.h>

#define BUF_SIZE 8

int		main(int ac, char **av) {
	if (ac != 2) {
		fprintf(stderr, "Usage: ./stegano <filename>\n");
		return (1);
	}
	unsigned char	buf[BUF_SIZE];
	FILE *file = fopen(av[1], "rb");
	if (!file) {
		fprintf(stderr, "Cannot open file.\n");
		return (1);
	}
	unsigned char signature[8];
	fread(signature, 1, 8, file);
	if (memcmp(signature, "\x89PNG\r\n\x1a\n", 8) != 0) {
		fprintf(stderr, "Not a PNG file\n");
		return (1);
	}
	size_t	bytes_read = 0;
	while ((bytes_read = fread(buf, 1, BUF_SIZE, file)) > 0) {
		for (size_t i = 0; i < bytes_read; i++)
			printf("%02X ", buf[i]);
	}
	printf("\n");
	fclose(file);
	return (0);
}


// void		hideByte(unsigned char* img, int startIndex, unsigned char data) {
//     for (int i = 0; i < 8; i++) {
//         img[startIndex + i] =
//             (img[startIndex + i] & 0xFE) | ((data >> i) & 1);
//     }
// }
