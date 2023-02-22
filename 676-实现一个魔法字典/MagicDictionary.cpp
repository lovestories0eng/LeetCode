#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

class MagicDictionary {
public:
    vector<string> words;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        words = dictionary;
    }
    
    bool search(string searchWord) {
        for (int i=0;i<words.size();i++) {
            // 判断长度是否相等
            if (searchWord.length() == words[i].length()) {
                // 判断是否只有一个字母不等
                int diff = 0;
                int len = searchWord.length();
                for (int j=0;j<len;j++) {
                    if (searchWord[j] != words[i][j]) {
                        diff++;
                        if (diff > 1) 
                            break;
                    }
                }
                if (diff == 1) {
                    return true;
                }
                if (diff == 0) {
                    continue;
                }
            } else {
                continue;
            }
        }
        return false;
    }
};

int main() {

    return 0;
}