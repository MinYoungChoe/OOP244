#include <iostream>
#include <string.h>
#include<iomanip>

#include "Robot.h"
using namespace std;

namespace sdds {
void Robot::resetInfo(){

    if(r_name){
        delete [] r_name;
        
    }

    if(r_location){
        delete [] r_location;
    }
    
    r_name = nullptr;
    r_location = nullptr;
    r_weight = 0.0;
    r_width = 0.0;
    r_height = 0.0;
    r_speed = 0.0;
    r_deployed = false;
}
Robot::Robot(){
    r_name = nullptr;
    r_location = nullptr;
    resetInfo();
}

Robot::Robot(const char* name, const char* location, double weight,
             double width, double height, double speed, bool deployed){

    r_name = new char[strlen(name)+1];
    strcpy(r_name, name);
    r_location = new char[strlen(location)+1];
    strcpy(r_location, location);
    r_weight = weight;
    r_width = width;
    r_height = height;
    r_speed = speed;
    r_deployed = deployed;
}

Robot::~Robot(){
    if(r_name){
        delete[] r_name;
        r_name = nullptr;
    }
    if(r_location){
        delete [] r_location;
        r_location = nullptr;
    }
}

Robot& Robot::set(const char* name, const char* location, double weight,
                  double width, double height, double speed, bool deployed){
    resetInfo();
    r_name = new char[strlen(name)+1];
    strcpy(r_name, name);
    r_location = new char[strlen(location)+1];
    strcpy(r_location, location);
    r_weight = weight;
    r_width = width;
    r_height = height;
    r_speed = speed;
    r_deployed = deployed;
    return *this;
}
void Robot::setLocation(const char* location){
    if(r_location){
        delete [] r_location;
        r_location = nullptr;
    }
    r_location = new char[strlen(location)+1];
    strcpy(r_location, location);
}
void Robot::setDeployed(bool deployed){
    r_deployed = deployed;
}
char* Robot::getName(){
    return r_name;
}
char* Robot::getLocation(){
    return r_name;
}
bool Robot::isDeployed() const{
    return r_deployed;
}
bool Robot::isValid() const{
    return (r_name && r_location)
    && (r_weight >= 0 && r_width > 0 && r_height > 0 && r_speed > 0);
}
double Robot::speed()const{
    return r_speed;
}
void Robot::display()const{

    cout << "| "  << setw(10) << left  << r_name;
    cout << " | " << setw(15) << left  << r_location;
    cout << " | " << setw(6)  << right << fixed << setprecision(1) << r_weight;
    cout << " |"  << setw(7)  << right << fixed << setprecision(1) << r_width;
    cout << " |"  << setw(7)  << right << fixed << setprecision(1) << r_height;
    cout << " |"  << setw(7)  << right << fixed << setprecision(1) << r_speed;
    
    
    if(r_deployed){
        cout << " | " << setw(8) << left <<"YES" << " |" << endl;
    }
    else{
        cout << " | " << setw(8) << left << "NO" << " |" << endl;
    }
}
int conrtolRooomReport(const Robot robot[], int num_robots){
    int invalidArrayIndex = -1, numberOfDeployed = 0;
    int equaNumrobots = 0;
    cout << "                        ------ Robot Control Room -----" << endl;;
    cout << "                    ---------------------------------------" << endl;;
    cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" <<endl;
    cout << "|------------+-----------------+--------+--------+--------+--------+----------|" <<endl;
    
    bool isInvlidFound = false;
    for (int i = 0; i < num_robots && !isInvlidFound; i++){
        
        if(robot[i].isValid()){
            robot[i].display();
            equaNumrobots++;

            if(robot[i].isDeployed()){
                numberOfDeployed++;
            }
        }
        else{
            invalidArrayIndex = i;
            isInvlidFound = true;
        }
    }
    
    int fastestLocation = 0;
    double max = 0;
    
    for(int i = 0; i < num_robots; i++){
        if(robot[i].speed() > max){
            max = robot[i].speed();
            fastestLocation = i;
        }
    }
    
    
    if(equaNumrobots == num_robots){
        cout << setw(60) << "|=============================================================================|" << endl;;
        cout <<             "| SUMMARY:                                                                    |" <<endl;
        cout << "| " << setw(3) <<numberOfDeployed << "robots are deployed.                                                     |" <<endl;
        cout << "| The fastest robot is:                                                       |" <<endl;
        cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" <<endl;
        cout << "|------------+-----------------+--------+--------+--------+--------+----------|" <<endl;
        robot[fastestLocation].display();
        cout << setw(60) << "|=============================================================================|" << endl;;
    }
    
    return invalidArrayIndex;
}

}
