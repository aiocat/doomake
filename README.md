# Doomake

Simple <50 line Makefile (like) clone written in C.

## Limitations

- Line length must be less than 1024 byte (1kb)
- You must leave a empty newline at end of the file
  - I suggest add a newline and character after empty newline (check `Doomake` file if you confused)

## Features

- It works
- Flexible command names (almost everything is allowed)
- Bloat-free and fast
- C99 Compatible

## Compile

Make sure you installed a C compiler (like gcc, clang, tcc etc...)

- Run `gcc doomake.c -o doomake` (gcc example)
- Add `doomake` executable to the PATH

## Usage

Example `Doomake` file:

```sh
compile:
gcc main.c -o main

run:
gcc main.c -o main
.\main.exe

command with spaces:
color a
echo Hello There!

```

Run command with `doomake <command>`:

- `doomake compile`
- `doomake run`
- `doomake "command with spaces"`
