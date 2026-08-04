import sys

def print_pattern():
    # Read the single integer input n
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    
    # Calculate the total size of the grid
    size = 2 * n - 1
    
    # Generate the pattern row by row
    for i in range(size):
        row = []
        for j in range(size):
            # Find the minimum distance to any of the 4 borders
            dist_top = i
            dist_left = j
            dist_bottom = (size - 1) - i
            dist_right = (size - 1) - j
            
            min_dist = min(dist_top, dist_left, dist_bottom, dist_right)
            
            # The value starts at n and decreases by the minimum distance
            val = n - min_dist
            row.append(str(val))
            
        # Print the row with numbers separated by a single space
        print(" ".join(row))

if __name__ == '__main__':
    print_pattern()
