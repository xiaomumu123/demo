#ifndef GLORY_NODE_OPTIONS_H
#define GLORY_NODE_OPTIONS_H

#include <string>
#include <tuple>

#include "lua_parameter_dictionary.h"
//#include "proto/base_station_options.pb.h"
//#include "baseStation.h"

struct NodeOptions {
    std::string baseStation_Name;
    int baseStation_ID;
    std::string baseStation_Ip;
    
};

NodeOptions CreateNodeOptions(
    LuaParameterDictionary* lua_parameter_dictionary);

NodeOptions LoadOptions(
    const std::string& configuration_directory,
    const std::string& configuration_basename);


#endif  // GLORY_NODE_OPTIONS_H