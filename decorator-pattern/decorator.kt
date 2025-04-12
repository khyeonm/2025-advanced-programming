open class Coffee {
    open fun cost(): Int = 5
}

open class CoffeeDecorator(private val coffee: Coffee) : Coffee() {
    override fun cost(): Int = coffee.cost()
}

class MilkDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int = super.cost() + 2
}

class SugarDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int = super.cost() + 1
}

fun main() {
    val base = Coffee()
    println(base.cost())

    val withMilk = MilkDecorator(base)
    println(withMilk.cost())

    val withSugar = SugarDecorator(base)
    println(withSugar.cost())

    val withMilkAndSugar = SugarDecorator(withMilk)
    println(withMilkAndSugar.cost())
}

// kotlinc decorator.kt -include-runtime -d decorator.jar
// java -jar decorator.jar
