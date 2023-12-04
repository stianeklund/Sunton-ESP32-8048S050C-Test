// GT911: https://github.com/TAMCTec/gt911-arduino.git
#include <TAMC_GT911.h>
#include <Arduino_GFX_Library.h>
#include <Wire.h>

#define TOUCH_GT911
#define TOUCH_GT911_SCL 18
#define TOUCH_GT911_SDA 17
#define TOUCH_GT911_INT -1
#define TOUCH_GT911_RST 38
#define TOUCH_GT911_ROTATION ROTATION_NORMAL
#define TOUCH_MAP_X1 480
#define TOUCH_MAP_X2 0
#define TOUCH_MAP_Y1 480
#define TOUCH_MAP_Y2 0

int touch_last_x = 0, touch_last_y = 0;
TAMC_GT911 ts = TAMC_GT911(TOUCH_GT911_SDA, TOUCH_GT911_SCL, TOUCH_GT911_INT,
                           TOUCH_GT911_RST, max(TOUCH_MAP_X1, TOUCH_MAP_X2),
                           max(TOUCH_MAP_Y1, TOUCH_MAP_Y2));

void touch_init() {

  Wire.begin(TOUCH_GT911_SDA, TOUCH_GT911_SCL);
  ts.begin();
  ts.setRotation(TOUCH_GT911_ROTATION);
}

bool touch_has_signal() {}

bool touch_touched(Arduino_RPi_DPI_RGBPanel *gfx) {
  ts.read();
  if (ts.isTouched) {
#if defined(TOUCH_SWAP_XY)
    touch_last_x =
      map(ts.points[0].y, TOUCH_MAP_X1, TOUCH_MAP_X2, 0, gfx->width() - 1);
    touch_last_y =
      map(ts.points[0].x, TOUCH_MAP_Y1, TOUCH_MAP_Y2, 0, gfx->height() - 1);
#else
    touch_last_x =
      map(ts.points[0].x, TOUCH_MAP_X1, TOUCH_MAP_X2, 0, gfx->width() - 1);
    touch_last_y =
      map(ts.points[0].y, TOUCH_MAP_Y1, TOUCH_MAP_Y2, 0, gfx->height() - 1);
#endif
    return true;
  } else {
    return false;
  }
}

bool touch_released() {
  return true;
}