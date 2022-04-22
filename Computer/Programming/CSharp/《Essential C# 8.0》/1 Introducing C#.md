# Introducing C#

## Hello, World

### Dotnet CLI（Command-Line Interface）

```sh
dotnet new console
dotnet build
dotnet run  # 会隐式 build
dotnet clean  # 清理 build
```

Java 要求文件名和类名一致。C# 虽然也常遵守这一约定，却并非必须。在 C# 中，一个文件可以包含多个类，一个类的代码也可拆分到多个文件中，这是一种叫做 partial class 的特性。

## C# Syntax Fundamentals

### C# Keywords

保留关键字（reserved keyword）

上下文关键字（contextual keyword）

### Identifiers

PascalCase ，类

camelCase ，局部变量

### Type Definition

## 1.3 使用变量

### 1.3.1 数据类型

int 32 位

char 16 位，足以表示无代理项的 Unicode 字符．某些语言的文字编码要用两个 16 位值表示。 第一个代码值称为 “高位代理项”（high surrogate）， 第二个称为“低位代理项” （low surrogate）。在代理项的帮助下，Unicode 可以表示 100 多万个不同的字符。 美国和欧洲地区很少使用代理项， 东亚各国则很常用。

## 1.4 Console Input and Output

### 输入

`System.Console.Readline()`

`System.Console.Read()` ：读取字符对应的整数．

```csharp
int readValue;
char character;
readValue = System.Console.Read();
character = (char) readValue;
System.Console.Write(character);
```

`System.Console.ReadKey()` ：返回的用户的单次按键输入。可用它拦截用户按键操作，并执行相应行动，比如校验按键，限制只能按数字键。

### 输出

字符串插值（string interpolation）：

```csharp
System.Console.WriteLine($"Your full name is { firstName } { lastName }.");
```

复合格式化（composite formatting）：

```csharp
System.Console.WriteLine("Your full name is {0} {1}.", firstName, lastName);
```

## 1.5 Comments

XML 带分隔符的注释

XML 单行注释

> 编程史上确有一段时期，如代码没有详尽的注释，都不好意思说自己是专业程序员。时代变了。没有注释但可读性好的代码，比需要注释才能说清楚的代码更有价值。**如开发人员发现需要写注释才能说清楚代码块的功用，应考虑重构，而不是洋洋洒洒写一堆注释。**写注释来重复代码本来就讲得清的事情，只会变得臃肿，降低可读性，还容易过时，因为将来可能更改代码但没有来得及更新注释。

XML（Extensible Markup Language，可扩展标记语言）是一种简单而灵活的文本格式，常用于 Web 应用程序以及应用程序间的数据交换。XML 之所以“可扩展”，是因为 XML 文档中包含的是对数据进行描述的信息，也就是所谓的元数据 （metadata）。

```xml
<?xml version="1.0" encoding="utf-8" ?>
<body>
  <book title="Essential C# 8.0">
      <chapters>
          <chapter title="Introducing C#"/>
          <chapter title="Data Types"/>
          ...
      </chapters>
  </book>
</body>
```

XML 文件包含了对数据（比如 “Essential C#7.0”、“Data Types”等）进行描述的元数据（书 名、章名等）。这可能形成相当臃肿的文件，但优点是可通过描述来帮助解释数据。

## 1.6 托管执行和 CLI （Managed Execution and The Common Language Infrastructure）

公共语言基础结构（Common Language Infrastructure）包含很多方面的规范：

- 虚拟执行系统（Virtual Execution System，VES）或公共语言运行时（Common Language Runtime）：根据需要编译 CIL 代码，即「即时编译」（just-in-time compilation），下面还会列出一些其他的功能．
- 公共中间语言（Common Intermediate Language, CIL）或中间语言（IL）：C# 编译器将 C# 源代码转换成中间语言．这是一种汇编语言．
- 公共类型系统（Common Type System, CTS）：支持语言互操作性的类型系统．
- 公共语言规范（Common Language Specification, CLS）:编写可以被 CLI 兼容的语言（CLI compatible language）使用的「库」的规范．
- 使各种服务能被 CLI 识别的元数据，比如程序集的布局或文件格式规范．

一些其他的概念：

- 托管代码（managed code）：在「运行时」这样一个「代理」的上下文中执行的代码．
- 托管执行（managed execution）：在「运行时」的控制下执行．「运行时」负责内存分配、安全性和 JIT 编译．
- 本机代码（native code）或非托管代码（unmanaged code）：执行时不需要「运行时」的代码．

CLR 的功能：

- 语言互操作性：不同源语言间的互操作性。语言编译器将每种源语言转换成相同中间语言（CIL）来实现这种互操作性。
- 类型安全：检查类型间转换，确保兼容的类型才能相互转换。这有助于防范缓冲区溢出（这是产生安全隐患的主要原因）．
- 代码访问安全性：程序集开发者的代码有权在计算机上执行的证明。
- 垃圾回收：一种内存管理机制，自动释放“运行时”为数据分配的空间。
- 平台可移植性：同一程序集可在多种操作系统上运行。要实现这一点，一个显而易见的限制就是不能使用平台特有的库。所以平台依赖问题需单独解决。
- BCL（基类库）：提供开发者能（在所有.NET 框架中）依赖的大型代码库．

ildasm.exe（IL Disassembler）

可以对 CIL 反汇编．使用混淆器（obfuscator）可以使反汇编出的 IL 更难理解．

一些免费工具（比如 Red Gate Reflector，ILSpy，JustDecompile， dotPeek 和 CodeReflect）都能将 CIL 自动反编译成 C# ．

## 1.7 Multiple .NET Frameworks

## 1.7.1 Application Programming Interface

框架是一组很大的 API ．

## 1.7.2 C# and .NET Versioning

C# 6.0 ：跨平台编译

.Net Core 是一套完整的 SDK ：

- .NET Compiler Platform （Roslyn）
- .NET Core runtime
- dotnet （命令行工具）（C# 7.0）
