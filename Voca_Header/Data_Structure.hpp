//
// Created by 김태현 on 2020/11/11.
//

#ifndef VOCA_VER2_0_DATA_STRUCTURE_HPP
#define VOCA_VER2_0_DATA_STRUCTURE_HPP

#define DEBUG_MODE_ON
#define NO_KOR_WORD_ALLOW

#define VERIFY_STRING "altair823"

#ifndef DEBUG_MODE_ON
#define FILE_PATH "./desktop/voca.txt"
#endif
#ifdef DEBUG_MODE_ON
#define FILE_PATH "voca.txt"
#endif

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

    friend WordFactory;
    friend ostream& operator<<(ostream&, const Word&);
    friend fstream& operator<<(fstream&, const Word&);

    [[nodiscard]] string getEng() const;
    [[nodiscard]] vector<string> getKorVec() const;

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
