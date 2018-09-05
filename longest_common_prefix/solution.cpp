#include <iostream>
#include <vector>
#include <ostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <iterator>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = strs[0].size();
        int no_of_strs = strs.size();
        int lcp_index = -1;
        char cur_char;
        bool stop = false;
        bool min_len_init = false;
        for (int i=0; i<min_len; i++) {
            cur_char = strs[0][i];
            for (int j=1; j<no_of_strs; j++) {
                if (strs[i].size() < min_len && !min_len_init) {
                    min_len = strs[i].size();
                }
                if (strs[j][i] != cur_char) {
                    stop = true;
                    break;
                }
            }
            min_len_init = true;
            if (!stop) {
                lcp_index = i;
            } else {
                break;
            }
        }
        if (lcp_index == -1) {
            return "";
        } else {
            return strs[0].substr(0, lcp_index+1);
        }
    }
};

int main() {
    class Solution s;
    vector<string> strs = { string("dog"), string("racecar"), string("car")};
    cout << "Longest Common prefix: : " << s.longestCommonPrefix(strs) << endl; 
    return 0;
}
