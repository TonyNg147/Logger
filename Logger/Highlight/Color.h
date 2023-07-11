#ifndef COLOR_H
#define COLOR_H
#include <string>
#include <mutex>
namespace Utils{
    enum class Color{
        RED=0
        ,BLUE
        ,GREEN
        ,YELLOW
        ,CYAN
        ,MAX
    };
    class Highlighter{
        private:
            Highlighter() = default;
        public:
            static Highlighter& getInstance();
            const char* getColor(Color color, const std::string&);
        private:
            const char* hightlightContent(const char* format,...);
        private:
            std::mutex m_protected;
            char m_buffer[4096];
            const char* mSettingColor[static_cast<uint8_t>(Color::MAX)] = {
                "\033[31m%s\033[0m",   //RED
                "\033[34m%s\033[0m",   //BLUES
                "\033[32m%s\033[0m",   //GREEB
                "\033[33m%s\033[0m",   //YELLOW
                "\033[36m%s\033[0m"    //CYAN
            };
    };
}

#endif //COLOR_H