#ifndef _OWL_VECTOR2_HPP_HEADER_FILE_GUARD
#define _OWL_VECTOR2_HPP_HEADER_FILE_GUARD
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

typedef Vec2<int> Vec2i;
typedef Vec2<unsigned int> Vec2ui;
typedef Vec2<char> Vec2b;
typedef Vec2<unsigned char> Vec2ub;
typedef Vec2<float> Vec2f;
typedef Vec2<double> Vec2d;

}

#endif /*_OWL_VECTOR2_HPP_HEADER_FILE_GUARD*/

