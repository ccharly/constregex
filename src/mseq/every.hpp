#ifndef MSEQ_EVERY_HPP__
#define MSEQ_EVERY_HPP__

#include "seq.hpp"

namespace mseq {

    template <typename Tseq, template <typename> class Tfunctor>
    struct every {
        enum {
            value =
                Tfunctor<typename Tseq::hd>::value
                && every<typename Tseq::tl, Tfunctor>::value
        };
    };

    template <template <class> class Tfunctor>
    struct every<empty, Tfunctor> {
        enum {
            value = true
        };
    };

}

#endif
