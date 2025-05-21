# MLog: A single header C logging library
MLog is a simple, single header logging library for C. It creates a 
basic `log.txt` file in the same directory as the running application
and provides functions to write to it.  

MLog stands for "mini log" and aims to be very small and lightweight.
As such, MLog has no external dependencies, so you can just clone it 
and start using it in your projects.  

MLog only runs on Linux and Windows. Feel free to make a pull request
or an issue if you want to add additional platforms.

## Usage
Make sure [MLog.h](MLog.h) is somewhere where your C program can access it
(typically in a `lib` or `include` folder), then include it like so:
```c
#define MLOG_IMPL
#include "MLog.h"
```
It is neccessary to define `MLOG_IMPL` (MLog Implementation) before including
the header, as this will give you the defined versions of the methods. 
However, `MLOG_IMPL` can only be defined in ONE file, otherwise, your program
will not compile.

It is also worthwhile to note that the `write()` and `pwrite()` functions do
not automatically append a newline when writing/printing. You will have to do
this yourself.

### Documentation
Because MLog is so tiny, we can fit the documentation for the library in the
README. Documentation can also be found in [MLog.h](MLog.h) where they are
declared.  

> `void MLog_init();`
>> Creates a log file at the directory of the running application. Should
>> only be called once, at the top of the main function. Sets log_path to
>> the absolute path of the file created.

> `void MLog_clear();`
>> Clears the log file, sparing no content.

> `void MLog_write(char msg[]);`
>> Writes a message to the log file
>>  
>> Parameters:
>> - msg: The message to be written to the log file

> `void MLog_pwrite(char msg[]);`
>> Writes a message to the log file and prints it to the terminal
>>
>> Parameters:
>> - msg: The message to be written to the log file and printed to
>>        the terminal

> `char *MLog_read();`
>> Reads the content of the log file into a string and returns a pointer
>> to it. The string is dynamically allocated, and MUST be freed after
>> use.
>>
>> Returns:
>> A pointer to a dynamically allocated string

## License
MLog is licensed under the MIT license.
