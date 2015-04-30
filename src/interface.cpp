#include <gamepad_visualizer.h>

extern "C" {
void* getInstance () {
    return new GamepadVisualizer();
}
}
