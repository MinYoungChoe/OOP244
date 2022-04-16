#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include "Perishable.h"
#include "AidMan.h"
#include "Utils.h"
#include "Status.h"
#include "Item.h"

namespace sdds {

unsigned int AidMan::menu() const{
    
    std::cout << "Aid Management System" << std::endl;
    std::cout << "Date: " << Date() << std::endl;
    
    if(fileName != nullptr){
        std::cout << "Data file: " << fileName << std::endl;
    }
    else{
        std::cout << "Data file: No file" << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;
    
    return mainMenu.run();
}

AidMan::AidMan():mainMenu{7,
    "1- List Items\n"
    
    "2- Add Item\n"
    
    "3- Remove Item\n"
    
    "4- Update Quantity\n"
    
    "5- Sort\n"
    
    "6- Ship Items\n"
    
    "7- New/Open Aid Database\n"
    
    "---------------------------------\n"
}
{
    fileName = nullptr;
}

AidMan::~AidMan(){
    delete [] fileName;
    fileName = nullptr;
}

void AidMan::run(){
    
    bool isZero = false;
    int userInput = 0;
    int userInput2 = 0;
    
    while(!isZero){

        userInput = menu();
        
        if(userInput != 0 && fileName == nullptr && userInput != 7){
            userInput = 7;
        }
        
        if(userInput == 1){
            std::cout << "\n****List Items****" << std::endl;
            if(list()){
                
                std::cout << "Enter row number to display details or <ENTER> to continue:\n> ";
                std::cin.clear();
                std::cin.ignore();
                if(std::cin.peek() != '\n'){
                    userInput2 = ut.getint(1, numOfPointers);
                }
                if(userInput2){
                    m_items[userInput2-1]->linear(false);
                    std::cout << *m_items[userInput2-1] << std::endl;
                }
                if(std::cin.peek() == '\n'){
                    std::cout << "\n";
                }
            }
        }
        if(userInput == 2){
            std::cout << "\n****Add Item****" << std::endl;
            add();
            save();
        }
        if(userInput == 3){
            std::cout << "\n****Remove Item****" << std::endl;
            removeItem();
            save();
        }
        if(userInput == 4){
            std::cout << "\n****Update Quantity****" << std::endl;
            update();
            save();
        }
        if(userInput == 5){
            std::cout << "\n****Sort****" << std::endl;
            std::cout << "Sort completed!\n\n";
            sort();
            save();
        }
        if(userInput == 6){
            std::cout << "\n****Ship Items****" << std::endl;
            ship();
        }
        if(userInput == 7){
            std::cout << "\n****New/Open Aid Database****" << std::endl;
            load();
        }
        if(userInput == 0){
            isZero = true;
        }
        
    }
    std::cout << "Exiting Program!" << std::endl;
    deallocate();
}
void AidMan::save()const{
    
    if(fileName){
        std::ofstream fout(fileName);
        for(int i = 0; i < numOfPointers; i++){
            m_items[i]->save(fout) << std::endl;
        }
    }
}

void AidMan::deallocate(){
    
    for(int i = 0; i < numOfPointers; i++ ){
        delete m_items[i];
        m_items[i] = nullptr;
    }
    numOfPointers = 0;
    delete [] fileName;
    fileName = nullptr;
}

bool AidMan::load(){
    bool isLoaded = false;
    int userInput = 0;
    bool isZero = false;
    int tempInput = 0;
    std::string tempFilename;
    
    save();
    std::cout << "Enter file name: ";
    std::cin.clear();
    std::cin.ignore();
    getline(std::cin, tempFilename, '\n');
    fileName = new char[strlen(tempFilename.c_str())+1];
    strcpy(fileName, tempFilename.c_str());
    
    if(fileName){
        std::ifstream fin(fileName);
        
        if(fin){
            int i = 0;
            while(tempInput != EOF && fin && i < sdds_max_num_items){
                tempInput = fin.peek();
                
                if (tempInput >= '1' && tempInput <= '3'){
                    m_items[i] = new Perishable;
                }
                else if(tempInput >= '4' && tempInput <='9'){
                    m_items[i] = new Item;
                }
                else{
                    fin.setstate(std::ios::failbit);
                    m_items[i] = nullptr;
                }
                if(m_items[i]){
                    m_items[i]->load(fin);
                    if(*m_items[i]){
                        numOfPointers++;
                        i++;
                    }
                    else{
                        delete m_items[i];
                        
                    }
                }
            }
        }
        else{
            std::cout << "Failed to open FN for reading!\n";
            std::cout << "Would you like to create a new data file?\n";
            std::cout << "1- Yes!\n";
            std::cout << "0- Exit\n";
            while(!isZero){
                userInput = ut.getint(0, 1,"> ");
                
                if(userInput == 1){
                    std::ofstream(fileName).flush();
                    isZero = true;
                    
                }
                else{
                    delete [] fileName;
                    fileName = nullptr;
                    isZero = true;
                }
            }
        }
        if(numOfPointers){
            std::cout << numOfPointers << " records loaded!\n" << std::endl;
        }
        
    }
    return isLoaded;
}

int AidMan::list(const char* sub_desc) {
    
    int counter = 0;
    
    if (*m_items) {
        
        std::cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << std::endl;
        std::cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << std::endl;
        
        if (sub_desc != nullptr && sub_desc[0] != '\0') {
            
            for (int i = 0; i< numOfPointers; i ++) {
                
                if (m_items[i]->operator==(sub_desc)) {
                    m_items[i]->linear(true);
                    std::cout << std::right << std::setw(4) << std::setfill(' ') << i+1 << " | ";
                    m_items[i]->display(std::cout);
                    std::cout << std::endl;
                    counter ++;
                }
            }
            std::cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << std::endl;
        }
        else{
            
            for (int i = 0; i< numOfPointers; i ++) {
                
                m_items[i]->linear(true);
                std::cout << std::right << std::setw(4) << std::setfill(' ') << i+1 << " | ";
                m_items[i]->display(std::cout);
                std::cout << std::endl;
                counter ++;
                
            }
            std::cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << std::endl;
        }
    }
    else{
        std::cout << "The list is emtpy!\n";
    }
    
    return counter;
}
int AidMan::search(int sku) const{
    int matched = -1;
    
    for(int i = 0; i < numOfPointers; i++){
        if(m_items[i]->operator==(sku)){
            matched = i;
        }
    }
    return matched;
}
void AidMan::add(){
    bool isZero = false;
    int userInput = 0;
    int tempSku = 0;
    int& i = numOfPointers;
    
    
    if(fileName==nullptr){
        std::cout << "No data file is open!\n";
    }
    else if(numOfPointers > sdds_max_num_items){
        std::cout << "Database full!\n";
    }
    else{
        std::cout << "1- Perishable\n";
        std::cout << "2- Non-Perishable\n";
        std::cout << "-----------------\n";
        std::cout << "0- Exit\n";
        std::cout << "> ";
        while(!isZero){
            userInput = ut.getint(0, 2);
            if(userInput == 1){
                
                m_items[i] = new Perishable;
                tempSku=m_items[i]->readSku(std::cin);
                if(search(tempSku) == -1){
                    m_items[i]->read(std::cin);
                    if(*m_items[i]){
                        i++;
                        tempSku=0;
                        isZero = true;
                    }
                }
                else{
                    std::cout << "Sku: 44444 is already in the system, try updating quantity instead.\n" <<std::endl;
                    delete m_items[i];
                    isZero = true;
                }
            }
            if(userInput == 2){
                m_items[i] = new Item;
                tempSku = m_items[i]->readSku(std::cin);
                if(search(tempSku) == -1){
                    m_items[i]->read(std::cin);
                    if(*m_items[i]){
                        i++;
                        isZero = true;
                    }
                }
                else{
                    std::cout << "Sku: 44444 is already in the system, try updating quantity instead.\n" <<std::endl;
                    delete m_items[i];
                    isZero = true;
                }
            }
            if(userInput == 0){
                std::cout << "Aborted\n";
                isZero = true;
            }
        }
    }
    
}

void AidMan::remove(int index){
    if(m_items[index]){
        delete m_items[index];
        for(int i = index; i < numOfPointers - 1; i++){
            m_items[i] = m_items[i+1];
        }
        numOfPointers--;
    }
}

void AidMan::removeItem(){
    std::string tempDescription = "";
    int tempSku = 0;
    int tempIndex = 0;
    
    std::cout << "Item description: ";
    
    std::cin.clear();
    std::cin.ignore();
    
    getline(std::cin, tempDescription, '\n');
    list(tempDescription.c_str());
    
    std::cout << "Enter SKU: ";
    std::cin >> tempSku;
    tempIndex = search(tempSku);
    
    if(tempIndex != -1){
        std::cout << "Following item will be removed: \n";
        m_items[tempIndex]->linear(false);
        m_items[tempIndex]->display(std::cout) << std::endl;
        
        std::cout << "Are you sure?\n";
        std::cout << "1- Yes!\n";
        std::cout << "0- Exit\n";
        std::cout << "> ";
        
        int userInput = 0;
        bool isZero = false;
        
        while(!isZero){
            userInput = ut.getint(0, 2);
            
            if(userInput == 1){
                remove(tempIndex);
                std::cout << "Item removed!\n\n";
                isZero = true;
            }
            
            if(userInput == 0){
                std::cout << "Aborted\n";
                isZero = true;
            }
        }
    }
    else{
        std::cout << "SKU not found!" << std::endl;
    }
}

void AidMan::update(){
    std::string tempDescription = "";
    int tempSku = 0;
    int tempIndex = 0;
    int addgAmount = 0;
    int reduceAmount = 0;
    int userInput = 0;
    bool isZero = false;
    
    std::cout << "Item description: ";
    
    std::cin.clear();
    std::cin.ignore();
    
    getline(std::cin, tempDescription, '\n');
    
    for(int i = 0; i < numOfPointers; i++){
        if(m_items[i]->operator==(tempDescription.c_str())){
            list(tempDescription.c_str());
        }
        else{
            //            std::cout << "No matches found!\n";
        }
    }
    
    std::cout << "Enter SKU: ";
    std::cin >> tempSku;
    tempIndex = search(tempSku);
    
    if(tempIndex != -1){
        std::cout << "1- Add\n";
        std::cout << "2- Reduce\n";
        std::cout << "0- Exit\n";
        std::cout << "> ";
        while(!isZero){
            userInput = ut.getint(0, 2);
            //            std::cin.clear();
            //            std::cin.ignore();
            if(userInput == 1){
                if(m_items[tempIndex]->qty() == m_items[tempIndex]->qtyNeeded()){
                    std::cout << "Quantity Needed already fulfilled!\n\n";
                    isZero = true;
                }
                else{
                    std::cout << "Quantity to add: ";
                    addgAmount = ut.getint(1, m_items[tempIndex]->qtyNeeded());
                    m_items[tempIndex]->operator+=(addgAmount);
                    std::cout << addgAmount << " items added!\n\n";
                    isZero = true;
                }
            }
            if(userInput == 2){
                if(m_items[tempIndex]->qty() == 0){
                    std::cout << "Quaintity on hand is zero!\n";
                    isZero = true;
                }
                
                else{
                    std::cout << "Quantity to reduce: ";
                    reduceAmount = ut.getint(1, m_items[tempIndex]->qtyNeeded());
                    m_items[tempIndex]->operator-=(reduceAmount);
                    
                    if(m_items[tempIndex]->qtyNeeded() - reduceAmount < 0){
                        std::cout << m_items[tempIndex]->qty();
                    }
                    else{
                        std::cout << reduceAmount;
                    }
                    std::cout << " items removed!\n\n";
                    isZero = true;
                }
            }
            
            if(userInput == 0){
                std::cout << "Aborted!\n\n";
                isZero = true;
            }
        }
    }
    else{
        std::cout << "SKU not found!\n" << std::endl;
    }
}
void AidMan::sort(){
    int i = 0;
    int j = 0;
    iProduct* temp;

    for (i = 0; i < numOfPointers-1; i++) {
        for (j = 0; j < numOfPointers-1-i; j++) {
            if ((m_items[j]->qtyNeeded()-m_items[j]->qty()) < (m_items[j+1]->qtyNeeded()-m_items[j+1]->qty())) {
                temp = m_items[j];
                m_items[j] = m_items[j+1];
                m_items[j+1] = temp;
            }
        }
    }
    
}
void AidMan::ship(){
    
    std::ofstream fout("shippingOrder.txt");
    ut.testMode(true);
    Date currentDate;
    int counter = 0;
    fout << "Shipping Order, Date: " << currentDate << std::endl;
    
    if (*m_items) {
        
        fout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << std::endl;
        fout << "-----+-------+-------------------------------------+------+------+---------+-----------" << std::endl;
        
        for (int i = 0; i< numOfPointers; i ++) {
            
            if (m_items[i]->qty() == m_items[i]->qtyNeeded()) {
                m_items[i]->linear(true);
                fout << std::right << std::setw(4) << std::setfill(' ') << counter+1 << " | ";
                m_items[i]->display(fout);
                fout << std::endl;
                remove(i);
                save();
                counter ++;
            }
        }
        fout << "-----+-------+-------------------------------------+------+------+---------+-----------" << std::endl;
        fout.close();
        std::cout << "Shipping Order for " << counter << " times saved!\n" << std::endl;
        
    }
}
}
