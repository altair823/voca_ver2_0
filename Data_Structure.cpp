//
// Created by 김태현 on 2020/11/11.
//

#include "Voca_Header/Data_Structure.hpp"

#include <utility>


Word WordFactory::MakeWord(string eng, vector<string> kor) {

    //영어단어가 입력되지 않으면
    if (eng.empty()){
        cout<<"No english word input error!"<<endl;
        exit(9);
    }

    if(kor.empty()){
        cout<<"No korean word input error!"<<endl;
#ifndef NO_KOR_WORD_ALLOW
        exit(9);
#endif
    }

    //입력받은 매개변수가 이상이 없다면
    //단어 객체를 생성하여 반환
    return Word{eng, kor};
}
static inline void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}


// trim from end (in place)
static inline void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}


Word::Word(string &eng_in, vector<string> &kor_in) : eng(eng_in), kor(kor_in) {

    //Word 객체를 생성할 때 매개변수로 주어진 string과 vector<string>들에 포함된 양옆의 공백을 삭제
    int n;
    n = eng.find_first_not_of(' ');
    if ( n != string::npos )
        eng.replace(0, n,"");
    n = eng.find_last_not_of(' ');
    if ( n != string::npos )
        eng.replace(n+1, eng.length()-n,"");

    for (auto& i : kor){
        n = i.find_first_not_of(' ');
        if ( n != string::npos )
            i.replace(0, n,"");
        n = i.find_last_not_of(' ');
        if ( n != string::npos )
            i.replace(n+1, eng.length()-n,"");
    }
}


string Word::getEng() const {
    return eng;
}

vector<string> Word::getKorVec() const {
    return kor;
}

ostream &operator<<(ostream &os, const Word &ref) {
    os<<ref.eng<<": ";
    for (auto& i : ref.kor) {
        os<<i;
        if (i != *ref.kor.rbegin()){
            os<<", ";
        }
    }
    return os;
}


