# 🧮 Bit Manipulation: Techniques & Tricks

Bit manipulation is a powerful tool in the toolkit of computer scientists and programmers, allowing for highly efficient mathematical operations and algorithm optimizations. Below is a list of some common techniques and useful tricks:

---

## Table of Contents

- [Bitwise Operators Quick Reference](#bitwise-operators-quick-reference)
- [Basic Tricks](#basic-tricks)
- [Common Use Cases](#common-use-cases)
- [Sample Problems](#sample-problems)
- [References](#references)

---

## Bitwise Operators Quick Reference

| Operator | Symbol | Example (A=5, B=3) | Result |
|----------|--------|--------------------|--------|
| AND      | `&`    | 5 & 3              | 1      |
| OR       | `&#124;`    | 5 &#124; 3            | 7      |
| XOR      | `^`    | 5 ^ 3              | 6      |
| NOT      | `~`    | ~5                 | -6     |
| Left Shift | `<<` | 5 << 1             | 10     |
| Right Shift| `>>` | 5 >> 1             | 2      |

---

## Basic Tricks

### 1. **Check if n is even or odd**
```cpp
if (n & 1) 
    // Odd
else 
    // Even
```

### 2. **Get the i-th bit (0-based)**
```cpp
(n >> i) & 1
```

### 3. **Set the i-th bit**
```cpp
n |= (1 << i);
```

### 4. **Clear the i-th bit**
```cpp
n &= ~(1 << i);
```

### 5. **Toggle the i-th bit**
```cpp
n ^= (1 << i);
```

### 6. **Count set bits (Hamming Weight)**
```cpp
while (n) {
    n &= (n - 1); // Drops the lowest set bit
    count++;
}

for (int i = 0; i < 32; i++) {
    if (n>>i&1) count ++;
}

```

### 7. **Check if n is a power of two**
```cpp
bool isPowerOfTwo = n > 0 && (n & (n - 1)) == 0;
```

### 8. **Swap two numbers without a temporary variable**
```cpp
a ^= b;
b ^= a;
a ^= b;
```

---

## Common Use Cases

- **Set Operations**: Use bits to represent presence/absence (e.g., subsets of a set).
- **State Compression**: Represent complex system states compactly for DP/memoization.
- **Efficient Modulo/Multiplication/Division by Powers of Two**: Use shift operators.
- **Masking**: Quickly extract or clear ranges of bits.

---