# Rozue postulates
* should always be copyleft and open-source
* code should be as "self-documenting" as possible
    * this includes type defining as much as possible, native types should be interfaced
* complex and/or hard to understand lines of code should be documented
* every non-obvious class should have a short description in documentation
* coldline engine should be as modular and extensible as possible
    * modules like `network` `geometry` `utility` are a good example
    * they are completely independant of any exterior engine's code
* client should never have access to anything that it shouldn't use
* server should be independant of any media libraries
* small and specialized libraries should be preferred
* every game assets that are unrelated to the engine should be embedded in language like lua
* mod support
