using namespace std;

#include <string>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    static bool wordPattern(string pattern, string s) {
        unordered_map<char, string> record1;
        unordered_map<string, char> record2;
        int i = 0, pi = 0;
        while (i < s.length()) {
            int start = i, end = i;
            do {
                ++end;
            } while (end < s.length() && s[end] != ' ');
            string temp = s.substr(start, end-start);
            if (record1.find(pattern[pi]) == record1.end()) {
                record1[pattern[pi]] = temp;
            } else {
                if (record1[pattern[pi]] != temp) {
                    return false;
                } 
            }
            if (record2.find(temp) == record2.end()) {
                record2[temp] = pattern[pi];
            } else {
                if (record2[temp] != pattern[pi]) {
                    return false;
                } 
            }
            i = end+1;
            ++pi;
        }
        return pi==pattern.length();
        
    }
};

int main(int argc, char *argv[]) {
    string pattern = "ab";
    string s = "dog dog";
    cout << Solution::wordPattern(pattern, s) << endl;
    return 0;
}