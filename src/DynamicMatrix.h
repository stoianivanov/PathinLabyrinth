#pragma once
#include <iostream>
class DynamicMatrix
{
    char** pData;
	size_t LengthX, LengthY;

    void copy(const DynamicMatrix&);


public:
    DynamicMatrix();
    DynamicMatrix(size_t, size_t);
    DynamicMatrix(const DynamicMatrix&);
    DynamicMatrix& operator=(const DynamicMatrix&);
    ~DynamicMatrix();

    size_t sizeX() const;
    size_t sizeY() const;
    void destroy();
    char& at(size_t, size_t);
    void setAt(size_t , size_t, char elem);
    friend std::ostream& operator<<(std::ostream&, const DynamicMatrix&);
    friend std::istream& operator>>(std::istream&, DynamicMatrix&);
;

};
