#include "../stdc++.h"
using namespace std;

// TODO：AC自动机
// https://oi-wiki.org/string/ac-automaton/
// https://blog.csdn.net/bestsort/article/details/82947639

typedef struct TrieNode {
    vector<TrieNode *> children;
    // 表示当前节点是否为一个单词的结尾
    // 当自己或者自己的某一后缀能匹配字符串数组的某个字符串时为 true
    bool isEnd;
    // 失配节点，指向当前节点的最长后缀所对应的节点
    TrieNode *fail;
    TrieNode() {
        this->children = vector<TrieNode *>(26, nullptr);
        this->isEnd = false;
        this->fail = nullptr;
    }
};

class StreamChecker {
public:
    TrieNode *root;
    TrieNode *temp;
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        // 构造trie树
        for (string &word : words) {
            TrieNode *cur = root;
            for (int i = 0; i < word.size(); i++) {
                int index = word[i] - 'a';
                if (cur->children[index] == nullptr) {
                    cur->children[index] = new TrieNode();
                }
                cur = cur->children[index];
            }
            cur->isEnd = true;
        }
        root->fail = root;
        queue<TrieNode *> q;
        for (int i = 0; i < 26; i++) {
            if(root->children[i] != nullptr) {
                // root下面的第一层结点默认指向root
                root->children[i]->fail = root;
                q.emplace(root->children[i]);
            } else {
                // 如果该节点对应的孩子没有字母，则也默认指向根节点
                root->children[i] = root;
            }
        }
        while (!q.empty()) {
            // 返回对队列第一个元素的引用。 对队列执行 pop 操作后，该元素将被删除
            TrieNode *node = q.front();
            q.pop();
            node->isEnd = node->isEnd || node->fail->isEnd;
            for (int i = 0; i < 26; i++) {
                // 思想类似于动态规划
                // 当前的最大前缀，其实就是看当前节点的失配指针fail(p, c)
                if(node->children[i] != nullptr) {
                    // node->fail->children[i]实际上就是root，如果node->fail->children[i]是null的话
                    node->children[i]->fail = node->fail->children[i];
                    q.emplace(node->children[i]);
                } else {
                    /*
                      当节点 p 的依靠字符 c 指向的子节点 u 为空时，将其指向 p.fail 依靠字符 c 指向的子节点 v，
                      这种类似于路径压缩的思路，使得每个空子节点最终都会指向一个非空节点，从而省去了在失配链路上不停考察的过程。
                    */
                    node->children[i] = node->fail->children[i];
                }
            }
            /*
              bfs算法遍历
              在当前层遍历完之后的状态：
            */
        }

        temp = root;
    }
    
    bool query(char letter) {
        // 会通过失配指针指回去
        temp = temp->children[letter - 'a'];
        return temp->isEnd;
    }
};