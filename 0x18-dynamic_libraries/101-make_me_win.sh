#!/bin/bash
wget -P https://github.com/ilyassdaaif/alx/raw/master/0x18%20C%20-%20Dynamic%20libraries/libgiga.so
export LD_PRELOAD=/tmp/libgiga.so
