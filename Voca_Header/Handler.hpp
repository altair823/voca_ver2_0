//
// Created by 김태현 on 2020/11/10.
//

#ifndef VOCA_VER2_0_HANDLER_HPP
#define VOCA_VER2_0_HANDLER_HPP
//#include <boost/di.hpp>
#include <iostream>

#include "File_ioHandler.hpp"
#include "Console_ioHandler.hpp"
#include "Quiz.hpp"

struct Handler {

private:

    Handler();

    vector<Word> wordList;

public:

    //Handler 인스턴스를 생성하는 함수
    static Handler* get();

    void setWordList(const vector<Word>&);
    vector<Word> getWordList();

    void printAllWord();

    void inputAWord();

    void deleteWord();

    //싱글톤 패턴
    Handler(Handler const&) = delete;
    Handler(Handler&&) = delete;
    Handler& operator=(Handler const&) = delete;
    Handler& operator=(Handler&&) = delete;

};

#endif //VOCA_VER2_0_HANDLER_HPP
