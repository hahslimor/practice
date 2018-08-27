#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &a) {
    cout << "Array: ";
    for (auto &i: a) {
        cout << " " << i;
    }
    cout << "\n";
}

class Solution {
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        cout << "n : " << n << "\n";
        cout << "k : " << k << "\n";
        if (k == 0 || n == 0) {
            return;
        }
        for (int i=0; i<(n/k); i++) {
            int startpos = i*k;
            for (int j = 0; j<( k); j++) {
                cout << "Swapping : " << j+startpos << "  " << n- k+j << " ";
                swap(nums[j+startpos], nums[n- k+j]);
                print(nums);
            }
        }
    }
};


int main() {
    vector<int> test = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};

    class Solution s;
    print(test);
    s.rotate(test, 4);
    print(test);
}
