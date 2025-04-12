// 기존 객체에 새 기능을 추가할 때 상속 대신 객체를 감싸는 방식 사용
#include <iostream>
using namespace std;

class Coffee {
public:
    virtual int cost() {
        return 5;
    }

    virtual ~Coffee() {}
};

class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;

public:
    CoffeeDecorator(Coffee* c) : coffee(c) {}
    int cost() override {
        return coffee->cost();
    }
};

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* c) : CoffeeDecorator(c) {}

    int cost() override {
        return coffee->cost() + 2;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* c) : CoffeeDecorator(c) {}

    int cost() override {
        return coffee->cost() + 1;
    }
};

int main() {
    Coffee* base = new Coffee();
    cout << base->cost() << endl; 

    Coffee* milk = new MilkDecorator(base);
    cout << milk->cost() << endl; 

    Coffee* sugar = new SugarDecorator(base);
    cout << sugar->cost() << endl; 

    Coffee* milk_and_sugar = new SugarDecorator(milk);
    cout << milk_and_sugar->cost() << endl;

    delete base;
    delete milk;
    delete sugar;
    delete milk_and_sugar;

    return 0;
}

// g++ -O3 decorator.cpp -o decorator
// ./decorator