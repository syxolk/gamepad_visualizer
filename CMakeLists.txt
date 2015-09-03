set ( SOURCES 
	"src/gamepad_visualizer.cpp"
	"src/interface.cpp"
)

set (HEADERS
	"include/gamepad_visualizer.h"
)

include_directories("include")

add_library(gamepad_visualizer MODULE ${SOURCES} ${HEADERS})
target_link_libraries(gamepad_visualizer PRIVATE lmscore gamepad_lib imaging)
