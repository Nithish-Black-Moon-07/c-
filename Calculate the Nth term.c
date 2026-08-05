import sys

def find_nth_term(n, a, b, c):
    # Base cases
    if n == 1:
        return a
    if n == 2:
        return b
    if n == 3:
        return c
    
    # Recursive step
    return find_nth_term(n - 1, a, b, c) + find_nth_term(n - 2, a, b, c) + find_nth_term(n - 3, a, b, c)

if __name__ == '__main__':
    # Read all inputs from standard input
    input_data = sys.stdin.read().split()
    
    if input_data:
        n = int(input_data[0])
        a = int(input_data[1])
        b = int(input_data[2])
        c = int(input_data[3])
        
        # Calculate and print the result
        result = find_nth_term(n, a, b, c)
        print(result)
