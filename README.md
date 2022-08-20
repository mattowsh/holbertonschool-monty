# <a  href="https://www.python.org/"> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/1f/Python_logo_01.svg/800px-Python_logo_01.svg.png" alt="Python Language" width=4% heigth=4% ></img></a> Interpreter for Monty ByteCodes files
The **interpeter for Monty ByteCodes files project** is a project of Foundations: second trimester, of the career Software Engineering at Holberton School.

The objetive is **create an interpreter for Monty ByteCodes files** using C programming language.

The authors are Santiago "Toti" Fernández and Belén Matto.  
Holberton School, 2022.  

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (like Python). It relies on a unique stack, with specific instructions to manipulate it.

Files containing Monty byte codes usually have the .m extension.

There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

## C libraries used
- `<stdio.h>`
- `<string.h>`
- `<stdlib.h>`
- `<sys/stat.h>`
- `<fcntl.h>`
- `<unistd.h>`

## Files and folders
- **`monty.h`** : Header File
- **`main.c`** : Coordinates the execution of opcodes using our interpreter for Monty ByteCodes files
- **`openfile.c`** : Opens the file passed like argument in ./monty execution
- **`set_strtok.c`** : Tokenizes a string based in a specific delimiter
- **`get_opcode.c.h`** : Gets the correct opcode function
- **`functions.c`** : Contains the opcodes functions: 
	- *_pall*: Prints all the values on the stack from the top of the stack
	- *_pint*: Prints the value at the top of the stack
	- *_pop*: Removes the top element of the stack
	- *_push*: Pushes an element to the stack
	- *verify_digit*: Verifies if a string is or not a number
- **`functions2.c`** : Contains the opcodes functions:
	- *_swap*: Swaps the top two elements of the stack
	- *_add*: Adds the top two elements of the stack
	- *_nop*: Does not do anything
- **`free_grid.c`** : Frees a 2 dimensional grid
- **`free_dlist.c`** : Frees a stack_t double linked list

- **`tests FOLDER`** : Contais many .m files used to test the performance of our code

## Usage example
Clone this repository:

    git clone https://github.com/mattowsh/holbertonschool-monty.git

Compile the files in the following way:

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty

You can use the interpreter by typing:

	./monty your_montybyte_code.m


![usage_example](https://user-images.githubusercontent.com/103126719/185729230-225fa299-250f-4ea3-b60f-f99296f88f5c.png)


## Authors
[Santiago "Toti" Fernández](https://www.linkedin.com/in/santiago-fern%C3%A1ndez-801641230/)  
[Belén Matto](https://www.linkedin.com/in/mattobelen/) 

Montevideo, Uruguay.
