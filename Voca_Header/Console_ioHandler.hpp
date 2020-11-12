//
// Created by 김태현 on 2020/11/12.
//

#ifndef VOCA_VER2_0_CONSOLE_IOHANDLER_HPP
#define VOCA_VER2_0_CONSOLE_IOHANDLER_HPP

#include <iostream>

#include "Data_Structure.hpp"

struct Console{

    //시작화면
    static void VocaStart(const string& id, int vocaSize);

    //선택화면
    static CHOICE VocaChoice();
};

#endif //VOCA_VER2_0_CONSOLE_IOHANDLER_HPP
