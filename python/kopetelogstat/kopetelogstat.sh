#!/bin/sh
cat `find $1 -name '*.xml' ` | grep 'nick' | sed -re 's/.*nick=\"([^"]*)\"\s+in=\"([10])\".*/\1\t\2/'| python stat.py
