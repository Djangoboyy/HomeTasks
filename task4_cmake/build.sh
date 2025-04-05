#!/bin/bash
set -e

# Вид сборки / суффикс в названии каталога сборки
# "Ninja" / "ninja"
# "Visual Studio 17 2022" / "visual_studio"

export BUILD_TYPE="Ninja"
export BUILD_SUFFIX="ninja"

BUILD_FOLDER="build-${BUILD_SUFFIX}"
SOURCE_FOLDER="projects"

if [ ! -d "$BUILD_FOLDER" ]; then
  mkdir -p "$BUILD_FOLDER"
fi

# cd "$BUILD_FOLDER"

# if [ ! -d "$SOURCE_FOLDER" ]; then
#   mkdir -p "$SOURCE_FOLDER"
# fi


cmake -G $BUILD_TYPE $SOURCE_FOLDER

cmake --build .

#TARGET_DIR="$BUILD_FOLDER/bubble_sort"
#if [ ! -d "$TARGET_DIR" ]; then
#  mkdir -p "$TARGET_DIR"
#fi
#cp "$SOURCE_FOLDER/bubble_sort/run_bubble_sort.bat" "$TARGET_DIR/run_bubble_sort.bat"

echo "Сборка завершена"
