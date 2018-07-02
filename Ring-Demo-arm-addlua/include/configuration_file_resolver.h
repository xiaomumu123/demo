#ifndef GLORY_CONFIGURATION_FILE_RESOLVER_H_
#define GLORY_CONFIGURATION_FILE_RESOLVER_H_

#include "lua_parameter_dictionary.h"

class ConfigurationFileResolver : public FileResolver {
 public:
  explicit ConfigurationFileResolver(
      const std::string& configuration_files_directories);

  std::string GetFullPathOrDie(const std::string& basename) override;
  std::string GetFileContentOrDie(const std::string& basename) override;

 private:
  std::string configuration_files_directories_;
};


#endif  // GLORY_CONFIGURATION_FILE_RESOLVER_H_
