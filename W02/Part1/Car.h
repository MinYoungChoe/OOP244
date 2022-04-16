#ifndef SDDS_Car_H
#define SDDS_Car_H

struct Car{
    char plate[9];
    char* makeAndModel;
    int time;
};

namespace sdds {
void VBPLE_Title();
void initialize(int allocSize);
void deallocate(Car& C);
bool read(Car& C);
void print(const Car& C);
void record(const Car& C);
void endOfDay();
}

#endif /* SDDS_Car_H */
