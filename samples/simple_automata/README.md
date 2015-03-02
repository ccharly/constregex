## Run it

Since we match string at compile-time we have to inject before compilation
using preprocessor.

`INPUT` is a preprocessor directive that will be used as input. You can use it
with the run command like the following:
```
INPUT="foo" make run
```
