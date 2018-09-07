#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include "openvpn3/client/ovpncli.hpp"

class ConnectionManager : public openvpn::ClientAPI::OpenVPNClient
{
public:
    ConnectionManager();
};

#endif // CONNECTIONMANAGER_H
