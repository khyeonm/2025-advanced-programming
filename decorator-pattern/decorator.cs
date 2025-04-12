using System;

class Coffee {
    public virtual int Cost() {
        return 5;
    }
}

class CoffeeDecorator : Coffee {
    protected Coffee coffee;

    public CoffeeDecorator(Coffee c) {
        coffee = c;
    }

    public override int Cost() {
        return coffee.Cost();
    }
}

class MilkDecorator : CoffeeDecorator {
    public MilkDecorator(Coffee c) : base(c) { }

    public override int Cost() {
        return coffee.Cost() + 2;
    }
}

class SugarDecorator : CoffeeDecorator {
    public SugarDecorator(Coffee c) : base(c) { }

    public override int Cost() {
        return coffee.Cost() + 1;
    }
}

class Program {
    static void Main(string[] args) {
        Coffee baseCoffee = new Coffee();
        Console.WriteLine(baseCoffee.Cost()); 

        Coffee withMilk = new MilkDecorator(baseCoffee);
        Console.WriteLine(withMilk.Cost()); 

        Coffee withSugar = new SugarDecorator(baseCoffee);
        Console.WriteLine(withSugar.Cost()); 

        Coffee withMilkAndSugar = new SugarDecorator(withMilk);
        Console.WriteLine(withMilkAndSugar.Cost()); 
    }
}

// dotnet new console -n decoratorApp --force
// mv decorator.cs decoratorApp/Program.cs
// cd decoratorApp
// dotnet run
