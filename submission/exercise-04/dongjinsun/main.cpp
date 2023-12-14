#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

constexpr int max_num(int a, int b) {
    int num = a % b;
    while (num != 0) {
        a = b;
        b = num;
        num = a % b;
    }
    return a / b;
}

int main() {
    vector<int> vect;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vect.push_back(a);
    }

    std::sort(vect.begin(),vect.end(), [](int a,int b) {
        return std::abs(a) > std::abs(b);
        });
    
    for (auto x : vect) {
        cout << x;
    }


    return 0;
}