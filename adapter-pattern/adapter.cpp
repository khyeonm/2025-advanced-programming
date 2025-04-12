// 클래스 간 함수 연결
#include <iostream>
#include <string>
using namespace std;

class InternalClass {
public:
    string fetch() {
        return "get user info";
    }
};

class ExternalClass {
public:
    string search() {
        return "get user info";
    }
};

// 어댑터 클래스
class Adapter {
private:
    ExternalClass* external;
public:
    Adapter(ExternalClass* ext) : external(ext) {}

    string fetch() {
        return external->search();
    }
};

int main() {
    ExternalClass ext;
    Adapter adapter(&ext);

    cout << adapter.fetch() << endl;

    return 0;
}

// g++ -O3 adapter.cpp -o adapter
// ./adapter