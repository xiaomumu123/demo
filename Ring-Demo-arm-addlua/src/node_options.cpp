#include "node_options.h"
#include "configuration_file_resolver.h"


NodeOptions CreateNodeOptions(
    LuaParameterDictionary* const
        lua_parameter_dictionary) {
  NodeOptions options;
  
  options.baseStation_Name = 
      lua_parameter_dictionary->GetString("baseStation_Name");
  options.baseStation_ID =
      lua_parameter_dictionary->GetInt("baseStation_ID");
  options.baseStation_Ip =
      lua_parameter_dictionary->GetString("baseStation_Ip");
 
  return options;
}



NodeOptions LoadOptions(
    const std::string& configuration_directory,
    const std::string& configuration_basename) {
  auto file_resolver = new ConfigurationFileResolver(configuration_directory);
  
  const std::string code =
      file_resolver->GetFileContentOrDie(configuration_basename);

  LuaParameterDictionary lua_parameter_dictionary(
      code, std::move(file_resolver));

    return CreateNodeOptions(&lua_parameter_dictionary);
}

