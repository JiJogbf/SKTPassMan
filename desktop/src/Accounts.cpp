#include "Accounts.hpp"

#include <fstream>
#include <iostream>

void Accounts::load(const char* filename){
    std::ifstream s(filename);
    int count = 0;
    s >> count;
    for(int i = 0; i < count; i++){
        std::string name;
        std::string username;
        std::string password;       
        s >> name >> username >> password;
        Account acc(name, username, password);
        items[acc.name] = acc;        
    } 
    s.close();
}

Account Accounts::get(const std::string& name){
    return items[name];
}

void Accounts::remove(const std::string& name){
    std::map<std::string, Account>::iterator it = items.find(name);
    if(it != items.end()){
        items.erase(it);
    }
}

void Accounts::save(const char* filename){
    std::ofstream s(filename);
    s << items.size() << std::endl;
    
    for(auto p = items.begin(); p != items.end(); ++p){
        s << p->first << std::endl
        << p->second.username << std::endl
        << p->second.password << std::endl;            
    }
    s.close();
}

void Accounts::print(){
    for(auto p = items.begin(); p != items.end(); ++p){
        std::cout << p->second.toString() << std::endl;
    }
}

void Accounts::add(const Account& acc){
    items[acc.name] = acc;
}