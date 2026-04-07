import sys
import threading

def input():
    return sys.stdin.readline().strip()

def main():
    solve()

def solve():
    pass

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return (a * b) // gcd(a, b)

if __name__ == "__main__":
    main()