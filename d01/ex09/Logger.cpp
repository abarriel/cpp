#include "Logger.hpp"
#include <iostream>
#include <fstream>
#include <time.h>

#define CALL_MEMBER_FN(object,ptrToMember)  ((object)->*(ptrToMember))

void Logger::logToConsole(std::string log) {
    std::cout << log << std::endl;
}

void Logger::logToFile(std::string log) {
    std::ofstream ofs(this->_name, std::ofstream::app);
    if (!ofs.is_open())
    {
        std::cout << "failed to create file " << this->_name << std::endl;
        return ;
    }
    ofs << log << std::endl;
    // std::cout << log << std::endl;
}

std::string Logger::makeLogEntry(std::string log) {
  time_t rawtime;
  char buffer[22];
  time (&rawtime);
  strftime(buffer,22,"[%F-%T] ", localtime(&rawtime));
  return log.insert(0, buffer);
}

Logger::Logger(std::string name): _name(name) {
    std::cout << "constructor called" << std::endl;
}

Logger::~Logger() {
    std::cout << "destructor called" << std::endl;
}

void Logger::log(std::string const & dest, std::string const & message) {
    const std::string name[2] = {"file", "log"};
    typedef void(Logger::*log)(std::string);
    log members[] = {&Logger::logToFile, &Logger::logToConsole};
    for (int i = 0; i < 2; i++) {
        if (dest == name[i])
        {
            CALL_MEMBER_FN(this, members[i])(Logger::makeLogEntry(message));            
            break;
        }
    }
}