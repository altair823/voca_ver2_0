//
// Created by 김태현 on 2020/11/10.
//

#ifndef VOCA_VER2_0_HANDLER_HPP
#define VOCA_VER2_0_HANDLER_HPP
#include <boost/di.hpp>
#include <iostream>

#include "File_ioHandler.hpp"
#include "Console_ioHandler.hpp"

struct Handler : public boost::noncopyable {

private:

    Handler();


public:
    static Handler* get();
    void test();
};

#endif //VOCA_VER2_0_HANDLER_HPP
