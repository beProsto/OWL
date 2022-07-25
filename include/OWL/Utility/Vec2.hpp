#pragma once

#include <stddef.h>

namespace OWL {
template<typename T> class Vec2 {
public:
	Vec2(T _a = 0) {
		x = _a;
		y = _a;
	}
	Vec2(T _x, T _y) {
		x = _x;
		y = _y;
	}
	template<typename Y> Vec2(const Vec2<Y>& _other) {
		x = static_cast<T>(_other.x);
		y = static_cast<T>(_other.y);
	}

	T& operator[](size_t _i) {
		return *(((T*)this)+_i);
	}

	template<typename Y> Vec2& operator=(const Vec2<Y>& _other) {
		x = static_cast<T>(_other.x);
		y = static_cast<T>(_other.y);
		return *this;
	}

	template<typename Y> Vec2 operator+(const Vec2<Y>& _a) const {
		return Vec2(x + static_cast<T>(_a.x), 
					y + static_cast<T>(_a.y));
	}
	template<typename Y> Vec2 operator-(const Vec2<Y>& _a) const {
		return Vec2(x - static_cast<T>(_a.x), 
					y - static_cast<T>(_a.y));
	}
	template<typename Y> Vec2 operator*(const Vec2<Y>& _a) const {
		return Vec2(x * static_cast<T>(_a.x), 
					y * static_cast<T>(_a.y));
	}
	template<typename Y> Vec2 operator/(const Vec2<Y>& _a) const {
		return Vec2(x / static_cast<T>(_a.x), 
					y / static_cast<T>(_a.y));
	}
	template<typename Y> Vec2 operator%(const Vec2<Y>& _a) const {
		return Vec2(x % static_cast<T>(_a.x), 
					y % static_cast<T>(_a.y));
	}

	template<typename Y> Vec2& operator+=(const Vec2<Y>& _a) {
		return (*this) = Vec2(x + static_cast<T>(_a.x), 
								y + static_cast<T>(_a.y));
	}
	template<typename Y> Vec2& operator-=(const Vec2<Y>& _a) {
		return (*this) = Vec2(x - static_cast<T>(_a.x), 
								y - static_cast<T>(_a.y));
	}
	template<typename Y> Vec2& operator*=(const Vec2<Y>& _a) {
		return (*this) = Vec2(x * static_cast<T>(_a.x), 
								y * static_cast<T>(_a.y));
	}
	template<typename Y> Vec2& operator/=(const Vec2<Y>& _a) {
		return (*this) = Vec2(x / static_cast<T>(_a.x), 
								y / static_cast<T>(_a.y));
	}
	template<typename Y> Vec2& operator%=(const Vec2<Y>& _a) {
		return (*this) = Vec2(x % static_cast<T>(_a.x), 
								y % static_cast<T>(_a.y));
	}

	template<typename Y> bool operator==(const Vec2<Y>& _a) const {
		return (x == static_cast<T>(_a.x) && y == static_cast<T>(_a.y));
	}
	template<typename Y> bool operator!=(const Vec2<Y>& _a) const {
		return (x != static_cast<T>(_a.x) || y != static_cast<T>(_a.y));
	}
	template<typename Y> bool operator<=(const Vec2<Y>& _a) const {
		return (x <= static_cast<T>(_a.x) && y <= static_cast<T>(_a.y));
	}
	template<typename Y> bool operator>=(const Vec2<Y>& _a) const {
		return (x >= static_cast<T>(_a.x) && y >= static_cast<T>(_a.y));
	}
	template<typename Y> bool operator<(const Vec2<Y>& _a) const {
		return (x < static_cast<T>(_a.x) && y < static_cast<T>(_a.y));
	}
	template<typename Y> bool operator>(const Vec2<Y>& _a) const {
		return (x > static_cast<T>(_a.x) && y > static_cast<T>(_a.y));
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
};

using Vec2i  = Vec2<int>;
using Vec2ui = Vec2<unsigned int>;
using Vec2b  = Vec2<char>;
using Vec2ub = Vec2<unsigned char>;
using Vec2f  = Vec2<float>;
using Vec2d  = Vec2<double>;

}