using System;

class Calculator {
    private double result = 0;

    public Calculator Add(double value) {
        result += value;
        return this;
    }

    public Calculator Subtract(double value) {
        result -= value;
        return this;
    }

    public Calculator Multiply(double value) {
        result *= value;
        return this;
    }

    public Calculator Divide(double value) {
        if (value != 0) result /= value;
        return this;
    }

    public double GetResult() {
        return result;
    }

    public static void Main(string[] args) {
        Calculator calc = new Calculator();
        double result = calc.Add(5).Multiply(2).Subtract(3).Divide(2).GetResult();
        Console.WriteLine("Result: " + result);
    }
}

// dotnet new console -n methodApp --force
// mv method.cs methodApp/Program.cs
// cd methodApp
// dotnet run