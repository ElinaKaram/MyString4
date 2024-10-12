#include <iostream>
using namespace std;

class MyString
{
    char* str;
    int length;

public:
    MyString()
    {
        length = 0;
        str = new char[length + 1];
        str[0] = '\0';
    }

    MyString(const char* input)
    {
        length = 0;
        while (input[length] != '\0')
        {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            str[i] = input[i];
        }
        str[length] = '\0';
    }

    MyString(const MyString& other)
    {
        length = other.length;
        str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            str[i] = other.str[i];
        }
        str[length] = '\0';
    }

    ~MyString()
    {
        delete[] str;
    }

    MyString& operator=(const MyString& other)
    {
        if (this == &other)
        {
            return *this; 
        }

        delete[] str; 
        length = other.length;
        str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            str[i] = other.str[i];
        }

        str[length] = '\0';
        return *this;
    }

    char& operator[](int index)
    {
        if (index >= 0 && index < length)
        {
            return str[index];
        }
        throw out_of_range("Index out of range");
    }

    void operator()()
    {
        cout << "Enter the line: ";
        char temp[1000];
        cin.getline(temp, 1000);
        int newLength = 0;

        while (temp[newLength] != '\0')
        {
            newLength++;
        }

        delete[] str;
        str = new char[newLength + 1];

        for (int i = 0; i < newLength; i++)
        {
            str[i] = temp[i];
        }
        str[newLength] = '\0';
        length = newLength;
    }

    MyString operator+(char c) const
    {
        MyString result;
        result.length = length + 1;
        result.str = new char[result.length + 1];

        for (int i = 0; i < length; i++)
        {
            result.str[i] = str[i];
        }

        result.str[length] = c;
        result.str[result.length] = '\0';
        return result;
    }

    MyString operator+(int n) const
    {
        MyString result;
        result.length = length + n;
        result.str = new char[result.length + 1];

        for (int i = 0; i < length; i++)
        {
            result.str[i] = str[i];
        }
        for (int i = 0; i < n; i++)
        {
            result.str[length + i] = '*';
        }

        result.str[result.length] = '\0';
        return result;
    }

    MyString operator++(int)
    {
        MyString temp = *this;
        *this = *this + '!';
        return temp;
    }

    MyString& operator++()
    {
        *this = '!' + *this;
        return *this;
    }

    void setCharAt(int index, char c)
    {
        if (index >= 0 && index < length)
        {
            str[index] = c;
        }
    }

    char getCharAt(int index) const
    {
        if (index >= 0 && index < length)
        {
            return str[index];
        }
        throw out_of_range("Index out of range");
    }

    void display() const
    {
        cout << str << endl;
    }

    ostream& output(ostream& os) const
    {
        os << str;
        return os;
    }

    istream& input(istream& is)
    {
        char temp[1000];
        is.getline(temp, 1000);
        int newLength = 0;

        while (temp[newLength] != '\0')
        {
            newLength++;
        }
        delete[] str;
        str = new char[newLength + 1];

        for (int i = 0; i < newLength; i++)

        {
            str[i] = temp[i];
        }

        str[newLength] = '\0';
        length = newLength;
        return is;
    }
};

ostream& operator<<(ostream& os, const MyString& myStr)
{
    return myStr.output(os);
}

istream& operator>>(istream& is, MyString& myStr)
{
    return myStr.input(is);
}

int main()
{
    MyString s1("Hello");
    cout << "s1: " << s1 << endl;
    cout << "Third symbol: " << s1[2] << endl;

    s1();
    cout << "After entering: " << s1 << endl;

    MyString s2 = s1 + 'A';
    cout << "After adding the symbol at the and: " << s2 << endl;

    MyString s3 = s1 + 10;
    cout << "After adding 10 symbol at the and: " << s3 << endl;

    MyString s6 = s1++;
    cout << "After postfix increment: " << s1 << endl;

    MyString s6 = ++s1;
    cout << "After prefix increment: " << s1 << endl;

    return 0;
}