// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//getopt.h
//(C) C. Meli 2024
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