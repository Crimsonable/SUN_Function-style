#include <cassert>
#include <functional>
#include <iostream>
#include <tuple>
#include <type_traits>

#include "function_traits.hpp"
#include "tuple_tools.hpp"

namespace _Sun {
    template <class Func, class Tuple = std::tuple<> >
    class currying_functor {
    private:
        Func _f;
        Tuple _t;
        std::size_t _argc_now;
        using traits = function_traits<Func>;
        using func_type = typename function_traits<Func>::func_type;

    public:
        currying_functor(Func &&f) : _f(std::forward<decltype(f)>(f)), _argc_now(0) {}
        currying_functor(const Func &f, const Tuple &t) : _f(f), _t(t), _argc_now(std::tuple_size<Tuple>::value) {}

        template <class... Args>
        auto operator()(Args &&... args) {
            auto args_list = std::tuple_cat(_t, std::forward_as_tuple(args...));
            return currying_functor<Func, decltype(args_list)>(_f, args_list);
        }

        auto eval() {
            return tuple_apply(_f, _t);
        }
    };

    template <class Func>
    auto curry(Func &&f) {
        auto _f = make_func(std::forward<Func>(f));
        return currying_functor<decltype(_f)>(std::forward<decltype(_f)>(_f));
    }
}  // namespace _Sun

int main() {
    auto g = [](int &a, int b) {a = 5; return 3; };
    auto c = _Sun::curry(g);
    int a = 10;
    auto st = c(a);
    st(2).eval();
    std::cout << a;
    system("pause");
    return 1;
}