#pragma once

#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>

#pragma pack(push, 1)
struct BMPHeader {
	uint16_t file_type{0x4D42};          // File type always BM which is 0x4D42
	uint32_t file_size{0};               // Size of the file (in bytes)
	uint16_t reserved1{0};               // Reserved, always 0
	uint16_t reserved2{0};               // Reserved, always 0
	uint32_t offset_data{0};             // Start position of pixel data (bytes from the beginning of the file)
};

struct BMPInfoHeader {
	uint32_t size{0};                    // Size of this header (in bytes)
	int32_t width{0};                    // width of bitmap in pixels
	int32_t height{0};                   // width of bitmap in pixels
										 // (if positive, bottom-up, with origin in lower left corner)
										 // (if negative, top-down, with origin in upper left corner)
	uint16_t planes{1};                  // No. of planes for the target device, this is always 1
	uint16_t bit_count{0};               // No. of bits per pixel
	uint32_t compression{0};             // 0 or 3 - uncompressed. THIS PROGRAM CONSIDERS ONLY UNCOMPRESSED BMP images
	uint32_t size_image{0};              // 0 - for uncompressed images
	int32_t x_pixels_per_meter{0};
	int32_t y_pixels_per_meter{0};
	uint32_t colors_used{0};             // No. color indexes in the color table. Use 0 for the max number of colors allowed by bit_count
	uint32_t colors_important{0};        // No. of colors used for displaying the bitmap. If 0 all colors are required
};
#pragma pack(pop)

struct BMPColorHeader {
	uint32_t red_mask{0x00ff0000};         // Bit mask for the red channel
	uint32_t green_mask{0x0000ff00};       // Bit mask for the green channel
	uint32_t blue_mask{0x000000ff};        // Bit mask for the blue channel
	uint32_t alpha_mask{0xff000000};       // Bit mask for the alpha channel
	uint32_t color_space_type{0x73524742}; // Default "sRGB" (0x73524742)
	uint32_t unused[16]{0};                // Unused data for sRGB color space
};

class BMP {
public:
	BMP(int width, int height, bool has_alpha = false);
	BMP(const char *fname);
	void read(const char *fname);
	void write(const char *fname);

	void set_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);
	void set_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	void get_pixel(int x, int y, uint8_t &r, uint8_t &g, uint8_t &b) const;
	void get_pixel(int x, int y, uint8_t &r, uint8_t &g, uint8_t &b, uint8_t &a) const;

	int get_width() const;
	int get_height() const;

private:
	uint32_t row_stride{0};
	BMPHeader file_header;
	BMPInfoHeader bmp_info_header;
	BMPColorHeader bmp_color_header;
	std::vector<uint8_t> data;

	void write_headers(std::ofstream &of);
	void write_headers_and_data(std::ofstream &of);
	uint32_t make_stride_aligned(uint32_t align_stride);
};
