#pragma once
#include "TCP.h"
class Host
{
  public:
    Host() = default;
    ~Host() = default;

    void HostMain();

  private:
    TCP host{};
};
