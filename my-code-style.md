# My Code Style

+++**Page Contents**

- [Why](#why)
- [Principles](#principles)
- [Style](#style)
+++

## Why
My friend (who was just learning programming at that time) once gave me some code to debug. I (who had some experience in programming) asked him to improve and clean up the code style a little and he refused. He said
> Hav compilerakhatir code barayta.

Which translates to "I write code for the compiler."
This forced me to write down the code style I follow, the reasons behind it and **FORCE** it on all of my code as well as try to motivate others to use it.

I anyway debugged the code and it ran. He asked me what I did and I said "I fixed the code style." Which was exactly what I had done.

*This* is the reason why consistent code style is important. Badly written code is so unreadable that it is almost impossible to isolate the error. When I fixed the code style, the bad code automatically got fixed.

## Principles
> **"Code is for humans, not for the computer."**

Computer finally compiles the *code* into machine language which *it* can read. The initial *code* is only for humans. Compiler will compile any (badly styled or otherwise) code into the same final output.

The initial code should be such that it is readable by not just the initial programmer but by the people who will read it in the future.

My code style is based on the following principles:

- Code should be [**Future-Self** Readable](#future-self-readable).
- Code should be [**Future-Humans** Readable](#future-human-readable).
- Code should be [**Clean And Compact**](#clean-and-compact).

### Future-Self Readable
The code should have enough explanation in the comments that you should understand it when you look at it in the future.

### Future-Human Readable
***Future-Human** is a word I learnt from another programmer.*

Anyone other than the initial programmer, who reads the code, should understand the logic, the uses of each of the variables and so on.

### Clean And Compact

The code should be *compact* which means that there should be no unnecessary lines, no redundant code and no unused code.

## Style
+++Contents
- [Naming](#naming)
- [Indentation And Spacing](#indentation-and-spacing)
- [Comments](#comments)
- [Closures](#closures)
+++

### Naming
+++Contents
- [File Naming](#file-naming)
- [Function Naming](#function-naming)
- [Variable Naming](#variable-naming)
+++

#### File Naming
File names should be in all small letters and words should be separated by `-` and not a space or a `_` or camelcase.
eg: `file.js`, `file-2.cpp`, `hello-world.c`

#### Function Naming
Function/Method names should always start with a small letter and have no special character. Words should be separated by camelcase.
eg: `sayHello()`, `hello()`, `hello2()`

#### Variable Naming
Variables can be of different types:
1. **Normal Variables**: Should start with a small letter, no special characters and camelcase., `i`, `j`, `numMessages`.
2. **Constants**: Constants such as [enums](https://www.thoughtco.com/what-is-an-enum-958326) and other predefined constants should be written in ALL CAPS and words should be separated by `_`. eg: `ID`, `TOKEN`, `PACKAGE_NAME`.

### Indentation And Spacing
+++Contents
- [Indentation](#indentation)
- [Operator Spacing](#operator-spacing)
+++

#### Indentation
Indentation should be with spaces and not tabs. Indentation size should only be `2` and no other amount.

#### Operator Spacing
1. **Unary Operators**: Unary operators should have no spaces between operator and operand. eg: `i++`, `--j`, `!k`.
2. **Binary Operators**: Binary operators should have one space between each operator operand pair. eg: `1 + 1`, `x += 2`, `y != 4`.
3. **Ternary Operator**: Same as binary. eg: `x == y ? 1 : 0`.

### Comments
> Compiler ignores comments so why should I bother?

Because **CODE IS NOT FOR COMPILER**. Comments are for future-humans and future-self.

+++Contents
- [Multi Line Comments](#multi-line-comments)
- [Variable Comments](#variable-comments)
- [Function Comments](#function-comments)
- [Explanation Comments](#explanation-comments)
+++

#### Multi Line Comments
*[JSDoc](https://jsdoc.app/) comment standard is made and used for JavaScript but there is nothing that says that it cannot be used anywhere else,*
Some IDEs like [VSCode](https://github.com/microsoft/vscode) even recognize JSDoc in C/C++ or any other files.

```cpp
/**
 * This multi-line comment just looks better.
 * Especially if the comment is very long since the comment can be
 * easily distinguished from a non comment line due to `*`. Also word
 * wrap looks nice.
 */
```

#### Variable Comments
*All variable names which are less than 100% obvious should have a comment describing them.*
This comment can be inline, or above the variable or multi-line as per convenience.

Examples:
```cpp
string personName;
int i; // Iterator (Not so obvious so needs a comment)

/** Even I don't know what this is. It needs a seriously long explanation
 *  Can use multi line comments for this
 */
int aadadd[];
```

#### Function Comments
*Functions are made to be reused. To reuse a function, one needs to know how to use it.*

Even if [JSDoc](https://jsdoc.app) is made for and used in JS, there is no harm in using it in other cases.
In the worst case, without any code completion or info showing up on hover, it will at least be used as a nice, readable format for a comment.
Besides, code editors like [VSCode](https://github.com/microsoft/vscode) show function info on hover and provide code completion(for JSDoc comments) for even *non-JS* files.

```cpp
/**
 * This is a cpp file but this JSDoc comment still makes sense.
 * (Try using aFunction somewhere or hover over it in a modern IDE like VSCode to see the real power of JSDoc)
 *
 * Returns the sum of two numbers
 * @param l First number
 * @param m Second number
 *
 * @returns The sum of l and m.
 */
int aFunction(int l, int m) {
  return l + m;
}
```

#### Explanation Comments
*No one, not even you, will understand how an (rather sophisticated) algorithm works just by looking at its code.*

If a very long or complex algorithm is used then either add a reference link to it
in a comment above, or if it is your own code, explain the whole code in a multi-line comment above it.

### Closures
*Closures or {} are very important to isolate `if`, `for` blocks and or functions in a clean, readable way. Languages which do not have {} are not programming languages at all.*

#### Indentation inside closures
Always add one indent (2 spaces only) to every line of code inside a closure.

#### Starting and ending closures
Closures for a `for`, `if` or similar block should start ON THE SAME LINE; and it should end at the same indentation level.

Example:
```js
if (x == 1) { // Start here

} // same indentation as if

function x() { // Same

} // Same
```
