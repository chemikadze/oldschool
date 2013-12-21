#include "matrix.h"

bool matrixMultiply(const Matrix &a, const Matrix &b, Matrix &c)
{
	int i, j, k;
	matrixType sum;

	if (a[0].size()!=b.size() || a.size()==0 || b.size()==0 || a[0].size()==0 || b[0].size()==0)
		return false;

	resizeMatrix(c, a.size(), b[0].size());
	for (i=0; i<a.size(); i++)
		for (j=0; j<b[0].size(); j++)
		{
			sum=0;
#ifdef _DEBUG
			qDebug() << "matrix.cpp [ 19]: sum=" << sum;
#endif
			for (k=0; k<b.size(); k++)
			{
#ifdef _DEBUG
				qDebug() << "matrix.cpp [ 24]: " << a[i][k]*b[k][j];
#endif	
				sum+=a[i][k]*b[k][j];
			}
			c[i][j]=sum;	
#ifdef _DEBUG
			qDebug() << "matrix.cpp [ 30]: " << sum;
#endif
		}
	return true;
}


void matrixTransposing(const Matrix &a,  Matrix &b)
{
	int i, j;

	resizeMatrix(b, a[0].size(), a.size());
	for (i=0; i<a.size(); i++)
		for (j=0; j<b.size(); j++)
			b[j][i]=a[i][j];
}


bool matrixSum(const Matrix &a, const Matrix &b, Matrix &c, const matrixType sumFactor/*=1*/)
{
	int i, j;

	if (a.size()==0 || b.size()==0 || a[0].size()==0 || b[0].size()==0 || b.size()!=a.size() || a[0].size()!=b[0].size())
		return false;
	c.resize(a.size());
	for (i=0; i<a.size(); i++)
		for (c[i].resize(a[0].size()), j=0; j<a[0].size(); j++)
			c[i][j]=a[i][j]+sumFactor*b[i][j];
	return true;
}

void matrixOnDigit(const Matrix &a, const matrixType digit, Matrix &b)
{
	int i, j;
	
	b.resize(a.size());
	for (i=0; i<a.size(); i++)
		for (b[i].resize(a[0].size()), j=0; j<a[0].size(); j++)
			b[i][j]=digit*a[i][j];
}


void resizeMatrix(Matrix &a, int i, int j)
{
	a.resize(i);
	for (i=0; i<a.size(); i++)
	{
	//	if (a[i].size()<j)
	//		a[i].insert(a[i].size(), j-a[i].size(), 0);
	//	else
			a[i].resize(j);
	}
}

Matrix newMatrix(int i, int j, const matrixType defElem/*=0*/)
{
	Matrix a;
	a.resize(i);
	for (i=0; i<a.size(); i++)
	{
		a[i].resize(0);
		a[i].insert(0, j, defElem);
	}
	return a;
}

void matrixMinor(const Matrix &a, int mi, int mj, Matrix &b)
{
	int i, j;
	resizeMatrix(b, a.size()-1, a[0].size()-1);
	
	for (i=0; i<b.size(); i++)
		for (j=0; j<b[0].size(); j++)
		{
			b[i][j]=a[i+(i>=mi)][j+(j>=mj)];
		}
}

matrixType matrixAlgebraicAddition(const Matrix &a, int mi, int mj)
{
	return ((mi+mj)%2) ? -matrixDet(matrixMinor(a, mi, mj)) : matrixDet(matrixMinor(a, mi, mj));
}

Matrix matrixMinor(const Matrix &a, int mi, int mj)
{
	Matrix result;
	matrixMinor(a, mi, mj, result);
	return result;
}

Matrix matrixOnDigit(const Matrix &a, const matrixType digit)
{
	Matrix result;
	matrixOnDigit(a, digit, result);
	return result;
}

Matrix matrixTransposing(const Matrix &a)
{
	Matrix result;
	matrixTransposing(a, result);
	return result;
}

matrixType matrixDet(const Matrix &a)
{
/*	if (ok!=NULL)
		(*ok)= a.size()==a[0].size();*/
	if (a.size()!=a[0].size())
		return 0;
	if (a.size()==1)
		return a[0][0];
	if (a.size()==2)
		return a[0][0]*a[1][1]-a[0][1]*a[1][0];
	if (a.size()==3)
		return a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+a[0][2]*a[1][0]*a[2][1]-
		       a[0][2]*a[1][1]*a[2][0]-a[0][1]*a[1][0]*a[2][2]-a[0][0]*a[1][2]*a[2][1];
	
	int i;
	matrixType ans=0;
	if (a.size() < 6)
	{
		for (i=0; i<a.size(); i++)
			ans+=a[i][0]*matrixAlgebraicAddition(a, i, 0);
			
	}
	else
	{
		int j;
		int nullI=0, nullJ=0;
		Matrix nullA=a;
		for (i=0; i<a.size(); i++)
			for (j=0; j<a[0].size(); j++)
			{
				if (a[i][j]==1)
				{
					nullI=i;
					nullJ=j;
					i=a.size(); break;
				}
				else
					if (a[i][j]<10 && ceill(a[i][j])==a[i][j])
					{
						nullI=i;
						nullJ=j;
					}
			}
		for (i=0; i<a.size(); i++)
			for (j=0; j<a[0].size() && i!=nullI; j++)
				nullA[i][j]=a[i][j]-a[i][nullJ]*a[nullI][j]/a[nullI][nullJ];
		return a[nullI][nullJ]*matrixAlgebraicAddition(nullA, nullI, nullJ);
	}
	return ans;
}


void matrixFriendly(const Matrix &a, Matrix &b)
{
	int i, j;
	resizeMatrix(b, a[0].size(), a.size());
	for (i=0; i<a.size(); i++)
		for (j=0; j<a[0].size(); j++)
			b[j][i]=matrixAlgebraicAddition(a, i, j);
}

Matrix matrixFriendly(const Matrix &a)
{
	Matrix b;
	matrixFriendly(a, b);
	return b;
}

void matrixAntipod(const Matrix &a, Matrix &b)
{
	matrixFriendly(a, b);
	matrixOnDigit(b, 1/matrixDet(a), b);
}

Matrix matrixAntipod(const Matrix &a)
{
	Matrix b;
	matrixAntipod(a, b);
	return b;
}


bool solveLinearSystemMatrix(const Matrix &a, const Matrix &b, Matrix &x)
{
	if (a.size()!=a[0].size() || b[0].size()!=1)
		return false;
#ifdef _DEBUG
	qDebug() << "starting solving";
#endif
	return matrixMultiply(matrixAntipod(a), b, x);
}

Matrix solveLinearSystemMatrix(const Matrix &a, const Matrix &b /*, bool *ok=true*/)
{
	Matrix x;
	solveLinearSystemMatrix(a, b, x);
	return x;
}
