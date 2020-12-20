#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    vector<string> res;
    unordered_map<char, string> data;

    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return {};
        }
        data['2'] = "abc";
        data['3'] = "def";
        data['4'] = "ghi";
        data['5'] = "jkl";
        data['6'] = "mno";
        data['7'] = "pqrs";
        data['8'] = "tuv";
        data['9'] = "wxyz";


        recurse(digits, "");

        return res;
    }

    void recurse(string digits, string comb) {
        if (digits.length() == 0) {
            res.push_back(comb);
        } else {
            char digit = digits[0];

            for (auto ch : data[digit]) {
                std::cout << digits.substr(1) << std::endl;
                std::cout << comb + ch << std::endl;

                recurse(digits.substr(1), comb + ch);
            }
        }
    }
};
