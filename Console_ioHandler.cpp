//
// Created by 김태현 on 2020/11/12.
//

#include "Voca_Header/Console_ioHandler.hpp"

void Console::VocaStart(const string& id) {
    cout<<id<<"'s Vocabulary"<<endl;
    cout<<"---------------------------------"<<endl;
}

CHOICE Console::VocaChoice() {
    CHOICE choice;
    while (true) {
        cout << "1. 단어들을 모두 출력" << endl;
        cout << "2. 단어 입력" << endl;
        cout << "3. 단어 삭제" << endl;
        cout << "4. 퀴즈" << endl;
        cout << "5. 프로그램 종료" << endl;
        cout << ">>";
        int choice_in;
        cin >> choice_in;
        switch (choice_in) {
            case 1:
                choice = CHOICE::PRINT;
                break;
            case 2:
                choice = CHOICE::INPUT;
                break;
            case 3:
                choice = CHOICE::DELETE;
                break;
            case 4:
                choice = CHOICE::QUIZ;
                break;
            case 5:
                choice = CHOICE::EXIT;
                break;
            default:
                cout<<"잘못된 입력입니다"<<endl;
                choice = CHOICE::FALSE;
                cin.clear();
                cin.ignore();
                break;

        }
        if (choice != CHOICE::FALSE){
            break;
        }
    }
    return choice;
}

string Console::inputEngWord() {
    string eng;

    while (true){
        cout<<"영어 단어를 입력하시오"<<endl;
        cout<<">>";
        cin>>eng;
        if (!eng.empty()){
            cin.clear();
            cin.ignore();
            return eng;
        }
        else{
            cout<<"잘못된 입력입니다"<<endl;
            cin.clear();
            cin.ignore();
        }
    }
}

Word Console::inputWord() {
    //영어 단어를 입력받음
    string eng = inputEngWord();

    //한국어 뜻을 입력 받음
    vector<string> kor;
    string buffer;
    cout<<"뜻을 입력하십시오. 숫자 0을 입력할 때까지 계속 입력할 수 있습니다."<<endl;
    while (true){
        cout<<">>";
        cin>>buffer;

        //만약 공백이 입력된다면 루프를 탈출하고 입력 받는 것을 중단함
        if (buffer == "0"){
            cin.clear();
            cin.ignore();
            return WordFactory::MakeWord(eng, kor);
        }
        else{
            kor.push_back(buffer);
            cin.clear();
            cin.ignore();

        }
    }
}

