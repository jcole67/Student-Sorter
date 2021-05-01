# Student-Sorter

Define a structure called Class with name (string), units (int) and grade (char) as its member data.

Define a structure called Student with ID (int), name (string), num (int), gpa (double) and an array of maximum of 20 Class structures called classes, where ID is a 5 digit number, name is the student's full name, num is the number of classes taken so far and gpa is the current grade point average and classes is all the classes taken so far.

Write a function called get_info which takes an array of Student structures called students and array size, reads all the information for as many students as the user wants to enter except for the gpa which is later calculated, storing them in students array.  It then returns the number of students entered by the user before quitting. The user indicates the end of data entry by entering -99 for the ID of a student. The user must enter as many classes for each student as indicated by num - number of classes.

Write a function called display which takes an array of Student structures called students and array size and displays the information for all the students of the array.

Write a function called get_gpa that takes the array of Class structures belonging to a single student and the size of the array of classes and returns the GPA for those classes. GPA is calculated by multiplying the number of units for each class by the number of points earned for the class, adding up all these units*points products and dividing the resulting sum by the total number of units of all classes. The points earned is given by the letter grade earned for each class. A is worth 4 points, B 3 points, C 2 points, D 1 point and F 0 points. For example, if a student has taken 3 classes with units of 3, 5 and 4 and grades of A, C and B, respectively, the GPA is given by:  (3 x 4 + 5 x 2 + 4 x 3) / (3 + 5 + 4) which is 2.8.

Write a sort_id function that takes an array of Student structures and array size and sorts the array in ascending order based on the student id. Write a sort_name function  that takes an array of Student structures and array size and sorts the array in ascending order based on the student name. Write a sort_gpa function  that takes an array of Student structures and array size and sorts the array in ascending order based on gpa.

Write a search_id function that takes students sorted on id, its size and an id and performs a binary search on the students to find the specified id. The function must return the index of the student if found or -1 if not found.  

Write a search_name function that takes students sorted on name, its size and a name and performs a binary search on the students to find the specified name. The function must return the index of the student if found or -1 if not found. 

In main, declare an array of maximum of 100 Student structures.  Pass the array and its maximum size to get_info to read as many students as the user wants storing the information entered in the array passed as parameter. The function must set gpa to 0.0.

Then, pass the array of Class structures (classes) of each student to get_gpa function and store the returned gpa in gpa field of the student overwriting the 0.0. For example, if students[0] has taken 3 classes with units of 3, 5 and 4 and grades of A, C and B, respectively, get_gpa should return a gpa of 2.8 which main must store in the gpa field of the student in question.

Then, pass the array of students and the size returned by get_info to display to print all students entered.

Pass the array of Student structures and the actual size returned by get_info to sort_id function to sort the array based on id  Then, print the sorted students using the display function.

Ask the user to enter an id and pass it along with students array and array size  to the search_id function. Print the information of the student found or print "Student not found" in main.

Pass the array of Student structures and the actual size returned by get_info to sort_name function to sort the array based on name. Again, display the sorted list of students using display. 

Ask the user to enter a name and pass it along with students array and array size  to the search_name function. Print the information of the student found or print "Student not found" in main.

Finally, pass  the array of Student structures and the actual size returned by get_info to sort_gpa function to sort the array based on gpa. Then, print the sorted list of students using the display function.

Upload and submit only the cpp file.  Submitting only the exe file will not earn you any points.  If you cannot build due to errors, submit only the cpp file.

The following is a sample execution of the program:

Enter student ID: 34567

Enter student name:  Robert Hall

Enter number of classes taken by Robert:  3

Enter name of class 1: CS 101

Enter units for CS 101: 3

Enter letter grade received for CS 101: C

Enter name of class 2: CS 102

Enter units for CS 102: 3

Enter letter grade received for CS 102: B

Enter name of class 3: CS 117

Enter units for CS 117: 3

Enter letter grade received for CS 117: A

Enter student ID: 12345

Enter student name:  Susan Ball

Enter number of classes taken by Susan:  2

Enter name of class 1: CS 101

Enter units for CS 101: 3

Enter letter grade received for CS 101: A

Enter name of class 2: CS 104

Enter units for CS 104: 3

Enter letter grade received for CS 104: B

Enter student ID: 23456

Enter student name:  Kim Yong

Enter number of classes taken by Kim:  2

Enter name of class 1: Math 101

Enter units for Math 101: 4

Enter letter grade received for Math 101: C

Enter name of class 2: Math 102

Enter units for Math 102: 3

Enter letter grade received for Math 102: B

Enter student ID: -99
 
List of students entered:
 
Student: 34567  Robert Hall
CS 101, 3 units, Grade C
CS 102, 3 units, Grade B
CS 117, 3 units, Grade A
GPA: 3.0
 
Student: 12345 Susan Hall
CS 101, 3 units, Grade A
CS 104, 3 units, Grade B
GPA: 3.6
 
Student: 23456 Kim Yong
Math 101, 4 units, Grade C
Math 102, 3 units, Grade B
GPA: 2.1
 
List of students sorted on ID:
 
Student: 12345 Susan Hall
CS 101, 3 units, Grade A
CS 104, 3 units, Grade B
GPA: 3.6
 
Student: 23456 Kim Yong
Math 101, 4 units, Grade C
Math 102, 3 units, Grade B
GPA: 2.1
 
Student: 34567  Robert Hall
CS 101, 3 units, Grade C
CS 102, 3 units, Grade B
CS 117, 3 units, Grade A
GPA: 3.0
 
Enter an ID to search for:  23456
Student: 23456 Kim Yong
Math 101, 4 units, Grade C
Math 102, 3 units, Grade B
GPA: 2.1
 
List of students sorted on name:
 
Student: 23456 Kim Yong
Math 101, 4 units, Grade C
Math 102, 3 units, Grade B
GPA: 2.1
 
Student: 34567  Robert Hall
CS 101, 3 units, Grade C
CS 102, 3 units, Grade B
CS 117, 3 units, Grade A
GPA: 3.0
 
Student: 12345 Susan Hall
CS 101, 3 units, Grade A
CS 104, 3 units, Grade B
GPA: 3.6
 
Enter a name to search for:  Robert Hall
Student: 34567  Robert Hall
CS 101, 3 units, Grade C
CS 102, 3 units, Grade B
CS 117, 3 units, Grade A
GPA: 3.0
 
List of students sorted by GPA:
 
Student: 12345 Susan Hall
CS 101, 3 units, Grade A
CS 104, 3 units, Grade B
GPA: 3.6
 
Student: 34567  Robert Hall
CS 101, 3 units, Grade C
CS 102, 3 units, Grade B
CS 117, 3 units, Grade A
GPA: 3.0
 
Student: 23456 Kim Yong
Math 101, 4 units, Grade C
Math 102, 3 units, Grade B
GPA: 2.1
 
Press any key to continue.

