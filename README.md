# StockLion 
[![Build Status](https://travis-ci.org/jacobrs/stocklion.svg?branch=master)](https://travis-ci.org/jacobrs/stocklion)
[![codecov](https://codecov.io/gh/jacobrs/stocklion/branch/master/graph/badge.svg)](https://codecov.io/gh/jacobrs/stocklion)

A custom built chess bot in c++.
This project is part of the coding night initiative to introduce algorithms and datastructures. Bots compete against one another at the end of the development period.

### Standards
StockLion abides by the UCI protocol to communicate with games servers or graphical user interfaces. PGN game format is also supported. Feeding a PGN to the bot allows it to start playing from a specific position.

### Algorithms
StockLion uses alpha-beta pruning to decide which move to play next.

### How can I run this?
You can build StockLion uses cmake:
* `mkdir build`
* `cd build`
* `cmake <path to stocklion root directory>`
* `make`
* `./stocklion`

