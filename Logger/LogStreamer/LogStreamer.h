#ifndef LOG_STREAMER_H
#define LOG_STREAMER_H
#include <string.h>
#include <vector>
#include "../Highlight/Color.h"
namespace Utils{
    enum class RecordLevel{
        INFO=0,
        DEBUG,
        WARN,
        CRITICAL,
        FATAL
    };
    class LogStream{
        public:
            static RecordLevel _sysLogLevel ;
            static void createLog(RecordLevel logLevel, 
                                  const std::string& content);
        private:
            static void printLog(const char* format, ...);
            static std::string denoteLogLevel(RecordLevel logLevel);
        private:
            static std::vector<Utils::Color> _logHighlight;
            static std::vector<std::string> _logStamp;
    };
}
#endif //LOG_STREAMER_H