# Game dev

A testing project for learning purposes.

# Build
## With docker

```bash
make docker-build && make compile && make run
```

## Native

In order to build source code you need to install SDL and CMake first:

```bash
sudo apt-get install libsdl2-dev
```

```bash
sudo apt-get install cmake
```

Go into *build* directory:

```bash
cd build
```
CMake root directory:

```bash
cmake ..
```

Compile and run:

```bash
make && ./game-dev
```