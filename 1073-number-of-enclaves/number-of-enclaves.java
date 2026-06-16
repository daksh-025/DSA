class Solution {
    private static final int[][] DIRS = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    private static final int WATER = 0;
    private static final int LAND = 1;
    
    public int numEnclaves(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        
        for (int c = 0; c < cols; c++) {
            sink(grid, 0, c);
            sink(grid, rows - 1, c);
        }
        
        for (int r = 0; r < rows; r++) {
            sink(grid, r, 0);
            sink(grid, r, cols - 1);
        }
        
        return countLand(grid);
    }
    
    private void sink(int[][] grid, int sr, int sc) {
        if (grid[sr][sc] == WATER) return;
        
        Deque<Point> stack = new ArrayDeque<>();
        stack.push(new Point(sr, sc));
        grid[sr][sc] = WATER;
        
        while (!stack.isEmpty()) {
            Point p = stack.pop();
            
            for (int[] dir : DIRS) {
                int r = p.r + dir[0];
                int c = p.c + dir[1];
                
                if (isSafe(grid, r, c)) {
                    grid[r][c] = WATER;
                    stack.push(new Point(r, c));
                }
            }
        }
    }
    
    private boolean isSafe(int[][] grid, int r, int c) {
        return r >= 0 && r < grid.length && c >= 0 && c < grid[0].length && grid[r][c] == LAND;
    }
    
    private int countLand(int[][] grid) {
        int count = 0;
        for (int r = 1; r < grid.length; r++) {
            for (int c = 1; c < grid[0].length; c++) {
                if (grid[r][c] == LAND) count++;
            }
        }
        return count;
    }
    
    private static class Point {
        final int r, c;
        Point(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
}