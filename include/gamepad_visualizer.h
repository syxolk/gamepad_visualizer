#ifndef GAMEPAD_VISUALIZER_H
#define GAMEPAD_VISUALIZER_H

#include <lms/datamanager.h>
#include <lms/imaging/image.h>
#include <gamepad/gamepad.h>

class GamepadVisualizer : public lms::Module {
public:
    bool initialize() override;
    bool cycle() override;
    bool deinitialize() override;
private:
    lms::imaging::Image *imagePtr;
    const Gamepad *gamepad;
};

#endif /* GAMEPAD_VISUALIZER_H */
