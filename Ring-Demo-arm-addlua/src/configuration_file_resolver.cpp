#include "configuration_file_resolver.h"

#include <fstream>
#include <iostream>
#include <streambuf>


using namespace std;

ConfigurationFileResolver::ConfigurationFileResolver(
    const std::string& configuration_files_directories) {
  configuration_files_directories_ = configuration_files_directories;
}

std::string ConfigurationFileResolver::GetFullPathOrDie(
    const std::string& basename) {
    const std::string filename = configuration_files_directories_ + "/" + basename;
    std::ifstream stream(filename.c_str());
    if (stream.good()) {
      cout << "Found '" << filename << "' for '" << basename << "'."<<endl;
      return filename;
    }
  cout << "File '" << basename << "' was not found in : " << filename<<endl;
}

std::string ConfigurationFileResolver::GetFileContentOrDie(
    const std::string& basename) {
  const std::string filename = GetFullPathOrDie(basename);
  std::ifstream stream(filename.c_str());
  return std::string((std::istreambuf_iterator<char>(stream)),
                     std::istreambuf_iterator<char>());
}

