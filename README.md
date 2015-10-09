# revisionControlSystem
Revision Control System


To develop with the Boost libraries in Ubuntu/Debian, you need to install the libboost-all-dev package:

sudo apt-get install libboost-all-dev

 Easy Build and Install

Issue the following commands in the shell (don't type $; that represents the shell's prompt):

```sh
$ cd path/to/boost_1_59_0
$ ./bootstrap.sh --help

```

Select your configuration options and invoke ./bootstrap.sh again without the --help option. Unless you have write permission in your system's /usr/local/ directory, you'll probably want to at least use

```sh
$ ./bootstrap.sh --prefix=path/to/installation/prefix
```

to install somewhere else. Also, consider using the --show-libraries and --with-libraries=library-name-list options to limit the long wait you'll experience if you build everything. Finally,

```sh
$ ./b2 install
```
will leave Boost binaries in the lib/ subdirectory of your installation prefix. You will also find a copy of the Boost headers in the include/ subdirectory of the installation prefix, so you can henceforth use that directory as an #include path in place of the Boost root directory.


Compile

```

g++ -std=c++11 -Os -Wall -pedantic x.cpp -lboost_system -lboost_filesystem


```


