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

try:
    from argparse import ArgumentParser, RawDescriptionHelpFormatter
except ImportError:
    print "Error: library 'argparse' is missing. Please, install it."
    sys.exit(-1)


def parse_verbose_option():
    """
    Parse command line options
    """
    
    epilog = "There are not mandatory arguments"
    
    # The RawDescriptionHelpFormatter is required to show the epilog
    parser = ArgumentParser(epilog=epilog, formatter_class=RawDescriptionHelpFormatter,version="%prog 1.0")
    
    parser.add_argument("-s", "--show",
                        metavar = "\"SHOW\"",
                        default = "",
                        help = "Show details")
    
    args = parser.parse_args()
    
    # Convert the list of options to a dictionary
    options = args.__dict__
    
    if options["show"] == "":
        return False
    elif options["show"] in ["TRUE", "True", "true", "T", "t", "YES", "Yes", "yes", "Y", "y", "1"]:
        return True
    else:
        print "-s argument not recognized"
        exit(-1)
        
    return False



if __name__ == "__main__":
    """
    Interpret and run all attacks
    """   
    # Retrieve command line arguments and options
    verbose = parse_verbose_option()
    
    dir_name = os.path.dirname(sys.argv[0])
    root_path = os.path.abspath(dir_name)
    
    # Remove .xml files contained in the attack current dir
    
    attacks_path = os.path.join(root_path, "attacks")
    
    for path, subdirs, files in os.walk(attacks_path):
        for file_name in files:
            if file_name.endswith(".xml"):
                xml_file_path = os.path.join(path, file_name)
                shell_cmd = "rm " + xml_file_path
                if verbose :
                    print shell_cmd
                call(shell_cmd, shell=True)
    
    # Interpret .asl files contained in the current dir and launch simulation
    for path, subdirs, files in os.walk(attacks_path):
        for file_name in files:
            if file_name.endswith(".asl"):
                asl_file_path = os.path.join(path, file_name)
                shell_cmd = "python ../../interpreter/interpreter/interpreter.py -i " + asl_file_path
                if verbose :
                    print shell_cmd                
                call(shell_cmd, shell=True)
                # if ok launch simulation
    
