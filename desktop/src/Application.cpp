#include "Application.hpp"

#include <iostream>
#include <windows.h>

#include "Account.hpp"

const std::string Application::notEnoughArgsMsg = "not enough args";
const std::string Application::unrecognizedCmdMsg = "unrecognized command";
const std::string Application::unsuportedCmdMsg = "unsoported command";
const std::string Application::filename = "db.txt";

Application::Application(int argc, char** argv): 
    argc(argc), argv(argv), accounts()
{}

Application::~Application(){}

static void error(const std::string& msg){
    std::cout << msg << std::endl;
}

static void info(const char* msg){
    std::cout << msg << std::endl;
}

static int getCmdIndex(const std::string& cmd){
    if(cmd == "add"){
        return 0;
    }else if(cmd == "list"){
        return 1;
    }else if(cmd == "remove"){
        return 2;
    }else if(cmd == "clip"){
        return 3;
    }else if(cmd == "help"){
        return 4;
    }else{
        return -1;
    }
}

static void newHelp(){
    std::cout << "Available commands: " << std::endl 
        << "add\t - add new data -- add [acc-name] [username] [password]" << std::endl
        << "list\t - list created commands" << std::endl
        << "remove\t - remove account by [acc-name]" << std::endl
        << "clip\t - copy password by [acc-name]" << std::endl
        << "help\t - print this list of commands" << std::endl;
}

static void tryAddAccount(Accounts& accounts, char** argv, int argc){
    if(argc >= 5){
        accounts.add(Account{argv[2], argv[3], argv[4]});
    }else{
        error(Application::notEnoughArgsMsg);
    }
}

static void tryRemoveAccount(Accounts& accounts, char** argv, int argc){
    if(argc >= 3){
        accounts.remove(argv[2]);
    }else{
        error(Application::notEnoughArgsMsg);
    }
}

void Application::copyToClipboard(const std::string& msg){
	OpenClipboard(0);
	EmptyClipboard();	
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, msg.size() + 1);
	if (!hg){
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), msg.c_str(), msg.size() + 1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}

void Application::tryCopyToClip(){
    if(argc >= 3){
        Account acc = accounts.get(argv[2]);
        copyToClipboard(acc.password);
        info("account password copied to clibboard");
    }else{
        error(notEnoughArgsMsg);
    }
}

void Application::execCommand(int index){
    switch(index){
        case 0: tryAddAccount(accounts, argv, argc); break;
        case 1: accounts.print(); break;
        case 2: tryRemoveAccount(accounts, argv, argc); break;
        case 3: tryCopyToClip(); break;
        case 4: newHelp(); break;
        case -1: error(unrecognizedCmdMsg); break; 
        default: error(unsuportedCmdMsg); break;
    }
}

void Application::run(){
    if(argc >= 2){
        accounts.load(filename.c_str());
        execCommand(getCmdIndex(argv[1]));
        accounts.save(filename.c_str());
    }else{
        error(notEnoughArgsMsg);
    }
}