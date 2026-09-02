void dfs(char** board, int r, int c, int rows, int cols) {
    // Check boundary conditions and if the cell is 'O'
    if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O') {
        return;
    }
    
    // Mark as visited/safe
    board[r][c] = 'T';
    
    // Explore all 4 neighbors
    dfs(board, r + 1, c, rows, cols);
    dfs(board, r - 1, c, rows, cols);
    dfs(board, r, c + 1, rows, cols);
    dfs(board, r, c - 1, rows, cols);
}

void solve(char** board, int boardSize, int* boardColSize) {
    if (boardSize == 0 || boardColSize[0] == 0) return;
    
    int rows = boardSize;
    int cols = boardColSize[0];
    
    // Step 1: Run DFS from the left and right borders
    for (int i = 0; i < rows; i++) {
        dfs(board, i, 0, rows, cols);
        dfs(board, i, cols - 1, rows, cols);
    }
    
    // Step 2: Run DFS from the top and bottom borders
    for (int j = 0; j < cols; j++) {
        dfs(board, 0, j, rows, cols);
        dfs(board, rows - 1, j, rows, cols);
    }
    
    // Step 3: Flip 'O' to 'X' and restore 'T' to 'O'
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'T') {
                board[i][j] = 'O';
            }
        }
    }
}
