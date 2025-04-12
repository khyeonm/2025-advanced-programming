// 여러개의 클래스를 하나의 클래스로 통합
#include <iostream>
using namespace std;

class CPU {
public:
    string process() {
        return "CPU 처리 중";
    }
};

class Memory {
public:
    string load() {
        return "메모리 로딩 중";
    }
};

class SSD {
public:
    string read() {
        return "SSD 드라이브 읽는 중";
    }
};

class Computer { // Facade 클래스
private:
    CPU cpu;
    Memory memory;
    SSD ssd;

public:
    void boot() {
        cout << ssd.read() << endl;
        cout << memory.load() << endl;
        cout << cpu.process() << endl;
    }
};

int main() {
    Computer c;
    c.boot();
    return 0;
}

// g++ -O3 facade.cpp -o facade
// ./facade