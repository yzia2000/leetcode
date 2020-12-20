#include <string>
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> zigVec(numRows);
        int i = 0;
        bool zagging = false;
        for (auto ch : s) {
            if (zagging) {
                i--;
                zigVec[i].push_back(ch);
                std::cout << i << " " << ch << " " << zigVec[i] << std::endl;
                if (i == 0) {
                    zagging = false;
                    i++;
                }
            } else {
                std::cout << i << " " << ch << " " << zigVec[i] << std::endl;
                zigVec[i].push_back(ch);
                i++;
                if (i == numRows) {
                    zagging = true;
                    i--;
                }
            }
        }

        string res;

        for (auto i : zigVec) {
            res.append(i);
        }

        return res;
    }
};
