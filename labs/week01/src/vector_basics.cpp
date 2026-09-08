#include <iostream>
#include <vector>

int main() {
    std::vector<int> values{10, 20, 30};

    values.push_back(40);
    values.push_back(50);

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    // TODO: add 50, then print the size, first element, and last element.
    std::cout << "Number of elements: " << values.size() << '\n';

    std::cout << "First element: " << values.front() << '\n';

    std::cout << "Last element: " << values.back() << '\n';
}

