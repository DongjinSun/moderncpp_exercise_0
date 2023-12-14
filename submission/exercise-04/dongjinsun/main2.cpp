#include <iostream>
#include <map>

int main() {
    int N;
    std::cin >> N;

    // 절댓값을 키로, 정수를 값으로 하는 std::map을 생성합니다
    std::multimap<int,int> m;
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        m.emplace(std::abs(x), x);
    }

    // std::map의 iterator를 사용하여 정렬된 정수를 출력합니다
    for (auto it = m.begin(); it != m.end(); it++) {
        std::cout << it->second << " ";
    }
    std::cout << std::endl;

    return 0;
}
