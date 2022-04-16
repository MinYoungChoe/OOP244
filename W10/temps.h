#ifndef SDDS_TEMPS_H_
#define SDDS_TEMPS_H_
#include "Collection.h"
#include "Car.h"
#include "Employee.h"
#include "Student.h"

namespace sdds {

template<typename type>
Collection<type> select(const type m_array[], int m_size, const type& m_reference);

template<typename type>
void printCollection(const type& m_reference, const char* m_title);

template<typename type>
Collection<type> select(const type m_array[], int m_size, const type& m_reference){
    
    int matched = 0;
    int a = 0;
      for(int i = 0; i < m_size; i++){
          if(m_array[i] == m_reference){
              matched++;
          }
      }
    Collection<type> object(matched);
    
      for(int i = 0; i < m_size; i++){
          if(m_array[i] == m_reference){
              object[a] = m_array[i];
              a++;
          }
      }
      return object;
}

template<typename type>
void printCollection(const type& m_reference, const char* m_title){
    std::cout << m_title << std::endl;
    for(int i = 0; i < m_reference.size(); i++){
        std::cout << m_reference[i] << std::endl;
    }
}
}

#endif /* SDDS_TEMPS_H_ */



