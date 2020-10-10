#ifndef SKT_ACCOUNTS_HPP
#define SKT_ACCOUNTS_HPP

#include <string>
#include <map>

#include "Account.hpp"

class Accounts{
private:
    std::map<std::string, Account> items;
public:
    void load(const char* filename);
    void save(const char* filename);
    void add(const Account& acc);
    void remove(const std::string& name);
    void print();
    Account get(const std::string& name);
};

#endif