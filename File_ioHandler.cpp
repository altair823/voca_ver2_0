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
        vocaFile.open(FILE_PATH);
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
            makeFile.open(FILE_PATH);
            makeFile.close();
            fileErrorCount++;
        }
    }


}

void FHandler::closeFHandler() {
#ifdef DEBUG_MODE_ON
    cout<<"file is close"<<endl;
#endif
    vocaFile.close();
}

Word FHandler::readAWord() {
    string buffer;
    string eng;
    vector<string> kor;

    getline(vocaFile, buffer, '\n');
    getline(vocaFile, eng, ':');

    for (int i=0; ; i++){
        getline(vocaFile, buffer, ',');
        //cout<<buffer<<endl;
        if (buffer == "/"){
            break;
        }
        kor.push_back(buffer);
    }

    //cout<<"tt"<<endl;
    return WordFactory::MakeWord(eng, kor);
    //cout<<"gg"<<endl;
    //return word;
}

vector<Word> FHandler::readFile() {
    vector<Word> wordList;
    int size = verifyFile();
    wordList.reserve(size);
    for (int i = 0;i<size; ++i) {
        wordList.push_back(readAWord());
    }
    return wordList;
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

void FHandler::saveFile(const vector<Word> &wordList) {
    bool isFileAlreadyOpen = false;
    if (vocaFile.is_open()){
        cout<<"읽기전용 파일 스트림이 열려있습니다."<<endl;
        cout<<"파일을 저장하기 위해 읽기전용 파일 스트림을 닫고 쓰기전용 파일 스트림을 엽니다."<<endl;
        isFileAlreadyOpen = true;
        closeFHandler();
    }

    ofstream vocaFileOut;

    vocaFileOut.open(FILE_PATH);
    vocaFileOut<<VERIFY_STRING<<endl;

    vocaFileOut<<"voca_size: "<<wordList.size()<<endl;

    for (auto& i : wordList){
        vocaFileOut<<i<<",/,"<<endl;
    }

}


