//
// Created by 김태현 on 2020/11/10.
//

#ifndef VOCA_VER2_0_HANDLER_HPP
#define VOCA_VER2_0_HANDLER_HPP
//#include <boost/di.hpp>
#include <iostream>

#include "File_ioHandler.hpp"
#include "Console_ioHandler.hpp"

struct Handler{//; : public boost::noncopyable {

private:

    Handler();

    vector<Word> wordList;

    //FHandler fileHandler;

public:
    static Handler* get();
    void test();

    void printAllWord();

    void inputAWord();

    //싱글톤 패턴
    Handler(Handler const&) = delete;
    Handler(Handler&&) = delete;
    Handler& operator=(Handler const&) = delete;
    Handler& operator=(Handler&&) = delete;

};

#endif //VOCA_VER2_0_HANDLER_HPP
