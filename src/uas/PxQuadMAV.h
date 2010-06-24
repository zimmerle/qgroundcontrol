#ifndef PXQUADMAV_H
#define PXQUADMAV_H

#include "UAS.h"

class PxQuadMAV : public UAS
{
    Q_OBJECT
    Q_INTERFACES(UASInterface)
public:
    PxQuadMAV(MAVLinkProtocol* mavlink, int id);
public slots:
    /** @brief Receive a MAVLink message from this MAV */
    void receiveMessage(LinkInterface* link, mavlink_message_t message);
    /** @brief Send a command to an onboard process */
    void sendProcessCommand(int watchdogId, int processId, unsigned int command);
signals:
    void watchdogReceived(int systemId, int watchdogId, unsigned int processCount);
    void processReceived(int systemId, int watchdogId, int processId, QString name, QString arguments, int timeout);
    void processChanged(int systemId, int watchdogId, int processId, int state, bool muted, int crashed, int pid);
};

#endif // PXQUADMAV_H