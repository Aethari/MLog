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
Make sure [mlog.h](mlog.h) is somewhere where your C program can access it
(typically in a `lib` or `include` folder), then include it like so:
```c
#define MLOG_IMPL
#include "mlog.h"
```
It is neccessary to define `MLOG_IMPL` (MLog Implementation) before including
the header, as this will give you the defined versions of the methods.

### Documentation
Because MLog is so tiny, we can fit the documentation for the library in the
README. Documentation can also be found in [mlog.h](mlog.h) where they are
declared.  

> `char log_path[1000]`
>> The path to the log file.

> `void log_init();`
>> Creates a log file at the directory of the running application. Should
>> only be called once, at the top of the main function. Sets log_path to
>> the absolute path of the file created.

> `void log_clear();`
>> Clears the log file, sparing no content.

> `void log_write(char msg[]);`
>> Writes a message to the log file
>>  
>> Parameters:
>> - msg: The message to be written to the log file

> `void log_pwrite(char msg[]);`
>> Writes a message to the log file and prints it to the terminal
>>
>> Parameters

## License
MLog is licensed under the MIT license.
