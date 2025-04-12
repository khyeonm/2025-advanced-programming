using System;

class InternalClass {
    public string Fetch() {
        return "get user info";
    }
}

class ExternalClass {
    public string Search() {
        return "get user info";
    }
}

class Adapter {
    private ExternalClass external;

    public Adapter(ExternalClass ext) {
        external = ext;
    }

    public string Fetch() {
        return external.Search();
    }
}

class Program {
    static void Main(string[] args) {
        ExternalClass ext = new ExternalClass();
        Adapter adapter = new Adapter(ext);

        Console.WriteLine(adapter.Fetch());
    }
}

// dotnet new console -n adapterApp --force
// mv adapter.cs adapterApp/Program.cs
// cd adapterApp
// dotnet run