#include <string.h>
#include "Text.h"
#include "HtmlText.h"

namespace sdds {

HtmlText::HtmlText(){
    m_title = nullptr;
}

HtmlText::HtmlText(const char* newHtmlText):Text(newHtmlText){
    
    if(newHtmlText){
        m_title = new char[strlen(newHtmlText)+1];
        strcpy(m_title, newHtmlText);
    }
    else{
        m_title = nullptr;
    }
}

HtmlText::HtmlText(const HtmlText& newHtmlText):Text(newHtmlText){
    
    m_title = new char[strlen(newHtmlText.m_title)+1];
    strcpy(m_title, newHtmlText.m_title);
    
}

HtmlText& HtmlText::operator=(const HtmlText& newHtmlText){
    if(this != &newHtmlText){
        Text::operator=(newHtmlText);
        if(newHtmlText.m_title){
            if(newHtmlText.m_title){
                m_title = new char[strlen(newHtmlText.m_title)+1];
                strcpy(m_title, newHtmlText.m_title);
            }
            
        }
        
    }
    return *this;
}

HtmlText::~HtmlText(){
    delete [] m_title;
    m_title = nullptr;
}

ostream& HtmlText::write(ostream& ostr) const{
    bool MS = false;
    const HtmlText& T = *this;
    
    ostr << "<html><head><title>" << (m_title ? m_title : "No Title") << "</title></head>\n<body>\n";
    
    if (m_title) {
        
        ostr << "<h1>" << m_title << "</h1>\n";
        
    }
    
    for(int i = 0; T[i]; i++){
        
        if(T[i] == ' '){
            if(MS){
                ostr << "&nbsp;";
            }
            else{
                MS = true;
                ostr << ' ';
            }
        }
        else if(T[i] == '<'){
            ostr << "&lt;";
            MS = false;
        }
        else if(T[i] == '>'){
            ostr << "&gt;";
            MS = false;
        }
        else if(T[i] == '\n'){
            ostr << "<br />\n";
            MS = false;
        }
        else{
            ostr << T[i];
            MS = false;
        }
    }
    ostr << "</body>\n</html>";
    
    return ostr;
}

}
