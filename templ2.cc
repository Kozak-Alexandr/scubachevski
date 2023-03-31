#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>
#include <iomanip>

template<typename T>
bool f1(const T& cont, const typename T::value_type key) {
        return std::any_of(cont.cbegin(), cont.cend(),
                           [key](auto elem){ return (elem == key); });
}

int main() {
        std::vector<int> vec{1, 2, 3, 4};
        std::cout << (f1<std::vector<int>>(vec, 2) ? "ye" : "no") << std::endl;
        return 0;
}
