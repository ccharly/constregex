#ifndef MSEQ_APPEND_HPP__
#define MSEQ_APPEND_HPP__

#include "seq.hpp"

namespace mseq {

    template <typename Tseq_1, typename Tseq_2>
    struct append {
        typedef
            seq__<
                typename Tseq_1::hd,
                typename append<typename Tseq_1::tl, Tseq_2>::type
            > type;
    };

    template <typename Tseq_2>
    struct append<mseq::empty, Tseq_2> {
        typedef
            seq__<
                typename Tseq_2::hd,
                typename append<mseq::empty, typename Tseq_2::tl>::type
            > type;
    };

    template <>
    struct append<mseq::empty, mseq::empty> {
        typedef mseq::empty type;
    };

}

#endif
