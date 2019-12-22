#!/bin/bash
newpath="#define PATH \"`pwd`\""
echo $newpath
sed -i "8s|.*|$newpath|g" Shell_loop.c
