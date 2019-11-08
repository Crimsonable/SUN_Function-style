#include<iostream>
#include<tuple>
#include<functional>
#include<string>

namespace _Sun {

	template<class T>
	constexpr std::string type_name() {
		#ifdef __clang__
            return __PRETTY_FUNCTION__;
        #endif
        #ifdef __GNUC__
            return __PRETTY_FUNCTION__;
        #endif
        #ifdef _MSC_VER
            return __FUNCSGI__;
        #endif
    }

	template<typename F> struct function_traits;

	template <typename Return, typename... Args>
	struct function_traits<Return(Args...)> {
		using func_type = std::function<Return(Args...)>;
		using return_type = Return;
		static constexpr std::size_t aursize = sizeof...(Args);
		template<std::size_t I> struct arugment {
			static_assert(I < aursize, "Index out of range");
			using type = typename std::tuple_element<I, std::tuple<Args...>>::type;
		};
	};

	template <class Return, class...Args>
	struct function_traits<Return(*)(Args...)> : public function_traits<Return(Args...)> {};

	template <class Return, class...Args>
	struct function_traits<std::function<Return(Args...)>> : public function_traits<Return(Args...)> {};

	template <typename Functor>
	struct function_traits : public function_traits<decltype(&Functor::operator())> {};

	template <class Class, class Return, class...Args>
	struct function_traits<Return(Class::*)(Args...) const> : public function_traits<Return(Args...)> {};

	template <class Func>
	auto make_func(Func &&f)
	{
		typename function_traits<std::remove_reference_t<Func>>::func_type _f = std::forward<decltype(f)>(f);
		return std::forward<decltype(_f)>(_f);
	}
}  // namespace _Sun

double t(int a, int b) { return 2; }
auto g = [](int a, int b)->double{ return a + b + 0.2; };

int main() {
	using traits = _Sun::function_traits<decltype(g)>;
	std::cout << _Sun::type_name<decltype(&decltype(g)::operator())>() << std::endl;
	std::cout << traits::aursize << std::endl;
    system("pause");
    return 1;
}
