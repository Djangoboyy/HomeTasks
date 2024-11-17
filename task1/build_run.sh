#!/bin/bash

# Установка кодировки
CHARSET="-finput-charset=utf-8 -fexec-charset=utf-8"

# Определение имен файлов
MAIN="after_refactoring.cpp"
PRODUCT="before_refactoring.exec"

# Удаление предыдущего исполняемого файла, если он существует
if [ -f "$PRODUCT" ]; then
    rm $PRODUCT
fi

# Компиляция программы
g++ $CHARSET $MAIN -o $PRODUCT

./$PRODUCT
