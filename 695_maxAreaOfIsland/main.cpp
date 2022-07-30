#include <iostream>
#include "../test_runner/test_runner.h"

class Solution {
public:
    void checkIsland(std::vector<std::vector<int>> &grid, int sr, int sc, int &area) {
        if (sr < 0 || sc < 0 || sr >= grid.size() || sc >= grid.at(sr).size() || grid.at(sr).at(sc) == 0) {
            return;
        }
        area++;
        grid[sr][sc] = 0;
        if (sr - 1 >= 0)
            checkIsland(grid,sr-1,sc,area);
        if (sr + 1 < grid.size())
            checkIsland(grid,sr+1,sc,area);
        if (sc - 1 >= 0)
            checkIsland(grid,sr,sc-1,area);
        if (sc + 1 < grid.at(sr).size())
            checkIsland(grid,sr,sc+1,area);
    }

    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.at(i).size(); ++j){
                int area = 0;
                if ( grid.at(i).at(j) == 1){
                    area++;
                    grid[i][j] = 0;
                    if (i - 1 >= 0)
                        checkIsland(grid,i-1,j,area);
                    if (i + 1 < grid.size())
                        checkIsland(grid,i+1,j,area);
                    if (j - 1 >= 0)
                        checkIsland(grid,i,j-1,area);
                    if (j + 1 < grid.at(i).size())
                        checkIsland(grid,i,j+1,area);
                }
                if (area > maxArea){
                    maxArea = area;
                }
            }
        }
        return maxArea;
    }
private:
    int maxArea = 0;
};

void SimpleTest(){
    {
        Solution sl;
        std::vector<std::vector<int>> v = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                              {0,0,0,0,0,0,0,1,1,1,0,0,0},
                              {0,1,1,0,1,0,0,0,0,0,0,0,0},
                              {0,1,0,0,1,1,0,0,1,0,1,0,0},
                              {0,1,0,0,1,1,0,0,1,1,1,0,0},
                              {0,0,0,0,0,0,0,0,0,0,1,0,0},
                              {0,0,0,0,0,0,0,1,1,1,0,0,0},
                              {0,0,0,0,0,0,0,1,1,0,0,0,0}};
        ASSERT_EQUAL( sl.maxAreaOfIsland(v), 6);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v = {{0,0,0,0,0,0,0,0}};
        ASSERT_EQUAL( sl.maxAreaOfIsland(v), 0);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
