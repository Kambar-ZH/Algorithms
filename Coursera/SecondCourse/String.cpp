#include <iostream>
using namespace std;
 
class MyString
{
private:
    char *str;

public:
    MyString()
    {
        str = NULL;
    }
    MyString(char *str)
    {
        int length = strlen(str);
        this->str
    }
    ~MyString();
};

MyString::MyString(/* args */)
{
}

MyString::~MyString()
{
}


int main()
{
    MyString str("testtest")
    return 0;
}