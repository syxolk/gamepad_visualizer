#ifndef GAMEPAD_VISUALIZER_H
#define GAMEPAD_VISUALIZER_H

#include <lms/module.h>
#include <lms/datamanager.h>
#include <lms/imaging/image.h>
#include <gamepad/gamepad.h>
#include <lms/imaging/graphics.h>

class GamepadVisualizer : public lms::Module {
public:
    bool initialize() override;
    bool cycle() override;
    bool deinitialize() override;
private:
    void draw2DAxis(lms::imaging::Graphics &g, const Gamepad::axis &axis,
                    int x, int y, int w, int h);
    void drawTrigger(lms::imaging::Graphics &g, const Gamepad::axis &axis,
                    int x, int y, int w, int h);
    void drawButton(lms::imaging::Graphics &g, bool pressed,
                                       int x, int y, int w, int h);

    lms::WriteDataChannel<lms::imaging::Image> imagePtr;
    lms::ReadDataChannel<Gamepad> gamepad;
};

#endif /* GAMEPAD_VISUALIZER_H */
