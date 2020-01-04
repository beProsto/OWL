#ifndef _OWL_VECTOR3_HPP_HEADER_FILE_GUARD
#define _OWL_VECTOR3_HPP_HEADER_FILE_GUARD
namespace OWL {
template<typename T> class Vec3 {
public:
	Vec3(T _a = 0) {
		x = _a;
		y = _a;
		z = _a;
	}
	Vec3(T _x, T _y, T _z) {
		x = _x;
		y = _y;
		z = _z;
	}
	template<typename Y> Vec3(const Vec3<Y>& _other) {
		x = static_cast<T>(_other.x);
		y = static_cast<T>(_other.y);
		z = static_cast<T>(_other.z);
	}

	T& operator[](size_t _i) {
		return *(((T*)this)+_i);
	}

	template<typename Y> Vec3& operator=(const Vec3<Y>& _other) {
		x = static_cast<T>(_other.x);
		y = static_cast<T>(_other.y);
		z = static_cast<T>(_other.z);
		return *this;
	}

	template<typename Y> Vec3 operator+(const Vec3<Y>& _a) const {
		return Vec3(x + static_cast<T>(_a.x), 
					y + static_cast<T>(_a.y),
					z + static_cast<T>(_a.z));
	}
	template<typename Y> Vec3 operator-(const Vec3<Y>& _a) const {
		return Vec3(x - static_cast<T>(_a.x), 
					y - static_cast<T>(_a.y),
					z - static_cast<T>(_a.z));
	}
	template<typename Y> Vec3 operator*(const Vec3<Y>& _a) const {
		return Vec3(x * static_cast<T>(_a.x), 
					y * static_cast<T>(_a.y),
					z * static_cast<T>(_a.z));
	}
	template<typename Y> Vec3 operator/(const Vec3<Y>& _a) const {
		return Vec3(x / static_cast<T>(_a.x), 
					y / static_cast<T>(_a.y),
					z / static_cast<T>(_a.z));
	}
	template<typename Y> Vec3 operator%(const Vec3<Y>& _a) const {
		return Vec3(x % static_cast<T>(_a.x), 
					y % static_cast<T>(_a.y),
					z % static_cast<T>(_a.z));
	}

	template<typename Y> Vec3& operator+=(const Vec3<Y>& _a) {
		return (*this) = Vec3(x + static_cast<T>(_a.x), 
								y + static_cast<T>(_a.y),
								z + static_cast<T>(_a.z));
	}
	template<typename Y> Vec3& operator-=(const Vec3<Y>& _a) {
		return (*this) = Vec3(x - static_cast<T>(_a.x), 
								y - static_cast<T>(_a.y),
								z - static_cast<T>(_a.z));
	}
	template<typename Y> Vec3& operator*=(const Vec3<Y>& _a) {
		return (*this) = Vec3(x * static_cast<T>(_a.x), 
								y * static_cast<T>(_a.y),
								z * static_cast<T>(_a.z));
	}
	template<typename Y> Vec3& operator/=(const Vec3<Y>& _a) {
		return (*this) = Vec3(x / static_cast<T>(_a.x), 
								y / static_cast<T>(_a.y),
								z / static_cast<T>(_a.z));
	}
	template<typename Y> Vec3& operator%=(const Vec3<Y>& _a) {
		return (*this) = Vec3(x % static_cast<T>(_a.x), 
								y % static_cast<T>(_a.y),
								z % static_cast<T>(_a.z));
	}

	template<typename Y> bool operator==(const Vec3<Y>& _a) const {
		return (x == static_cast<T>(_a.x) && y == static_cast<T>(_a.y) && z == static_cast<T>(_a.z));
	}
	template<typename Y> bool operator!=(const Vec3<Y>& _a) const {
		return (x != static_cast<T>(_a.x) || y != static_cast<T>(_a.y) || z != static_cast<T>(_a.z));
	}
	template<typename Y> bool operator<=(const Vec3<Y>& _a) const {
		return (x <= static_cast<T>(_a.x) && y <= static_cast<T>(_a.y) && z <= static_cast<T>(_a.z));
	}
	template<typename Y> bool operator>=(const Vec3<Y>& _a) const {
		return (x >= static_cast<T>(_a.x) && y >= static_cast<T>(_a.y) && z >= static_cast<T>(_a.z));
	}
	template<typename Y> bool operator<(const Vec3<Y>& _a) const {
		return (x < static_cast<T>(_a.x) && y < static_cast<T>(_a.y) && z < static_cast<T>(_a.z));
	}
	template<typename Y> bool operator>(const Vec3<Y>& _a) const {
		return (x > static_cast<T>(_a.x) && y > static_cast<T>(_a.y) && z > static_cast<T>(_a.z));
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
};

typedef Vec3<int> Vec3i;
typedef Vec3<unsigned int> Vec3ui;
typedef Vec3<char> Vec3b;
typedef Vec3<unsigned char> Vec3ub;
typedef Vec3<float> Vec3f;
typedef Vec3<double> Vec3d;

}

#endif /*_OWL_VECTOR3_HPP_HEADER_FILE_GUARD*/

