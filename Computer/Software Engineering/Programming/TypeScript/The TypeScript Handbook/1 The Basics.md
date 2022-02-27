# 1 The Basics

JavaScript only truly provides _dynamic_ typing - running the code to see what happens.

The alternative is to use a _static_ type system to make predictions about what code is expected _before_ it runs.

## Static type-checking

_Static types systems_ describe the shapes and behaviors of what our values will be when we run our programs.
A type-checker like TypeScript uses that information and tells us when things might be going off the rails.

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-01-20 16.48.02.png" alt="截屏2022-01-20 16.48.02" style="zoom:50%;" />

## Non-exception Failures

[the ECMAScript specification](https://tc39.github.io/ecma262/) 规定了 JavaScript 的一些异常，但是不够，比如下面这个例子会返回 `undefined`：

```js
const user = {
  name: "Daniel",
  age: 26,
};

user.location; // returns undefined
```

但是 TypeScript 会直接视为错误：

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-01-20 16.48.38.png" alt="截屏2022-01-20 16.48.38.png" style="zoom:50%;" />

While sometimes that implies a trade-off in what you can express, the intent is to catch legitimate bugs in our programs.（虽然这限制了语言的表达能力，但是能发现“合法的 Bug”）And TypeScript catches _a lot_ of **legitimate bugs**.（对于 JavaScript 来说是合法的，但其实是 Bug）

For example: typos（拼写错误）

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-01-20 16.49.50.png" alt="截屏2022-01-20 16.49.50.png" style="zoom:50%;" />

uncalled functions（函数后面没写括号，没调用）

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-01-20 16.50.09.png" alt="截屏2022-01-20 16.50.09.png" style="zoom:50%;" />

or basic logic errors（不可到达的分支）.

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-01-20 16.50.30.png" alt="截屏2022-01-20 16.50.30.png" style="zoom:50%;" />

## Types for Tooling

静态类型也可以在编写代码时发挥作用。

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-01-20 16.51.05.png" alt="截屏2022-01-20 16.51.05.png" style="zoom:50%;" />

## `tsc`, the TypeScript compiler

First we'll need to grab it via npm.

```sh
npm install -g typescript
```

> This installs the TypeScript Compiler `tsc` globally.
> You can use `npx` or similar tools if you'd prefer to run `tsc` from a local `node_modules` package instead.

**反正我用 brew 。**

Now let's move to an empty folder and try writing our first TypeScript program: `hello.ts`:

```ts twoslash
// Greets the world.
console.log("Hello world!");
```

And now let's type-check it by running the command `tsc` which was installed for us by the `typescript` package.

```sh
tsc hello.ts
```

If we look in our current directory, we'll see a `hello.js` file next to `hello.ts`. That's the output from our `hello.ts` file after `tsc` _compiles_ or _transforms_ it into a plain JavaScript file. The compiler tries to emit clean readable code that looks like something a person would write.

## Emitting with Errors

就算 tsc 输出了错误，它还是会将 TS 转换成 JS 。This is based on one of TypeScript's core values: much of the time, _you_ will know better than TypeScript. 所以在将现有的 JS 代码迁移到 TS 的过程中，即使迁移工作没有完全完成，代码仍然可运行，虽然 tsc 会输出错误。

但如果你希望 tsc 更严格一点，也可以使用编译选项 [`noEmitOnError`](/tsconfig#noEmitOnError) ，这样如果 tsc 检查到了错误，就不会更新 JS 。Try changing your `hello.ts` file and running `tsc` with that flag:

```sh
tsc --noEmitOnError hello.ts
```

You'll notice that `hello.js` never gets updated.

## Explicit Types

```ts twoslash
function greet(person: string, date: Date) {
  console.log(`Hello ${person}, today is ${date.toDateString()}!`);
}
```

添加了类型注释（type annotation）之后，TS 可以检查出更多的错误。

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-01-20 16.51.46.png" alt="截屏2022-01-20 16.51.46.png" style="zoom:50%;" />

Perhaps surprisingly, calling `Date()` in JavaScript returns a `string`.
On the other hand, constructing a `Date` with `new Date()` actually gives us what we were expecting.

```ts twoslash {4}
function greet(person: string, date: Date) {
  console.log(`Hello ${person}, today is ${date.toDateString()}!`);
}

greet("Maddison", new Date());
```

类型注释并不是总需要写的，TS 有时可以自己推断出来。如果 TS 能推断出来，那最好就不要写。

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-01-20 16.52.17.png" alt="截屏2022-01-20 16.52.17.png" style="zoom:50%;" />

## Erased Types

转换到 JS 后类型会被抹去：

```javascript
"use strict";
function greet(person, date) {
  console.log("Hello " + person + ", today is " + date.toDateString() + "!");
}
greet("Maddison", new Date());
```

Notice two things here:

1. Our `person` and `date` parameters no longer have type annotations.
2. Our "template string" - that string that used backticks (the `` ` `` character) - was converted to plain strings with concatenations (`+`).

More on that second point later, but let's now focus on that first point.
Type annotations aren't part of JavaScript (or ECMAScript to be pedantic), so there really aren't any browsers or other runtimes that can just run TypeScript unmodified.
That's why TypeScript needs a compiler in the first place - it needs some way to strip out or transform any TypeScript-specific code so that you can run it.
Most TypeScript-specific code gets erased away, and likewise, here our type annotations were completely erased.

> **Remember**: Type annotations never change the runtime behavior of your program.

## Downleveling

One other difference from the above was that our template string was rewritten from

```js
`Hello ${person}, today is ${date.toDateString()}!`;
```

to

```js
"Hello " + person + ", today is " + date.toDateString() + "!";
```

Why did this happen?

Template strings are a feature from a version of ECMAScript called ECMAScript 2015 (a.k.a. ECMAScript 6, ES2015, ES6, etc. - _don't ask_).
TypeScript has the ability to rewrite code from newer versions of ECMAScript to older ones such as ECMAScript 3 or ECMAScript 5 (a.k.a. ES3 and ES5).
**This process of moving from a newer or "higher" version of ECMAScript down to an older or "lower" one is sometimes called _downleveling_.**

By default TypeScript targets ES3, an extremely old version of ECMAScript.
We could have chosen something a little bit more recent by using the [`target`](/tsconfig#target) option.
Running with `--target es2015` changes TypeScript to target ECMAScript 2015, meaning code should be able to run wherever ECMAScript 2015 is supported.
So running `tsc --target es2015 hello.ts` gives us the following output:

```js
function greet(person, date) {
  console.log(`Hello ${person}, today is ${date.toDateString()}!`);
}
greet("Maddison", new Date());
```

> 虽然默认的目标是 ES3 ，但是现代浏览器都支持 ES2015 了，所以如果兼容老浏览器不是很重要的话，把目标改到 ES2015 也没问题。

## Strictness

Different users come to TypeScript looking for different things in a type-checker.
Some people are looking for a more loose opt-in experience which can help validate only some parts of their program, and still have decent tooling.
This is the default experience with TypeScript, where types are optional, inference takes the most lenient types, and there's no checking for potentially `null`/`undefined` values.
Much like how `tsc` emits in the face of errors, these defaults are put in place to stay out of your way.

If you're migrating existing JavaScript, that might be a desirable first step.

默认设置比较宽松，也不会检查潜在的 `null`/`undefined` ，这是为了让你能够使用 TS 开始工作，比如你正在迁移现有的 JS 代码。

In contrast, a lot of users prefer to have TypeScript validate as much as it can straight away, and that's why the language provides strictness settings as well.
These strictness settings turn static type-checking from a switch (either your code is checked or not) into something closer to a dial.
The further you turn this dial up, the more TypeScript will check for you.

这些严格性设置将静态类型检查从开关（检查代码或者不检查代码）变成刻度。刻度调得越高，TS 就检查越多。

This can require a little extra work, but generally speaking it pays for itself in the long run, and enables more thorough checks and more accurate tooling.

这可能需要一些额外的工作，但一般来说，从长远来看，这是值得的，并允许更彻底的检查和更准确的工具。

When possible, a new codebase should always turn these strictness checks on.

TypeScript has several type-checking strictness flags that can be turned on or off, and all of our examples will be written with all of them enabled unless otherwise stated.
The [`strict`](/tsconfig#strict) flag in the CLI, or `"strict": true` in a [`tsconfig.json`](https://www.typescriptlang.org/docs/handbook/tsconfig-json.html) toggles them all on simultaneously, but we can opt out of them individually.
The two biggest ones you should know about are [`noImplicitAny`](/tsconfig#noImplicitAny) and [`strictNullChecks`](/tsconfig#strictNullChecks).

## `noImplicitAny`

Recall that in some places, TypeScript doesn't try to infer types for us and instead falls back to the most lenient type: `any`.
This isn't the worst thing that can happen - after all, falling back to `any` is just the plain JavaScript experience anyway.

However, using `any` often defeats the purpose of using TypeScript in the first place.
The more typed your program is, the more validation and tooling you'll get, meaning you'll run into fewer bugs as you code.
Turning on the [`noImplicitAny`](/tsconfig#noImplicitAny) flag will issue an error on any variables whose type is implicitly inferred as `any`.

## `strictNullChecks`

By default, values like `null` and `undefined` are assignable to any other type.
This can make writing some code easier, but forgetting to handle `null` and `undefined` is the cause of countless bugs in the world - some consider it a [billion dollar mistake](https://www.youtube.com/watch?v=ybrQvs4x0Ps)!
The [`strictNullChecks`](/tsconfig#strictNullChecks) flag makes handling `null` and `undefined` more explicit, and _spares_ us from worrying about whether we _forgot_ to handle `null` and `undefined`.
