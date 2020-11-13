//
// Created by 김태현 on 2020/11/12.
//

#include "Voca_Header/Console_ioHandler.hpp"

void Console::VocaStart(const string& id, int vocaSize) {
    cout<<id<<"'s Vocabulary"<<endl;
    cout<<"Vocabulary size is "<<vocaSize<<endl;
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
                break;

        }
        if (choice != CHOICE::FALSE){
            break;
        }
    }
    return choice;
}
