class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0|| grid[0].size() == 0){
            return 0;
        }
        int numIslands = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; i < grid.size(); j++){
                if('1' == grid[i][j]){
                numIslands++;
                BFS(1,grid,i);
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
