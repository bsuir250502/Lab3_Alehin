To create a Makefile you need cmake.

The simplest cmake command is
$ cmake .
(you need to be in directory contains CMakeLists.txt)

To change the generator, you should first run
$ cmake --help
And you can see:

The following generators are available on this platform:
    Unix Makefiles              = Generates standard UNIX makefiles.
    CodeBlocks - Unix Makefiles = Generates CodeBlocks project files.
    Eclipse CDT4 - Unix Makefiles
                                = Generates Eclipse CDT 4.0 project files.
    KDevelop3                   = Generates KDevelop 3 project files.
    KDevelop3 - Unix Makefiles  = Generates KDevelop 3 project files.

Then, to select a different generator you need to call cmake with the -G option and pass it the full name of the generator you want to use. For example, to have cmake generate CodeBlocks build files, you'd call
$ cmake . -G "CodeBlocks - Unix Makefiles"

cmake also has an interactive mode which you start by typing
$ cmake . -i

In this mode, cmake will present to you all cache variables and ask you if you want to keep the current value or enter a new one. 

This commands just produced your Makefile, last command is:
$ make

