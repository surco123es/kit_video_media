// This file is a part of media_kit
// (https://github.com/media-kit/media-kit).
//
// Copyright © 2021 & onwards, Hitesh Kumar Saini <saini123hitesh@gmail.com>.
// All rights reserved.
// Use of this source code is governed by MIT license that can be found in the
// LICENSE file.
#ifndef kit_video_media_PLUGIN_H_
#define kit_video_media_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include "video_output_manager.h"

namespace kit_video_media {

class KitVideoMediaPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows* registrar);

  KitVideoMediaPlugin(flutter::PluginRegistrarWindows* registrar);

  virtual ~KitVideoMediaPlugin();

  KitVideoMediaPlugin(const KitVideoMediaPlugin&) = delete;
  KitVideoMediaPlugin& operator=(const KitVideoMediaPlugin&) = delete;

 private:
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue>& method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);

  flutter::PluginRegistrarWindows* registrar_ = nullptr;
  std::unique_ptr<flutter::MethodChannel<flutter::EncodableValue>> channel_ =
      nullptr;
  std::unique_ptr<VideoOutputManager> video_output_manager_ = nullptr;
};

}  // namespace kit_video_media

#endif  // kit_video_media_PLUGIN_H_
