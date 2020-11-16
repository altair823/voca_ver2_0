//
// Created by 김태현 on 2020/11/10.
//

#include "Voca_Header/handler.hpp"

Handler::Handler() {
    auto fileHandler = FHandler::get();

    Console::VocaStart("altair823");
}

Handler *Handler::get() {
    //C++11 이상에서 스레드 세이프 함
    static auto *handler = new Handler;
    return handler;
}


void Handler::printAllWord() {
    for (auto& i : wordList) {
        cout<<i<<endl;
    }
}

void Handler::inputAWord() {
    wordList.push_back(Console::inputWord());
    cout<<wordList.capacity()<<endl;
}

void Handler::deleteWord() {
    string inputWord = Console::inputEngWord();
    for (int i=0; i<wordList.size(); i++){
        if (inputWord == wordList[i].getEng()){
            wordList.erase(wordList.begin() + i);
        }
    }
}

void Handler::setWordList(const vector<Word> &ref) {
    wordList.assign(ref.begin(), ref.end());
    cout<<"Vocabulary size is "<<wordList.size()<<endl;
}

vector<Word> Handler::getWordList() {
    return wordList;
}
