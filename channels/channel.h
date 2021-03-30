#ifndef CHANNEL_H
#define CHANNEL_H

#include <stdint.h>
#include <string>
#include <cstdarg>
#include <map>

class Channel {
protected:
    uint8_t id;
    std::map<uint8_t, std::string> commands;
public:
    Channel(uint8_t id) {this->id = id;}
    virtual bool ExecCommand(uint8_t channel_id, std::string cmd, ... );
    ~Channel() {};
};

#endif; // CHANNEL_H