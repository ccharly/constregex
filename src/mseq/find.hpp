#ifndef MSEQ_FIND_HPP__
#define MSEQ_FIND_HPP__

#include "seq.hpp"

namespace mseq {

    namespace find_st {

        template <bool Tcond, typename Tthen, typename Telse>
        struct if_else {
            typedef Tthen type;
        };

        template <typename Tthen, typename Telse>
        struct if_else<false, Tthen, Telse> {
            typedef typename Telse::type type;
        };
    }

    template <typename Tseq, template <typename> class Tfunctor>
    struct find {
        typedef
            typename find_st::if_else<Tfunctor<typename Tseq::hd>::value,
                /* then */ typename Tseq::hd,
                /* else */ find<typename Tseq::tl, Tfunctor>
            >::type type;
    };

    template <template <typename> class Tfunctor>
    struct find<empty, Tfunctor> {
    };

}

#endif
