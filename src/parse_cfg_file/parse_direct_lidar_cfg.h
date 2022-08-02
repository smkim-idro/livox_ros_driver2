//
// The MIT License (MIT)
//
// Copyright (c) 2019 Livox. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef LIVOX_ROS_DRIVER_PARSE_DIRECT_LIDAR_CFG_H_
#define LIVOX_ROS_DRIVER_PARSE_DIRECT_LIDAR_CFG_H_

#include "livox_def_direct.h"

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"

#include "../comm/comm.h"

#include <iostream>
#include <string>
#include <memory>
#include <vector>

namespace livox_ros {

class ParseDirectLidarCfgFile {
 public:
  explicit ParseDirectLidarCfgFile(const std::string& path);
  ~ParseDirectLidarCfgFile() {}
  
  bool Parse(DirectLidarParam& direct_lidar_param);
 private:
  bool ParseHostCfg(const rapidjson::Value &object, DirectLidarHostCfg& direct_host_cfg);
  bool ParseLidarsCfg(const rapidjson::Value& array, std::vector<DirectLidarCfg>& vec_direct_lidar_cfg);
  bool ParseLidarIpCfg(const rapidjson::Value& lidar_cfg_object, DirectLidarIpCfg& direct_lidar_cfg);
  bool ParseInstallAttitude(const rapidjson::Value& object, InstallAttitude& install_attitude);
 private:
  const std::string path_;
};

} // namespace livox_ros
#endif // LIVOX_ROS_DRIVER_PARSE_DIRECT_LIDAR_CFG_H_
