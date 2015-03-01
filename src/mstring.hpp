#ifndef MSTRING_HPP__
#define MSTRING_HPP__

#define MSTRING_GET_1(str, i) \
    (sizeof(str) > (i) ? str[(i)] : 0)

#define MSTRING_GET_4(str, i) \
    MSTRING_GET_1(str, i+0),  \
    MSTRING_GET_1(str, i+1),  \
    MSTRING_GET_1(str, i+2),  \
    MSTRING_GET_1(str, i+3)

#define MSTRING_GET_16(str, i) \
    MSTRING_GET_4(str, i+0),   \
    MSTRING_GET_4(str, i+4),   \
    MSTRING_GET_4(str, i+8),   \
    MSTRING_GET_4(str, i+12)

#define MSTRING_GET_64(str, i) \
    MSTRING_GET_16(str, i+0),  \
    MSTRING_GET_16(str, i+16), \
    MSTRING_GET_16(str, i+32), \
    MSTRING_GET_16(str, i+48)

template <char... Tstr>
struct mstring__ {

    template <size_t Ti, char Tc, char... Ts>
    struct at__ {
        enum {
            value = at__<Ti - 1, Ts...>::value
        };
    };

    template <char Tc, char... Ts>
    struct at__<0, Tc, Ts...> {
        enum {
            value = Tc
        };
    };

    template <char Tc, size_t Ti>
    struct length__ {
        enum {
            value = 1 + length__<at__<Ti, Tstr...>::value, Ti + 1>::value
        };
    };

    template <size_t Ti>
    struct length__<'\0', Ti> {
        enum {
            value = 0
        };
    };

    enum {
        length = length__<at__<0, Tstr...>::value, 0 + 1>::value
    };

    template <size_t Ti>
    struct at {
        enum {
            value = std::enable_if<Ti <= length, at__<Ti, Tstr...> >::type::value
        };
    };

};

#define MSTRING(str) MSTRING_GET_64(str, 0), 0
#define mstring(str) mstring__<MSTRING(str)>

#endif
