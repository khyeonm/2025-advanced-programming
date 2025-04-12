class InternalClass {
    fun fetch(): String {
        return "get user info"
    }
}

class ExternalClass {
    fun search(): String {
        return "get user info"
    }
}

class Adapter(private val external: ExternalClass) {
    fun fetch(): String {
        return external.search()
    }
}

fun main() {
    val ext = ExternalClass()
    val adapter = Adapter(ext)

    println(adapter.fetch())
}

// kotlinc adapter.kt -include-runtime -d adapter.jar
// java -jar adapter.jar
