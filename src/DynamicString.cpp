#include <cstring>
#include "DynamicString.h"

const int MAX_SIZE = (unsigned short) - 1;

///
/// �������� ����� �� �������� �� ����� �� ��� ���� ����
///
void DynamicString::copy(const DynamicString& other)
{
    pData = new char[strlen(other.pData) + 1];

    if (!pData)
        std::cerr << "Out of memory!" << std::endl;
    else
        strcpy(pData, other.pData);
}

///
/// �������� ����� �� �������� �� C-���
///
void DynamicString::copy(const char* pStr)
{
    pData = new char[strlen(pStr) + 1];

    if (!pData)
        std::cerr << "Out of memory!" << std::endl;
    else
        strcpy(pData, pStr);
}

///
/// �������� ����� �� �������� �� ������
///
void DynamicString::copy(const char ch)
{
    pData = new char[2];

    if (!pData)
        std::cerr << "Out of memory!" << std::endl;
    else
    {
        *pData = ch;
        *(pData + 1) = '\0';
    }
}

///
/// �������� �����, ����� ����������� ���������� �����
///
void DynamicString::destroy()
{
    delete[] pData;
}

///
/// ����������� �� ������������
///
DynamicString::DynamicString()
{
    pData = new char[2];

    if (!pData)
        std::cerr << "Out of memory!" << std::endl;
    else
        *pData = '\0';
}

///
/// ����������� �� ��������
///
DynamicString::DynamicString(const DynamicString& other)
{
    copy(other);
}

///
/// ����������� �� �������� �� C-���
///
DynamicString::DynamicString(const char* pStr)
{
    copy(pStr);
}

///
/// ����������� �� �������� �� ������
///
DynamicString::DynamicString(const char ch)
{
    copy(ch);
}

///
/// �������� �� �����������
///
DynamicString& DynamicString::operator=(const DynamicString& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

///
/// �������� �� ����������� �� C-���
///
DynamicString& DynamicString::operator=(const char* pStr)
{
    destroy();
    copy(pStr);

    return *this;
}

///
/// �������� �� ����������� �� ������
///
DynamicString& DynamicString::operator=(const char ch)
{
    destroy();
    copy(ch);

    return *this;
}

///
/// ����������
///
DynamicString::~DynamicString()
{
    destroy();
}

///
/// ����� ��������� �� ����
///
size_t DynamicString::size() const
{
    return strlen(pData);
}

///
/// ����� ������� �� �������� �������
///
char& DynamicString::operator[](size_t pos)
{
    size_t length = strlen(pData);
    return pos < length ? pData[pos] : pData[length - 1];
}

///
/// �������� �� ��������� �� ��� ����
///
bool operator==(const DynamicString& ds1, const DynamicString& ds2)
{
    return !strcmp(ds1.pData, ds2.pData);
}

///
/// �������� �� ��������� �� ��� � C-���
///
bool operator==(const DynamicString& ds, const char* str)
{
    return !strcmp(ds.pData, str);
}

///
/// �������� �� ��������� �� ��� � ������
///
bool operator==(const DynamicString& ds, const char ch)
{
    return *ds.pData == ch && *(ds.pData + 1) == '\0';
}

///
/// �������� �� ����������� ����� ��� ����
///
bool operator!=(const DynamicString& ds1, const DynamicString& ds2)
{
    return !(ds1 == ds2);
}

///
/// �������� �� ����������� ����� ��� � C-���
///
bool operator!=(const DynamicString& ds, const char* str)
{
    return !(ds == str);
}

///
/// �������� �� ����������� ����� ��� � ������
///
bool operator!=(const DynamicString& ds, const char ch)
{
    return !(ds == ch);
}

///
/// �������� �� ��������� ��� ������� �����
///
std::ostream& operator<<(std::ostream& os, const DynamicString& ds)
{
    os << ds.pData;
    return os;
}

///
/// �������� �� ��������� �� ������ �����
///
std::istream& operator>>(std::istream& is, DynamicString& ds)
{
    char* pTemp = new char[MAX_SIZE];
    is >> pTemp;
    ds.destroy();
    ds.copy(pTemp);
    delete[] pTemp;
    return is;
}

///
/// �������� �� ��������� �� ��� �� ������ �����
///
std::istream& getline(std::istream& is, DynamicString& ds)
{
    char* pTemp = new char[MAX_SIZE];
    is.getline(pTemp, MAX_SIZE);
    ds.destroy();
    ds.copy(pTemp);
    delete[] pTemp;
    return is;
}


char* DynamicString::getString() const{
	return this->pData;
}


