import sys

def main():
    # Read inputs
    a = int(sys.stdin.readline().strip())
    b = int(sys.stdin.readline().strip())
    
    # Array mapping for numbers 1 to 9
    words = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    
    # Iterate through the interval [a, b]
    for n in range(a, b + 1):
        if 1 <= n <= 9:
            print(words[n])
        elif n % 2 == 0:
            print("even")
        else:
            print("odd")

if __name__ == '__main__':
    main()

