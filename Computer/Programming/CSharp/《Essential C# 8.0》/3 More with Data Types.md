# 3 More with Data Types

## Categories of Type

- value type: copied by value
- reference type: copied by reference

### Value Types

Value types require a memory copy.

### Reference Types

![图 8](../../../../.media/a097fcc8824b118c458e45d13c6ce70591dd8302380561703eeb2adf6aaa9847.png)  

解引用（dereferencing）: 引用类型通过引用访问数据．

拷贝时只有引用会被拷贝，数据不会．

引用的大小和机器字长（比如 64 位）相等．

### Declaring Types That Allow null

赋 null 值在数据库编程时特别有用．

在类型后加一个问号，比如 int? ，被称为 nullable modifire ．

C# 2.0 支持 value type
C# 8.0 支持 reference type

#### Dereferencing a null Reference

需要额外的检查，否则可能会抛出运行时异常．

#### Checking for null

```csharp
if (number is null) {
    System.Console.WriteLine(
        "'number' requires a value and cannot be null");
}
```

虽然 == 也可以，但是 == 有被重载的可能，所以 is 更好．

C# 6.0 之后可以使用 null-conditional operator ．

```csharp
int? length = text?.Length;
```

#### Dereferencing null on Value Types

虽然严格地说，值类型不能被解引用，也不能被赋值为 null （因为 null 代表 reference to nothing），但这里是为了统一．

解引用一个 null 的值类型会抛出 InvalidOperationException ，而不是 NullReferenceException ，也是因为值类型实际上不是引用．

当值是 null 时， `HasValue` ， `ToString()` ， `GetHashCode()` 和 `Equals()` 都不会抛出异常，因为它们都实现了 `Nullable<T>` ．

但是 `GetType()` 会抛出 NullReferenceException ，这是因为 `GetType()` 不是虚函数，所以 `Nullable<T>` 无法重载这个行为，而是采用了默认的行为．

总而言之就是有不一致性，很混乱．

#### Nullable Reference Types

在 C# 8.0 之前所有的引用类型都默认是 nullable 的，这很糟糕．

C# 8.0 中引用类型默认不是 nullable 的了．但为了向后兼容，也可以在文件/项目/命令行中开启「默认引用类型可为 null」．

### Implicitly Typed Local Variables

C# 3.0 之后允许用 `var` 声明一个隐式类型的局部变量，但要求变量必须在声明时初始化，编译器会根据被赋的值来决定变量的类型．

Guidelines：只有在被赋的值的类型很明显时才使用 `var` ．

#### Anonymous Types

`var` 使匿名类型成为可能．

```csharp
public class Program
{
    public static void Main()
    {
        var patent1 =
            new { Title = "Bifocals",
                YearOfPublication = "1784" };
        var patent2 =
            new { Title = "Phonograph",
                YearOfPublication = "1877" };

        System.Console.WriteLine(
            $"{patent1.Title} ({patent1.YearOfPublication})");
        System.Console.WriteLine(
            $"{patent2.Title} ({patent2.YearOfPublication})");
    }
}
```

但是 C# 7.0 的 tuple 几乎取代了匿名类型．

### Tuples

![图 9](../../../../.media/c1e63060e18c93cc9909e13fc3acbb9279a5e330a5e82ab6dab172615bc0883b.jpg)  

有点误导，实际上不是声明了 Tuple ，相反是在 deconstruct 一个 tuple ．只有 `var` 可以写在最外面（第 4 种写法）．

![图 10](../../../../.media/668440dc0be86f527b1d38830014e9f1c31fa745cad77631863bce2d0e966ad4.png)  

9 使用下划线．

5，6，7，8，10 是真正声明 Tuple 的写法．

5，6，10 中元组中的元素是有名字的，7，8 是没有名字的．

10 的写法是在 C# 7.1 以后才行．

Guidlines

变量使用 camelCasing ，而元组使用 PascalCasing 比较好．

以下这些可忽略，在编程时可以不使用．

Tuple 使用 System.ValueTuple<...> 泛型来实现，包括以上的例子的右侧和从 5 开始的左侧（为啥 9 也是呢），只有比较和相等方法， CLI 代码中实际上是没有元组中项的名字的，而 ItemX 总是可用的，即使对于项有名字的元组也是如此（但是 IntelliSense 不会显示）．

在 Tuple 声明的余下作用域中，这是可行的，但是如果 Tuple 作为 API 出现在函数的参数中，就必须要知道项的名字了．编译器会以属性的形式将项目名称添加到成员的元数据中．

下面这个函数的返回值是一个元组，

```csharp
public (string First, string Second) ParseNames(string fullName)
```

编译器生成的等价的 CLI 代码为：

```csharp
[return: System.Runtime.CompilerServices.TupleElementNames(new string[] { "First", "Second" })]
public System.ValueTuple<string, string> ParseNames(string fullName)
```

C# 7.0 在直接使用 `System.ValueTuple` 声明时不允许项有自定义名称．

当项的个数超过 7 个时， Tuple 会以一种“递归”的方式实现：

```csharp
System.ValueTuple<T1, T2, T3, T4, T5, T6, T7, TRest>
```

所以 `System.ValueTuple<T1>` 是存在的（否则就无法支持 8 个项的元组），但必须直接使用才能声明一个只有一个项的元组，因为 C# 规定 Tuple 最少要有 2 个项．

### Arrays
