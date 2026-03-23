cmake_minimum_required(VERSION 3.31.0)
project(VisualCalculator)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(VisualCalc
  General.cpp
  main.cpp
  Math.cpp
  ObjectManager.cpp
  RendererManager.cpp
  VisualCalculator.cpp
  WindowManager.cpp
)

target_link_libraries(VisualCalc
PRIVATE
  SDL2::SDL2
  SDL2::SDL2main
  SDL2_ttf::SDL2_ttf
)

add_custom_command(TARGET VisualCalc POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/data.txt"
        "${CMAKE_CURRENT_SOURCE_DIR}/font.ttf"
        "${CMAKE_CURRENT_SOURCE_DIR}/punkty.txt"
        $<TARGET_FILE_DIR:VisualCalc>
)