#include <iostream>
#include <queue>
#include "../test_runner/test_runner.h"

class Solution {
public:
    void NewRottingOrange(std::pair<int,int> rotOrange, std::vector<std::vector<int>>& grid){
        int row = rotOrange.first;
        int column =  rotOrange.second;
        if ( row + 1 < grid.size()  && grid[row + 1][column ] == 1){
            rottingOrange.push({row+1, column});
            freshOrange.erase({row+1,column});
            grid[row + 1][column ] = 2;
        }
        if ( row - 1 < grid.size() && grid[row - 1][column ] == 1){
            rottingOrange.push({row-1, column});
            freshOrange.erase({row-1,column});
            grid[row - 1][column ] = 2;
        }

        if ( column + 1 < grid.at(0).size() && grid[row][column + 1] == 1){
            rottingOrange.push({row, column+1});
            freshOrange.erase({row,column+1});
            grid[row][column + 1] = 2;
        }

        if ( column -  1 >= 0 && grid[row][column - 1] == 1){
            rottingOrange.push({row, column-1});
            freshOrange.erase({row, column-1});
            grid[row][column - 1] = 2;
        }
    }

    int orangesRotting(std::vector<std::vector<int>>& grid) {
        size_t rows = grid.size();
        size_t columns = grid.at(0).size();
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j] == 2){
                    rottingOrange.push({i,j});
                } else if (grid[i][j] == 1){
                    freshOrange.insert({i,j});
                }
            }
        }
        if (rottingOrange.size() == 0 && freshOrange.size() > 0){
            return -1;
        } else if (freshOrange.size() == 0){
            return 0;
        }
        int step = 0;
        while (rottingOrange.size() > 0 && freshOrange.size() != 0){
            step++;
            int size_before = rottingOrange.size();
            for (int i = 0; i < size_before; ++i){
                NewRottingOrange(rottingOrange.front(),grid);
                rottingOrange.pop();
            }
        }
        if (freshOrange.size() == 0){
            return step;
        } else {
            return -1;
        }

    }

private:
    std::set<std::pair<int,int>> freshOrange;
    std::queue<std::pair<int,int>> rottingOrange;
};

void SimpleTest() {
    {
        Solution sl;
        std::vector<std::vector<int>> v = {{0, 1, 0},
                                           {0, 2, 0},
                                           {0, 0, 0}};

        ASSERT_EQUAL(sl.orangesRotting(v), 1);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v = {{0, 0, 0},
                                           {0, 2, 0},
                                           {1, 1, 1}};

        ASSERT_EQUAL(sl.orangesRotting(v), 2);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v = {{2,1,1},{1,1,0},{0,1,1}};

        ASSERT_EQUAL(sl.orangesRotting(v), 4);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v = {{2,1,1},{0,1,1},{1,0,1}};

        ASSERT_EQUAL(sl.orangesRotting(v), -1);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}


