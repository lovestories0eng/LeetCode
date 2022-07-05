#include<vector>
#include<map>
using namespace std;

class MyCalendar {
    map<int, int> mp;
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        // ��ʾmp�ļ��� �� start��һ����С��ֵ
        auto temp = mp.lower_bound(start);
        // ������������Ұ벿��
        if (temp != mp.end()) {
            if (end > temp->first) 
                return false;
        }
        // �������������벿��
        if (temp != mp.begin()) {
            temp--;
            if (temp->second > start)
                return false;
        }
        mp[start] = end;
        return true;
    }
};