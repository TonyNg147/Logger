#include "LogStreamer.h"
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <chrono>
using namespace Utils;

std::string getApp(){
    FILE* f = nullptr;
    f = fopen("/proc/self/comm","r");
    if (f){
        char buff[4096];
        fscanf(f, "%s", buff);
        std::chrono::seconds secondsSinceEpoch = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch());
        srand(secondsSinceEpoch.count());
        uint8_t colorRand = rand() % 4 ;
        std::string appHightlight = Utils::Highlighter::getInstance().getColor(static_cast<Utils::Color>(colorRand),buff);
        return appHightlight;
    }
    return std::string("UNKNOWN");
}
std::string app = getApp();
RecordLevel LogStream::_sysLogLevel = RecordLevel::INFO;
std::vector<Utils::Color> LogStream::_logHighlight = {
    Utils::Color::GREEN,
    Utils::Color::YELLOW,
    Utils::Color::CYAN,
    Utils::Color::RED,
    Utils::Color::RED,
};
std::vector<std::string> LogStream::_logStamp = {
    "INFO",
    "DEBUG",
    "WARN",
    "CRITICAL",
    "FATAL",
};
void LogStream::createLog(RecordLevel logLevel, const std::string& content){
    if (logLevel >= _sysLogLevel && logLevel >= RecordLevel::INFO && logLevel <= RecordLevel::FATAL){
        std::string logLevelStamp = denoteLogLevel(logLevel);
        printLog("[%s][%s] %s\n",
                   app.c_str(),
                   logLevelStamp.c_str(),
                   content.c_str());
    }
}
#include <stdarg.h>
void LogStream::printLog(const char* format, ...){
    va_list list;
    va_start(list,format);  
    vprintf(format,list);
    va_end(list);
}

std::string LogStream::denoteLogLevel(RecordLevel logLevel)
{
    uint8_t logLevelIdx = static_cast<uint8_t>(logLevel);
    std::string logLevelStr = _logStamp[logLevelIdx];
    Color color             =  _logHighlight[logLevelIdx];
    return Highlighter::getInstance().getColor(color,logLevelStr);
}