/*
 *      Copyright (C) 2015 Garrett Brown
 *      Copyright (C) 2015 Team XBMC
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "VFSFileUtils.h"
#include "filesystem/generic/ReadableFile.h"

#include "kodi/kodi_vfs_utils.hpp"

namespace ADDON { class CHelper_libXBMC_addon; }

namespace JOYSTICK
{
  class CVFSFile : public CReadableFile
  {
  public:
    CVFSFile(ADDON::CHelper_libXBMC_addon* frontend);

    virtual ~CVFSFile(void) { Close(); }

    // implementation of IFile
    virtual bool Open(const std::string& url, READ_FLAG flags = READ_FLAG::READ_FLAG_NONE) override;
    virtual bool OpenForWrite(const std::string& url, bool bOverWrite = false) override;
    virtual int64_t Read(uint64_t byteCount, std::string& buffer) override;
    virtual int64_t ReadLine(std::string& buffer) override;
    virtual int64_t Write(uint64_t byteCount, const std::string& buffer) override;
    virtual void Flush(void) override;
    virtual int64_t Seek(int64_t filePosition, SEEK_FLAG whence = SEEK_FLAG_SET) override;
    virtual bool Truncate(uint64_t size) override;
    virtual int64_t GetPosition(void) override;
    virtual int64_t GetLength(void) override;
    virtual void Close(void) override;

  private:
    ADDON::CHelper_libXBMC_addon* const m_frontend;
    ADDON::CVFSFile                     m_file;
    bool                                m_bOpen;
  };
}
