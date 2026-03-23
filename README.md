# Simple Geometry Visualizer

A C++ application for 2D visualization of points, lines, and geometric algorithms, using the SDL2 library for graphics. It features interactive view manipulation (moving and zooming) and automated dependency management.

## Features
* Rendering of large datasets (e.g., 10,000+ points) loaded from `.txt` files.
* TrueType font rendering for UI/data labels.
* Interactive camera controls (pan and zoom).
* Cross-platform ready build system using CMake and vcpkg.

## Prerequisites
To build this project from source, you will need:
* A modern C++ Compiler (e.g., MSVC for Windows)
* **CMake** (version 3.31.0 or higher)
* **vcpkg** (C++ package manager)

## Building the Project

This project uses CMake and vcpkg in manifest mode (`vcpkg.json`). Dependencies (`sdl2`, `sdl2-ttf`) are downloaded and built automatically during the CMake configuration step. No manual linking is required!

### Option 1: Visual Studio 2022 (Recommended for Windows)
1. Clone this repository.
2. Open Visual Studio and select **"Open a local folder"**, pointing to the repository root.
3. Visual Studio should detect `CMakeLists.txt` automatically. 
   *(Note: Ensure your CMake settings in VS point to your local vcpkg toolchain file).*
4. Select `VisualCalc.exe` from the startup item dropdown and click Play/Build.

### Option 2: Command Line
Assuming you have an environment variable `VCPKG_ROOT` pointing to your vcpkg installation:

```bash
git clone [https://github.com/Krolik05/VisualGeometry.git](https://github.com/Krolik05/VisualGeometry.git)
cd VisualGeometry

# Configure the project and download dependencies
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="%VCPKG_ROOT%/scripts/buildsystems/vcpkg.cmake"

# Build the project (Release mode)
cmake --build build --config Release
