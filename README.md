# libft-pain
libft tester, not the fanciest one but has some useful features

Currently does not test the bonus functions!

### Features

- Multiple tests for every function, making sure they behave as expected.
- Shows usefull errors: (errors with pointers usally are return values)
```
_bin/test_ft_isascii.out:
		ERROR on byte 180: expected: <1> got: <0>
	ERROR on <0>: 1 bytes different
_bin/test_ft_memcpy.out:
  ERROR on <0>: expected: <0x7ffc20fd3da0> got: <0x7ffc20fd3da1>
```
- Tests rigerously for correct handling of failed allocation and memory leaks
- Checks for wrongly used "" / <>
```
wrongly used "" / <>:
../libft/ft_split.c:#include <libft.h> //ft_strchr
```
- Finds non static functions
```
files with non static functions:
		2 ft_split.o
```
- Directly links against the library (requires working makefile)
- Finds missing const in function declarations

### Usage

Add the correct path at the top of pain.sh and run it


## Leaks on ft_split

A lot of people have a hard time figuring out why/where the ft_split is leaking so here the solution:

```
Malloc array of pointers to strings

If array == Null  // Allocation failed
	return NULL;
	
while (splits left) 
{
	Malloc string
	If (string == null)  // Allocation failed
	{ 
		free ALL previously allocated strings
		free array
		return NULL
	}
	Fill string
}
return array
```
