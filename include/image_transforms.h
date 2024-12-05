#include <vector>
#include <cstdint>

#include "colors.h"
#include "compressor_funcs.h"

void rotate(
    UncompressedImage& img, int angle, ColorRGB fill_color = {0, 0, 0},
    bool smart_gap_interpolation = false);


void applyKernel(
    UncompressedImage& img, const std::vector<std::vector<int>>& kernel, int divisor = 1);

void sharpen(UncompressedImage& img);
void gaussianBlurApprox(UncompressedImage& img, bool hard_blur = false);
void edgeDetect(UncompressedImage& img);

void negative(UncompressedImage& img);
void negative(CompressedImage& img);

void toGrayscale(UncompressedImage& img);
void toGrayscale(CompressedImage& img);

// template methods below

template<typename Image>
void mirror(Image& img, bool horizontal = false) {
    if (horizontal) {
        for (int x = 0; x < img.width; x++) {
            for (int y = 0; y < img.height/2; y++) {
                std::swap(img.image_data[x][y], img.image_data[x][img.height-1-y]);
            }
        }
    }else {
        for (int x = 0; x < img.width/2; x++) {
            for (int y = 0; y < img.height; y++) {
                std::swap(img.image_data[x][y], img.image_data[img.width-1-x][y]);
            }
        }
    }
}