#!/bin/bash

path_main_c="./lib/cubemx/src/main.c"
path_main_h="./lib/cubemx/inc/main.h"
path_driver_c="./lib/cubemx/src/driver.c"
path_driver_h="./lib/cubemx/src/driver.h"
Inc="./lib/cubemx/Inc/"
src="./lib/cubemx/src/"
main="main.h"
driver="driver.h"

# move Src to src
if [ -d "./lib/cubemx/Src" ]; then
    mv ./lib/cubemx/Src ./lib/cubemx/src
fi

# move Inc file to src
if [ -d "$Inc" ]; then
    cp "${Inc}"* "$src"
    rm -rf "$Inc"
fi

# replace main.c with driver.c
if [ -e "$path_main_c" ]; then
    sed "s/main/driver/" $path_main_c > $path_driver_c
    rm $path_main_c
    echo "remove main.c"
fi

# replace all occurence of "main.h" in srcs
if [ -e "$src$main_h" ]; then
    for file in "$src"/*; do
        if [ -f "$file" ]; then
            sed "s/$main/$driver/g" "$file" > "${file}.new"
            mv "${file}.new" "$file"
        fi
    done
    # rename main.h to driver.h
    mv "$src/$main" "$src/$driver"
fi

# add driver declaration
if [ -f "$path_driver_h" ]; then
    if ! grep -q "int driver(void);" "$path_driver_h"; then
        sed '/\/\* USER CODE BEGIN EFP \*\//a int driver(void);' "$path_driver_h" > "${path_driver_h}.new"
        mv "${path_driver_h}.new" "$path_driver_h"
    fi
fi