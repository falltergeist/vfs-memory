#pragma once

// Project includes
#include "falltergeist/vfs/MemoryFile.h"

// Third party includes
#include "falltergeist/vfs/IDriver.h"

// stdlib
#include <map>
#include <memory>

namespace Falltergeist::VFS {
    /**
     * MemoryDriver provides support for storing/accessing files stored in memory
     * Once file created it will be stored in memory even if it was closed
     * Therefore it can be reopened again without content loss
     */
    class MemoryDriver final : public IDriver {
    public:
        MemoryDriver();

        ~MemoryDriver() override = default;

        const std::string& name() override;

        bool exists(const std::string &path) override;

        std::shared_ptr<IFile> open(const std::string &path, IFile::OpenMode mode) override;

    private:
        std::string _name;

        std::map<std::string, std::shared_ptr<MemoryFile>> _files;
    };
}
