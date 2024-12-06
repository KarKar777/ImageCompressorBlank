#pragma once

#include <fstream>
#include <map>
#include <vector>
#include <string>

#include "colors.h"
#include "images.h"
#include "cassert"

uint8_t findClosestColorId(const ColorRGB& color, const std::map<uint8_t, ColorRGB>& colorTable);

void saveAsBMP(const UncompressedImage& img, const std::string& filename);
UncompressedImage loadFromBMP(const std::string& filename);

UncompressedImage readUncompressedFile(const std::string& filename);
void writeUncompressedFile(const std::string& filename, const UncompressedImage& file);

CompressedImage toCompressed(
    const UncompressedImage& img, const std::map<uint8_t, ColorRGB>& color_table = {},
    bool approximate = false, bool allow_color_add = true);
UncompressedImage toUncompressed(const CompressedImage& img);

CompressedImage readCompressedFile(const std::string& filename);
void writeCompressedFile(const std::string& filename, const CompressedImage& file);

ColorRGB getColor(const CompressedImage& img, int x, int y);
