#include "../stdc++.h"
using namespace std;

class TrieNode {
public:
    // 或用链表、map表示子节点
    TrieNode *children[26];
    // 标识该节点是否为单词结尾
    bool isWord;
    TrieNode() {
        // 分配内存
        memset(children, 0, sizeof(children));
        isWord = false;
    }
};

void insert(TrieNode *root, string word) {
    TrieNode *p = root;
    for (auto w : word) {
        if (p->children[w - 'a'] == NULL) {
            p->children[w - 'a'] = new TrieNode();
        }
        p = p->children[w - 'a'];
    }
    p->isWord = true;
}

bool startsWith(TrieNode *root, string prefix) {
    TrieNode *p = root;
    for (auto w : prefix) {
        if (p->children[w - 'a'] == NULL)
            return false;
        if (p->children[w - 'a']->isWord)
            return true;
        p = p->children[w - 'a'];
    }
    return p->isWord;
}

class StreamChecker {
public:
    TrieNode* trie;
    string queryLetter = "";
    StreamChecker(vector<string> &words) {
        trie = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            // 倒置字符串
            reverse(words[i].begin(), words[i].end());
            insert(trie, words[i]);
        }
    }

    bool query(char letter) {
        if ((int) queryLetter.size() >= 200) {
            // 移除最后一个字符串
            queryLetter.erase(queryLetter.size() - 1, 1);
        }
        queryLetter.insert(0, string(1, letter));
        return startsWith(trie, queryLetter);
    }
};