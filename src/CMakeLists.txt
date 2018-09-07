# Add libviface library to build
add_executable(${PROJECT_NAME} "main.cpp")

# Set library version
set_target_properties(
    ${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_NAME}_VERSION_STRING
)

set(CMAKE_REQUIRED_LIBRARIES m)
# TODO Just a test, to remove
CHECK_LIBRARY_EXISTS(tuntap tuntap_version "/usr/lib/" HAVE_TUNTAP)

# Specify shared library install directory
install(
    TARGETS
    ${PROJECT_NAME}
    DESTINATION
    ${CMAKE_BINARY_DIR}
)
