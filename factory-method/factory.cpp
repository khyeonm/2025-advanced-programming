// 객체 생성을 서브클래스에 위임
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Animal {
public:
    virtual string speak() const = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    string speak() const override {
        return "Woof!";
    }
};

class Cat : public Animal {
public:
    string speak() const override {
        return "Meow!";
    }
};

class AnimalFactory {
public:
    unique_ptr<Animal> createAnimal(const string& animalType) {
        if (animalType == "dog") {
            return make_unique<Dog>();
        } else if (animalType == "cat") {
            return make_unique<Cat>();
        }
        return nullptr;
    }
};

int main() {
    AnimalFactory factory;
    auto dog = factory.createAnimal("dog");
    auto cat = factory.createAnimal("cat");

    if (dog) cout << dog->speak() << endl;
    if (cat) cout << cat->speak() << endl;

    return 0;
}

// 실행 코드
// g++ -O3 factory.cpp -o factory
// ./factory