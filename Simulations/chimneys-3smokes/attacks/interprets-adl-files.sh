# author: Francesco Racciatti <racciatti.francesco@gmail.com>

#!/bin/bash

echo "Intepret all adl files..."
rm *.xml
python ../../../interpreter/interpreter/interpreter.py -i misread.adl
python ../../../interpreter/interpreter/interpreter.py -i misplace.adl
python ../../../interpreter/interpreter/interpreter.py -i injection.adl
