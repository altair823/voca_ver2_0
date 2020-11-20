#include <iostream>
#include "Voca_Header/Handler.hpp"

int main() {
    Handler* handler;
    auto fhandler = FHandler::get();

    handler = Handler::get();
    handler->setWordList(fhandler->readFile());

    fhandler->closeFHandler();

    while (true){
        switch (Console::VocaChoice()) {
            case CHOICE::PRINT:
                handler->printAllWord();
                break;
            case CHOICE::INPUT:
                handler->inputAWord();
                break;
            case CHOICE::DELETE:
                handler->deleteWord();
                break;
            case CHOICE::QUIZ:
                break;
            case CHOICE::FALSE:
                break;
            case CHOICE::EXIT:
                fhandler->saveFile(handler->getWordList());
                return 0;
        }
    }

}
