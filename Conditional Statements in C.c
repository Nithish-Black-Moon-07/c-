import sys

def main():
    # Read the integer input from standard input
    n = int(sys.stdin.read().strip())
    
    # List mapping indices 1 to 9 to their lowercase English words
    words = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    
    # Check the constraints and print the appropriate output
    if 1 <= n <= 9:
        print(words[n - 1])
    else:
        print("Greater than 9")

if __name__ == '__main__':
    main()
