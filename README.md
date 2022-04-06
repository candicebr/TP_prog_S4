# [TP Prog](https://julesfouchy.github.io/Learn--Clean-Code-With-Cpp/lessons/)

 

- [Level 1](#level-1)
- [Level 2](#level-2)
- [Level 3](#level-3)

---  

## Level 1

#### Introduction
#### Install a compiler
#### Use an IDE
  > <kbd>F2</kbd> : Rename  
  > <kbd>F12</kbd> : Go to definition  
  > <kbd>ALT</kbd> + <kbd>O</kbd> : Switch between .h and .cpp
#### Use Git
 > Clear commit : [part of the code] Add/Fix/Update thing
#### Use a debugger
#### Use a formatting tool
#### Use static analysers
#### Naming
  > Use variables or functions to split complicated statements (in 'if' statement for example)
#### Stack vs Heap
  > Prefer the stack  
  > When to use the heap : for varying-size objects, for big objects or for polymorphisme
#### Consistency in style

---  

## Level 2

#### Make it work, then make it good
#### Prefer free functions
  > Better encapsulation (can only use the public interface of the class)  
  > Easy to reuse, minimal dependencies
#### Design cohesive classes
  > Prefer struct over class if no invariants to enforce  
  > Single Responsability Principle : not mix concerns inside a single class  
  > No private methods : use free functions instead  
  > Public methods only to access private members  
#### Use structs to group data
  > Designated initializers : we can initialize an instance by naming its members  
  > Ex : .initial_width = 500
#### Write small functions
#### DRY: Don't repeat yourself
  > Code duplication doesn't mean textual duplication  
#### Enums
  > enum class : type checking  
  > "using enum *nameOfEnum*" : skip enum name in all switch cases  
#### Split problems in small pieces
#### Composition over Inheritance
  > Static polymorphism (compile time) through templates  
  > Dynamic polymorphism (runtime) - [std::variant](https://julesfouchy.github.io/Learn--Clean-Code-With-Cpp/lessons/variant/) - [std::function](https://julesfouchy.github.io/Learn--Clean-Code-With-Cpp/lessons/std-function/)  
  > Good use for inheritance : interfaces

---

## Level 3

#### std::vector
#### Minimize dependencies
#### Strong Types
 > Carry specific meaning through its name -> concrete representation to concepts, physical units, coordinate spaces...  
 > Prevent logic errors and make APIs harder to misuse  
#### Use libraries
 > Add libraries with CMake :
 > ```CMake
 > add_subdirectory(libname)
 > target_link_libraries(${PROJECT_NAME} PRIVATE libname)
 > ```
#### Range-based for loop
 > ```C++
 > for (/*const*/ auto& element : v) {
 > // ...
 > }
 > ```
 > Guarantees that we are not modifying the index in the body of the loop  
#### Testing
 > [doctest](https://github.com/doctest/doctest)

