"""
Interprets .asl files.

Usage:
 $ python interpret-all-attacks.py

Author(s):
 + Francesco Racciatti  <racciatti.francesco@gmail.com>
"""


import os
import sys

from subprocess import call


if __name__ == "__main__":
    """
    Interpret all attacks
    """   
    dir_name = os.path.dirname(sys.argv[0])
    abspath = os.path.abspath(dir_name)
    
    # Remove .xml files contained in the current dir
    for path, subdirs, files in os.walk(abspath):
        for file_name in files:
            if file_name.endswith(".xml"):
                file_abspath = os.path.join(path, file_name)
                shell_cmd = "rm " + file_abspath
                call(shell_cmd, shell=True)
    
    
    # Interpret .asl files contained in the current dir
    for path, subdirs, files in os.walk(abspath):
        for file_name in files:
            if file_name.endswith(".asl"):
                file_abspath = os.path.join(path, file_name)
                shell_cmd = "python ../../../interpreter/interpreter/interpreter.py -i " + file_abspath
                call(shell_cmd, shell=True)
    
