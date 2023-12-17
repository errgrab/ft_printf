# ft_printf

### **Because ft_putnbr() and ft_putstr() aren’t enough.**

## Description

`ft_printf` is a custom implementation of the standard C library function `printf`. This project aims to provide a versatile and extensible printf function, allowing you to format and print output in a variety of ways.

## Roadmap

The following is a roadmap for implementing the features of `ft_printf`. Each feature corresponds to a specific format specifier:

Character | Feature | Status
---|---|---
**%c** | Print a Single Character | :white_check_mark:
**%s** | Print a String | :white_check_mark:
**%p** | Print a Pointer in Hexadecimal | :white_check_mark:
**%d** | Print a Decimal Number | :white_check_mark:
**%i** | Print an Integer in Base 10 | :white_check_mark:
**%u** | Print an Unsigned Decimal Number | :white_check_mark:
**%x** | Print a Number in Hexadecimal (Lowercase | :white_check_mark:
**%X** | Print a Number in Hexadecimal (Uppercase | :white_check_mark:
**%%** | Print a Percent Sign | :white_check_mark:

### Bonus:

The printf formatting with bonus works as follows:

```
%[flag][width].[precision][format specifier]
```

the flag is one of the follows:

Character | Descrition | Status
---|---|---
**-** | Negative width | :construction:
**0** | instead of spaces the padding of width is made of `0` | :construction:
**#** | `0x` or `0X` for hex and upper case hex respectively | :construction:
**\<space>** | idk, it's just there... | :construction:
**+** | Display a `+` for positive numbers | :construction:

### :construction: width

Width is a number that dictates minimum width to be printed, it should work in every format specifier except `%` for some reason.

### :construction: precision

I don't know very well, it looks like it should limit the printing of the string somehow, and i didn't search for other specifiers.
