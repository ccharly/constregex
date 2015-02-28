#ifndef MSEQ_IF_ELSE_HPP__
#define MSEQ_IF_ELSE_HPP__

#include "seq.hpp"

namespace mseq {

    template <bool Tcond, typename Tthen, typename Telse>
    struct if_else {
        typedef Tthen type;
    };

    template <typename Tthen, typename Telse>
    struct if_else<false, Tthen, Telse> {
        typedef Telse type;
    };

}

#endif
