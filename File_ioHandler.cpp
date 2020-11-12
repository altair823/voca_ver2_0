//
// Created by 김태현 on 2020/11/10.
//

#include "Voca_Header/File_ioHandler.hpp"

FHandler* FHandler::get() {
    static auto *fhandler = new FHandler;
    return fhandler;
}

void FHandler::test() {
    cout<<"test"<<endl;
}

