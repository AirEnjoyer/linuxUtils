#!/bin/zsh
g++ install.cpp -o install
mkdir build
cd build
../install mkfat
../install clone
../install sdltemplate
../install template
../install tobin 
../install txt2pdf
