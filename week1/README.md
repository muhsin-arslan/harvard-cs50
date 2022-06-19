# C Projects from CS50 Class

## Week1

1. hello-world
2. get-string
3. calculator
4. condition
5. points
6. parity
7. agree
8. meow (loop)
9. meow-function
10. discount
11. mario
12. floating-point (Floating point imprecision)
13. type-conversion
14. pennies
15. switch-case

# How to Install cs50.h library (macOS)

1. Download the latest release from https://github.com/cs50/libcs50/releases
2. Extract libcs50-version
3. cd libcs50-version
4. sudo make install

# Fix for make command (CS50 head file) on macOS arm64 (m1/silicon) architecture

Add the that code to terminal environment/config file (I'm using zsh. So it is **.zshrc** file)

```
export LDLIBS='-lcs50'
```
