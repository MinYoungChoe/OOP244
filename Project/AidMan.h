#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
#include "iProduct.h"

const int sdds_max_num_items = 100;

namespace sdds{

class AidMan{
    char* fileName;
    Menu mainMenu;
    iProduct* m_items[sdds_max_num_items];
    int numOfPointers{};
    void deallocate();
    
public:
    unsigned int menu()const;
    AidMan();
    ~AidMan();
    void run();
    void save()const;
    bool load();
    int list(const char* sub_desc = nullptr);
    int search(int sku) const;
    void add();
    void remove(int index);
    void removeItem();
    void update();
    void sort();
    void ship();

};
}

#endif //SDDS_AIDMAN_H

