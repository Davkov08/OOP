#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Color {
    int r, g, b;
};

struct Pixel {
    Color color;
};

struct Image {
    int width, height;
    Pixel* data;

    Image(int w, int h) {
        width = w;
        height = h;
        data = new Pixel[w * h];
    }

    ~Image() {
        delete[] data;
    }

    Pixel& getPixel(int x, int y) {
        return data[y * width + x];
    }
};

void generateGradient(Image &img) {
    int cx = img.width / 2;
    int cy = img.height / 2;
    double maxDist = sqrt(cx * cx + cy * cy);

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            int dx = x - cx;
            int dy = y - cy;
            double dist = sqrt(dx * dx + dy * dy);
            double ratio = dist / maxDist;

            // Gradient from red (center) to black (edges)
            int r = (int)(255 * (1 - ratio));
            int g = (int)(200 * (1 - ratio));  // less green
            int b = (int)(100 * (1 - ratio));  // more blue at edges

            img.getPixel(x, y).color = {r, g, b};
        }
    }
}

void savePPM(const Image &img, const string &filename) {
    ofstream out(filename);
    out << "P3\n" << img.width << " " << img.height << "\n255\n";
    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            const Color &c = img.data[y * img.width + x].color;
            out << c.r << " " << c.g << " " << c.b << " ";
        }
        out << "\n";
    }
    out.close();
}

int main() {
    int width, height;
    cin>>width>>height;
    Image img(width, height);

    generateGradient(img);
    savePPM(img, "davkov.ppm");

    return 0;
}
