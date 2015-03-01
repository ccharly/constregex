#ifndef MSEQ_FILTER_HPP__
#define MSEQ_FILTER_HPP__

#include "seq.hpp"
#include "push.hpp"

namespace mseq {

    namespace filter_st {

        template <bool Tcond, typename Tthen, typename Telse>
        struct if_else {
            typedef typename Tthen::type type;
        };

        template <typename Tthen, typename Telse>
        struct if_else<false, Tthen, Telse> {
            typedef typename Telse::type type;
        };
    }

    template <typename Tseq, typename Tresult, template <typename> class Tfunctor>
    struct filter__ {
        typedef
            typename filter_st::if_else<Tfunctor<typename Tseq::hd>::value,
                /* then */ filter__<typename Tseq::tl, typename push<Tresult, typename Tseq::hd>::type, Tfunctor>,
                /* else */ filter__<typename Tseq::tl, Tresult, Tfunctor>
            >::type type;
    };

    template <typename Tresult, template <typename> class Tfunctor>
    struct filter__<empty, Tresult, Tfunctor> {
        typedef Tresult type;
    };

    template <typename Tseq, template <typename> class Tfunctor>
    struct filter {
        typedef
            typename filter__<Tseq, empty, Tfunctor>::type
            type;
    };

}

#endif
