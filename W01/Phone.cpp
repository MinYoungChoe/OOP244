#include <iostream>
#include "Phone.h"
#include "cStrTools.h"

using namespace std;
using namespace sdds;

namespace sdds {
void phoneDir(const char* programTitle, const char* fileName){
    char input[50];
    input[0] = '\0';
    char tempInput[50];
    tempInput[0] = '\0';
    char exit[] = "!";
    
    FILE *fp = NULL;
    
    Phone phone1[100];
    cout << programTitle << " phone direcotry search" << endl;
    cout <<"-------------------------------------------------------" << endl;
    
    do {
        fp=fopen(fileName, "r");
        if (fp != NULL){
            int i = 0;
            cout << "Enter a partial name to search (no spaces) or enter '!' to exit\n> ";
            cin >> tempInput;
            toLowerCaseAndCopy(input,tempInput);
            input[0] = toupper(input[0]);
            while(fscanf(fp, "%[^\t]\t%s\t%s\t%s\n", phone1[i].name, phone1[i].area, phone1[i].prefix, phone1[i].number)!= EOF){
                if((strStr(phone1[i].name, input) != nullptr)){
                    cout << phone1[i].name << ":" << " ("<< phone1[i].area << ") " << phone1[i].prefix << "-" << phone1[i].number << endl;
                }
                
                else{
                    i++;
                }
            }
            fclose(fp);
            
        }
        else{
            cout << fileName << " " << "file not found!" << endl;
            cout << "Thank you for using Broken Phone Book directory." << endl;
            break;
        }
        
    }while(strCmp(exit,input) != 0);
    cout << "Thank you for using Star Wars directory." << endl;
    
}
}
