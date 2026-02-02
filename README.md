# C++ Projects from School 42

This repository contains my C++ projects from school 42.

Each project directory ('C00', 'C01', ...) includes:
- Source code
- 'subject.pdf' - the project instruction from the 42
- A Makefile to compile the project

## Usage
Build a single project

```bash
make -C C00
```

Build all projects:
```bash
make
```

Clean a project:
```bash
make -C C00 clean
```

Clean all projects:
```bash
make fclean
```