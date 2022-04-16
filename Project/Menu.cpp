#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string.h>
#include "Utils.h"
#include "Menu.h"

using namespace std;
using namespace sdds;

namespace sdds {

void Menu::setEmpty(){
    delete [] theMenuContent;
    theMenuContent = nullptr;
}
void Menu::setAvailable(int newAvailable){
    m_available = newAvailable;
    
}

Menu::Menu(){
    theMenuContent = nullptr;
    m_available = 0;
}

Menu::Menu(unsigned int newAvailable, const char* newContent){
    if(newAvailable <= 15 || newContent != nullptr){
        theMenuContent = new char[strlen(newContent)+1];
        }
    strcpy(theMenuContent,newContent);
    m_available = newAvailable;

}

Menu::~Menu(){
    delete [] theMenuContent;
    theMenuContent = nullptr;
}

unsigned int Menu::run()const{
    
    cout << theMenuContent;
    cout << 0 <<"- " << "Exit" << endl;
    return ut.getint(0, m_available, "> ");
}



}
