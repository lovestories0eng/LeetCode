#include "../stdc++.h"
using namespace std;

class Solution {
public:
    int directionX[4] = { 0, 1, 0, -1 };
    int directionY[4] = { 1, 0, -1, 0 };
    int sizeX, sizeY;
    int minValue;
    int thresold;
    vector<int> result;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return result;
        sizeX = matrix.size();
        sizeY = matrix[0].size();
        minValue = sizeX < sizeY ? sizeX : sizeY;
        thresold = minValue < 2 ? 0 : (minValue % 2 == 1 ? minValue / 2 : minValue / 2 - 1);
        recurse(matrix, 0);
        return result;
    }

    void recurse(vector<vector<int>>& matrix, int startPoint) {
        if (startPoint > thresold) return;

        if (startPoint == thresold) {
            if (startPoint * 2 + 1 == sizeX && startPoint * 2 + 1 == sizeY) {
                result.push_back(matrix[startPoint][startPoint]);
                return;
            } else if (startPoint * 2 + 1 == sizeX) {
                for (int i = startPoint; i <= sizeY - startPoint - 1; i++) {
                    result.push_back(matrix[startPoint][i]);
                }
                return;
            } else if (startPoint * 2 + 1 == sizeY) {
                for (int i = startPoint; i <= sizeX - startPoint - 1; i++) {
                    result.push_back(matrix[i][startPoint]);
                }
                return;
            }
        }

        int cordX = startPoint, cordY = startPoint;
        for (int i = 0; i < 4; i++) {
            int tmpX = directionX[i], tmpY = directionY[i];
            while(
                cordX >= startPoint 
                && cordX <= sizeX - startPoint - 1
                && cordY >= startPoint
                && cordY <= sizeY - startPoint - 1
            ) {
                result.push_back(matrix[cordX][cordY]);
                cordX += tmpX;
                cordY += tmpY;
            }
            cordX -= tmpX;
            cordY -= tmpY;
            if (i <= 2) {
                cordX += directionX[i + 1];
                cordY += directionY[i + 1];
            }
        }
        // 弹出多余元素
        result.pop_back();
        recurse(matrix, startPoint + 1);
    }
};