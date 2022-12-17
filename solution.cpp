class Solution {
    
public:
    // returns the number of islands. What determines an island if vertex value '1' in the grid has edges
    // to another vertex '1'
    int numIslands(vector<vector<char>>& grid) {
        
        int numIslands = 0; // counter variable to sum the number of islands
        
        // using for loops to map a 2D grid
        for(int r = 0; r < grid.size(); r++){ // rows loop
            for(int c = 0; c < grid.size(); c++){ // colmuns loop
                if(grid[r][c] == '1'){
                    numIslands++;  // incremeants the number of islands
                    BFS(grid,r,c); // Breadth Search Algorithnm, checks for all vertices to see if it has edges
                }
            }
        }
        return numIslands; //once the for loops finish iterating, it will return the number of islands.
    }
 
private:
    // private helper function
    void BFS(int vtx, vector<vector<char>> &iGraph, int gSize) {
        queue<int> Q;
        int* visited;
        visited = new int[gSize] {0};

        visited[vtx] = 1;
        Q.emplace(vtx);

        while (!Q.empty()) {
            int next = Q.front();
            Q.pop();
            for (int v = 0; v < gSize; v++) {  
                if (iGraph[next][v] == '1' && visited[v] == 0) { 
                    visited[v] = 1;
                    Q.emplace(v);
                }
            }
        }
        delete[] visited;
    }
};
