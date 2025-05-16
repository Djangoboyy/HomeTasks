#!/bin/bash
clear

set -e

# Вид сборки / суффикс в названии каталога сборки
# "Ninja" / "ninja"
# "Visual Studio 17 2022" / "visual_studio"

export BUILD_TYPE="Ninja"
export BUILD_SUFFIX="ninja"
export directory

BUILD_FOLDER="build-${BUILD_SUFFIX}"
SOURCE_FOLDER="projects"

if [ ! -d "$BUILD_FOLDER" ]; then
  mkdir -p "$BUILD_FOLDER"
fi

if [ ! -d "${SOURCE_FOLDER}/lib/" ]; then
  mkdir -p "${SOURCE_FOLDER}/lib/"
fi

if [ ! -d "${SOURCE_FOLDER}/lib/googletest" ]; then
  git clone https://github.com/google/googletest ${SOURCE_FOLDER}/lib/googletest
  echo "[googletest] Зависимости подтянулись"
fi

cd "$BUILD_FOLDER"

cmake -G $BUILD_TYPE ../$SOURCE_FOLDER
cmake --build .

echo "Сборка завершена"