#ifndef SDDS_Phone_H
#define SDDS_Phone_H

struct Phone {
  char name[50];
  char area[50];
  char prefix[50];
  char number[50];
};

namespace sdds {
void phoneDir(const char* programTitle, const char* fileName);
}

#endif /* SDDS_Phone_H */
