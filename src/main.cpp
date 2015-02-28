#include <cstdlib>
#include "mseq.hpp"
#include "state.hpp"
#include "automata.hpp"

typedef Automata<mseq::empty>
    ::push_state<State<0>>::type
    ::push_state<State<1>>::type
    ::push_state<State<2, true>>::type
    ::start_state<2>::type
    automata;

template <typename T>
void print_type() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main() {
    print_type<automata>();
    return 0;
}
