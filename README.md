# Nummy

**Nummy** is a lightweight command-line program for computing mathematical functions such as:
- **Euler's number (e)** using a series expansion
- **The natural logarithm of 2 (ln(2))**
- **The value of pi (π)** using a Gregory-Leibniz-based series
- **The square root of a number** using the Newton-Raphson method

## Features
- Compute accurate approximations of mathematical constants and functions.
- Customizable number of terms for series-based calculations to balance precision and performance.

## Usage

The program takes two arguments:
1. **Flag**: Specifies the operation to perform:
   - `-e`: Compute Euler's number (e)
   - `-l`: Compute ln(2) (natural logarithm of 2)
   - `-p`: Compute pi (π)
   - `-s`: Compute the square root of a number
2. **Integer N**: The number of terms for series-based calculations or the number to find the square root of.

### Syntax
```bash
./nummy [FLAG] N
