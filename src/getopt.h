// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//getopt.h
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
#if !defined(__POLYRAY_GETOPT)
#define __POLYRAY_GETOPT
#include <string>

class GetOpt {
public:
    GetOpt() {}
    int getopt(int argc, char** argv, const std::string& ostr);
    std::string GetOptarg1(void) { return optarg1;}
    std::string GetOptarg2(void) { return optarg2;}

private:
    static inline int _optind = 2;
    static inline std::string optarg1;//args associated with options
    static inline std::string optarg2;
    static inline const std::string EMESG = "";

    static void warning(const std::string& message) {
        // Implement warning message handling
    }
};

#endif //__POLYRAY_GETOPT