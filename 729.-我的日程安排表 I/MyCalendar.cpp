#include<vector>
#include<map>
using namespace std;

class MyCalendar {
    map<int, int> mp;
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        // 表示mp的键是 ≥ start的一个最小键值
        auto temp = mp.lower_bound(start);
        // 检测相邻区间右半部分
        if (temp != mp.end()) {
            if (end > temp->first) 
                return false;
        }
        // 检测相邻区间左半部分
        if (temp != mp.begin()) {
            temp--;
            if (temp->second > start)
                return false;
        }
        mp[start] = end;
        return true;
    }
};