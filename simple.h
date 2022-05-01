/*
CREATED BY KINUSEKA
SIMPLE CODE IMPLEMENTATION
FUNCTIONS
*/



#ifndef SIMPLE_H
#define SIMPLE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>


/*Simple functions made easier to be readable*/
namespace pystd {
    template <typename T>
    std::string input(T usrinput) {
        std::cout << usrinput;
        std::string enter_str;
        getline(std::cin, enter_str);
        return enter_str;
    }
    int toint(std::string usrinput) {
        std::stringstream fromstr(usrinput);
        int buff = 0;
        fromstr >> buff;
        return buff;
    }
    std::string tostr(int usrinput) {
        std::stringstream tostr;
        tostr << usrinput;
        std::string buff;
        tostr >> buff;
        return buff;
    }
    int pchar(std::string chr) {
        std::string ascii;
        std::string concat;
        for (int i = 0; i < chr.length(); i++){
            ascii = tostr((int)chr[i]);
            concat = concat + ascii;
        }
        return toint(concat);
    }
    //int range(int range = 0, int last = 0, int step = 1) {
    class Random {
        public:
        Random() {
            seed(std::time(NULL));
        }
        template <typename SeedData>
        void seed(SeedData a) {
           std::srand((unsigned) a);
        }
        int randint(int start, int end){
            int determined = (std::rand() % ((end + 1) - start)) + start;
            return determined;
        }
    };
    bool is_digit(unsigned char chr) {
        return std::isdigit(chr);
    }
    bool all_digits(const std::string &str) {
        return std::all_of(str.begin(), str.end(), is_digit);
    }

}

/*Formatting tools*/
namespace pyformat {
    std::string lower(std::string usrstring) {
        for (char & c: usrstring) c = std::tolower(c);
        return usrstring;
    }
    std::string upper(std::string usrstring) {
        for (char & c: usrstring) c = std::toupper(c);
        return usrstring;
    }
}

#endif /* SIMPLE_H */
