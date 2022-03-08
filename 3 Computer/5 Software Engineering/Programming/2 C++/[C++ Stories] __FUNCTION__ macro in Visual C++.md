Recently, I’ve found something interesting in **Visual Studio** that improved my Logger!

I had a function called `AddMsg`

```cpp
/** appends message to the log file */
void AddMsg(LOG_MODE m, int level, char* strModule, char *strMsg, ...);
```

But, when you wanted to add a comment you needed to use quite complicated and long syntnax, like:

```cpp
/** one need to pass function name... quite boring task */
gLogger->AddMsg(lmNormal, 0, "class::func", "bla... param = %d", param);
// gLogger is a singleton...
```

But, there is a very useful define in Visual Studio, called <mark>**\_\_FUNCTION\_\_** that returns name of a current function</mark>. So one can use it to automate passing function name to the logMsg function. To do that, I needed to define macro:

```
#define LOG(m, l, ...) gLogger->AddMsg(m, l, __FUNCTION__, __VA_ARGS__)
```

And now one can simply write:

```
LOG(lmNormal, "bla bla bla... param = %d", param);
```

In that way logging becomes a bit more simple…

## Some more info

- <mark>**\_\_VA_ARGS\_\_** can be used in macros that support “…” format, like for the **printf** function</mark>.
- In **GCC** there is also the same macro, [but more documentation here](http://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html)
- More macros in VS: [link to msdn documentation](<http://msdn.microsoft.com/en-us/library/b0084kay(v=vs.80).aspx>)
