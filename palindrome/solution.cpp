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
    bool isPalindrome(string s) {
        int n = s.size();
        int j=n-1;
        for (int i=0; i<n/2; i++) {
            while (!isalnum(s[i]) && i < j) {
                cout << " " << s[i] << " invalid char" << endl;
                i++;
            }
            if (i == n && j == (n-1)) {
                return true;
            }
            if (i == j) {
                cout << " i == j " << endl;
                return true;
            }
            cout << "Left : " << i << " " << s[i] << endl;
            while (j > i && !isalnum(s[j])) {
                cout << " " << s[j] << " invalid char" << endl;
                j--;
            }
            if (j < i) {
                cout << " j < i " << j << " " << i << endl;
                return true;
            }
            cout << "Right: " << j << " " << s[j] << endl;

            if (tolower(s[i]) != tolower(s[j])) {
                cout << s[i] << " " << s[j] << endl;
                return false;
            }
            j--;
         }
        return true;
    }
};

int main() {
    class Solution s;
    cout << "Palindrome : " << s.isPalindrome(string("A man, a plan, a canal: Panama")) << endl; 
    cout << "Palindrome : " << s.isPalindrome(string("0P")) << endl; 
    cout << "Palindrome : " << s.isPalindrome(string("Never a foot too far, even.")) << endl; 
    cout << "Palindrome : " << s.isPalindrome(string("Live on evasions? No, I save no evil.")) << endl; 
    cout << "Palindrome : " << s.isPalindrome(string(".a")) << endl; 
    return 0;
}
