//
// Created by 김태현 on 2020/11/10.
//

#include "Voca_Header/File_ioHandler.hpp"

FHandler* FHandler::get() {
    static auto *fhandler = new FHandler;
    return fhandler;
}


FHandler::FHandler() {
    static int fileErrorCount = 0;
    while (true) {
#ifdef PROGRAM_RELEASED
        vocaFile.open(FILE_PATH);
#endif
#ifndef PROGRAM_RELEASED
        vocaFile.open("voca.txt");
#endif
        if (vocaFile.is_open()) {
            cout << "file opened successfully" << endl;
            break;
        }

        //파일이 열리지 않으면 새 파일을 만든다.
        else {
            cout << "file open error" << endl;
            if (fileErrorCount == 5){
                cout<<"file can not opened!"<<endl;
                cout<<"exit program"<<endl;
                exit(7);
            }
            cout << "make a new file" << endl;
            ofstream makeFile;
#ifdef PROGRAM_RELEASED
            makeFile.open(FILE_PATH);
#endif
#ifndef PROGRAM_RELEASED
            makeFile.open("voca.txt");
            makeFile.close();
            fileErrorCount++;
#endif
        }
    }


}

void FHandler::closeFHandler() {
    cout<<"close"<<endl;
    vocaFile.close();
}

Word FHandler::readAWord() {
    string buffer;
    string eng;
    vector<string> kor;

    getline(vocaFile, buffer, '\n');
    getline(vocaFile, eng, '-');

    for (int i=0; ; i++){
        getline(vocaFile, buffer, '-');
        //cout<<buffer<<endl;
        if (buffer == "/"){
            break;
        }
        kor.push_back(buffer);
    }

    //cout<<"tt"<<endl;
    auto word = WordFactory::MakeWord(eng, kor);
    //cout<<"gg"<<endl;
    return word;
}
/*
bool FHandler::isThisEnd(){
    string buffer;
    getline(vocaFile, buffer, '\n');
}
 */

void FHandler::readFile(vector<Word> &wordList) {
    int size = verifyFile();
    cout<<size<<endl;
    for (int i = 0;i<size; ++i) {
        wordList.push_back(readAWord());
        cout<<wordList[i]<<endl;
    }
}


int FHandler::verifyFile() {
    string verify;
    vocaFile>>verify;
    if (verify != VERIFY_STRING){
        cout<<"Invalid file content!"<<endl;
        exit(8);
    }

    string buffer;
    int listSize;

    vocaFile>>buffer;
    vocaFile>>listSize;
    return listSize;
}

