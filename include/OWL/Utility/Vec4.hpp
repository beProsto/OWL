#pragma once

#include <stddef.h>

namespace OWL {
template<typename T> class Vec4 {
public:
	Vec4(T _a = 0) {
		x = _a;
		y = _a;
		z = _a;
		w = _a;
	}
	Vec4(T _x, T _y, T _z, T _w) {
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}
	template<typename Y> Vec4(const Vec4<Y>& _other) {
		x = static_cast<T>(_other.x);
		y = static_cast<T>(_other.y);
		z = static_cast<T>(_other.z);
		w = static_cast<T>(_other.w);
	}

	T& operator[](size_t _i) {
		return *(((T*)this)+_i);
	}

	template<typename Y> Vec4& operator=(const Vec4<Y>& _other) {
		x = static_cast<T>(_other.x);
		y = static_cast<T>(_other.y);
		z = static_cast<T>(_other.z);
		w = static_cast<T>(_other.w);
		return *this;
	}

	template<typename Y> Vec4 operator+(const Vec4<Y>& _a) const {
		return Vec4(x + static_cast<T>(_a.x), 
					y + static_cast<T>(_a.y),
					z + static_cast<T>(_a.z),
					w + static_cast<T>(_a.w));
	}
	template<typename Y> Vec4 operator-(const Vec4<Y>& _a) const {
		return Vec4(x - static_cast<T>(_a.x), 
					y - static_cast<T>(_a.y),
					z - static_cast<T>(_a.z),
					w - static_cast<T>(_a.w));
	}
	template<typename Y> Vec4 operator*(const Vec4<Y>& _a) const {
		return Vec4(x * static_cast<T>(_a.x), 
					y * static_cast<T>(_a.y),
					z * static_cast<T>(_a.z),
					w * static_cast<T>(_a.w));
	}
	template<typename Y> Vec4 operator/(const Vec4<Y>& _a) const {
		return Vec4(x / static_cast<T>(_a.x), 
					y / static_cast<T>(_a.y),
					z / static_cast<T>(_a.z),
					w / static_cast<T>(_a.w));
	}
	template<typename Y> Vec4 operator%(const Vec4<Y>& _a) const {
		return Vec4(x % static_cast<T>(_a.x), 
					y % static_cast<T>(_a.y),
					z % static_cast<T>(_a.z),
					w % static_cast<T>(_a.w));
	}

	template<typename Y> Vec4& operator+=(const Vec4<Y>& _a) {
		return (*this) = Vec4(x + static_cast<T>(_a.x), 
								y + static_cast<T>(_a.y),
								z + static_cast<T>(_a.z),
								w + static_cast<T>(_a.w));
	}
	template<typename Y> Vec4& operator-=(const Vec4<Y>& _a) {
		return (*this) = Vec4(x - static_cast<T>(_a.x), 
								y - static_cast<T>(_a.y),
								z - static_cast<T>(_a.z),
								w - static_cast<T>(_a.w));
	}
	template<typename Y> Vec4& operator*=(const Vec4<Y>& _a) {
		return (*this) = Vec4(x * static_cast<T>(_a.x), 
								y * static_cast<T>(_a.y),
								z * static_cast<T>(_a.z),
								w * static_cast<T>(_a.w));
	}
	template<typename Y> Vec4& operator/=(const Vec4<Y>& _a) {
		return (*this) = Vec4(x / static_cast<T>(_a.x), 
								y / static_cast<T>(_a.y),
								z / static_cast<T>(_a.z),
								w / static_cast<T>(_a.w));
	}
	template<typename Y> Vec4& operator%=(const Vec4<Y>& _a) {
		return (*this) = Vec4(x % static_cast<T>(_a.x), 
								y % static_cast<T>(_a.y),
								z % static_cast<T>(_a.z),
								w % static_cast<T>(_a.w));
	}

	template<typename Y> bool operator==(const Vec4<Y>& _a) const {
		return (x == static_cast<T>(_a.x) && y == static_cast<T>(_a.y) && z == static_cast<T>(_a.z) && w == static_cast<T>(_a.w));
	}
	template<typename Y> bool operator!=(const Vec4<Y>& _a) const {
		return (x != static_cast<T>(_a.x) || y != static_cast<T>(_a.y) || z != static_cast<T>(_a.z) || w != static_cast<T>(_a.w));
	}
	template<typename Y> bool operator<=(const Vec4<Y>& _a) const {
		return (x <= static_cast<T>(_a.x) && y <= static_cast<T>(_a.y) && z <= static_cast<T>(_a.z) && w <= static_cast<T>(_a.w));
	}
	template<typename Y> bool operator>=(const Vec4<Y>& _a) const {
		return (x >= static_cast<T>(_a.x) && y >= static_cast<T>(_a.y) && z >= static_cast<T>(_a.z) && w >= static_cast<T>(_a.w));
	}
	template<typename Y> bool operator<(const Vec4<Y>& _a) const {
		return (x < static_cast<T>(_a.x) && y < static_cast<T>(_a.y) && z < static_cast<T>(_a.z) && w < static_cast<T>(_a.w));
	}
	template<typename Y> bool operator>(const Vec4<Y>& _a) const {
		return (x > static_cast<T>(_a.x) && y > static_cast<T>(_a.y) && z > static_cast<T>(_a.z) && w > static_cast<T>(_a.w));
	}
	

	union { /*[0]*/
		T x;
		T u;
		T r;	
	};
	union { /*[1]*/
		T y;
		T v;
		T g;
	};
	union { /*[2]*/
		T z;
		T b;
	};
	union { /*[3]*/
		T w;
		T a;
	};
};

using Vec4i  = Vec4<int>;
using Vec4ui = Vec4<unsigned int>;
using Vec4b  = Vec4<char>;
using Vec4ub = Vec4<unsigned char>;
using Vec4f  = Vec4<float>;
using Vec4d  = Vec4<double>;

}