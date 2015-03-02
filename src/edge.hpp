#ifndef EDGE_HPP__
#define EDGE_HPP__

constexpr char LAMBDA = (char)0xFF;

template <size_t Tlhs, size_t Trhs, char Tc = LAMBDA>
struct Edge {

    enum {
        is_lambda = Tc == LAMBDA,
        lhs = Tlhs,
        rhs = Trhs,
        c = Tc
    };

};

template <size_t Tid>
struct lhs_is {
    template <typename T>
    struct functor {
        enum {
            value = Tid == T::lhs
        };
    };
};

#endif
