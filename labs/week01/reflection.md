# Week 1 reflection

Write concise answers in your own words.

## 1. Source and executable

What is the difference between `src/hello.cpp` and `build/manual/hello` after compilation?

Answer: src/hello.cpp is the raw code file you write, and build/manual/hello is the compiled program you run.

## 2. Compiler warnings

What is the purpose of `-Wall -Wextra -Wpedantic`?

Answer: They turn on strict compiler warnings to help you catch mistakes early.

## 3. Value and reference parameters

What is the difference between these declarations?

```cpp
void f(std::vector<int> values);
void f(std::vector<int>& values);
```

Answer: The first passes a copy of the vector, while the second passes a reference to the original.

## 4. Const reference

Why can this parameter form be useful?

```cpp
void print(const std::vector<int>& values);
```

Answer: It avoids the overhead of copying data while using const to make sure the function can't accidentally mess up your original data.

## 5. Linux navigation

Which command shows the current working directory?

Answer:pwd

## 6. Git state

Which command shows modified files?

Answer: git status

