# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/esp/esp-idf/components/bootloader/subproject"
  "D:/GITHUB/MiscCodes/Huzaifa/Progress_ESP32/BME280/build/bootloader"
  "D:/GITHUB/MiscCodes/Huzaifa/Progress_ESP32/BME280/build/bootloader-prefix"
  "D:/GITHUB/MiscCodes/Huzaifa/Progress_ESP32/BME280/build/bootloader-prefix/tmp"
  "D:/GITHUB/MiscCodes/Huzaifa/Progress_ESP32/BME280/build/bootloader-prefix/src/bootloader-stamp"
  "D:/GITHUB/MiscCodes/Huzaifa/Progress_ESP32/BME280/build/bootloader-prefix/src"
  "D:/GITHUB/MiscCodes/Huzaifa/Progress_ESP32/BME280/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/GITHUB/MiscCodes/Huzaifa/Progress_ESP32/BME280/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
