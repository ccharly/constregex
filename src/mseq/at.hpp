#ifndef MSEQ_AT_HPP__
#define MSEQ_AT_HPP__

#include "seq.hpp"

namespace mseq {

    template <typename Tseq, size_t Tn>
    struct at {
        typedef
            typename at<typename Tseq::tl, Tn - 1>::type
            type;
    };

    template <typename Tseq>
    struct at<Tseq, 0> {
        typedef
            typename Tseq::hd
            type;
    };

}

#endif
