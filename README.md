<!-- Copyright (c) 2019 Pradhumna Rathore -->
# Page-Replacement
Various implementation of LRU (Least Recently Used) page replacement algorithm done as an OS assignment

## Group Members

| Name              | Enrollment Number |
| -------------     |:-------------:    |
| Nikunj Gupta      |   17114052        |
| Kanav Gupta       |   17114042        |
| Mahesh Kale       |   17114041        |
| Jaynil Jaiswal    |   17114040        |
| Pradhumna Rathore |   17114058        |
| Sameer Gupta      |   17114067        |
| Ashish Singh      |   17114014        |
| Aazim             |   161140          |

## Building

### Pre-Requisites

The program is written in standard C++14 standards and requires a C++ compiler (`gcc`, `clang` etc.).
Following are the pre-requisites to building:

```
* A C++ compiler
* Make
* CMake (Preferred)
```

**Note:** To run *graph.py* to generate graphs for the benchmarks, you require to install `matplotlib`
and `tkinter`. For Ubuntu/Debian systems, the commands are as follows:
```
$ sudo apt install python-tk
$ pip install matplotlib
```

### Building

The complete code for the LRU and clock are given as header files for easy and convinient use.
The library can be utilized simply by copy-pasting into your personal project. Here are the 
instructions to run `benchmarks`

1. Create a build folder
```
$ cd benchmarks
$ mkdir build && cd build
```

2. Invoke cmake
```
$ cmake ..
```

3. Build files
```
$ make
```

If you have done the setup right, you should see 4 executables `lru_aging`, `lru_counter`,
`lru_stack` and `clock`. To run, simply execute the executable:

```
$ ./lru_counter
```

Once all executables are in place, we can plot the graph from the given output. To generate
graph, run graph.py:
```
$ python2 graph.py
```


**Note:** In case you do not have Cmake installed, you can use a fallback makefile option.
To get the above executables, simply run the *Makefile* provided in the *benchmarks* folder.

```
$ cd benchmarks
$ make
```

## License

This project is licensed under the Apache-2.0 License - see the [LICENSE](LICENSE) for details.
