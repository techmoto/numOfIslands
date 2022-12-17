class Solution {
    
public:
    // returns the number of islands. What determines an island if vertex value '1' in the grid has edges
    // to another vertex '1'
    int numIslands(vector<vector<char>>& grid) {
        
        int numIslands = 0; // counter variable to sum the number of islands

        // rows = m , columns = n
        // using for loops to map a 2D grid
        for(int r = 0; r < grid.size(); r++){ // rows loop, iteration determined by vector(grid) size 
            for(int c = 0; c < grid[0].size(); c++){ // colmuns loop, iteration determined by vector(grid) size, *constraint n == grid[i].length
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
        
        queue<pair<int, int>> Q; // creates a new heterogeneous queue 
        vector<int> offsets({0, 1, 0, -1, 0}); // prevents from out of bounds
        
        Q.push({r,c}); // uses the for loop varibles r and c to add the value to the queue
        iGraph[r][c] = '0'; // reference value so it dosen't account for a second time 

        while (Q.size() != 0) {  // while the size of the queue is not empty
            pair<int, int> p = Q.front();  // creates a heterogeneous queue and sets it to the front of the queue 
            int i = p.first, j = p.second;  // .frist and .second stores in the pair p 
            Q.pop(); // removes the r and c value from the queue, so the loop is not continous
            for (int index = 0; index < offsets.size() - 1; index++) { // adjusting for out of bounds
                int RI = i + offsets[index], CI = j + offsets[index + 1]; // updates rows and columns to account for out of bounds
                // as long as the rows and columns is greater than 0 but less than the size of grid
                if (RI >= 0 && RI < iGraph.size() && CI >= 0 && CI < iGraph[0].size() && iGraph[RI][CI] == '1') {  //  *constraints n == grid[i].length and m == grid.length
                    Q.push(pair<int,int>(RI, CI)); // values are added to a new heterogeneous pair 
                    iGraph[RI][CI] = '0'; // reference the value to not count it for the second time
                }
            }
        }
    }
};
