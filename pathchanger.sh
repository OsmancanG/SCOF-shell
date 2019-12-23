#!/bin/bash
newpath="#define PATH \"`pwd`\""
shpath="MYPATH=`pwd`"
echo $newpath
sed -i "8s|.*|$newpath|g" Shell_loop.c
sed -i "2s|.*|$shpath|g" ./Manuals/mancrypto.sh
sed -i "2s|.*|$shpath|g" ./Manuals/manfile.sh
sed -i "2s|.*|$shpath|g" ./Manuals/manhisted.sh
sed -i "2s|.*|$shpath|g" ./Manuals/manmakegen.sh
