#include <gamepad_visualizer.h>
#include <lms/imaging/graphics.h>
#include <gamepad/gamepad_types.h>

bool GamepadVisualizer::initialize() {
    gamepad = datamanager()
                ->readChannel<Gamepad>(this,"Xbox");

    imagePtr = datamanager()
            ->writeChannel<lms::imaging::Image>(this, "CAMERA_IMAGE");

    return true;
}

bool GamepadVisualizer::cycle() {
    imagePtr->resize(400, 400, lms::imaging::Format::BGRA);
    imagePtr->fill(255);  // everything white

    lms::imaging::BGRAImageGraphics g(*imagePtr);
    g.setColor(lms::imaging::black);

    Gamepad::axis ls = gamepad->getAxis("LS");
    Gamepad::axis rt = gamepad->getAxis("RT");
    Gamepad::axis lt = gamepad->getAxis("LT");

    g.drawRect(100, 100, 200, 200);
    g.setColor(lms::imaging::red);
    g.drawVerticalLine(200, 100, 200);
    g.drawHorizontalLine(100, 200, 200);
    g.setColor(lms::imaging::black);
    g.drawLine(200, 200, 200 + (int)(ls.x * 100), 200 + (int)(ls.y * 100));


    g.drawRect(50, 100, 50, 200);
    g.drawVerticalLine(75, 100, 100 + (int)(lt.x * 100));

    g.drawRect(300, 100, 50, 200);
    g.drawVerticalLine(325, 100, 100 + (int)(rt.x * 100));

    return true;
}

bool GamepadVisualizer::deinitialize() {
    return true;
}
