#include<iostream>
#include<string>
#include<tuple>

namespace _Sun {
	template<class Func, class Tuple, int N>
	struct TupleHelper
	{
		static void func(Func f, const Tuple &_) {
			TupleHelper<Func, Tuple, N - 1>::func(f, _);
			f(std::get<N - 1>(_), N - 1);
		}
	};


	template<class Func, class Tuple>
	struct TupleHelper<Func, Tuple, 1>
	{
		static void func(Func f, const Tuple &_) {
			f(std::get<0>(_), 0);
		}
	};

	template<class Func, class ...Args>
	void tuple_handler(Func f, const std::tuple<Args...> &_) {
		TupleHelper<Func, decltype(_), sizeof...(Args)>::func(f, _);
	}

	template<class Func>
	void tuple_handler(Func f, std::tuple<> &_) {
          std::cout << "Trying to manipulate empty tuple!" << std::endl;
        }

	template<class ...Args>
	void print_tuple(const std::tuple<Args...> &_) {
		std::cout << '(';
		tuple_handler([](auto _, std::size_t index) {
			if (index) std::cout << ", ";
			std::cout << _;
		}, _);
		std::cout << ')';
	}
}