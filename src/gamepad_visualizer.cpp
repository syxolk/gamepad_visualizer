#include <gamepad_visualizer.h>
#include <lms/imaging/graphics.h>
#include <gamepad/gamepad_types.h>

bool GamepadVisualizer::initialize() {
    gamepad = datamanager()
                ->readChannel<Gamepad>(this, "GAMEPAD");

    imagePtr = datamanager()
            ->writeChannel<lms::imaging::Image>(this, "IMAGE");

    return true;
}

bool GamepadVisualizer::cycle() {
    imagePtr->resize(600, 400, lms::imaging::Format::BGRA);
    imagePtr->fill(255);  // everything white

    lms::imaging::BGRAImageGraphics g(*imagePtr);

    Gamepad::axis ls = gamepad->getAxis("LS");
    Gamepad::axis rs = gamepad->getAxis("RS");
    Gamepad::axis lt = gamepad->getAxis("LT");
    Gamepad::axis rt = gamepad->getAxis("RT");
    bool ba = gamepad->buttonPressed("A");
    bool bb = gamepad->buttonPressed("B");
    bool bx = gamepad->buttonPressed("X");
    bool by = gamepad->buttonPressed("Y");

    draw2DAxis(g, ls, 100, 100, 200, 200);
    draw2DAxis(g, rs, 300, 100, 200, 200);

    drawTrigger(g, lt, 50, 100, 50, 200);
    drawTrigger(g, rt, 500, 100, 50, 200);

    drawButton(g, ba, 200, 300, 50, 50);
    drawButton(g, bb, 250, 300, 50, 50);
    drawButton(g, bx, 300, 300, 50, 50);
    drawButton(g, by, 350, 300, 50, 50);

    return true;
}

void GamepadVisualizer::draw2DAxis(lms::imaging::Graphics &g,
                                   const Gamepad::axis &axis, int x, int y,
                                   int w, int h) {
    g.setColor(lms::imaging::black);
    g.drawRect(x, y, w, h);
    g.setColor(lms::imaging::red);
    g.drawVerticalLine(x + w / 2, y, h);
    g.drawHorizontalLine(x, y + h / 2, w);
    g.setColor(lms::imaging::black);
    g.drawLine(x + w/2, y + h/2, x + w/2 + (int)(axis.x * w / 2),
               y + h/2 + (int)(axis.y * h / 2));
}

void GamepadVisualizer::drawTrigger(lms::imaging::Graphics &g,
                                    const Gamepad::axis &axis,
                                    int x, int y, int w, int h) {
    g.setColor(lms::imaging::black);
    g.drawRect(x, y, w, h);
    g.drawVerticalLine(x + w/2, y, h / 2 + (int)(axis.x * h / 2));
}

void GamepadVisualizer::drawButton(lms::imaging::Graphics &g, bool pressed,
                                   int x, int y, int w, int h) {
    g.setColor(lms::imaging::black);
    g.drawRect(x, y, w, h);
    if(pressed) {
        g.drawLine(x, y, x + w, y + h);
        g.drawLine(x + w, y, x, y + h);
    }
}

bool GamepadVisualizer::deinitialize() {
    return true;
}
