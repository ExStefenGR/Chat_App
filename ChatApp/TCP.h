#pragma once
#include <SDL.h>
#include <SDL_Net.h>

#include <iostream>
#include <string>
#include <thread>
#include <vector>

class TCP
{
    //=============Host Mode=============
  public:
    TCP() = default;
    ~TCP() = default;
    bool HostInitialise();
    bool HostOpenSocket();
    void HostListenSocket();
    bool HostSendMessage();
    bool HostReceiveMessage();
    Uint16 m_port{2345u};

  private:
    TCPsocket m_listenSocket = nullptr;
    TCPsocket m_clientSocket = nullptr;
    int m_maxSockets{6};
    //=============Client mode=============
  public:
    bool ClientInitialise();
    bool ClientSendMessage();
    bool ClientReceiveMessage();

  private:
    IPaddress m_clientIp{};

    //=======Shared Access==========
  public:
    void Shutdown();
    IPaddress m_serverIp{};
    // SDLNet_SocketSet m_checker{};  <--This would be useful to avoid blocking
    // but there is no proper documentation
};
