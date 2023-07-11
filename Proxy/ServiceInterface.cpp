#include "ServiceInterface.h"
ControllerInterface::ControllerInterface(const QString& service, 
                    const QString& object,
                    const QDBusConnection& connection,
                    QObject* parent )
    : QDBusAbstractInterface(service,object,"controller.service",connection,parent)
{

}
ControllerInterface::~ControllerInterface(){

}

ControllerInterface& ControllerInterface::getInstance(){
    static ControllerInterface instance("controller.service","/controller",QDBusConnection::sessionBus());
    return instance;
}
