#include "Init.h"
#include <LogStreamer.h>


 QDBusArgument &operator<<(QDBusArgument &argument, const DataTransfer &myStruct){
    argument.beginStructure();
    argument << myStruct.grade << myStruct.name;
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, DataTransfer &myStruct){
    argument.beginStructure();
    argument>> myStruct.grade >> myStruct.name;
    argument.endStructure();
    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const METHOD_RESULT &res){
    argument.beginStructure();
    argument<<static_cast<int>(res);
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, METHOD_RESULT &res){
    int resValue = -1;
    argument.beginStructure();
    argument>>resValue;
    argument.endStructure();
    if (resValue != static_cast<int>(METHOD_RESULT::SUCCESS) && resValue != static_cast<int>(METHOD_RESULT::FAILURE)){
        res = METHOD_RESULT::INVALID;
    }else{
        res = static_cast<METHOD_RESULT>(resValue);
    }
    return argument;
}
static void messageHandler(QtMsgType type, const QMessageLogContext &, const QString & msg){
    bool isValid = true;
    Utils::RecordLevel recordLevel = Utils::RecordLevel::INFO;
    switch(type){
        case QtDebugMsg:{
            recordLevel = Utils::RecordLevel::DEBUG;
            break;
        }
        case QtInfoMsg:{
            recordLevel = Utils::RecordLevel::INFO;
            break;
        }
        case QtWarningMsg:{
            recordLevel = Utils::RecordLevel::WARN;
            break;
        }
        case QtFatalMsg:{
            recordLevel = Utils::RecordLevel::FATAL;
            break;
        }
        case QtSystemMsg:{
            recordLevel = Utils::RecordLevel::CRITICAL;
            break;
        }
        default:{
            isValid = false;
            break;
        }
    }
    if (isValid){
        Utils::LogStream::createLog(recordLevel,msg.toStdString());
    }
}
namespace DBusNavtive{
    void initialize(){
        printf("Install success\n");
        qDBusRegisterMetaType<DataTransfer>();
        qDBusRegisterMetaType<METHOD_RESULT>();
        qInstallMessageHandler(messageHandler);
    }
}

