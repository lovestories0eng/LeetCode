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
            // �жϳ����Ƿ����
            if (searchWord.length() == words[i].length()) {
                // �ж��Ƿ�ֻ��һ����ĸ����
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