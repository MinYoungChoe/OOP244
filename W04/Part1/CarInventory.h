#ifndef SDDS_CarInventory_h
#define SDDS_CarInventory_h
namespace sdds {

class CarInventory{
private:
    char* m_type;
    char* m_brand;
    char* m_model;
    int m_year;
    int m_code;
    double m_price;
    void resetInfo();

public:
    CarInventory();
    CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price= 1);
    ~CarInventory();
    CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
    void printInfo() const;
    bool isValid() const;
    bool isSimilarTo(const CarInventory& car) const;

};

bool find_similar(CarInventory car[], const int num_cars);

}

#endif /* SDDS_CarInventory */
