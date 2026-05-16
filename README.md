[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/2E2RzXXN)
# CS4050 Lab 4: DYNAMIC PROGRAMMING FOR “BAD SCANTRON”,  SIGNAL SYCHRONIZATION

![GitHub Latest Pre-Release)](https://img.shields.io/github/v/release/angrynarwhal/4050-Lab-4?include_prereleases&label=pre-release&logo=github)  

**On this lab, if you use an AI to contribute to your solution, you must paste a link to all of your prompts, which are usually in one session as you ask clarifying questions of the "AI" (which is really just a pattern recognition engine).** We note that we *can* tell when AI's are used, and we are confident that AI use has been extensive to this point. There are reflection questions at the end of this assignment regarding AI use that you must also answer if you used an AI to assist you with the assignment. 
 
Place all of your submission documents in the [./lab4_submission](lab4_submission) folder. You will submit a your GitHub URL.
---------------------
## Overview
In this assignment, we are imagining that some CMP_SC 1050 students took a 40 question “Scantron” exam.  Some of them answered all of the questions, and some of them left a few questions blank.  Unfortunately, Mizzou used a new buggy version of the Scantron software to read the answers from the exams, and then promptly lost the original paper answer sheets.  The Scantron software correctly read the answers and recorded them.  However, it did not leave a space or a mark to show that a particular question was omitted by a student.  This isn’t really a problem for grading students who answered all of the questions.  The problem is that we don’t really know WHICH question(s) a student omitted and for WHICH questions(s) a student marked an answer.

Luckily, we have a way to solve this problem in CMP_SC 4050:  Dynamic Programming!  Your job is to grade the Scantron strings against a 40-question key.  Since some of the response strings from “Bad Scantron” will have less than 40 responses in them, you will need to use a Dynamic Programming algorithm to line up the student responses with the responses in the key.  Note that you will want to do this in a way that is as “student-friendly” as possible, as students will undoubtedly complain if they receive less points than they could from your alignment.

## Learning Objectives ##

1. Alignment problems under uncertainty

2. Optimization over multiple candidate solutions

3. Mapping real-world noise to algorithms

4. Time complexity tradeoffs

5. Careful index reasoning

## Signal synchronization ##
## Topic: Signal Matching Using Shifts ##

Exercise 1: Problem Statement**
A reference signal (the key) is transmitted correctly from a transmitting device  using the values below:

**Key Signal:
5 2 3 2 2 1 4**

A receiver records a shorter signal (the exam), but the recording starts late due to synchronization error:

**Recorded Signal:
3 2 2 1**

Because of timing error, the recorded signal may be shifted left or right relative to the key.
                        
  ## Exercise 1 ##
 Question  1.
1.	Slide (shift) the recorded signal across the key. Hint key does not move, provide all detailed work for these shift including tables, snap shots etc
```
a.	-2 
b.	-1
c.	0
d.	+1

```

2.	For each alignment (shift), count how many values match.
3.	Determine:
``` 
  o	the score at each shift
  o	the best alignment
  o	the maximum score
```

## Exercise 2 :
1.	Explain why testing all offsets (shifts) guarantees the optimal score.
2.	What does Shift Left mean in signal alignment?
3.	What does No Shift mean?
4.	What does Shift Right mean?
5.	Where else is this algorithm used?   provide a real word scenario. 


## HOW TO GET STARTED ON EXCERSICE 3 ##
To get started you should:

git clone https://github.com/JimRies1966/cs4050fs2024a4.git
In this repo you will find a main.C, grade.h, you are to create  a grade.C function code that TA will complie using the make function.
You are welcome to work on your code on any platform you like, but remember that the TAs will grade this on Hellbender.  If your code does not compile, segfaults, or otherwise fails to run on Hellbender, you will get a zero.  
Once you have the starter code in a directory, just type “make”.  This will build the code and leave you with an executable file called “grade”.  Just type **./grade** to execute.  You will want to implement the function grade() in grade.c to make things work correctly.

## SAMPLE OUTPUT #1 – BEFORE IMPLEMENTING

```
jimr@JimRBeastCanyon:~/CS4050/FS2024/assignments/cs4050fs2024a4$ make
Compiling main.c
Compiling grade.c
Linking grade
jimr@JimRBeastCanyon:~/CS4050/FS2024/assignments/cs4050fs2024a4$ ./grade
The key scored 0 out 40 against itself.
Exam #0 scored 0 out of 40.
Exam #1 scored 0 out of 40.
Exam #2 scored 0 out of 40.
Exam #3 scored 0 out of 40.
Exam #4 scored 0 out of 40.
Exam #5 scored 0 out of 40.

```


## SAMPLE OUTPUT #2 – AFTER IMPLEMENTING
```

jimr@JimRBeastCanyon:~/CS4050/FS2024/assignments/A4$ make
Compiling main.c
Compiling grade.c
Linking grade
jimr@JimRBeastCanyon:~/CS4050/FS2024/assignments/A4$ ./grade
The key scored 40 out 40 against itself.
Exam #0 scored 20 out of 40.
Exam #1 scored 22 out of 40.
Exam #2 scored 16 out of 40.
Exam #3 scored 30 out of 40.
Exam #4 scored 18 out of 40.
Exam #5 scored 22 out of 40.

```

## Exercise 3 Questions ##
1. submit grade.C 
2. What does the key signal represent in the grading system?
3. What does the exam signal represent?
4. Why might the exam signal be shorter than the key signal?
5. Why must the grading program test multiple shifts?
6. Why must the program check array bounds when comparing signals?
7. Write pseudocode for computing the best alignment score


## submit all deliverables inside a zip folder including tables and snapshot to respective questions in a pdf format

# If you used AI, also include answers to these questions in a separate markdown document: 
1. How and to what extent do you think using AI allowed you to complete the assignment more quickly?
2. What effects on your learning and understanding of the topic in this lab did AI have? Do you think you learned more? Less? Due to AI use?
3. Describe a lab design that would help to ensure you fully understand the material, while also allowing AI use. 
