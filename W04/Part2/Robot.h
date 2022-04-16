#ifndef Robot_h
#define Robot_h

namespace sdds {

class Robot{
    
    char* r_name;
    char* r_location;
    double r_weight;
    double r_width;
    double r_height;
    double r_speed;
    bool r_deployed;
    void resetInfo();
    
public:
    Robot();
    ~Robot();
    Robot(const char* name, const char* location, double weight = 0.0, double width = 0.0, double height = 0.0, double speed = 0.0, bool deployed = false);
    Robot& set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed);
    void setLocation(const char* location);
    void setDeployed(bool deployed);
    char* getName();
    char* getLocation();
    bool isDeployed() const;
    bool isValid() const;
    double speed() const;
    void display()const;    
};

int conrtolRooomReport(const Robot robot[], int num_robots);

}
#endif /* Robot_h */
