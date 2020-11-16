//
// Created by 김태현 on 2020/11/10.
//

#ifndef VOCA_VER2_0_FILE_IOHANDLER_HPP
#define VOCA_VER2_0_FILE_IOHANDLER_HPP

#include <fstream>

#include "Data_Structure.hpp"

struct FHandler{//; : boost::noncopyable {

private:
    ifstream vocaFile;

    FHandler();

public:
    static FHandler* get();

    int verifyFile();
    Word readAWord();
    vector<Word> readFile();

    //파일을 모두 지우고 필요한 내용을 위에서부터 저장하는 함수
    void saveFile(const vector<Word> &);

    //반드시 마지막에 호출할 것!
    void closeFHandler();


    FHandler(FHandler const&) = delete;
    FHandler(FHandler &&) = delete;
    FHandler& operator=(FHandler const&) = delete;
    FHandler& operator=(FHandler&&) = delete;

};

#endif //VOCA_VER2_0_FILE_IOHANDLER_HPP
