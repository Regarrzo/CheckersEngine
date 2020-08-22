# CheckersEngine
A C++ checkers engine implementing multithreaded negamax with alpha beta pruning.

##### NOTE: **The engine is functional, but there are a few incomplete features, which include:**

- Zobrist hashing
- PDN in and output
- Time control

## Building
There are no external dependencies, so building should be fairly straightforward.

#### Linux
Prebuilt x64 binaries exist in the release and debug folders.

This project uses some experimental C++20 features, like the starship operator. You will need the latest GCC compiler to successfully compile.
To build with the existing makefiles, simply navigate to either release or debug and run the make command.

#### Windows
As of uploading this the MSVC compiler doesn't yet support the starship operator introduced in C++20, you will need a compiler that supports it to build. 
Another issue might be that the unicode icons used for the checkers pieces are not supported by the command line. Either replace them in checkers.cpp, in the Checkers::toString() method, or use a terminal with unicode character support.

## Usage
Upon compilation you can play against the engine in a command line. 
Simply run the program and select one of the listed moves by inputting one of the listed numbers.

```bash
Black turn: 
0  · ● · ● · ● · ● 
1  ● · ● · ● · ● · 
2  · ● · ● · ● · ● 
3  · · · · · · · · 
4  · · · · · · · · 
5  ○ · ○ · ○ · ○ · 
6  · ○ · ○ · ○ · ○ 
7  ○ · ○ · ○ · ○ · 
   0 1 2 3 4 5 6 7
Found 7 moves.
(0) Start: (Y=5, X=0), End: (Y=4, X=1), Takes:
(1) Start: (Y=5, X=2), End: (Y=4, X=3), Takes:
(2) Start: (Y=5, X=2), End: (Y=4, X=1), Takes:
(3) Start: (Y=5, X=4), End: (Y=4, X=5), Takes:
(4) Start: (Y=5, X=4), End: (Y=4, X=3), Takes:
(5) Start: (Y=5, X=6), End: (Y=4, X=7), Takes:
(6) Start: (Y=5, X=6), End: (Y=4, X=5), Takes:
Enter move: 4
```

To change the player you are controlling, to change the depth to which the engine searches and to change the amount of allowed threads, you will need to modify main.cpp.
