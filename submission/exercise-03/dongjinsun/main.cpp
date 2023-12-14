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
    constexpr int a = 270;
    constexpr int b = 192;

    cout << max_num(a, b);

    return 0;
}