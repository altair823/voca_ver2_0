//
// Created by 김태현 on 2020/11/10.
//

#include "Voca_Header/handler.hpp"

Handler::Handler() = default;

Handler *Handler::get() {
    //C++11 이상에서 스레드 세이프 함
    static auto *handler = new Handler;
    return handler;
}

void Handler::test() {
    auto a = FHandler::get();
    a->test();
    Console::VocaStart("altair823", 3);
    Console::VocaChoice();

}