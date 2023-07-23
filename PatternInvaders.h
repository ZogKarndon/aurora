/*
 * Aurora: https://github.com/pixelmatix/aurora
 * Copyright (c) 2014 Jason Coon
 *
 * Inspired by 'Space Invader Generator': https://the8bitpimp.wordpress.com/2013/05/07/space-invader-generator
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef PatternInvaders_H
#define PatternInvaders_H

class PatternInvadersSmall : public Drawable {
  private:
    uint8_t x = 1;
    uint8_t y = 1;

    static const uint8_t IMG_HEIGHT = 5;
    static const uint8_t IMG_WIDTH = 5;

  public:
    PatternInvadersSmall() {
      name = (char *)"Invaders Small";
    }

    void start() {
      backgroundLayer.fillScreen(CRGB(CRGB::Black));
    }

    unsigned int drawFrame() {
      CRGB color1 = effects.ColorFromCurrentPalette(random(0, 255));

      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
          CRGB color = CRGB::Black;

          if (random(0, 2) == 1) color = color1;

          backgroundLayer.drawPixel(x + i, y + j, color);

          if (i < 2)
            backgroundLayer.drawPixel(x + (4 - i), y + j, color);
        }
      }

      x += IMG_WIDTH + 1;   // for separation
      if (x > (MATRIX_WIDTH - (IMG_WIDTH+2))) {
        x = 1;
        y += IMG_HEIGHT + 1;
      }

      if (y > MATRIX_HEIGHT - (IMG_HEIGHT + 2)) y = x = 1;

      return 125;
    }
};

class PatternInvadersMedium : public Drawable {
  private:
    uint8_t x = 0;
    uint8_t y = 0;
    static const uint8_t IMG_HEIGHT = 10;
    static const uint8_t IMG_WIDTH = 10;
  public:
    PatternInvadersMedium() {
      name = (char *)"Invaders Medium";
    }

    void start() {
      backgroundLayer.fillScreen(CRGB(CRGB::Black));
    }

    unsigned int drawFrame() {
      CRGB color1 = effects.ColorFromCurrentPalette(random(0, 255));

      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
          CRGB color = CRGB::Black;

          if (random(0, 2) == 1) color = color1;

          backgroundLayer.fillRectangle(x + (i * 2), y + (j * 2), x + (i * 2 + 1), y + (j * 2 + 1), color);

          if (i < 2)
            backgroundLayer.fillRectangle(x + (8 - i * 2), y + (j * 2), x + (9 - i * 2), y + (j * 2 + 1), color);
        }
      }

      x += IMG_WIDTH + 1;   // for separation
      if (x > (MATRIX_WIDTH - (IMG_WIDTH+2))) {
        x = 0;
        y += IMG_HEIGHT + 1;
      }

      if (y > MATRIX_HEIGHT - (IMG_HEIGHT + 2)) y = x = 0;


      return 500;
    }
};

class PatternInvadersLarge : public Drawable {
  private:
      uint8_t x = 1;
      uint8_t y = 1;
      static const uint8_t IMG_HEIGHT = 20;
      static const uint8_t IMG_WIDTH = 20;

  public:
    PatternInvadersLarge() {
      name = (char *)"Invaders Large";
    }

    void start() {
      backgroundLayer.fillScreen(CRGB(CRGB::Black));
    }

    unsigned int drawFrame() {
      backgroundLayer.fillScreen(CRGB(CRGB::Black));

      CRGB color1 = effects.ColorFromCurrentPalette(random(0, 255));

      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
          CRGB color = CRGB::Black;

          if (random(0, 2) == 1) {
            color = color1;
          }

          backgroundLayer.fillRectangle(x + i * 6, y + j * 6, (x + 4) + i * 6, (y + 4) + j * 6, color);

          if (i < 2)
            backgroundLayer.fillRectangle(x + (4 - i) * 6, y + j * 6, (x+4) + (4 - i) * 6, (y+4) + j * 6, color);
        }
      }

      x += IMG_WIDTH + 1;   // for separation
      if (x > (MATRIX_WIDTH - (IMG_WIDTH + 2))) {
          x = 1;
          y += IMG_HEIGHT + 1;
      }

      if (y > MATRIX_HEIGHT - (IMG_HEIGHT + 2)) y = x = 1;


      return 2000;
    }
};

#endif
