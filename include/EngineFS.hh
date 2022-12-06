#pragma once

#include "FileSystem.hh"

namespace TVE {

  using FSEntry = std::filesystem::directory_entry;
  using FSPath = std::filesystem::path;
  using FSEntryIter = std::filesystem::directory_iterator;

  class EngineFSEntity : public FileSystemEntity{
  public:
    explicit EngineFSEntity(FSEntry fsEntry);

    bool isDirectory() const override;
    bool exist() const override;
    std::filesystem::path getPath() const override;
    std::filesystem::path resolveFilePath(const std::filesystem::path& file) const override;

  private:
    FSEntry _fsEntry;
  };

  class EngineFS : public FileSystem {
  public:
    std::string getExtensionName(FSEntityPtr file) const override;
    FSEntityPtr getParentDirectory(FSEntityPtr file) const override;
    FSEntityList getFileList(FSEntityPtr dir) const override;
    std::string getFileContent(FSEntityPtr file) const override;
  };

};
