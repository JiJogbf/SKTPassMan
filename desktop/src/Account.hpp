#ifndef SKT_ACCOUNT_HPP
#define SKT_ACCOUNT_HPP

#include <string>

struct Account{
    std::string name;
    std::string username;
    std::string password;
    Account() = default;
    Account(const std::string& name, 
            const std::string& username,  
            const std::string& password);
    std::string toString();
};

#endif