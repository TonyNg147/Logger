#include "Color.h"
#include <stdarg.h>
using namespace Utils;
Highlighter& Highlighter::getInstance(){
    static Highlighter instance;
    return instance;
}
const char* Highlighter::hightlightContent(const char* format,...){
    std::unique_lock<std::mutex>  lock(m_protected);
    va_list list;
    va_start(list,format);
    vsprintf(m_buffer,format,list);
    va_end(list);
    return m_buffer;
};
const char* Highlighter::getColor(Color color, const std::string& str){
    if (color < Color::RED || color > Color::CYAN) return nullptr;
    return hightlightContent(mSettingColor[static_cast<uint8_t>(color)],str.c_str());
}