#ifndef HTMLTEXT_H
#define HTMLTEXT_H
#include <iostream>
#include "Text.h"

namespace sdds {

class HtmlText : public Text{
    
    char* m_title;
    
public:
    HtmlText();
    HtmlText(const char* newHtmlText);
    HtmlText(const HtmlText& newHtmlText);
    HtmlText& operator=(const HtmlText& newHtmlText);
    ~HtmlText();
    ostream& write(ostream& ostr) const;
    
};
}

#endif

