# reaper-minimal-plugin

Minimal REAPER plugin which uses REAPER's provided SWELL on Linux and OS X

**Currently for Linux only!**

## Develop

### Build

#### Linux

Create debug build:
```sh
mkdir -p build/linux
cd build/linux
cmake -DCMAKE_BUILD_TYPE=Debug ../..
cmake --build .
```

Result will be located at `build/linux/reaper_minimal_plugin.so`