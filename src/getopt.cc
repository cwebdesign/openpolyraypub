// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//getopt.cc
//(C) C. Meli 2024
#include <string>
#include <stdexcept>

#include "getopt.h"

    int GetOpt::getopt(int argc, char** argv, const std::string& ostr) {
        static std::string place = EMESG;  // option letter processing
        std::string::size_type oli;        // option letter list index

        if (place.empty()) {  // update scanning pointer
            if (_optind >= argc || (place = argv[_optind])[0] != '-' || place.empty()) {
                return EOF;
            }
            if (place[1] == '-') {  // found "--"
                ++_optind;
                return EOF;
            }
            place.erase(0, 1); // skip '-'
        }

        // check for a good letter option
        char optopt = place[0];
        place.erase(0, 1);
        if (optopt == ':' || optopt == '+' || (oli = ostr.find(optopt)) == std::string::npos) {
            if (place.empty()) ++_optind;
            warning(": illegal option -- '" + std::string(1, optopt) + "'");
            return 0;
        }

        if (ostr[oli + 1] == ':') {
            // need an argument
            if (!place.empty()) {
                optarg1 = place;
            } else if (argc <= ++_optind) { // no arg
                place = EMESG;
                warning(": option requires an argument -- '" + std::string(1, optopt) + "'");
                return 0;
            } else {
                optarg1 = argv[_optind];
            }
            place = EMESG;
            ++_optind;
        } else if (ostr[oli + 1] == '+') {
            // handle case for two arguments
            // similar to the above case, but requires two arguments
        } else {
            // don't need argument
            optarg1.clear();
            if (place.empty()) ++_optind;
        }
        return optopt;
    }

