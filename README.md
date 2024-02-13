# Soundex TDD Example

This repository contains code for the Soundex test-driven development (TDD)
exercise from Jeff Langr's book (see `References` section below). You can learn
more about Soundex and the underlying algorithm by reading the
[Wikipedia article](https://en.wikipedia.org/wiki/Soundex).

## Setup using Docker (recommended)

To setup the project on your local machine it is recommended to use Visual
Studio Code together with the [Dev Containers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)
installed. This allows you to easily run the application inside of a Docker
container with all required dependencies already installed. 

## How to use

From the root folder of the project, prepare an out-of-source build:

```
cmake -B build
```

Use CMake to build the project:

```
cmake --build build
```

Run all tests in verbose mode:

```
ctest --test-dir build/ -V
```

## References

- Langr, J. (2013): *Modern C++ Programming with Test-Driven Development: Code
Better, Sleep Better.* Raleigh, NC: Pragmatic Bookshelf.
