#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <iostream>

class Logger {
    public:
        Logger(std::string name);
        ~Logger(void);
        const std::string _name;
        void log(std::string const & dest, std::string const & message);
    private:
        void logToConsole(std::string log);
        void logToFile(std::string log);
        std::string makeLogEntry(std::string log);
};

#endif
