# author: Francesco Racciatti <racciatti.francesco@gmail.com>

#!/bin/bash

echo "Intepret all adl files..."
rm *.xml
python ../../../interpreter/interpreter/interpreter.py -i attack1-100ms.adl
python ../../../interpreter/interpreter/interpreter.py -i attack1-250ms.adl

python ../../../interpreter/interpreter/interpreter.py -i attack2-100ms.adl
python ../../../interpreter/interpreter/interpreter.py -i attack2-250ms.adl

python ../../../interpreter/interpreter/interpreter.py -i attack3-base-v17.adl
python ../../../interpreter/interpreter/interpreter.py -i attack3-base-v35.adl
python ../../../interpreter/interpreter/interpreter.py -i attack3-clone1-v17.adl
python ../../../interpreter/interpreter/interpreter.py -i attack3-clone1-v35.adl
python ../../../interpreter/interpreter/interpreter.py -i attack3-clone2-v17.adl
python ../../../interpreter/interpreter/interpreter.py -i attack3-clone2-v35.adl
python ../../../interpreter/interpreter/interpreter.py -i attack3-clone4-v17.adl
python ../../../interpreter/interpreter/interpreter.py -i attack3-clone4-v35.adl

python ../../../interpreter/interpreter/interpreter.py -i attack7-base.adl
python ../../../interpreter/interpreter/interpreter.py -i attack7-2clones.adl
python ../../../interpreter/interpreter/interpreter.py -i attack7-4clones.adl
python ../../../interpreter/interpreter/interpreter.py -i test.adl
