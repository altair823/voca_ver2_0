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


Word::Word(string &eng, vector<string> &kor) : eng(eng), kor(kor) {

}

vector<string> Word::PrintWord() {
    vector<string> wordLine(kor);
    wordLine.insert(wordLine.begin(), eng);
    return wordLine;
}

