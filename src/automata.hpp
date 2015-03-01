#ifndef AUTOMATA_HPP__
#define AUTOMATA_HPP__

#include "edge.hpp"
#include "state.hpp"
#include "mstring.hpp"

template <typename Tstates = mseq::empty, size_t Tstart = 0, typename Tedges = mseq::empty>
struct Automata {

    typedef Tedges edges;
    typedef Tstates states;
    static const size_t start = Tstart;

    template <size_t Tn, bool Tfinal = false>
    struct create_state {
        typedef
            Automata<
                typename mseq::push<states, State<Tn, Tfinal> >::type,
                start
            > type;
    };

    template <size_t Tnew_start>
    struct set_start_state {
        private:
            typedef
                Automata<states, Tnew_start, edges>
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

    template <size_t Tid>
    struct get_state {
        private:
            template <typename T>
            using functor = typename id_is<Tid>::template functor<T>;

        public:
            typedef
                typename mseq::find<states, functor>::type
                type;
    };

    template <size_t Tlhs, size_t Trhs, char Tc>
    struct create_edge {
        typedef
            Automata<
                states,
                start,
                typename mseq::push<edges, Edge<Tlhs, Trhs, Tc> >::type
            > type;
    };

    template <size_t Tid>
    struct get_edges_for {
        private:
            template <typename T>
            using functor = typename lhs_is<Tid>::template functor<T>;

        public:
            typedef
                typename mseq::filter<edges, functor>::type
                type;
    };

    template <char Tc>
    struct get_next_state {

        template <typename T>
        struct functor {
            enum {
                value = T::c == Tc
            };
        };

        enum {
            next =
                mseq::find<
                    typename get_edges_for<start>::type,
                    functor
                >::type::rhs
        };

        typedef typename get_state<next>::type type;
    };

    template <char Tc>
    struct has_next_state {

        template <typename T>
        struct functor {
            enum {
                value = T::c == Tc
            };
        };

        enum {
            value =
                mseq::some<
                    typename get_edges_for<start>::type,
                    functor
                >::value
        };
    };

    template <typename Ts, size_t Ti = 0>
    struct match {

        enum {
            current = Ts::template at<Ti>::value
        };

        template <bool Tcond, typename Tdummy = void>
        struct is_nextable {
            typedef
                typename set_start_state<
                    get_next_state<current>::type::id
                >::type
                NewAutomata;

            enum {
                value =
                    NewAutomata
                    ::template match<Ts, Ti + 1>::value
            };
        };

        template <typename Tdummy>
        struct is_nextable<false, Tdummy> {
            enum {
                value = false
            };
        };

        template <char Tzerobyte, typename Tdummy = void>
        struct is_zerobyte {
            enum {
                value =
                    is_nextable<
                        has_next_state<current>::value
                    >::value
            };
        };

        template <typename Tdummy>
        struct is_zerobyte<'\0', Tdummy> {
            enum {
                value = get_state<start>::type::is_final
            };
        };

        enum {
            value = is_zerobyte<current>::value
        };

    };

};

#endif
