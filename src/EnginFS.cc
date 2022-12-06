#include "EngineFS.hh"

#include <fstream>

namespace TVE {
  EngineFSEntity::EngineFSEntity(FSEntry fsEntry) 
    : _fsEntry(std::move(fsEntry)) {
  }

  bool EngineFSEntity::isDirectory() const {
    return _fsEntry.is_directory();
  }

  bool EngineFSEntity::exist() const {
    return _fsEntry.exists();
  }

  std::filesystem::path EngineFSEntity::getPath() const {
    return _fsEntry.path();
  }

  std::filesystem::path EngineFSEntity::resolveFilePath(const std::filesystem::path& file) const {
    if (_fsEntry.path().empty() && file.empty()) {
      return std::string();
    }
    if (file.is_absolute() || _fsEntry.path().empty() || _fsEntry.is_regular_file()) {
      return file.string();
    }
    return std::filesystem::path(_fsEntry.path().string() + "/" + file.string());
  }

  std::string EngineFS::getExtensionName(FSEntityPtr file) const {
    return file->getPath().extension().string();
  }

  FSEntityPtr EngineFS::getParentDirectory(FSEntityPtr file) const {
    // return getEntity(file->getPath().parent_path(), true);
    FSEntityPtr p;
    return p;
  }

  FSEntityList EngineFS::getFileList(FSEntityPtr dir) const {
    FSEntityList list;

    FSEntry dirEty(dir->getPath());

    for (auto const& file : FSEntryIter{dirEty}) {
      FSEntityPtr entity(std::make_shared<EngineFSEntity>(file));
      list.emplace_back(entity);
    }

    return list;
  }

  std::string EngineFS::getFileContent(FSEntityPtr file) const {
    std::string content;

    std::ifstream inFile(file->getPath(), std::ios::ate);

    if (!inFile.is_open()) {
      throw std::runtime_error("failed to open file: " + file->getPath().string());
    }

    size_t fileSize = (size_t)inFile.tellg();

    content.resize(fileSize);

    inFile.read(content.data(), fileSize);

    return content;
  }

};
