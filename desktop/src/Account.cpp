#include "Account.hpp"

Account::Account(const std::string& name, 
        const std::string& username, 
        const std::string& password):
    name(name), username(username), password(password)
{}

std::string Account::toString(){
    return "name=" + name + ", username=" + 
        username + ", password=" + password;
}