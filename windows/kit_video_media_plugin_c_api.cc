// This file is a part of media_kit
// (https://github.com/media-kit/media-kit).
//
// Copyright © 2021 & onwards, Hitesh Kumar Saini <saini123hitesh@gmail.com>.
// All rights reserved.
// Use of this source code is governed by MIT license that can be found in the
// LICENSE file.
#include "include/kit_video_media/kit_video_media_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#ifndef MEDIA_KIT_LIBS_NOT_FOUND

#include "kit_video_media_plugin.h"

void KitVideoMediaPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  kit_video_media::KitVideoMediaPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}

#else

#include <iostream>

void KitVideoMediaPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  std::cout << "media_kit: WARNING: package:media_kit_libs_*** not found."
            << std::endl;
}

#endif
