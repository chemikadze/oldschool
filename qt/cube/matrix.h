#ifndef _MATRIX_H
#define _MATRIX_H

#include <QVector>
#include <QDebug>
#include <cmath>

//#define _DEBUG
//#define _LONGDOUBLE

#ifdef _LONGDOUBLE
typedef long double matrixType;
#else
typedef double matrixType;
#endif
typedef QVector < QVector <matrixType> > Matrix;

void matrixTransposing(const Matrix &a,  Matrix &b);
bool matrixMultiply(const Matrix &a, const Matrix &b, Matrix &c);
bool matrixSum(const Matrix &a, const Matrix &b, Matrix &c, const matrixType sumFactor=1);
void matrixOnDigit(const Matrix &a, const matrixType digit, Matrix &b);
void resizeMatrix(Matrix &a, int i, int j);
void matrixMinor(const Matrix &a, int mi, int mj, Matrix &b);
matrixType matrixAlgebraicAddition(const Matrix &a, int mi, int mj);
Matrix matrixMinor(const Matrix &a, int mi, int mj);
Matrix matrixOnDigit(const Matrix &a, const matrixType digit);
Matrix matrixTransposing(const Matrix &a);
matrixType matrixDet(const Matrix &a);
void matrixFriendly(const Matrix &a, Matrix &b);
Matrix matrixFriendly(const Matrix &a);
void matrixAntipod(const Matrix &a, Matrix &b);
Matrix matrixAntipod(const Matrix &a);
Matrix newMatrix(int i, int j, const matrixType defElem=0);
bool solveLinearSystemMatrix(const Matrix &a, const Matrix &b, Matrix &x);
Matrix solveLinearSystemMatrix(const Matrix &a, const Matrix &b);

#endif
