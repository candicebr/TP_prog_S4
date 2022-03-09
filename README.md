# TP Prog

## Level 1

### Introduction
### Install a compiler
### Use an IDE
  > F2 : rename  
  > Go to definition  
  > ALT + O : Switch between .h and .cpp
### Use Git
 > Clear commit : [part of the code] Add/Fix/Update thing
### Use a debugger
### Use a formatting tool
### Use static analysers
### Naming
  > Use variables or functions to split complicated statements (in 'if' statement for example)
### Stack vs Heap
  > Prefer the stack  
  > When to use the heap : for varying-size objects, for big objects or for polymorphisme
### Consistency in style

## Level 2

### Make it work, then make it good
### Prefer free functions
  > Better encapsulation (can only use the public interface of the class)
  > Easy to reuse, minimal dependencies
### Design cohesive classes
  > Prefer struct over class if no invariants to enforce
  > Single Responsability Principle : not mix concerns inside a single class
  > No private methods : use free functions instead
  > Public methods only to access private members
### Use structs to group data
  > Designated initializers : we can initialize an instance by naming its members 
  > Ex : .initial_width = 500
### Write small functions
### DRY: Don't repeat yourself
  > Code duplication doesn't mean textual duplication
### Enums
  > enum class : type checking
  > using enum "name of the enum" : skip enum name in all switch cases
### Split problems in small pieces
### Composition over Inheritance
