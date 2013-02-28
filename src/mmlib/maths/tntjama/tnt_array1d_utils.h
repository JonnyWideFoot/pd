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

#ifndef TNT_ARRAY1D_UTILS_H
#define TNT_ARRAY1D_UTILS_H

#include <cstdlib>
#include <cassert>

namespace TNT
{


	template <class T>
	std::ostream& operator<<(std::ostream &s, const Array1D<T> &A)
	{
		int N = A.dim1();

#ifdef TNT_DEBUG
		s << "addr: " << (void *) &A[0] << "\n";
#endif
		s << N << "\n";
		for (int j=0; j<N; j++)
		{
			s << A[j] << "\n";
		}
		s << "\n";

		return s;
	}

	template <class T>
	std::istream& operator>>(std::istream &s, Array1D<T> &A)
	{
		int N;
		s >> N;

		Array1D<T> B(N);
		for (int i=0; i<N; i++)
			s >> B[i];
		A = B;
		return s;
	}



	template <class T>
	Array1D<T> operator+(const Array1D<T> &A, const Array1D<T> &B)
	{
		int n = A.dim1();

		if (B.dim1() != n )
			return Array1D<T>();

		else
		{
			Array1D<T> C(n);

			for (int i=0; i<n; i++)
			{
				C[i] = A[i] + B[i];
			}
			return C;
		}
	}



	template <class T>
	Array1D<T> operator-(const Array1D<T> &A, const Array1D<T> &B)
	{
		int n = A.dim1();

		if (B.dim1() != n )
			return Array1D<T>();

		else
		{
			Array1D<T> C(n);

			for (int i=0; i<n; i++)
			{
				C[i] = A[i] - B[i];
			}
			return C;
		}
	}


	template <class T>
	Array1D<T> operator*(const Array1D<T> &A, const Array1D<T> &B)
	{
		int n = A.dim1();

		if (B.dim1() != n )
			return Array1D<T>();

		else
		{
			Array1D<T> C(n);

			for (int i=0; i<n; i++)
			{
				C[i] = A[i] * B[i];
			}
			return C;
		}
	}


	template <class T>
	Array1D<T> operator/(const Array1D<T> &A, const Array1D<T> &B)
	{
		int n = A.dim1();

		if (B.dim1() != n )
			return Array1D<T>();

		else
		{
			Array1D<T> C(n);

			for (int i=0; i<n; i++)
			{
				C[i] = A[i] / B[i];
			}
			return C;
		}
	}









	template <class T>
	Array1D<T>& operator+=(Array1D<T> &A, const Array1D<T> &B)
	{
		int n = A.dim1();

		if (B.dim1() == n)
		{
			for (int i=0; i<n; i++)
			{
				A[i] += B[i];
			}
		}
		return A;
	}




	template <class T>
	Array1D<T>& operator-=(Array1D<T> &A, const Array1D<T> &B)
	{
		int n = A.dim1();

		if (B.dim1() == n)
		{
			for (int i=0; i<n; i++)
			{
				A[i] -= B[i];
			}
		}
		return A;
	}



	template <class T>
	Array1D<T>& operator*=(Array1D<T> &A, const Array1D<T> &B)
	{
		int n = A.dim1();

		if (B.dim1() == n)
		{
			for (int i=0; i<n; i++)
			{
				A[i] *= B[i];
			}
		}
		return A;
	}




	template <class T>
	Array1D<T>& operator/=(Array1D<T> &A, const Array1D<T> &B)
	{
		int n = A.dim1();

		if (B.dim1() == n)
		{
			for (int i=0; i<n; i++)
			{
				A[i] /= B[i];
			}
		}
		return A;
	}






} // namespace TNT

#endif
