default: build

builddir := 'build'
binName := 'engine'

build:
    meson compile -C {{ builddir }}

run:
    ./{{ builddir }}/{{ binName }}

brun: build run

setup:
    meson setup {{ builddir }}

clear:
    rm -rf ./{{ builddir }}
