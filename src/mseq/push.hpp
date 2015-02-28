#ifndef MSEQ_PUSH_HPP__
#define MSEQ_PUSH_HPP__

#include "seq.hpp"

namespace mseq {

    template <typename Tseq, typename... Targs>
    struct push {

        typedef
            seq__<
                typename Tseq::hd,
                typename push<typename Tseq::tl, Targs...>::type
            > type;
    };

    template <typename... Targs>
    struct push<empty, Targs...> {
        typedef
            typename make<Targs...>::type
            type;
    };

}

#endif
