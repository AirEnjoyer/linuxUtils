#!/bin/zsh
g++ install.cpp -o install
mkdir build
cd build
../install mkfat
../install qclone
../install sdltemplate
../install template
../install txt2pdf
