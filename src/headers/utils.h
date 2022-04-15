#ifndef UTILS_H
#define UTILS_H

#include <Windows.h>

#include <iostream>
#include <vector>
#include <fstream>

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


namespace utils {

    const float PI = 3.141592f;

    const std::string currentDateTime();

    bool fileExists(const std::string& filePath);

    int ourDistribution(int min, int max);

    template <typename T>
    T modulus(T val) {
        if (val >= 0)
            return val;
        return -val;
    }

    template <typename T = char*>
    void _insert_color(char* original, unsigned int pos, T new_insertion) {
        for (size_t i = 0; i < 6; i++)
            original[i + pos] = new_insertion[i + pos];
    }

    template <typename T>
    void swap(T& a, T& b) {
        T tmp = a;
        a = b;
        b = tmp;
    }


    class Logger {
    public:
        enum logPriority : unsigned short {Debug = 0, Info, Warning, Error, Critical};
        static bool DEBUG;

    private:
        unsigned short _priority;
        std::string _logFilePath;
        char* _prefix;

        inline std::vector<std::string> _getLogFileFolders() {

            auto pos = this->_logFilePath.find_first_of('/');

            std::vector<std::string> vSubstrs;

            std::string currSubstr = this->_logFilePath.substr(pos + 1);

            while (currSubstr.size() > 0) {
                currSubstr = this->_logFilePath.substr(pos + 1);
                vSubstrs.push_back(currSubstr);
            }

            return vSubstrs;
        }

        template<typename... Args>
        void _appendToFile(const char* priorityStr, const char* message, Args... args) {
            std::ofstream logFile;
            FILE* pFile;

            std::string loggingPath;
            if (Logger::DEBUG)
                loggingPath = this->_logFilePath;
            else
                loggingPath = "TermShooter.log";

            pFile = fopen((const char*) loggingPath.c_str(), "a+");

            std::fprintf(pFile, "[%s] - %s - %s - ", priorityStr, this->_prefix, currentDateTime().c_str());

            std::fprintf(pFile, message, args...);

            std::fprintf(pFile, ";\n");

            fclose(pFile);
        }

    public:
        Logger() {}
        Logger(char* loggerName, char* logFilePath, unsigned short priority=Info) {

            this->_prefix = loggerName;
            this->_logFilePath = std::string(logFilePath);
            this->_priority = priority;

            auto logFolderPaths = _getLogFileFolders();

            for (auto element : logFolderPaths) {
                // // Window API types Bullshit
                // LPCSTR longStr = new TCHAR[element.size() + 1];
                // strcpy(longStr, element.c_str());

                auto created = CreateDirectoryA(element.c_str(), NULL);

                if (created == ERROR_ALREADY_EXISTS)
                    this->debug("%s directory already exists", element);
            }
        }

        static void setDebug() {
            DEBUG = 1;
        }

        static void unsetDebug() {
            DEBUG = 0;
        }

        void setPriority(unsigned short priority) {
            this->_priority = priority;
        }

        unsigned short getPriority() {
            return this->_priority;
        }

        // Basic logging funcions:
        template<typename... Args>
        void debug(const char* message, Args... args) {
            if (this->_priority <= Debug)
                this->_appendToFile("DEBUG", message, args...);
        }

        template<typename... Args>
        void info(const char* message, Args... args) {
            if (this->_priority <= Info)
                this->_appendToFile("INFO", message, args...);
        }

        template<typename... Args>
        void warning(const char* message, Args... args) {
            if (this->_priority <= Warning)
                this->_appendToFile("WARNING", message, args...);
        }

        template<typename... Args>
        void error(const char* message, Args... args) {
            if (this->_priority <= Error)
                this->_appendToFile("ERROR", message, args...);
        }

        template<typename... Args>
        void critical(const char* message, Args... args) {
            if (this->_priority <= Critical)
                this->_appendToFile("CRITICAL", message, args...);
        }
    };
}

#endif // UTILS_H
