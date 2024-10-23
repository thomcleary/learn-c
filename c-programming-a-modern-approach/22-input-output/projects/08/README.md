# Project 8

Modify the `inventory.c` program of Section 16.3 by adding two new operations:

- Save the database in a specified file.
- Load the database from a specified file.

Use the codes `d` (dump) and `r` (restore), respectively, to represent these operations. The interaction with the user should have the following appearance:

```shell
Enter operation code: d
Enter name of output file: inventory.dat

Enter operation code: r
Enter name of input file: inventory.data
```

_Hint:_ Use `fwrite` to write the array containing the parts to a binary file. Use `fread` to restore the array by reading it from a file.
