#include <iostream>
#include <vector>
#include <ostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <iterator>

using namespace std;
class Solution {
    public int firstUniqChar(string s) {
            unordered_map<char, int> char_map;

            for (string::iterator i=s.begin(); i!=s.end(); ++i) {
                char_map[*i]++;
            }

            for (int i=0; i<s.size(); i++) {
                if (char_map[s[i]] == 1) {
                    return i;
                }
            }
            return -1;
        }
};

int main() {
    class Solution s;
    cout << "First unique char: " << s.firstUniqChar(string("rroommil")) << endl; 
    return 0;
}
