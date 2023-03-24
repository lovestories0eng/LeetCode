#include "../stdc++.h"
using namespace std;

// 9935超时
class Solution {
public:
    // 求出n以tmpNum为前缀的所有情况
    int sumAll(int tmpNum, int n, int nDigits) {
        int tmpDigits = log10(tmpNum) + 1;
        int originDigits = tmpDigits, originNum = tmpNum;
        int result = 0;
        int tmp = 1;
        while(true) {
            if (tmpDigits < nDigits) {
                result += tmp;
                tmp *= 10;
            } else if (tmpDigits == nDigits) {
                if (tmpNum < n) {
                    int tmpCalc = (int) pow(10, nDigits - originDigits), prefix = n / tmpCalc;
                    if (prefix - originNum >= 1) result += tmp;
                    else result += n % tmpCalc + 1;
                } else if (tmpNum == n) { 
                    result += 1; break;
                } 
                else break;
            } else break;
            tmpNum *= 10; tmpDigits++;
        }
        return result;
    }

    int numDupDigitsAtMostN(int n) {
        int ans = 0;
        int digits = log10(n) + 1;
        set<string> foundPrefix;
        function<void(string& str, int& ans, int& n)> dfs = [&] (string& str, int& ans, int& n) -> void {
            // 如果遍历过了则去除
            for (auto it = foundPrefix.begin(); it != foundPrefix.end(); ++it) {
                if (it->size() <= str.size()) {
                    if (str.substr(0, it->size()) == *it) return;
                }
            }
            int tmpNum = stoi(str);
            if (tmpNum > n) return;
            string tmpStr = str;
            int preSize = foundPrefix.size();
            if (str.size() > 1) {
                for (int i = 0; i < str.size() - 1; i++) {
                    if (str[str.size() - 1] == str[i]) {
                        ans += sumAll(tmpNum, n, digits);
                        foundPrefix.insert(str);
                        // cout << str << " " << sumAll(tmpNum, n, digits) << endl;
                        break;
                    }
                }
            }

            // 第一种情况：n = n + 1
            str = to_string(tmpNum + 1);
            dfs(str, ans, n);

            // 第二种情况：n = n * 10
            str = tmpStr + '0';
            dfs(str, ans, n);
        };

        string str = "1";
        dfs(str, ans, n);
        return ans;
    }
};


int main() {
    Solution solution;
    solution.numDupDigitsAtMostN(99350);
    return 0;
}

// g++ -std=c++11 your_file_name.cpp -o your_executable_name
