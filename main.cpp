#include <iostream>

int main() {
  // Image
  int image_width = 256;
  int image_height = 256;

  // Render a 2D array
  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
    // Progress indicator (not using stdout but std-logging output stream)
    // Currently not visible as the progress happens too fast. Alternative
    // options are "ncurses"
    std::clog << "\rScanlines remaining:" << (image_height - j) << ' '
              << std::flush;
    for (int i = 0; i < image_width; i++) {
      auto r = double(i) / (image_width - 1);
      auto g = double(j) / (image_height - 1);
      auto b = 0.0;

      /* -- Classic
       * 1. Pixels are written out in rows
       * 2. Every row of pixels is written left to right
       * 3. These rows are written out from top to bottom
       *
       * -- Conventions
       * 1. Each of the red/green/blue components are represented
       * internally by real-valued variables that rangef rom 0.0
       * to 1.0 which are further scaled to integer values between
       * 0 and 255 before being printed out
       * 2. Red goes from fully off (black) to fully on (bright red)
       * from left to right, and green goes from fully off at the top
       * (black) to fully on at the bottom (bright green). Adding red
       * and green light together make yellow so we should expect
       * the bottom right corner to be yellow
       */

      int ir = int(255.99 * r);
      int ig = int(255.99 * g);
      int ib = int(255.99 * b);

      std::cout << ir << ' ' << ig << ' ' << ib << '\n';
    }
  }
}

/*
 * -- Example
 * P3 -> Colors are in ASCII
 * 3 2 -> (cols, rows)
 * 255 000 000    000 255 000   000 000 255   (red, green, blue)
 * 255 255 000    255 255 255   000 000 000   (yellow, white, black)
 */
