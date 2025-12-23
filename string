#include <climits>
#include <cstdint>
#include <cstring>
#include <iostream>
using namespace std;

class String {
    char* content;
    uint32_t size;

    void copy(const String& orig) {
        const char* s;
        char* p;

        this->content=new char[orig.length()+1];
        s=orig.content;
        p=this->content;

        while (*s){
            *p=*s;
            p++;
            s++;
        }
        *p='\0';
    }

public:
    String(const char* str=""){
        const char* s;
        char* p;

        this->content=new char[strlen(str)+1];
        s=str;
        p=this->content;

        while (*s){
            *p=*s;
            p++;
            s++;
        }
        *p='\0';
    }

    String(const String& orig) {
        copy(orig);
    }

    String& operator=(const String& orig){
        if (this != &orig) {
            delete [] this->content;
            this->copy(orig);
        }
        return *this;
    }

    uint32_t length() const {
        char* p=this->content;
        uint32_t len=0;

        while (*p++) len++;

        return len;
    }

    String operator+(const String& second) {
        int l=this->length()+second.length();

        String result;
        result.content=new char[l+1];

        for (int i=0; i<this->length(); i++) result.content[i]=this->content[i];
        for (int j=this->length(); j<l; j++) result.content[j]=second.content[j];
        result.content[l]='\0';

        return result;
    }

    String& operator+=(const String& second) {
        char* tmp=new char[this->length()+second.length()+1];

        for (int i=0; i<this->length(); i++) tmp[i]=this->content[i];
        for (int j=this->length(); j<this->length()+second.length()+1; j++) tmp[j]=second.content[j];

        *this=tmp;

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream& is, String& str);

    ~String() {
        delete [] this->content;
    }
};

ostream& operator<<(std::ostream& os, const String& str) {
    os << str.content;
    return os;
}

istream& operator>>(std::istream& is, String& str) {
    char temp[10000];

    is.getline(temp, 10000);
    int len = strlen(temp);

    delete[] str.content;
    str.content = new char[len + 1];

    strcpy(str.content, temp);

    return is;
}

int main() {
    String s1, s2="Hello";

    cout << "Enter a string: ";
    cin >> s1;
    cout << "The strings are: " << s1 << " , " << s2 << '\n';

    cout << "length: " << s2.length() << "; operator+: " << s1+s2 << "; operator+=: " << s2.operator+=(s1) << '\n';


    return 0;
}
