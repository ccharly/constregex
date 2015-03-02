#include <cstdlib>
#include "mseq.hpp"
#include "state.hpp"
#include "automata.hpp"
#include "mstring.hpp"

// Let's create a basic automata
typedef
    Automata<>

    ::create_state<0>::type
    ::create_state<1, true>::type

    ::set_start_state<0>::type

    ::create_edge<0, 1, 'a'>::type
    ::create_edge<1, 1, 'a'>::type
    ::create_edge<1, 0, ','>::type

    automata;


// The input to match, because it is compile time,
// we need a constant expression.
// BUT, mstring is a macro that expand to multiple char(s):
//
// EXAMPLE: "hello" -> 'h', 'e', 'l', 'l', 'o'
//
// So you HAVE TO define a macro if you want to make a reference
// to a literal or use the literal directly...
#ifndef INPUT
# define THE_INPUT "aaaa,a"
#else
# define MAKE_LIT__(V) #V
# define MAKE_LIT(V) MAKE_LIT__(V)
# define THE_INPUT MAKE_LIT(INPUT)
#endif

int main() {

    std::cout << "Try to match the following input: " << THE_INPUT << std::endl;
    if (automata::match<mstring(THE_INPUT)>::value) {
        std::cout << "match" << std::endl;
    } else {
        std::cout << "does not match" << std::endl;
    }
    return 0;
}
