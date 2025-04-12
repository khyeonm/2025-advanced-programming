abstract class Animal {
    abstract fun speak(): String
}

class Dog : Animal() {
    override fun speak() = "Woof!"
}

class Cat : Animal() {
    override fun speak() = "Meow!"
}

class AnimalFactory {
    fun createAnimal(animalType: String): Animal? {
        return when (animalType) {
            "dog" -> Dog()
            "cat" -> Cat()
            else -> null
        }
    }
}

fun main() {
    val factory = AnimalFactory()
    val dog = factory.createAnimal("dog")
    val cat = factory.createAnimal("cat")

    dog?.let { println(it.speak()) }
    cat?.let { println(it.speak()) }
}

// kotlinc factory.kt -include-runtime -d factory.jar
// java -jar factory.jar