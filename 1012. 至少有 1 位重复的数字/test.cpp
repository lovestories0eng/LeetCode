#include<iostream>
using namespace std;

int main() {

    cout << stoi("000222") << endl;
    cout << (int)'i' << " " << (int)'0' << " " << (int)('9' + 1) <<  endl;
    cout << (char)('0' - 1) << endl;
    cout << (1 << 10) << endl;
    cout << ( 0 | (1 << 0)) << endl;

    return 0;
}