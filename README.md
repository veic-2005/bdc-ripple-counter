# bdc-ripple-counter
[An3049](https://www.microchip.com/en-us/application-notes/an3049) from Microchip

## XC8
- v2.05    
compile: passed
- v2.10    
compile: error
- v4.0    
compile: error

### v2.10
Simply comment out the "debug" line.

- device_config.c

### v4.0
change `char getch(void)` to `int getch(void)`

- eusart1.c

from [Article Number: 000015738](https://support.microchip.com/s/article/How-to-resolve-the-following-compiler-errors)
