#!/usr/bin/python
"""
notifyMe: allows the user to execute a program
and when it ends show up a dialog with a title and message
in order to notify that it is ended.

"""

__author__ = "Alessandro Pischedda"
__email__ = "alessandro.pischedda@gmail.com"


import sys
from subprocess import call


def setup_pynotify():

    if not pynotify.init("NotifyMe"):
        sys.exit(1)

    def notifier(title, message):

        n = pynotify.Notification(opts['title'], msg)
        n.show()

    return notifier


def setup_gntp():

    def notifier(_title, message):
        gntp.notifier.mini(
            title=u"{0}".format(_title),
            description=u"{0}".format(message),
            applicationName=u"NotifyMe"
        )

    return notifier


try:
    import pynotify
    notifier = setup_pynotify()
except ImportError:
    print "Library pynotify missing"
    print "trying to import gntp (Growl Notifications)"

    try:
        import gntp.notifier
        notifier = setup_gntp()
    except ImportError:
        print "Unable to import gntp, exiting"
        sys.exit(-1)

try:
    from argparse import ArgumentParser, RawDescriptionHelpFormatter
except ImportError:
    print "Library argparse missing"
    sys.exit(-1)


def options():

    # set the option and help
    epilog = '''\
Note: 
       Every options need an argument between the \"\" if the argument is 
       composed by more than 1 word.
       EXAMPLE if the title is Super Urgent Data you need to type :
              python notifyMe.py -t \"Super Urgent Data\" -e \"ls -l\".
       This is necessary even for the -e and -m options, if the argument 
       is composed by just one element you can ignore the \"\".

Mandatory Options:
       The option -e is mandatory.'''

    # the RawDescriptionHelpFormatter is used to show the epilog has I want
    parser = ArgumentParser(epilog=epilog, formatter_class=RawDescriptionHelpFormatter,version="%prog 0.9")
    parser.add_argument("-t", "--title",
                      default="",
                      metavar="\"TITLE\"",
                      dest="title",
                      help="specify the title in the notification bar, "
                      "by default the title will be empty")
    parser.add_argument("-m", "--message",
                      metavar="\"MESSAGE\"",
                      dest="message", default="Terminated",
                      help="specify the message to be showed in the notification bar "
                      "by default is \"Terminated\"")
    parser.add_argument("-T", "--timeit", dest="timeit", action="store_true",
                      help="time the command to be executed")
    parser.add_argument("-e", "--execute", dest="command",
                      metavar="\"COMMAND\"",
                      help="the command to be executed, "
                      "remember to type the options for the command."
                      " This option is mandatory.")


    args = parser.parse_args()

    # make options as a dictionary
    opts = args.__dict__

    if opts['command'] is None:
        parser.error("Missing the option -e, it is mandatory.")

    return opts

if __name__ == "__main__":

    opts = options()

    if opts['timeit'] is not None:
        import timeit
        cmd = opts['command']

        fun = "call('%s', shell=True)" % cmd
        setup = "from subprocess import call"
        avg = timeit.timeit(stmt=fun, setup=setup, number=1)

        msg = "%s\ntime: %s" % (opts['message'], avg)
    else:
        # execute the command and wait until it is finished
        call(opts['command'], shell=True)
        msg = opts['message']

    notifier(opts['title'], msg)
