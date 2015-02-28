#ifndef MSEQ_SEQ_HPP__
#define MSEQ_SEQ_HPP__

namespace mseq {

    struct empty {
    };

    template <typename Thd, typename Ttl>
    struct seq__ {
        typedef Thd hd;
        typedef Ttl tl;
    };

    template <typename Thd>
    struct seq__<Thd, empty> {
        typedef Thd hd;
        typedef empty tl;
    };

    template <typename Thd, typename... Targs>
    struct make__ {
        typedef
            seq__<
                Thd,
                typename make__<Targs...>::type
            > type;
    };

    template <typename... Targs>
    struct make__<empty, Targs...> {
        typedef empty type;
    };

    template <typename... Targs>
    struct make {
        typedef
            typename make__<Targs..., empty>::type
            type;
    };

}

#endif
