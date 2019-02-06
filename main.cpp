#include <iostream>

#define DEBUG true

#if DEBUG
#include "input.h"
#endif

int main() {
#if DEBUG
    auto input = jung::getIfStream(jung::getPath("../sample.txt"));
    #define cin input
#else
    #define cin std::cin
#endif

    std::string hello;
    cin >> hello;

    std::cout << hello << std::endl;
    return 0;
}