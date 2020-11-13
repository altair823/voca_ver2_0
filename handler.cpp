//
// Created by 김태현 on 2020/11/10.
//

#include "Voca_Header/handler.hpp"

Handler::Handler() {
    auto fileHandler = FHandler::get();
    vocaSize = 0;
}

Handler *Handler::get() {
    //C++11 이상에서 스레드 세이프 함
    static auto *handler = new Handler;
    return handler;
}

void Handler::test() {
    auto fileHandler = FHandler::get();
    fileHandler->readFile(wordList);
    Console::VocaStart("altair823", 3);
    Console::VocaChoice();

    fileHandler->closeFHandler();
}