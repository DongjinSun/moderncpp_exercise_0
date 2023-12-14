#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

int main() {

    std::vector<int> vect;
    for (int i = 0; i < 10; i++) {
        int a;
        std::cin >> a;
        vect.push_back(a);
    }
    
    int a;
    cin >> a;
    ptrdiff_t distance = -1;
    auto iter = find(vect.begin(), vect.end(), a);

    
    if (iter != vect.end()) {
        distance = std::distance(vect.begin(), iter);
    }

    else {
        int minimum = 10000;        
        for (auto it = vect.begin(); it != vect.end(); it++) {
            if (((*it) > a) && (((*it) - a) < minimum )){
                distance = std::distance(vect.begin(), it);
                minimum = (*it - a);
            }
        }
    }
    cout << distance;
 



    //for_each(vect.begin(), vect.end(), [](int a) {cout << a; });

    // for(auto iter=vect.begin();iter=vect.last();iter++){
    //     cout >> 
    // }

    return 0;
}