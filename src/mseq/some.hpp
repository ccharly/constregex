#ifndef MSEQ_SOME_HPP__
#define MSEQ_SOME_HPP__

#include "seq.hpp"

namespace mseq {

    template <typename Tseq, template <typename> class Tfunctor>
    struct some {
        enum {
            value =
                Tfunctor<typename Tseq::hd>::value
                || some<typename Tseq::tl, Tfunctor>::value
        };
    };

    template <template <class> class Tfunctor>
    struct some<empty, Tfunctor> {
        enum {
            value = false
        };
    };

}

#endif
