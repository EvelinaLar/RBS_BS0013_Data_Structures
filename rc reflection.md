[1mdiff --git a/labs/week01/assignment.md b/labs/week01/assignment.md[m
[1mindex 5e1959a..6509943 100644[m
[1m--- a/labs/week01/assignment.md[m
[1m+++ b/labs/week01/assignment.md[m
[36m@@ -542,11 +542,14 @@[m [mBefore running it:[m
 **What will it print?**[m
 [m
 Write down your prediction.[m
[32m+[m[32m11[m
 [m
 Now compile and run it.[m
[32m+[m[32mg++ -std=c++20 -Wall -Wextra -Wpedantic src/value_reference.cpp -o build/manual/value_reference[m
[32m+[m[32m./build/manual/value_reference[m
 [m
 Explain why the result occurs.[m
[31m-[m
[32m+[m[32mIt did not change because the function operated on a temporary copy of the variable rather than the original variable itself.[m
 ---[m
 [m
 # 12. Pass by reference[m
[36m@@ -564,11 +567,12 @@[m [mvoid increment(int& x)[m
 ```[m
 [m
 Predict again.[m
[31m-[m
[32m+[m[32m11[m
 Compile and run.[m
[31m-[m
[32m+[m[32mg++ -std=c++20 -Wall -Wextra -Wpedantic src/value_reference.cpp -o build/manual/value_reference[m
[32m+[m[32m./build/manual/value_reference[m
 What changed?[m
[31m-[m
[32m+[m[32mThe output[m
 Explain the difference between:[m
 [m
 ```cpp[m
[36m@@ -580,7 +584,7 @@[m [mand:[m
 ```cpp[m
 int& x[m
 ```[m
[31m-[m
[32m+[m[32mThe difference is that with int x, the main function result does not change, but with the &, it modifies the original value.[m
 ---[m
 [m
 # 13. Working with `std::vector`[m
[36m@@ -605,7 +609,8 @@[m [mint main() {[m
 ```[m
 [m
 Compile and run it.[m
[31m-[m
[32m+[m[32mg++ -std=c++20 -Wall -Wextra -Wpedantic src/vector_basics.cpp -o build/manual/vector_basics[m
[32m+[m[32m./build/manual/vector_basics[m
 Now modify the program so the vector contains:[m
 [m
 ```text[m
[36m@@ -640,13 +645,18 @@[m [ma.push_back(4);[m
 Without running the program, predict:[m
 [m
 ```text[m
[31m-a = ?[m
[31m-b = ?[m
[31m-c = ?[m
[32m+[m[32ma = 20[m
[32m+[m[32mb = 10[m
[32m+[m[32mc = 20[m
 ```[m
 [m
 Then write code to print all three containers and test your prediction.[m
 [m
[32m+[m[32mreal results:[m
[32m+[m[32ma = 1 20 3 4[m[41m [m
[32m+[m[32mb = 10 2 3[m[41m [m
[32m+[m[32mc = 1 20 3 4[m[41m [m
[32m+[m
 ## Explain[m
 [m
 What happened when we wrote:[m
[36m@@ -660,6 +670,8 @@[m [mWhat happened when we wrote:[m
 ```cpp[m
 auto& c = a;[m
 ```[m
[32m+[m[32mauto b = a; creates a separate copy that can be modified independently, whereas auto& c = a; creates a direct nickname so changes to it affect the original vector.[m
[32m+[m
 [m
 This distinction will become increasingly important when our structures become larger and more complicated.[m
 [m
[36m@@ -679,7 +691,13 @@[m [mImplement:[m
 void print_values(const std::vector<int>& values);[m
 ```[m
 [m
[31m-The function should print all values.[m
[32m+[m[32mThe function should print all values:[m
[32m+[m[32mvoid print_values(const std::vector<int>& values) {[m
[32m+[m[32m    for (int v : values) {[m
[32m+[m[32m        std::cout << v << ' ';[m
[32m+[m[32m    }[m
[32m+[m[32m    std::cout << '\n';[m
[32m+[m[32m}[m
 [m
 Implement:[m
 [m
[36m@@ -687,7 +705,14 @@[m [mImplement:[m
 int sum(const std::vector<int>& values);[m
 ```[m
 [m
[31m-The function should return their sum.[m
[32m+[m[32mThe function should return their sum:[m
[32m+[m[32mint sum(const std::vector<int>& values) {[m
[32m+[m[32m    int total = 0;[m
[32m+[m[32m    for (int v : values) {[m
[32m+[m[32m        total += v;[m
[32m+[m[32m    }[m
[32m+[m[32m    return total;[m
[32m+[m[32m}[m
 [m
 Implement:[m
 [m
[36m@@ -695,7 +720,12 @@[m [mImplement:[m
 void add_to_all(std::vector<int>& values, int amount);[m
 ```[m
 [m
[31m-The function should add `amount` to every element.[m
[32m+[m[32mThe function should add `amount` to every element:[m
[32m+[m[32mvoid add_to_all(std::vector<int>& values, int amount) {[m
[32m+[m[32m    for (int& v : values) {[m
[32m+[m[32m        v += amount;[m
[32m+[m[32m    }[m
[32m+[m[32m}[m
 [m
 For example:[m
 [m
[36m@@ -742,10 +772,11 @@[m [mvoid add_to_all(std::vector<int> values, int amount)[m
 Compile and run again.[m
 [m
 What happens?[m
[32m+[m[32mThe code compiles and runs, but the vector in main() remains unchanged.[m
 [m
 The function itself still modifies something.[m
 [m
[31m-So why does the vector in `main()` remain unchanged?[m
[32m+[m[32mSo why does the vector in `main()` remain unchanged? The local copy is destroyed when the function ends, leaving the original vector untouched.[m
 [m
 Restore the correct version afterwards.[m
 [m
[1mdiff --git a/labs/week01/src/broken.cpp b/labs/week01/src/broken.cpp[m
[1mindex 648c46c..9daf3a9 100644[m
[1m--- a/labs/week01/src/broken.cpp[m
[1m+++ b/labs/week01/src/broken.cpp[m
[36m@@ -2,13 +2,13 @@[m
 #include <vector>[m
 [m
 int main() {[m
[31m-    std::vector<int> values{4, 8, 15, 16, 23, 42}[m
[32m+[m[32m    std::vector<int> values{4, 8, 15, 16, 23, 42};[m
 [m
[31m-    for (int value : value) {[m
[31m-        cout << value << ' ';[m
[32m+[m[32m    for (int value : values) {[m
[32m+[m[32m        std::cout << value << ' ';[m
     }[m
 [m
[31m-    std::cout << '\n'[m
[31m-    return "0";[m
[32m+[m[32m    std::cout << '\n';[m
[32m+[m[32m    return 0;[m
 }[m
 [m
[1mdiff --git a/labs/week01/src/sequence.cpp b/labs/week01/src/sequence.cpp[m
[1mindex 800f755..d63ec3a 100644[m
[1m--- a/labs/week01/src/sequence.cpp[m
[1m+++ b/labs/week01/src/sequence.cpp[m
[36m@@ -2,20 +2,24 @@[m
 #include <vector>[m
 [m
 void print_values(const std::vector<int>& values) {[m
[31m-    (void)values;  // Remove this placeholder when the function is implemented.[m
[31m-    // TODO: print every value followed by a space, then print a newline.[m
[32m+[m[32m    for (int v : values) {[m
[32m+[m[32m        std::cout << v << ' ';[m
[32m+[m[32m    }[m
[32m+[m[32m    std::cout << '\n';[m
 }[m
 [m
 int sum(const std::vector<int>& values) {[m
[31m-    (void)values;  // Remove this placeholder when the function is implemented.[m
[31m-    // TODO: calculate and return the sum of the values.[m
[31m-    return 0;[m
[32m+[m[32m    int total = 0;[m
[32m+[m[32m    for (int v : values) {[m
[32m+[m[32m        total += v;[m
[32m+[m[32m    }[m
[32m+[m[32m    return total;[m
 }[m
 [m
 void add_to_all(std::vector<int>& values, int amount) {[m
[31m-    (void)values;  // Remove these placeholders when the function is implemented.[m
[31m-    (void)amount;[m
[31m-    // TODO: add amount to every element.[m
[32m+[m[32m    for (int& v : values) {[m
[32m+[m[32m        v += amount;[m
[32m+[m[32m    }[m
 }[m
 [m
 int main() {[m
[1mdiff --git a/labs/week01/src/value_reference.cpp b/labs/week01/src/value_reference.cpp[m
[1mindex d4fc7f7..2ee36ea 100644[m
[1m--- a/labs/week01/src/value_reference.cpp[m
[1m+++ b/labs/week01/src/value_reference.cpp[m
[36m@@ -1,6 +1,6 @@[m
 #include <iostream>[m
 [m
[31m-void increment(int x) {[m
[32m+[m[32mvoid increment(int& x) {[m
     ++x;[m
 }[m
 [m
[1mdiff --git a/labs/week01/src/vector_basics.cpp b/labs/week01/src/vector_basics.cpp[m
[1mindex e8b0179..2fbd341 100644[m
[1m--- a/labs/week01/src/vector_basics.cpp[m
[1m+++ b/labs/week01/src/vector_basics.cpp[m
[36m@@ -5,6 +5,7 @@[m [mint main() {[m
     std::vector<int> values{10, 20, 30};[m
 [m
     values.push_back(40);[m
[32m+[m[32m    values.push_back(50);[m
 [m
     for (int value : values) {[m
         std::cout << value << ' ';[m
[36m@@ -13,5 +14,10 @@[m [mint main() {[m
     std::cout << '\n';[m
 [m
     // TODO: add 50, then print the size, first element, and last element.[m
[32m+[m[32m    std::cout << "Number of elements: " << values.size() << '\n';[m
[32m+[m
[32m+[m[32m    std::cout << "First element: " << values.front() << '\n';[m
[32m+[m
[32m+[m[32m    std::cout << "Last element: " << values.back() << '\n';[m
 }[m
 [m
