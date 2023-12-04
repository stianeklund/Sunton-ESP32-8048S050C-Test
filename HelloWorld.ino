#include <Arduino_GFX_Library.h>
#include "touch.h"
#include "lcd_definitions.h"
#if defined(DISPLAY_DEV_KIT)
Arduino_GFX *gfx = create_default_Arduino_GFX();
#else  // !defined(DISPLAY_DEV_KIT)

Arduino_ESP32RGBPanel *bus = new Arduino_ESP32RGBPanel(
  // These are not in use as the interface is parallel not i2c
  GFX_NOT_DEFINED,  // CS
  GFX_NOT_DEFINED,  // SCK
  GFX_NOT_DEFINED,  // SDA
  DE, VSYNC, HSYNC, PCLK, R0, R1, R2, R3, R4, G0, G1, G2, G3, G4, G5, B0, B1,
  B2, B3, B4);

// Sunton 5" 8048S050C uses ST7262 as it's driver
// ST7262 IPS LCD 800x480
Arduino_RPi_DPI_RGBPanel *gfx = new Arduino_RPi_DPI_RGBPanel(
  bus, WIDTH, HSYNC_POLARITY, HSYNC_FRONT_PORCH, HSYNC_PULSE_WIDTH,
  HSYNC_BACK_PORCH, HEIGHT, VSYNC_POLARITY, VSYNC_FRONT_PORCH,
  VSYNC_PULSE_WIDTH, VSYNC_BACK_PORCH, PCLK_ACTIVE_NEG, PREFER_SPEED,
  AUTO_FLUSH);

#endif /* !defined(DISPLAY_DEV_KIT) */

void setup(void) {
  gfx->begin();
  gfx->fillScreen(BLACK);

#ifdef TFT_BL
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
#endif

  gfx->setCursor(10, 10);
  gfx->setTextColor(GREEN);
  gfx->println("Hello World!");

  delay(5000);  // 5 seconds
}

void loop() {
  gfx->setCursor(random(gfx->width()), random(gfx->height()));
  gfx->setTextColor(random(0xffff), random(0xffff));
  gfx->setTextSize(
    random(6),  // x scale,
    random(6),  // y scale
    random(2)   // pixel_margin
  );
  gfx->println("HELLO WORLD!");
  // delay(1);
}
