//
// Created by 김태현 on 2020/11/11.
//

#ifndef VOCA_VER2_0_DATA_STRUCTURE_HPP
#define VOCA_VER2_0_DATA_STRUCTURE_HPP

#define NO_KOR_WORD_ALLOW
//#define PROGRAM_RELEASED
#define FILE_PATH "./desktop/voca.txt"
#define VERIFY_STRING "altair823"

#include <iostream>
#include <vector>
//#include <boost/noncopyable.hpp>

using namespace std;
struct WordFactory;

enum class CHOICE{
    PRINT,
    INPUT,
    DELETE,
    QUIZ,
    EXIT,
    FALSE
};


//단어를 저장하는 기본 단위
struct Word{

    vector<string> PrintWord();

    friend WordFactory;
    friend ostream& operator<<(ostream& os, const Word&);
    //Word(const Word&);
private:
    string eng;
    vector<string> kor;

    Word(string& eng, vector<string>& kor);
    //~Word() = default;

};

//단어를 생성하는 팩터리
struct WordFactory{

    static Word MakeWord(string eng, vector<string> kor);
};

#endif //VOCA_VER2_0_DATA_STRUCTURE_HPP
