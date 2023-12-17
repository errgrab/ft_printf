# ft_printf
## Because ft_putnbr() and ft_putstr() aren’t enough.

### Description

`ft_printf` is a custom implementation of the standard C library function `printf`. This project aims to provide a versatile and extensible printf function, allowing you to format and print output in a variety of ways.

### Roadmap

The following is a roadmap for implementing the features of `ft_printf`. Each feature corresponds to a specific format specifier:

Feature | Status
---|---
**%c:** Print a Single Character | :white_check_mark:
**%s:** Print a String | :white_check_mark:
**%p:** Print a Pointer in Hexadecimal | :white_check_mark:
**%d:** Print a Decimal Number | :white_check_mark:
**%i:** Print an Integer in Base 10 | :white_check_mark:
**%u:** Print an Unsigned Decimal Number | :white_check_mark:
**%x:** Print a Number in Hexadecimal (Lowercase | :white_check_mark:
**%X:** Print a Number in Hexadecimal (Uppercase | :white_check_mark:
**%%:** Print a Percent Sign | :white_check_mark:

Bonus:

Feature | Status
---|---
**width**: Set a width to the for the formatted value | :construction:
**precision**: Set a precision to the for the formatted value | :construction:
**-**: Negative width | :construction:
**+**: Display a `+` for positive numbers | :construction:
**#**: `0x` or `0X` for hex and upper case hex respectively | :construction:
**<space>**: idk, it's just there... | :construction:
**0**: instead of spaces the padding of width is made of `0` | :construction:


