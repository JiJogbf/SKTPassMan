#ifndef SKT_APPLICATION_HPP
#define SKT_APPLICATION_HPP

#include <string>

#include "Accounts.hpp"

class Application{
public:
    static const std::string notEnoughArgsMsg; 
    static const std::string unrecognizedCmdMsg;
    static const std::string unsuportedCmdMsg;
    static const std::string filename;
public:
    Application(int argc, char** argv);
    ~Application();
    void run();
private:
    int argc;
    char** argv;
    Accounts accounts;
    void tryCopyToClip();
    void execCommand(int index);
    void copyToClipboard(const std::string& msg);
};

#endif 