#!/bin/bash

#compile the jemdoc files
JEMDOC='/Users/zhiminpeng/Documents/software/jemdoc.py'
$JEMDOC -c mysite.conf index paper MENU cv ms164 software pic10a15s blog

rm *~
