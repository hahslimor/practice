#include <iostream>
#include <vector>
#include <ostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Swap rows
        int no_of_rows = matrix.size();
        int no_of_cols = matrix[0].size();
        int temp;
        for (int i=0; i<matrix.size()/2; i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[no_of_rows - i - 1][j];
                matrix[no_of_rows - i - 1][j] = temp;
            }
        }

        //swap diagnoal
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<i; j++) {
                if (i != j ) {
                    temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }
    }
};

int main() {
    class Solution s;
    vector<vector<int>> test;
    test = {{1,2,3,4}, {5,6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    s.rotate(test);
    for (auto i : test) {
        for (auto j: i) {
            cout << " " << j ;
        }
    }
    return 0;
}
