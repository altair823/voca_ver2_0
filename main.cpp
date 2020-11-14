#include <iostream>
#include "Voca_Header/handler.hpp"

int main() {
    std::cout << "테스트" << std::endl;
    Handler* handler;

    handler = Handler::get();

    while (true){
        switch (Console::VocaChoice()) {
            case CHOICE::PRINT:
                handler->printAllWord();
                break;
            case CHOICE::INPUT:
                handler->inputAWord();
                break;
            case CHOICE::DELETE:
                break;
            case CHOICE::QUIZ:
                break;
            case CHOICE::FALSE:
                break;
            case CHOICE::EXIT:
                exit(0);
        }
    }

    return 0;
}
