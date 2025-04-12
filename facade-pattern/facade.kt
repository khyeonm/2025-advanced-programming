class CPU {
    fun process(): String {
        return "CPU 처리 중"
    }
}

class Memory {
    fun load(): String {
        return "메모리 로딩 중"
    }
}

class SSD {
    fun read(): String {
        return "SSD 드라이브 읽는 중"
    }
}

class Computer { // Facade 클래스
    private val cpu = CPU()
    private val memory = Memory()
    private val ssd = SSD()

    fun boot() {
        println(ssd.read())
        println(memory.load())
        println(cpu.process())
    }
}

fun main() {
    val c = Computer()
    c.boot()
}

// kotlinc facade.kt -include-runtime -d facade.jar
// java -jar facade.jar
