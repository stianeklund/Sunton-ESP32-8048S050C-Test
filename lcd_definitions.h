// Definitions for the Sunton 5" IPS Capacitive Display
// Sunton ESP32-8048S050C
// Uses a ESP32-S3 and the ST7262 driver GT911 for touch
// CS, SCK and SDA are not used here

// Backlight pin
#define TFT_BL 2


// Bus definitions
#define DE 40
#define VSYNC 41
#define HSYNC 39
#define PCLK 42
#define R0 45
#define R1 48
#define R2 47
#define R3 21
#define R4 14
#define G0 5
#define G1 6
#define G2 7
#define G3 15
#define G4 16
#define G5 4
#define B0 8
#define B1 3
#define B2 46
#define B3 9
#define B4 1

// LCD Panel definitions
#define WIDTH 800
#define HEIGHT 480

// HSYNC
#define HSYNC_POLARITY 0
#define HSYNC_FRONT_PORCH 8
#define HSYNC_BACK_PORCH 8
#define HSYNC_PULSE_WIDTH 4

// VSYNC
#define VSYNC_FRONT_PORCH 8
#define VSYNC_BACK_PORCH 8
#define VSYNC_POLARITY 0
#define VSYNC_PULSE_WIDTH 4

#define PCLK_ACTIVE_NEG 1
#define PREFER_SPEED 16000000
#define AUTO_FLUSH true