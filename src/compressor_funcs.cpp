#include "compressor_funcs.h"
#include "error_handlers.h"
#include "libbmp.h"

/*
* Implement all the functions declared in the header file here.
* Use the BMP class from libbmp.h to save and load BMP files.

* These function will read, write, convert and compress images across different formats.
*/

void saveAsBMP(const UncompressedImage& img, const std::string& filename) {
    /*
     * Create a BMP object with the same dimensions as the image.
     * Set the pixel values of the BMP object to the pixel values of the image.
     * Write the BMP object to the file.
     */
    BMP bmp_image(img.width, img.height);
    for (int x = 0; x < img.width; x++) {
        for (int y = 0; y < img.height; y++) {
            bmp_image.set_pixel(
                x,
                y,
                img.image_data[x][y].r,
                img.image_data[x][y].g,
                img.image_data[x][y].b);
        }
    } 
    // std::string asd = "asd.bmp";
    int n = filename.size(); 
    // std::cout << filename << "\n";
    char fname[n+1];
    copy(filename.begin(), filename.end(), fname);
    fname[n] = '\0';
    bmp_image.write(fname);
}

UncompressedImage loadFromBMP(const std::string& filename) {
    /*
     * Read the BMP file.
     * Create an UncompressedImage object with the same dimensions as the BMP object.
     * Set the pixel values of the UncompressedImage object to the pixel values of the BMP object.
     * Return the UncompressedImage object.
     */
    
    int n = filename.size(); 
    char fname[n+1];
    copy(filename.begin(), filename.end(), fname);
    fname[n] = '\0';

    BMP bmp(fname);
    UncompressedImage img;
    img.height = bmp.get_height();
    img.width = bmp.get_width();
    img.image_data.assign(img.width, std::vector<ColorRGB>(img.height));
    
    for (int x = 0; x < img.width; x++) {
        for (int y = 0; y < img.height; y++) {
            bmp.get_pixel(
                x,
                y,
                img.image_data[x][y].r,
                img.image_data[x][y].g,
                img.image_data[x][y].b);
        }
    }

    return img;
}

UncompressedImage readUncompressedFile(const std::string& filename) {
    /*
     * Read the file according to the uncompressed file format.
     * Gracefully handle errors if the file format is invalid.
     * Return the UncompressedImage object.
     */
    return {};
}

void writeUncompressedFile(const std::string& filename, const UncompressedImage& image) {
    /*
     * Write the file according to the uncompressed file format.
     * Gracefully handle errors if occured.
     */
}

uint8_t findClosestColorId(const ColorRGB& color, const std::map<uint8_t, ColorRGB>& colorTable) {
    /*
     * Find the closest color in the color table (pallette) to the given color.
     * Return the ID of the closest color.
     */
    return 0;
}

CompressedImage toCompressed(
    const UncompressedImage& img, const std::map<uint8_t, ColorRGB>& color_table, bool approximate,
    bool allow_color_add) {
    /*
     * Create a CompressedImage object with the same dimensions as the image.
     * Set the color table of the CompressedImage object to the given color table.
     * Set the pixel values of the CompressedImage object to the pixel values of the image.
     * Return the CompressedImage object.
     */
    return {};
}

UncompressedImage toUncompressed(const CompressedImage& img) {
    /*
     * Create an UncompressedImage object with the same dimensions as the image.
     * Set the pixel values of the UncompressedImage object to the pixel values of the image.
     * Return the UncompressedImage object.
     */

    return {};
}

ColorRGB getColor(const CompressedImage& img, int x, int y) {
    /*
     * Return the color of the pixel at the given coordinates.
     */

    // Note that [] operator cannot be used here as img (as well as its members) is const,
    // and [] operator is not a const member function of std::map

    return {};
}

CompressedImage readCompressedFile(const std::string& filename) {
    /*
     * Read the file according to the compressed file format.
     * Gracefully handle errors if the file format is invalid.
     * Return the CompressedImage object.
     */
    return {};
}

void writeCompressedFile(const std::string& filename, const CompressedImage& image) {
    /*
     * Write the file according to the compressed file format.
     * Gracefully handle errors if occured.
     */
}
