# Student Record System (C)

This was my project for practising file handling and structures in C. It stores student records in a text file, so data is not lost when the program closes.

## What it does
- Add a student (roll no, name, course, marks)
- Display all students
- Search a student by roll number
- Delete a student — this was the tricky part, I used a temp file for it

## Concepts I used
- Structures (`struct Student`)
- File handling — `fopen`, `fprintf`, `fscanf`, append and read modes
- Deleting a record using a temporary file, then renaming it
- Menu driven program using functions for each operation

## How to run
```
gcc student_records.c -o student_records
./student_records
```
On Windows, run `student_records.exe` after compiling.

## What I want to add later
- Update marks of an existing student
- Sort students by marks
