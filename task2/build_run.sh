#!/bin/bash

# Установка кодировки
CHARSET="-finput-charset=utf-8 -fexec-charset=utf-8"

# Определение имен файлов
CPP_FILES=*.cpp
PRODUCT="prog.exec"

# Удаление предыдущего исполняемого файла, если он существует
if [ -f "$PRODUCT" ]; then
    rm $PRODUCT
fi

# Компиляция программы
g++ $CHARSET $CPP_FILES -o $PRODUCT

./$PRODUCT
