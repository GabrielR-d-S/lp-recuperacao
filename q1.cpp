#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    for (auto i = 0; i < 5; i++) {
        int x;
        std::cin >> x;
        vec.push_back(x);
    }

    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}