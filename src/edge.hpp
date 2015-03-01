#ifndef EDGE_HPP__
#define EDGE_HPP__

template <size_t Tlhs, size_t Trhs, char Tc>
struct Edge {

    enum {
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
