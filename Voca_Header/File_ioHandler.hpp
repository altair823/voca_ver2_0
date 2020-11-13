//
// Created by 김태현 on 2020/11/10.
//

#ifndef VOCA_VER2_0_FILE_IOHANDLER_HPP
#define VOCA_VER2_0_FILE_IOHANDLER_HPP

#include <fstream>

#include "Data_Structure.hpp"

struct FHandler{//; : boost::noncopyable {

private:
    fstream vocaFile;

    FHandler();

public:
    static FHandler* get();
    void test();

    int verifyFile();
    //void readAWord(Word &word);
    void readFile(vector<Word>& wordList);

    //파일을 닫고 저장하는 함수
    //반드시 마지막에 호출할 것!
    void closeFHandler();


    FHandler(FHandler const&) = delete;
    FHandler(FHandler &&) = delete;
    FHandler& operator=(FHandler const&) = delete;
    FHandler& operator=(FHandler&&) = delete;

    Word readAWord();
};

#endif //VOCA_VER2_0_FILE_IOHANDLER_HPP
