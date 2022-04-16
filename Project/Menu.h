#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds {

class Menu{
    char* theMenuContent;
    unsigned int m_available;
    void setEmpty();
    
public:
    void setAvailable(int newAvailable);
    Menu();
    Menu(unsigned int newAvailable, const char* newContent = {});
    ~Menu();
    Menu(const Menu&) = delete;
    void operator=(const Menu&) = delete;
    unsigned int run()const;
};

}

#endif// !SDDS_MENU_H
