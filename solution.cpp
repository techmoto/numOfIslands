class Solution {
    
public:
    // returns the number of islands. What determines an island if vertex value '1' in the grid has edges
    // to another vertex '1'
    int numIslands(vector<vector<char>>& grid) {
        
        int numIslands = 0; // counter variable to sum the number of islands
        
        // using for loops to map a 2D grid
        for(int r = 0; r < grid.size(); r++){ // rows loop, iteration determined by vector(grid) size 
            for(int c = 0; c < grid.size(); c++){ // colmuns loop, iteration determined by vector(grid) size 
                if(grid[r][c] == '1'){ // if vertex value of '1' has appeared in the gird
                    numIslands++;  // incremeants the number of islands
                    BFS(grid,r,c); // Breadth Search Algorithnm, checks for all vertices to see if it has edges
                }
            }
        }
        return numIslands; //once the for loops finish iterating, it will return the number of islands.
    }
 
private:
    // private helper function
    void BFS(vector<vector<char>> &iGraph, int r, int c) {
        queue<pair<int, int>> Q;
        Q.push({r,c});
        
       iGraph[r][c] = '0';
        
        while (!Q.empty()) {
            pair<int, int> p = Q.front();
                 Q.pop();
                 for (int k = 0; k < 4; k++) {
                      int i = p.first + offsets[k], j = p.second + offsets[k + 1];
                      if (i >= 0 && i < m && j >= 0 && j < n && grid[i][c] == '1') {
                          grid[i][j] = '0';
                          Q.push({i, j});
                }
            }
        }
    }
};
