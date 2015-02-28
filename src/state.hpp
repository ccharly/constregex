#ifndef STATE_HPP__
#define STATE_HPP__

template <size_t Tid, bool Tfinal = false>
struct State {
    enum {
        id = Tid,
        is_final = Tfinal
    };

    typedef
        State<Tid, true>
        make_final;
};

template <size_t Tid>
struct id_is {
    template <typename T>
    struct functor {
        enum {
            value = Tid == T::id
        };
    };
};

#endif
