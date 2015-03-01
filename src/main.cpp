#include <cstdlib>
#include "mseq.hpp"
#include "state.hpp"
#include "automata.hpp"
#include "mstring.hpp"

typedef
    Automata<>

    ::create_state<0>::type
    ::create_state<1, true>::type

    ::set_start_state<0>::type

    ::create_edge<0, 1, 'a'>::type
    ::create_edge<1, 1, 'a'>::type
    ::create_edge<1, 0, ','>::type

    automata;

typedef
    automata::get_state<1>::type
    state1;

template <typename T>
void print_type() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main() {

    //if (automata::match("aa,a")::value) {
    //    std::cout << "matched" << std::endl;
    //}

    //print_type<automata>();
    //print_type<automata::get_edges_for<1>::type>();
    //print_type<state1>();

    //print_type<automata::get_next_state<'b'>::type>();

    //automata::match<salut, 0>::value;
    if (automata::match<mstring("aaaaaa,a")>::value) {
        std::cout << "matched" << std::endl;
    }

    return 0;
}
