
#include <cstring>
#include "DynamicMatrix.h"


///
///Swap
///
template <typename T>
void Swap(T& a, T& b)
{
    T temp=a;
    a=b;
    b=temp;
}

DynamicMatrix::DynamicMatrix()
{
	pData = new char*[1];
	    if (!pData)
	    {
	       std::cerr<<"Out of memory!"<<std::endl;
	    }
	    else
	    {
	        for (size_t i = 0; i < 1; i++)
	        {
	            pData[i] = new char[1 + 1];

	            for (size_t j = 0; j < 1; j++)
	                pData[i][j] = ' ';

	            pData[i][1] = '\0';
	        }
	        LengthX = 1;
	        LengthY = 1;
	    }
}

///
/// ����� �� ��������
///
void DynamicMatrix::copy(const DynamicMatrix& other)
{
    pData = new char*[other.sizeX()];
    if (!pData)
    {
        std::cerr<<"Out of memory!"<<std::endl;
    }
    else
    {
    	LengthX = other.LengthX;
        LengthY = other.LengthY;
        for (size_t i = 0; i < LengthX; i++)
        {
            pData[i] = new char[LengthY + 1];
            strcpy(pData[i], other.pData[i]);
        }

    }
}

///
/// �����, ����� ����������� ���������� �����
///
void DynamicMatrix::destroy()
{
    for (size_t i = 0; i < LengthX; i++)
        delete[] pData[i];
    delete[] pData;
}

///
/// ������������ � ��������� (� �� ������������)
///
DynamicMatrix::DynamicMatrix(size_t lengthX , size_t lengthY )
{
    pData = new char*[lengthX];
    if (!pData)
    {
       std::cerr<<"Out of memory!"<<std::endl;
    }
    else
    {
        for (size_t i = 0; i < lengthX; i++)
        {
            pData[i] = new char[lengthY + 1];

            for (size_t j = 0; j < lengthY; j++)
                pData[i][j] = ' ';

            pData[i][lengthY] = '\0';
        }
        LengthX = lengthX;
        LengthY = lengthY;
    }
}

///
/// ����������� �� ��������
///
DynamicMatrix::DynamicMatrix(const DynamicMatrix& other)
{
    copy(other);
}

///
/// �������� �� �����������
///
DynamicMatrix& DynamicMatrix::operator=(const DynamicMatrix& other)
{
    if(this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

///
/// ����������
///
DynamicMatrix::~DynamicMatrix()
{
    destroy();
}

///
/// ��������, ����� ����� ���� �� �������� �� ���������
///
size_t DynamicMatrix::sizeX() const
{
    return LengthX;
}

///
/// ��������, ����� ����� ���� �� ���������� �� ���������
///
size_t DynamicMatrix::sizeY() const
{
    return LengthY;
}

///
/// ��������, ����� ����� ������� �� �������� ������� (x, y) � ���������
///
char& DynamicMatrix::at(size_t x, size_t y)
{
    if (x < LengthX)
        if (y < LengthY)
            return pData[x][y];
        else
            return pData[x][LengthY - 1];
    else
        if (y < LengthY)
            return pData[LengthX - 1][y];
        else
            return pData[LengthX - 1][LengthY - 1];
}

///
/// �������� �� ���� �� �����
///
std::istream& operator>>(std::istream& is, DynamicMatrix& m)
{
    is >> std::ws;

    for (size_t i = 0; i < m.LengthX; i++)
    {
        is >> std::ws;
        is.ignore();
        is.getline(m.pData[i], m.LengthY);
    }

    return is;
}

///
/// �������� �� ����� ��� �����
///
std::ostream& operator<<(std::ostream & os, const DynamicMatrix& m)
{
    for (size_t i = 0; i < m.LengthX; i++)
        os << m.pData[i] << std::endl;

    return os;
}

void DynamicMatrix::setAt(size_t x, size_t y, char elem){
	this->pData[x][y]=elem;
}
