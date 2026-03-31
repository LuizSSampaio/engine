
default: build

builddir := 'builddir'
binName := 'engine'

[working-directory: 'builddir']
build:
    meson compile

run:
    ./{{ builddir }}/{{ binName }}

brun: build run

setup:
    meson setup {{ builddir }}

clear:
    rm -rf ./{{ builddir }}
