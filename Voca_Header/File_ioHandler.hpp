//
// Created by 김태현 on 2020/11/10.
//

#ifndef VOCA_VER2_0_FILE_IOHANDLER_HPP
#define VOCA_VER2_0_FILE_IOHANDLER_HPP

#include <fstream>

#include "Data_Structure.hpp"

struct FHandler : boost::noncopyable {

private:
    FHandler() = default;

public:
    static FHandler* get();
    void test();
};

#endif //VOCA_VER2_0_FILE_IOHANDLER_HPP
