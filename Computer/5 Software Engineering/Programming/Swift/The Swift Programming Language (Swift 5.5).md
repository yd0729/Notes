[TOC]

# Welcome to Swift / 欢迎使用 Swift

# About Swift / 关于 Swift

Swift 是一种非常好的编写软件的方式，无论是手机，台式机，服务器，还是其他运行代码的设备。它是一种安全，快速和互动的编程语言，将现代编程语言的精华和苹果工程师文化的智慧，以及来自开源社区的多样化贡献结合了起来。编译器对性能进行了优化，编程语言对开发进行了优化，两者互不干扰，鱼与熊掌兼得。

Swift 对于初学者来说也很友好。它是一门满足工业标准的编程语言，但又有着脚本语言般的表达力和可玩性。它支持代码预览（playgrounds），这个革命性的特性可以允许程序员在不编译和运行应用程序的前提下运行 Swift 代码并实时查看结果。

Swift 通过采用现代编程模式来避免大量常见编程错误：

- <mark>变量始终在使用前初始化。</mark>
- <mark>检查数组索引超出范围的错误。</mark>
- <mark>检查整数是否溢出。</mark>
- <mark>可选值确保明确处理 `nil` 值。</mark>
- <mark>内存被自动管理。</mark>
- <mark>错误处理允许从意外故障控制恢复。</mark>

Swift 代码被编译和优化，以充分利用现代硬件。语法和标准库是基于指导原则设计的，编写代码的明显方式也应该是最好的。安全性和速度的结合使得 Swift 成为从 “Hello，world！” 到整个操作系统的绝佳选择。

Swift 将强大的类型推理和模式匹配与现代轻巧的语法相结合，使复杂的想法能够以清晰简洁的方式表达。因此，代码不仅更容易编写，而且易于阅读和维护。

Swift 已经进行了多年，并且随着新特性和功能的不断发展。我们对 Swift 的目标是雄心勃勃的。我们迫不及待想看到你用它创建出的东西。

## Version Compatibility / 版本兼容性

本书描述的是在 Xcode 13 中默认包含的 Swift 5.5 版本。你可以使用 Xcode 13 来构建 Swift 5.5、Swift 4.2 或 Swift 4 写的项目。

使用 Xcode 13 构建 Swift 4 和 Swift 4.2 代码时，Swift 5.5 的大多数功能都适用。但以下功能仅支持 Swift 5.5 或更高版本:

- 返回值是<mark>不透明类型（opaque type）</mark>的函数依赖 Swift 5.1 运行时。
- <mark>**try?** 表达式不会为已返回可选类型的代码引入额外的可选类型层级。</mark>
- <mark>大数字的整型字面量初始化代码的类型将会被正确推导</mark>，例如 **UInt64(0xffff_ffff_ffff_ffff)** 将会被推导为整型类型而非溢出。

<mark>并发特性需要 Swift 5.5 及以上版本，以及一个提供了并发相关类型的 Swift 标准库版本。</mark>要应用于苹果平台，请至少将部署版本设置为 iOS 15、macOS 12、tvOS 15 或 watchOS 8.0。

<mark>用 Swift 5.5 写的项目可以依赖用 Swift 4.2 或 Swift 4 写的项目，反之亦然。</mark>这意味着，如果你将一个大的项目分解成多个框架（framework），你可以逐个地将框架从 Swift 4 代码迁移到 Swift 5.5。

## A Swift Tour / Swift 初见

<mark>全局作用域中的代码会被自动当做程序的入口点</mark>，所以你也不需要 `main()` 函数。你同样不需要在每个语句结尾写上分号。

### Simple Values / 简单值

#### 常量和变量

<mark>使用 `let` 来声明常量，使用 `var` 来声明变量。不需要在编译时明确给出常量的值，但是常量只能被赋值一次。</mark>

```swift
var myVariable = 42
myVariable = 50
let myConstant = 42
```

<mark>编译器会自动推断类型。</mark>编译器推断出 `myVariable` 是一个整数类型，因为它的初始值是整数。如果初始值没有提供足够的信息（或者没有初始值），那你需要在变量后面声明类型，用冒号分割。

```swift
let implicitInteger = 70
let implicitDouble = 70.0
let explicitDouble: Double = 70
```

#### 字符串

<mark>没有隐式类型转换，所有类型转换都是显式的。</mark>

```swift
let label = "The width is "
let width = 94
let widthLabel = label + String(width)
```

把值转换成字符串的更简单的方法是<mark>把值写到括号中，并且在括号之前写一个反斜杠（\）</mark>。例如：

```swift
let apples = 3
let oranges = 5
let appleSummary = "I have \(apples) apples."
let fruitSummary = "I have \(apples + oranges) pieces of fruit.”
```

<mark>使用三个双引号（`"""`）来包含多行字符串内容。每行行首的缩进会被去除到和结尾引号的缩进相匹配的位置。</mark>举个例子：

```swift
let quotation = """
I said "I have \(apples) apples."
And then I said "I have \(apples + oranges) pieces of fruit."
"""
```

#### 数组和字典

使用方括号 `[]` 来创建数组和字典，并使用下标或者键（key）来访问元素。最后一个元素后面允许有一个逗号。

```swift
var shoppingList = ["catfish", "water", "tulips"]
shoppingList[1] = "bottle of water"

var occupations = [
    "Malcolm": "Captain",
    "Kaylee": "Mechanic",
]
occupations["Jayne"] = "Public Relations"
```

数组会自动增长

```swift
shoppingList.append("blue paint")
print(shoppingList)
```

使用初始化语法来创建空数组或者空字典。

```swift
let emptyArray: [String] = []
let emptyDictionary: [String: Float] = [:]
```

可以推断类型时可以不写类型（作为函数的参数、给变量赋值等）。

```swift
shoppingList = []
occupations = [:]
```

### Control Flow / 控制流 ⭐️

条件：`if`，`switch`

循环：`for-in`，`while`，`repeat-while`

包裹条件和循环变量的括号可以省略，但是语句体的大括号是必须的。

```swift
let individualScores = [75, 43, 103, 87, 12]
var teamScore = 0
for score in individualScores {
    if score > 50 {
        teamScore += 3
    } else {
        teamScore += 1
    }
}
print(teamScore)
// Prints "11"
```

由于没有隐式转换，所以 `if` 后必须是一个布尔表达式，`if score { ... }` 这样的写法是错误的，score 不会隐式地与 0 做对比。

你可以一起使用 `if` 和 `let` 一起来处理值缺失的情况。这些值可由可选值来代表。一个可选的值是一个具体的值或者是 `nil` 以表示值缺失。在类型后面加一个问号（`?`）来标记这个变量的值是可选的。

```swift
var optionalString: String? = "Hello"
print(optionalString == nil)
// Prints "false"

var optionalName: String? = "John Appleseed"
var greeting = "Hello!"

if let name = optionalName {
    greeting = "Hello, \(name)"
}
```

如果变量的可选值是 `nil`，条件会判断为 `false`，大括号中的代码会被跳过。如果不是 `nil`，会将值解包并赋给 `let` 后面的常量，这样代码块中就可以使用这个值了。

另一种处理可选值的方法是通过使用 `??` 操作符来提供一个默认值。如果可选值缺失的话，可以使用默认值来代替。

```swift
let nickname: String? = nil
let fullName: String = "John Appleseed"
let informalGreeting = "Hi \(nickname ?? fullName)"
```

`switch` 支持任意类型的数据以及各种比较操作，但一定要有 `default` 。

```swift
let vegetable = "red pepper"
switch vegetable {
case "celery":
    print("Add some raisins and make ants on a log.")
case "cucumber", "watercress":
    print("That would make a good tea sandwich.")
case let x where x.hasSuffix("pepper"):
    print("Is it a spicy \(x)?")
default:
    print("Everything tastes good in soup.")
}
// Prints "Is it a spicy red pepper?
```

注意 `let` 在上述例子的等式中是如何使用的，它将匹配等式的值赋给常量 `x`。

运行 `switch` 中匹配到的 `case` 语句之后，程序会退出 `switch` 语句，并不会继续向下运行，所以不需要在每个子句结尾写 `break`。

`for-in` 可以用来遍历字典，字典是无序的，所以它们的键和值以任意顺序迭代结束。

```swift
let interestingNumbers = [
    "Prime": [2, 3, 5, 7, 11, 13],
    "Fibonacci": [1, 1, 2, 3, 5, 8],
    "Square": [1, 4, 9, 16, 25],
]
var largest = 0
for (_, numbers) in interestingNumbers {
    for number in numbers {
        if number > largest {
            largest = number
        }
    }
}
print(largest)
// Prints "25"
```

使用 `while` 来重复运行一段代码直到条件改变。循环条件也可以在结尾，保证能至少循环一次。

```swift
var n = 2
while n < 100 {
    n *= 2
}
print(n)
// Prints "128"

var m = 2
repeat {
    m *= 2
} while m < 100
print(m)
// Prints "128"
```

`...` 闭区间，`..<` 左闭右开

```swift
var total = 0
for i in 0..<4 {
    total += i
}
print(total)
// Prints "6"
```

### Functions and Closures / 函数和闭包 ⭐️

使用 `func` 来声明一个函数，使用名字和参数来调用函数。使用 `->` 来指定函数返回值的类型。

```swift
func greet(person: String, day: String) -> String {
    return "Hello \(person), today is \(day)."
}
greet(person: "Bob", day: "Tuesday")
```

默认情况下，函数使用它们的参数名称作为它们参数的标签，在参数名称前可以自定义参数标签，或者使用 `_` 表示不使用参数标签。

```swift
func greet(_ person: String, on day: String) -> String {
    return "Hello \(person), today is \(day)."
}
greet("John", on: "Wednesday")
```

元组可以用来生成复合值，作为函数的返回值。元组的元素可以通过名称或数字来引用。

```swift
func calculateStatistics(scores: [Int]) -> (min: Int, max: Int, sum: Int) {
    var min = scores[0]
    var max = scores[0]
    var sum = 0

    for score in scores {
        if score > max {
            max = score
        } else if score < min {
            min = score
        }
        sum += score
    }

    return (min, max, sum)
}
let statistics = calculateStatistics(scores: [5, 3, 100, 3, 9])
print(statistics.sum)
// Prints "120"
print(statistics.2)
// Prints "120"
```

函数可以嵌套。被嵌套的函数可以访问外侧函数的变量，你可以使用嵌套函数来重构一个太长或者太复杂的函数。

```swift
func returnFifteen() -> Int {
    var y = 10
    func add() {
        y += 5
    }
    add()
    return y
}
returnFifteen()
```

函数是一级类型，即函数可以作为返回值或参数。

```swift
func makeIncrementer() -> ((Int) -> Int) {
    func addOne(number: Int) -> Int {
        return 1 + number
    }
    return addOne
}
var increment = makeIncrementer()
increment(7)

func hasAnyMatches(list: [Int], condition: (Int) -> Bool) -> Bool {
    for item in list {
        if condition(item) {
            return true
        }
    }
    return false
}
func lessThanTen(number: Int) -> Bool {
    return number < 10
}
var numbers = [20, 19, 7, 12]
hasAnyMatches(list: numbers, condition: lessThanTen)”
```

函数可以看做是稍后可以调用的代码块，是闭包的特殊情况。闭包中的代码可以访问在创建闭包的范围内可用的变量和函数等内容，即使闭包在执行时处于不同的范围内，比如嵌套函数。将代码用大括号 `{}` 包包起来就可以编写没有名称的闭包。 `in` 将参数和返回类型与 body 分开。

```swift
numbers.map({ (number: Int) -> Int in
    let result = 3 * number
    return result
})
```

当闭包的类型已知时，例如委托的回调，您可以省略其参数的类型、返回类型或都省略。单个语句的闭包隐式返回其唯一语句的值。

```swift
let mappedNumbers = numbers.map({ number in 3 * number })
print(mappedNumbers)
// Prints "[60, 57, 21, 36]
```

您可以按数字而不是名称引用参数——这种方法在非常短的闭包中特别有用。作为函数最后一个参数传递的闭包可以写在括号之后。如果闭包是函数的唯一参数，函数的小括号可以省略。

```swift
let sortedNumbers = numbers.sorted { $0 > $1 }
print(sortedNumbers)
// Prints "[20, 19, 12, 7]
```

### Objects and Classes / 对象和类 ⭐️

属性和变量的写法是一样的，方法和函数的写法是一样的，唯一的区别就是它们的上下文是类。

```swift
class Shape {
    var numberOfSides = 0
    func simpleDescription() -> String {
        return "A shape with \(numberOfSides) sides."
    }
}

var shape = Shape()
shape.numberOfSides = 7
var shapeDescription = shape.simpleDescription()
```

`init` 是用来初始化实例的方法。所有的属性都需要被赋值，赋值可以在声明时完成，也可以在初始化器中完成。`deinit` 是用来销毁实例的方法。

```swift
class NamedShape {
    var numberOfSides: Int = 0
    var name: String

    init(name: String) {
        self.name = name
    }

    func simpleDescription() -> String {
        return "A shape with \(numberOfSides) sides."
    }
}
```

子类

```swift
class Square: NamedShape {
    var sideLength: Double

    init(sideLength: Double, name: String) {
        self.sideLength = sideLength
        super.init(name: name)
        numberOfSides = 4
    }

    func area() -> Double {
        return sideLength * sideLength
    }

    override func simpleDescription() -> String {
        return "A square with sides of length \(sideLength)."
    }
}
let test = Square(sideLength: 5.2, name: "my test square")
test.area()
test.simpleDescription()
```

简单的属性可以直接存储，复杂的属性可以用 getter 和 setter 。

```swift
class EquilateralTriangle: NamedShape {
    var sideLength: Double = 0.0

    init(sideLength: Double, name: String) {
        self.sideLength = sideLength
        super.init(name: name)
        numberOfSides = 3
    }

    var perimeter: Double {
        get {
            return 3.0 * sideLength
        }
        set {  // 默认名称是 newValue，也可以指定一个，写在 set 后面。
            sideLength = newValue / 3.0
        }
    }

    override func simpleDescription() -> String {
        return "An equilateral triangle with sides of length \(sideLength)."
    }
}
var triangle = EquilateralTriangle(sideLength: 3.1, name: "a triangle")
print(triangle.perimeter)
// Prints "9.3"
triangle.perimeter = 9.9
print(triangle.sideLength)
// Prints "3.3000000000000003"
```

如果您不需要计算属性，但仍然需要提供在设置新值之前和之后运行的代码，请使用 `willSet` 和 `didSet`。每当值在初始化器之外更改时，您提供的代码都会运行。

```swift
class TriangleAndSquare {
    var triangle: EquilateralTriangle {
        willSet {
            square.sideLength = newValue.sideLength
        }
    }
    var square: Square {
        willSet {
            triangle.sideLength = newValue.sideLength
        }
    }
    init(size: Double, name: String) {
        square = Square(sideLength: size, name: name)
        triangle = EquilateralTriangle(sideLength: size, name: name)
    }
}
var triangleAndSquare = TriangleAndSquare(size: 10, name: "another test shape")
print(triangleAndSquare.square.sideLength)
// Prints "10.0"
print(triangleAndSquare.triangle.sideLength)
// Prints "10.0"
triangleAndSquare.square = Square(sideLength: 50, name: "larger square")
print(triangleAndSquare.triangle.sideLength)
// Prints "50.0"
```

当使用可选值时，可以在方法、属性和下标之前添加`?`，如果可选值是`nil`，那么`?`之后的任何操作都会被忽略，整个表达式的值是`nil`。否则这个可选值会被解封，并且在`?`之后一直有效。总的来说，带有`?`的表达式的值是一个可选值。

```swift
let optionalSquare: Square? = Square(sideLength: 2.5, name: "optional square")
let sideLength = optionalSquare?.sideLength
```

### Enumerations and Structures

```swift
enum Rank: Int {
    case ace = 1
    case two, three, four, five, six, seven, eight, nine, ten
    case jack, queen, king

    func simpleDescription() -> String {
        switch self {
        case .ace:
            return "ace"
        case .jack:
            return "jack"
        case .queen:
            return "queen"
        case .king:
            return "king"
        default:
            return String(self.rawValue)
        }
    }
}
let ace = Rank.ace
let aceRawValue = ace.rawValue
```

默认从 0 开始，也可以自定义，也可以用初始化器`init?(rawValue:)`从 `rawValue` 创建枚举值。如果不存在匹配的枚举值，那么就返回`nil`。

```swift
if let convertedRank = Rank(rawValue: 3) {
    let threeDescription = convertedRank.simpleDescription()
}
```
