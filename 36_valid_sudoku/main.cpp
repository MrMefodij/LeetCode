#include <iostream>
#include <vector>
#include <set>
#include <array>
#include "test_runner.h"

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::array<std::set<int>,9> cubes;
        std::array<int,9> count_cubes = {0,0,0,0,0,0,0,0,0};
        for (int i=0; i<board.size(); i++){
            std::set<int> row;
            int count_row = 0;

            std::set<int> column;
            int count_column = 0;

            for (int j = 0; j < 9; ++j) {
                if (board.at(i).at(j) != '.'){
                    row.insert(board.at(i).at(j));
                    count_row ++;
                }

                if (board.at(j).at(i) != '.'){
                    column.insert(board.at(j).at(i));
                    count_column++;
                }
                
                if (board.at(i).at(j) != '.') {
                    //std::cout<<i<<' '<<j<< ' ' <<board.at(i).at(j)<<std::endl;
                    if (i < 3) {
                        if (j < 3) {
                            cubes[0].insert(board.at(i).at(j));
                            count_cubes[0]++;
                        } else if (j < 6) {
                            cubes[1].insert(board.at(i).at(j));
                            count_cubes[1]++;
                        } else if (j < 9) {
                            cubes[2].insert(board.at(i).at(j));
                            count_cubes[2]++;
                        }
                    } else if (i < 6) {
                        if (j < 3) {
                            cubes[3].insert(board.at(i).at(j));
                            count_cubes[3]++;
                        } else if (j < 6) {
                            cubes[4].insert(board.at(i).at(j));
                            count_cubes[4]++;
                        } else if (j < 9) {
                            cubes[5].insert(board.at(i).at(j));
                            count_cubes[5]++;
                        }
                    } else if (i < 9) {
                        if (j < 3) {
                            cubes[6].insert(board.at(i).at(j));
                            count_cubes[6]++;
                        } else if (j < 6) {
                            cubes[7].insert(board.at(i).at(j));
                            count_cubes[7]++;
                        } else if (j < 9) {
                            cubes[8].insert(board.at(i).at(j));
                            count_cubes[8]++;
                        }
                    }
                }
                for (int k = 0; k < 9; ++k) {
                    if (cubes[k].size() != count_cubes[k]){
                        //std::cout<<k<<' '<< cubes[k].size() << ' ' <<count_cubes[k]<<std::endl;
                        return false;
                    }
                }

                if (row.size() != count_row || column.size() != count_column){
                    return false;
                }
            }
        }
        return true;
    }
};

void SimpleTest(){
    {
        Solution sl;
        std::vector<std::vector<char>> v1 =
                {{'5','3','.','.','7','.','.','.','.'}
                ,{'6','.','.','1','9','5','.','.','.'}
                ,{'.','9','8','.','.','.','.','6','.'}
                ,{'8','.','.','.','6','.','.','.','3'}
                ,{'4','.','.','8','.','3','.','.','1'}
                ,{'7','.','.','.','2','.','.','.','6'}
                ,{'.','6','.','.','.','.','2','8','.'}
                ,{'.','.','.','4','1','9','.','.','5'}
                ,{'.','.','.','.','8','.','.','7','9'}};

        ASSERT_EQUAL(sl.isValidSudoku(v1), true);
    }

    {
        Solution sl;
        std::vector<std::vector<char>> v1 =
                {{'8','3','.','.','7','.','.','.','.'}
                ,{'6','.','.','1','9','5','.','.','.'}
                ,{'.','9','8','.','.','.','.','6','.'}
                ,{'8','.','.','.','6','.','.','.','3'}
                ,{'4','.','.','8','.','3','.','.','1'}
                ,{'7','.','.','.','2','.','.','.','6'}
                ,{'.','6','.','.','.','.','2','8','.'}
                ,{'.','.','.','4','1','9','.','.','5'}
                ,{'.','.','.','.','8','.','.','7','9'}};

        ASSERT_EQUAL(sl.isValidSudoku(v1), false);
    }
    {
        Solution sl;
        std::vector<std::vector<char>> v1 =
                        {{'5','3','.','.','7','.','.','.','.'}
                        ,{'6','5','.','1','9','2','.','.','.'}
                        ,{'.','9','8','.','.','.','.','6','.'}
                        ,{'8','.','.','.','6','.','.','.','3'}
                        ,{'4','.','.','8','.','3','.','.','1'}
                        ,{'7','.','.','.','2','.','.','.','6'}
                        ,{'.','6','.','.','.','.','2','8','.'}
                        ,{'.','.','.','4','1','9','.','.','5'}
                        ,{'.','.','.','.','8','.','.','7','9'}};

        ASSERT_EQUAL(sl.isValidSudoku(v1), false);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr,SimpleTest);
    return 0;
}