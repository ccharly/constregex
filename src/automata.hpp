#ifndef AUTOMATA_HPP__
#define AUTOMATA_HPP__

#include "state.hpp"

template <typename Tstates, size_t Tstart = 0>
struct Automata {

    typedef Tstates states;
    static const size_t start = Tstart;

    template <typename T>
    struct push_state {
        typedef
            Automata<
                typename mseq::push<states, T>::type,
                start
            > type;
    };

    template <size_t Tnew_start>
    struct start_state {
        private:
            typedef
                Automata<states, Tnew_start>
                NewAutomata;

            template <typename T>
            using functor = typename id_is<Tnew_start>::template functor<T>;

        public:
            typedef
                typename std::enable_if<
                    mseq::some<states, functor>::value,
                    NewAutomata
                >::type type;
    };

};

#endif
