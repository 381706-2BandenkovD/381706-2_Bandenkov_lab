#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include "TVector.h"

using namespace std;



template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
    TMatrix(int s = 10);
    TMatrix(const TMatrix &mt); // копирование 
    TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа 
    int operator==(const TMatrix &mt); // сравнение 
    TMatrix invert();//обратная матрица 
    TMatrix & operator= (const TMatrix &mt); // присваивание 
    TMatrix operator+ (const TMatrix &mt); // сложение 
    TMatrix operator- (const TMatrix &mt); // вычитание 
    TMatrix operator* (const TMatrix &mt); // умножение 
                                           // ввод / вывод
    friend istream & operator >> (istream &in, TMatrix &mt)
    {
        for (int i = 0; i < mt.size; i++)
            in >> mt.pVector[i];
        return in;
    }

    friend ostream & operator<<(ostream &out, const TMatrix &mt)
    {
        for (int i = 0; i < mt.size; i++)
            out << mt.pVector[i] << endl;
        return out;
    }
};


template<class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
    for (int i = 0; i < s; i++)
        this->pVector[i] = TVector<ValType>(s - i, i);
}

template<class ValType>
TMatrix<ValType>::TMatrix(const TMatrix & mt) : TVector<TVector<ValType> >(mt)
{
}



template<class ValType>
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) : TVector<TVector<ValType> >(mt)
{
}

template<class ValType>
int TMatrix<ValType>::operator==(const TMatrix & mt)
{
    int res = 1;
    for (int i = 0; i < this->size; i++)
        res *= (this->pVector[i] == mt.pVector[i]);
    return res;
}

template<class ValType>
TMatrix<ValType> & TMatrix<ValType>::operator=(const TMatrix & mt)
{
    if (mt.pVector != this->pVector)
    {
        if (this->size != mt.size)
        {
            delete[]this->pVector;
            this->pVector = new TVector<ValType>[mt.size];
            this->size = mt.size;
        }
        this->startIndex = mt.startIndex;
        for (int i = 0; i < this->size; i++)
            this->pVector[i] = mt.pVector[i];
    }
    return *this;
}
template<class ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix & mt)
{
    if (this->size != mt.size)
        throw 1;
    TMatrix res(this->size);
    for (int i = 0; i < this->size; i++)
        res.pVector[i] = this->pVector[i] + mt.pVector[i];
    return res;
}

template<class ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix & mt)
{
    if (this->size != mt.size)
        throw 1;
    TMatrix res(this->size);
    for (int i = 0; i < this->size; i++)
        res.pVector[i] = this->pVector[i] - mt.pVector[i];
    return res;
}
template<class ValType>
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix & mt)
{
    if (this->size != mt.size)
        throw 1;
    TMatrix res(this->size);
    for (int i = 0; i < this->size; i++)
        for (int j = i; j < this->size; j++)
            for (int k = i; k < j + 1; k++)
                res.pVector[i][j] += this->pVector[i][k] * mt.pVector[k][j];
    return res;
}

template<class ValType>
TMatrix<ValType> TMatrix<ValType>::invert()
{
    TMatrix<ValType> obrat(this->size);
    for (int i = 0; i < this->size; i++)
        obrat[i][i] = 1 / (this->pVector[i][i]);
    for (int i = 0; i < this->size; i++)
        for (int j = i + 1; j < this->size; j++)
        {
            ValType sum = 0;
            for (int k = i; k < j; k++)
                sum += obrat[i][k] * this->pVector[k][j];
            obrat[i][j] = -sum / this->pVector[j][j];
        }
    return obrat;
}
#endif
