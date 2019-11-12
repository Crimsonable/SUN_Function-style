#include <functional>
#include <iostream>
#include <string>
#include <tuple>

namespace _Sun {

    template <class T>
    constexpr std::string type_name() {
        std::string name;
#ifdef __clang__
        name = __PRETTY_FUNCTION__;
        return std::string(name.data() + 34, name.size() - 34 - 1);
#endif
#ifdef __GNUC__
        name = __PRETTY_FUNCTION__;
#if __cplusplus < 201402
        return std::string(name.data() + 36, name.size() - 36 - 1);
#else
        return std::string(name.data() + 50, name.find(';', 49) - 50);
#endif
#endif
#ifdef _MSC_VER
        name = __FUNCSIG__;
        return std::string(name.data() + 118, name.size() - 118 - 8);
#endif
    }

    template <typename F>
    struct function_traits;

    template <typename Return, typename... Args>
    struct function_traits<Return(Args...)> {
        using func_type = std::function<Return(Args...)>;
        using return_type = Return;
        static constexpr std::size_t argsize = sizeof...(Args);
        template <std::size_t I>
        struct argument {
            static_assert(argsize > 0, "function has no args!");
            static_assert(I < argsize, "Index out of range!");
            using type = typename std::tuple_element<I, std::tuple<Args...>>::type;
        };
    };

    //function pointer
    template <class Return, class... Args>
    struct function_traits<Return (*)(Args...)> : public function_traits<Return(Args...)> {};
    //std::function
    template <class Return, class... Args>
    struct function_traits<std::function<Return(Args...)>> : public function_traits<Return(Args...)> {};
    //back-end of Lambda and functor;class const member function
    template <class Class, class Return, class... Args>
    struct function_traits<Return (Class::*)(Args...) const> : public function_traits<Return(Args...)> {};
    //functor and Lambda
    template <typename Functor>
    struct function_traits : public function_traits<decltype(&Functor::operator())> {};
    //class member function
    template <class Class, class Return, class... Args>
    struct function_traits<Return (Class::*)(Args...)> : public function_traits<Return(Args...)> {};
    //class member object
    template <class Class, class Return>
    struct function_traits<Return(Class::*)> : public function_traits<Return()> {};

    template <class Func>
    constexpr auto make_func(Func&& f) {
        typename function_traits<std::remove_reference_t<Func>>::func_type _f = std::forward<decltype(f)>(f);
        return std::forward<decltype(_f)>(_f);
    }

    template <class Func>
    inline constexpr std::size_t argsize(Func&& f) {
        return function_traits<std::remove_reference_t<Func>>::argsize;
    }

    template <class Func, std::size_t I>
    struct arg_type {
        using type = typename function_traits<std::remove_reference_t<Func>>::template argument<I>::type;
    };
}  // namespace _Sun

/*double t(int a, int b) { return 2; }
auto g = [](int& a, int b) -> double { return a + b + 0.2; };
struct rua {
    double s(int& r) { return 1; }
    double k;
};

int main() {
    using traits = _Sun::function_traits<decltype(g)>;
    std::cout << traits::argsize << std::endl;
    std::cout << std::is_reference_v<traits::argument<1>::type> << std::endl;
    system("pause");
    return 1;
}*/
