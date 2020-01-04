#ifndef _DEBUG_OUT_HPP_HEADER_FILE_GUARD
#define _DEBUG_OUT_HPP_HEADER_FILE_GUARD

#include <iostream>
#include <string>

namespace Debug {
class Out {
public:
	enum Type {
		COMM = 0,
		ERROR = 1
	};
	static void Print(const std::string& _a, Type _t = Type::COMM) {
		#ifndef DEBUG_OUT_SET_OFF
		#ifndef DEBUG_OUT_SET_COMM_OFF
		if(_t == Type::COMM) {
			std::cout << _a;
			return;	
		}
		#endif/*DEBUG_OUT_SET_COMM_OFF*/
		#ifndef DEBUG_OUT_SET_ERROR_OFF
		if(_t == Type::ERROR) {
			std::cerr << _a;
			return;	
		}
		#endif/*DEBUG_OUT_SET_ERROR_OFF*/
		#endif/*DEBUG_OUT_SET_OFF*/
	}
};
}

#endif /*_DEBUG_OUT_HPP_HEADER_FILE_GUARD*/
