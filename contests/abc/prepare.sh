#!/bin/bash
set -e

TARGET=$1

mkdir $TARGET

cp main.template $TARGET/a.cpp
cp main.template $TARGET/b.cpp
cp main.template $TARGET/c.cpp
cp main.template $TARGET/d.cpp
cp main.template $TARGET/e.cpp
cp main.template $TARGET/f.cpp
cp main.template $TARGET/g.cpp
cp main.template $TARGET/h.cpp

cp Makefile.template $TARGET/Makefile
