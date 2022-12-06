#pragma once

#include "pchTVE.hh"

namespace TVE {

  class FileSystemEntity {
  public:
    virtual ~FileSystemEntity() = default;

    virtual bool isDirectory() const = 0;
    virtual bool exist() const = 0;
    virtual std::filesystem::path getPath() const = 0;
    virtual std::filesystem::path resolveFilePath(const std::filesystem::path& file) const = 0;
  };

  using FSEntityList = std::vector<std::shared_ptr<FileSystemEntity>>;
  using FSEntityPtr = std::shared_ptr<FileSystemEntity>;

  class FileSystem {
  public:
    virtual ~FileSystem() = default;

    virtual std::string getExtensionName(FSEntityPtr file) const = 0;
    virtual FSEntityPtr getParentDirectory(FSEntityPtr file) const = 0;
    virtual FSEntityList getFileList(FSEntityPtr dir) const = 0;
    virtual std::string getFileContent(FSEntityPtr file) const = 0;
  };

};
