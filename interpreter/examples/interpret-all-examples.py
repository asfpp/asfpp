"""

Interprets all example .asl files in sub-dirs.

Usage:
 $ python interpret-all-examples.py

Author:
 + Francesco Racciatti  <racciatti.francesco@gmail.com>

Maintainer:
 + Francesco Racciatti  <racciatti.francesco@gmail.com>
 
"""


import os
import sys

from subprocess import call


if __name__ == "__main__":
    """
    Interpret all examples
    """   
    dir_name = os.path.dirname(sys.argv[0])
    abspath = os.path.abspath(dir_name)
    
    # Remove ~ files from sub-dirs
    for path, subdirs, files in os.walk(abspath):
        for file_name in files:
            if file_name.find("~"):
                file_abspath = os.path.join(path, file_name)
                shell_cmd = "rm " + file_abspath
                call(shell_cmd, shell=True)
    
    # Remove .xml files from sub-dirs
    for path, subdirs, files in os.walk(abspath):
        for file_name in files:
            if file_name.endswith(".xml"):
                file_abspath = os.path.join(path, file_name)
                shell_cmd = "rm " + file_abspath
                call(shell_cmd, shell=True)
    
    
    # Interpret .asl files in sub-dirs
    for path, subdirs, files in os.walk(abspath):
        for file_name in files:
            if file_name.endswith(".asl"):
                file_abspath = os.path.join(path, file_name)
                shell_cmd = "python ../interpreter/interpreter.py -i " + file_abspath
                call(shell_cmd, shell=True)
    
