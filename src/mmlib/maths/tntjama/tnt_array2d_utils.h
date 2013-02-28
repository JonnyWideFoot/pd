// PD is a free, modular C++ library for biomolecular simulation with a 
// flexible and scriptable Python interface. 
// Copyright (C) 2003-2013 Mike Tyka and Jon Rea
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

/*
*
* Template Numerical Toolkit (TNT)
*
* Mathematical and Computational Sciences Division
* National Institute of Technology,
* Gaithersburg, MD USA
*
*
* This software was developed at the National Institute of Standards and
* Technology (NIST) by employees of the Federal Government in the course
* of their official duties. Pursuant to title 17 Section 105 of the
* United States Code, this software is not subject to copyright protection
* and is in the public domain. NIST assumes no responsibility whatsoever for
* its use by other parties, and makes no guarantees, expressed or implied,
* about its quality, reliability, or any other characteristic.
*
*/


#ifndef TNT_ARRAY2D_UTILS_H
#define TNT_ARRAY2D_UTILS_H

#include <cstdlib>
#include <cassert>

namespace TNT
{


	template <class T>
	std::ostream& operator<<(std::ostream &s, const Array2D<T> &A)
	{
		int M = A.dim1();
		int N = A.dim2();

		s << M << " " << N << "\n";

		for (int i=0; i<M; i++)
		{
			for (int j=0; j<N; j++)
			{
				s << A[i][j] << " ";
			}
			s << "\n";
		}


		return s;
	}

	template <class T>
	std::istream& operator>>(std::istream &s, Array2D<T> &A)
	{

		int M, N;

		s >> M >> N;

		Array2D<T> B(M,N);

		for (int i=0; i<M; i++)
			for (int j=0; j<N; j++)
			{
				s >> B[i][j];
			}

			A = B;
			return s;
	}


	template <class T>
	Array2D<T> operator+(const Array2D<T> &A, const Array2D<T> &B)
	{
		int m = A.dim1();
		int n = A.dim2();

		if (B.dim1() != m || B.dim2() != n )
			return Array2D<T>();

		else
		{
			Array2D<T> C(m,n);

			for (int i=0; i<m; i++)
			{
				for (int j=0; j<n; j++)
					C[i][j] = A[i][j] + B[i][j];
			}
			return C;
		}
	}

	template <class T>
	Array2D<T> operator-(const Array2D<T> &A, const Array2D<T> &B)
	{
		int m = A.dim1();
		int n = A.dim2();

		if (B.dim1() != m || B.dim2() != n )
			return Array2D<T>();

		else
		{
			Array2D<T> C(m,n);

			for (int i=0; i<m; i++)
			{
				for (int j=0; j<n; j++)
					C[i][j] = A[i][j] - B[i][j];
			}
			return C;
		}
	}


	template <class T>
	Array2D<T> operator*(const Array2D<T> &A, const Array2D<T> &B)
	{
		int m = A.dim1();
		int n = A.dim2();

		if (B.dim1() != m || B.dim2() != n )
			return Array2D<T>();

		else
		{
			Array2D<T> C(m,n);

			for (int i=0; i<m; i++)
			{
				for (int j=0; j<n; j++)
					C[i][j] = A[i][j] * B[i][j];
			}
			return C;
		}
	}




	template <class T>
	Array2D<T> operator/(const Array2D<T> &A, const Array2D<T> &B)
	{
		int m = A.dim1();
		int n = A.dim2();

		if (B.dim1() != m || B.dim2() != n )
			return Array2D<T>();

		else
		{
			Array2D<T> C(m,n);

			for (int i=0; i<m; i++)
			{
				for (int j=0; j<n; j++)
					C[i][j] = A[i][j] / B[i][j];
			}
			return C;
		}
	}





	template <class T>
	Array2D<T>& operator+=(Array2D<T> &A, const Array2D<T> &B)
	{
		int m = A.dim1();
		int n = A.dim2();

		if (B.dim1() == m || B.dim2() == n )
		{
			for (int i=0; i<m; i++)
			{
				for (int j=0; j<n; j++)
					A[i][j] += B[i][j];
			}
		}
		return A;
	}



	template <class T>
	Array2D<T>& operator-=(Array2D<T> &A, const Array2D<T> &B)
	{
		int m = A.dim1();
		int n = A.dim2();

		if (B.dim1() == m || B.dim2() == n )
		{
			for (int i=0; i<m; i++)
			{
				for (int j=0; j<n; j++)
					A[i][j] -= B[i][j];
			}
		}
		return A;
	}



	template <class T>
	Array2D<T>& operator*=(Array2D<T> &A, const Array2D<T> &B)
	{
		int m = A.dim1();
		int n = A.dim2();

		if (B.dim1() == m || B.dim2() == n )
		{
			for (int i=0; i<m; i++)
			{
				for (int j=0; j<n; j++)
					A[i][j] *= B[i][j];
			}
		}
		return A;
	}





	template <class T>
	Array2D<T>& operator/=(Array2D<T> &A, const Array2D<T> &B)
	{
		int m = A.dim1();
		int n = A.dim2();

		if (B.dim1() == m || B.dim2() == n )
		{
			for (int i=0; i<m; i++)
			{
				for (int j=0; j<n; j++)
					A[i][j] /= B[i][j];
			}
		}
		return A;
	}

	/**
	Matrix Multiply: compute C = A*B, where C[i][j]
	is the dot-product of row i of A and column j of B.


	@param A an (m x n) array
	@param B an (n x k) array
	@return the (m x k) array A*B, or a null array (0x0)
	if the matrices are non-conformant (i.e. the number
	of columns of A are different than the number of rows of B.)


	*/
	template <class T>
	Array2D<T> matmult(const Array2D<T> &A, const Array2D<T> &B)
	{
		if (A.dim2() != B.dim1())
			return Array2D<T>();

		int M = A.dim1();
		int N = A.dim2();
		int K = B.dim2();

		Array2D<T> C(M,K);

		for (int i=0; i<M; i++)
			for (int j=0; j<K; j++)
			{
				T sum = 0;

				for (int k=0; k<N; k++)
					sum += A[i][k] * B [k][j];

				C[i][j] = sum;
			}

			return C;

	}

} // namespace TNT

#endif
