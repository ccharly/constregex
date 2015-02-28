#ifndef MSEQ_DEBUG_HPP__
#define MSEQ_DEBUG_HPP__

#include <iostream>
#include "seq.hpp"

namespace mseq {

    template <typename Tseq>
    void debug() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        debug<typename Tseq::tl>();
    }

    template <>
    void debug<empty>() {
    }

}

#endif
