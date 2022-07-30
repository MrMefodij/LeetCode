#include <iostream>
#include <vector>
#include "../test_runner/test_runner.h"
class Solution {
public:
    std::vector<std::vector<int>> floodFill_was(std::vector<std::vector<int>> &image, int sr, int sc, int color, int color_was) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image.at(sr).size() || image.at(sr).at(sc) == color || image.at(sr).at(sc) != color_was) {
            return image;
        }
        image[sr][sc] = color;
        if (sr - 1 >= 0)
            floodFill_was(image,sr-1,sc,color,color_was);
        if (sr + 1 < image.size())
            floodFill_was(image,sr+1,sc,color,color_was);
        if (sc - 1 >= 0)
         floodFill_was(image,sr,sc-1,color,color_was);
        if (sc + 1 < image.at(sr).size())
            floodFill_was(image,sr,sc+1,color,color_was);
        return image;
    }
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image, int sr, int sc, int color) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image.at(sr).size() || image.at(sr).at(sc) == color ) {
            return image;
        }
        int color_was = image[sr][sc];
        if (sr - 1 >= 0)
            floodFill_was(image,sr-1,sc,color,color_was);
        if (sr + 1 < image.size())
            floodFill_was(image,sr+1,sc,color,color_was);
        if (sc - 1 >= 0)
            floodFill_was(image,sr,sc-1,color,color_was);
        if (sc + 1 < image.at(sr).size())
            floodFill_was(image,sr,sc+1,color,color_was);
        return image;
    }
};

void SimpleTest(){
    {
//        Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
//        Output: [[2,2,2],[2,2,0],[2,0,1]]
        Solution sl;
        std::vector<std::vector<int>> image = {{1,1,1},
                                               {1,1,0},
                                               {1,0,1}};
        std::vector<std::vector<int>> result = {{2,2,2},
                                               {2,2,0},
                                               {2,0,1}};
        ASSERT_EQUAL(sl.floodFill(image,1,1,2), result);
    }
    {
//        Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
//Output: [[0,0,0],[0,0,0]]
        Solution sl;
        std::vector<std::vector<int>> image = {{0,0,0},
                                               {0,0,0}};
        std::vector<std::vector<int>> result = {{0,0,0},
                                                {0,0,0}};
        ASSERT_EQUAL(sl.floodFill(image,0,0,0), result);
    }
};

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
