// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//getopt.cc
//(C) C. Meli 2024
/* This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
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

