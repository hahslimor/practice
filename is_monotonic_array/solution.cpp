#include <iostream>
#include <vector>
#include <ostream>
#include <limits>
#include <string>
#include <unordered_set>
#include <iterator>

using namespace std;
/**
 *  Monotonic array is an array which is either increasing, decreasing or equal (e.g. 1,2,3 ; 3, 2, 1, 1)
 */
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        size_t n = A.size();
        int last_seen;
        bool trend_init = false;
        int cur_trend = 2, running_trend = 2; // 0 - up; 1 - down; 2 - equal
        last_seen = A[0];
        for (size_t i=1; i<n; i++) {
            if (A[i] > last_seen) {
                cur_trend = 0;
            } else if (A[i] < last_seen) {
                cur_trend = 1;
            } else {
                cur_trend = 2;
            }
            last_seen = A[i];
            cout << " val : " << A[i] << " cur_trend " << cur_trend << " last_seen : " << last_seen << endl;
            if (!trend_init) {
                if (cur_trend == 0 || cur_trend == 1) {
                    trend_init = true;
                    running_trend = cur_trend;
                    cout << " val : " << A[i] << " running_trend " << running_trend << endl;
                }
                continue;
            }
            if (cur_trend == 2) {
                continue;
            }
            cout << " val : " << A[i] << " cur_trend : " << cur_trend << endl;
            if (cur_trend != running_trend) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    class Solution s;
    vector<int> arr = { 1, 3, 4 , 4};
    cout << "\nIs Monotonic : " << s.isMonotonic(arr) << endl;
    return 0;
}
