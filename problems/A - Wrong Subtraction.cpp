import java.util.Scanner

    fun main(args: Array<String>) {
        val sc = Scanner(System.`in`)
        var n = sc.nextInt()
        var k = sc.nextInt()
        while (k-- > 0) {
            if (n % 10 > 0)
                n--
            else
                n /= 10
        }
        println(n)
    }