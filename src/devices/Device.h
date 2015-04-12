/*
 *      Copyright (C) 2014 Garrett Brown
 *      Copyright (C) 2014 Team XBMC
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

#include "Buttons.h"

#include "kodi/kodi_peripheral_utils.hpp"

#include <map>
#include <stdint.h>
#include <string>

namespace JOYSTICK
{
  class CDevice
  {
  public:
    CDevice(void);

    CDevice(const std::string& m_strName,
            const std::string& strProvider,
            uint16_t           vid,
            uint16_t           pid,
            unsigned int       buttonCount,
            unsigned int       hatCount,
            unsigned int       axisCount);

    bool operator==(const CDevice& rhs) const;

    bool GetFeatures(const std::string& strDeviceId, std::vector<ADDON::JoystickFeature*>& features) const;

    bool MapFeature(const std::string& strDeviceId, const ADDON::JoystickFeature* feature);

  private:
    std::string  m_strName;
    std::string  m_strProvider;
    uint16_t     m_vid;
    uint16_t     m_pid;
    unsigned int m_buttonCount;
    unsigned int m_hatCount;
    unsigned int m_axisCount;

    typedef std::string                    DeviceName;
    typedef std::map<DeviceName, CButtons> ButtonMaps;

    ButtonMaps m_buttonMaps;
  };
}