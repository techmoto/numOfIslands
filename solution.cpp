class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int numIslands = 0; // counter variable to sum the number of islands
        
        // using for loops to map a 2D grid
        for(int r = 0; r < grid.size(); r++){ // rows loop
            for(int c = 0; c < grid.size(); c++){ // colmuns loop
                if(grid[r][c] == '1'){
                    numIslands++;  // incremeants the number of islands
                    BFS(grid,r,c); // Breadth Search Algorithnm 
                }
            }
        }
        return numIslands;   
    }
private:
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
