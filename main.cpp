#include <iostream>
#include "Voca_Header/handler.hpp"

int main() {
    std::cout << "테스트" << std::endl;
    Handler* handler;

    handler = Handler::get();
    handler->test();
    return 0;
}
