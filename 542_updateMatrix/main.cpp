#include <iostream>
#include "../test_runner/test_runner.h"

class Solution {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
        int m = mat.size();
        int n = mat.at(0).size();
        if (m == 1 &&  std::find(mat.at(0).begin(), mat.at(0).end(),0) == mat.at(0).end() - 1){
            for (int i = 0; i < n; ++i) {
                mat[0][i] = mat.at(0).size() - i - 1;
            }
        } else {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (mat[i][j] != 0) {
                        bool found = false;
                        for (int k = 0; k <= m + n && !found; ++k){
                            for ( int deltaI = 0; deltaI <= k && !found; deltaI++){
                                int deltaJ = k - deltaI;

                                if ((i+deltaI < m) && (j+deltaJ < n) && mat[i+deltaI][j + deltaJ] == 0){
                                    found = true;
                                    mat[i][j] = k;
                                    //std::cout << i+deltaI << " "<< j+deltaJ<< std::endl;
                                    break;
                                }
                                if ((i+deltaI < m) && (j - deltaJ >= 0) && mat[i+deltaI][j - deltaJ] == 0){
                                    found = true;
                                    mat[i][j] = k;
                                    //std::cout << i+deltaI << " "<< j-deltaJ<< std::endl;
                                    break;
                                }
                                if ((i-deltaI >= 0) && (j+deltaJ < n) && mat[i-deltaI][j + deltaJ] == 0){
                                    found = true;
                                    mat[i][j] = k;
                                    //std::cout << i-deltaI << " "<< j+deltaJ<< std::endl;
                                    break;
                                }
                                if ((i-deltaI >=0) && (j-deltaJ >= 0) && mat[i-deltaI][j - deltaJ] == 0){
                                    //std::cout << i- deltaI << " "<< j - deltaJ<< std::endl;
                                    found = true;
                                    mat[i][j] = k;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }

        return mat;
    }
};

void SimpleTest() {
    {
        Solution sl;
        std::vector<std::vector<int>> v = {{0,0,0},{0,1,0},{0,0,0}};
        std::vector<std::vector<int>> result = {{0,0,0},{0,1,0},{0,0,0}};

        ASSERT_EQUAL(sl.updateMatrix(v),result);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v = {{0,0,0},{0,1,0},{1,1,1}};
        std::vector<std::vector<int>> result = {{0,0,0},{0,1,0},{1,2,1}};

        ASSERT_EQUAL(sl.updateMatrix(v),result);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v = {{0},{0},{0},{0},{0}};
        std::vector<std::vector<int>> result = {{0},{0},{0},{0},{0}};

        ASSERT_EQUAL(sl.updateMatrix(v),result);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v = {{1,1,0,0,1,0,0,1,1,0},
                                           {1,0,0,1,0,1,1,1,1,1},
                                           {1,1,1,0,0,1,1,1,1,0},
                                           {0,1,1,1,0,1,1,1,1,1},
                                           {0,0,1,1,1,1,1,1,1,0},
                                           {1,1,1,1,1,1,0,1,1,1},
                                           {0,1,1,1,1,1,1,0,0,1},
                                           {1,1,1,1,1,0,0,1,1,1},
                                           {0,1,0,1,1,0,1,1,1,1},
                                           {1,1,1,0,1,0,1,1,1,1}};
        std::vector<std::vector<int>> result = {{2,1,0,0,1,0,0,1,1,0},
                                                {1,0,0,1,0,1,1,2,2,1},
                                                {1,1,1,0,0,1,2,2,1,0},
                                                {0,1,2,1,0,1,2,3,2,1},
                                                {0,0,1,2,1,2,1,2,1,0},
                                                {1,1,2,3,2,1,0,1,1,1},
                                                {0,1,2,3,2,1,1,0,0,1},
                                                {1,2,1,2,1,0,0,1,1,2},
                                                {0,1,0,1,1,0,1,2,2,3},
                                                {1,2,1,0,1,0,1,2,3,4}};

        ASSERT_EQUAL(sl.updateMatrix(v),result);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}

