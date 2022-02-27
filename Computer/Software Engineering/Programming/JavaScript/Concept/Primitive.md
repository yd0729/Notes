**In [JavaScript](https://developer.mozilla.org/en-US/docs/Glossary/JavaScript), a primitive (primitive value, primitive data type) is data that is not an [object](https://developer.mozilla.org/en-US/docs/Glossary/Object) and has no [methods](https://developer.mozilla.org/en-US/docs/Glossary/Method). There are 7 primitive data types: [string](https://developer.mozilla.org/en-US/docs/Glossary/String), [number](https://developer.mozilla.org/en-US/docs/Glossary/Number), [bigint](https://developer.mozilla.org/en-US/docs/Glossary/BigInt), [boolean](https://developer.mozilla.org/en-US/docs/Glossary/Boolean), [undefined](https://developer.mozilla.org/en-US/docs/Glossary/undefined), [symbol](https://developer.mozilla.org/en-US/docs/Glossary/Symbol), and [null](https://developer.mozilla.org/en-US/docs/Glossary/Null).**

Most of the time, a primitive value is represented directly at the lowest level of the language implementation.

**All primitives are immutable, i.e., they cannot be altered. It is important not to confuse a primitive itself with a variable assigned a primitive value. The variable may be reassigned a new value, but the existing value can not be changed in the ways that objects, arrays, and functions can be altered.**

## [Example](https://developer.mozilla.org/en-US/docs/Glossary/Primitive#example "Permalink to Example")

This example will help you understand that primitive values are **immutable.**

### [JavaScript](https://developer.mozilla.org/en-US/docs/Glossary/Primitive#javascript "Permalink to JavaScript")

```javascript
var bar = "baz";
console.log(bar);               
bar.toUpperCase();
console.log(bar);               


var foo = [];
console.log(foo);               
foo.push("plugh");
console.log(foo);               


bar = bar.toUpperCase();       
```

A primitive can be replaced, but it can't be directly altered.

## [Primitive wrapper objects in JavaScript](https://developer.mozilla.org/en-US/docs/Glossary/Primitive#primitive_wrapper_objects_in_javascript "Permalink to Primitive wrapper objects in JavaScript")

Except for `null` and `undefined`, all primitive values have object equivalents that wrap around the primitive values:

-   [`String`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String) for the string primitive.
-   [`Number`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Number) for the number primitive.
-   [`BigInt`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/BigInt) for the bigint primitive.
-   [`Boolean`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Boolean) for the boolean primitive.
-   [`Symbol`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Symbol) for the symbol primitive.

The wrapper's [`valueOf()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/valueOf) method returns the primitive value.

## [See also](https://developer.mozilla.org/en-US/docs/Glossary/Primitive#see_also "Permalink to See also")