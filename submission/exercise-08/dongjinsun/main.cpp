
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class MyApplication {
    public:
    MyApplication(){
        cout << __PRETTY_FUNCTION__ << endl;
    } //기본생성자
    MyApplication(const MyApplication & other){
        cout << __PRETTY_FUNCTION__ << endl;
    } // 복사 생성자
    MyApplication& operator=(const MyApplication& other){
        cout << __PRETTY_FUNCTION__ << endl;
        return *this;
    } // 복사 대입 생성자
    MyApplication(MyApplication &&other) noexcept{
        cout << __PRETTY_FUNCTION__ << endl;
    } // 이동 생성자
    MyApplication& operator=(MyApplication&& other) noexcept{
        cout << __PRETTY_FUNCTION__ << endl;
        return *this;
    } // 이동 대입 연산자
    ~MyApplication(){ // 소멸자
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main() {
    MyApplication a;

    MyApplication b = a;

    return 0;
}