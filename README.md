# StockLion 
[![Build Status](https://travis-ci.org/jacobrs/stocklion.svg?branch=master)](https://travis-ci.org/jacobrs/stocklion)
[![codecov](https://codecov.io/gh/jacobrs/stocklion/branch/master/graph/badge.svg)](https://codecov.io/gh/jacobrs/stocklion)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/b9e967bf6ac6493aa2e5faab60d5d5c2)](https://www.codacy.com/app/jacobrs/stocklion?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=jacobrs/stocklion&amp;utm_campaign=Badge_Grade)

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

