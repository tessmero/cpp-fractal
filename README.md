# cpp-fractal

A C++ program that generates a fractal. The fractal can be customized, but can only contain vertical or horizontal line segments.

![Image](fractal.png?raw=true)

Clone this repository and build using cmake.

```
cd cpp-fractal
mkdir build
cd build
cmake ..
make
```

Then run the executable that was created.

```
./cpp-fractal
```

This builds the default fractal and saves an image file ```fractal.png```

To build a configurable fractal, point the executable to the example configuration file included in this repository ```config.json```.

```
./cpp-fractal ../config.json
```

```config.json``` can be modified to customize the fractal as well as the output image. It also contains notes about all of the available options.