# gamepad_visualizer

LMS module that renders the current gamepad state in an imae

## DataChannels
- **GAMEPAD** - Gamepad data channel where the current gamepad (e.g. XBox Controller) state is hold
- **IMAGE** - Image to draw in

## Config
- **failSafeAfterMillis** - milliseconds after last timestamp to show failsafe

## Recommended Modules
- [gamepad_controller](https://github.com/Phibedy/gamepad_controller) - Imports the gamepad
- [image_renderer](https://github.com/Phibedy/image_renderer) - render the image output of gamepad_visualizer
- [ogre_window_manager](https://github.com/Phibedy/ogre_window_manager) - needed for image_renderer

## Dependencies
- [gamepad_lib](https://github.com/Phibedy/gamepad_lib)
- [imaging](https://github.com/syxolk/imaging)
