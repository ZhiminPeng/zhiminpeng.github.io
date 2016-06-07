#!/bin/bash

#compile the jemdoc files
source ~/.bashrc

jemdoc -c mysite.conf index paper MENU cv ms164 software pic10a15s blog

rm *~
