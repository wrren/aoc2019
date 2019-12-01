# Advent of Code 2019

Welcome to my Advent of Code 2019 solutions repository. This year I'll be tackling the AoC challenges
using C++20 in order to get up to speed on the new features that have been added to the language since
C++11.

## Building the Solutions

I'll be using [Xmake](https://xmake.io/#/), a new build system for C++, to build and run each solution. Check out the [installation page](https://xmake.io/#/getting_started) for instructions on setting it up. From my short time with it, I've found that it's far less confusing than CMake and overall lets me get things done faster.

## Running the Solutions

By default, each solution binary will read from the correct input file from the `inputs` directory of the repository. However
you can substitute your own input files by providing a path to an input file as the first argument to the binary.

```shell
# Run solution with default input file
xmake run day1

# Run solution with provided input file path
xmake run day1 /path/to/input/file
```