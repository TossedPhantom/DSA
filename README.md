# DSA

A collection of Data Structures and Algorithms implemented mostly in C.

## Building


To compile the whole repository at once, you may use this command in your terminal:
```
for f in *.c; do gcc "$f" -o "${f%.c}"; done
for f in *.cpp; do g++ "$f" -o "${f%.cpp}"; done
```

To compile `.c` files individually, you may use this command in your terminal:
```
gcc filename.c -o filename
```

To compile `.cpp` files individually, you may use this command in your terminal:
```
g++ filename.cpp -o filename
```

## Platform

Developed & Tested on Arch Linux(btw :3). Should work on other Unix-like systems fine. Maybe.

## License

Licensed under [GPL-2.0](LICENSE).
