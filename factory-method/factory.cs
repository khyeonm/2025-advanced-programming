using System;

abstract class Animal {
    public abstract string Speak();
}

class Dog : Animal {
    public override string Speak() {
        return "Woof!";
    }
}

class Cat : Animal {
    public override string Speak() {
        return "Meow!";
    }
}

class AnimalFactory {
    public Animal CreateAnimal(string animalType) {
        if (animalType == "dog") return new Dog();
        else if (animalType == "cat") return new Cat();
        throw new ArgumentException("Unknown animal type");
    }
}

class Program {
    static void Main(string[] args) {
        AnimalFactory factory = new AnimalFactory();
        Animal dog = factory.CreateAnimal("dog");
        Animal cat = factory.CreateAnimal("cat");

        if (dog != null) Console.WriteLine(dog.Speak());
        if (cat != null) Console.WriteLine(cat.Speak());
    }
}

// 실행 코드
// dotnet new console -n factoryApp --force
// mv factory.cs factoryApp/Program.cs
// cd factoryApp
// dotnet run