// grid dummy data

function mouseenter(flip)
{
    // var status = document.getElementById(flip);
  //  var number = flip.charAt(4);
   // alert(number)
 //   var divID = "#flip";
 //   var divID = divID.concat(number);
    document.getElementById(flip).style.backgroundColor = "#595a5f";
  //  $(divID).css("background-color", "#8182e0"); //lighter #33353e
}

function mouseleave(flip)
{
    /*    var status = $(this).attr('id');
        var number = status.charAt(4);
        var divID = "#flip";
        var divID = divID.concat(number);
        $(divID).css("background-color", "#2a2b30"); //darker #2a2b30*/

    document.getElementById(flip).style.backgroundColor = "#2a2b30";
}

function cclick(f)
{
    //alert("HELLO");
	var number = "";
    // var status = $(this).attr('id');
	if (f.charAt(5) == "")
	{
		number = f.charAt(4).toString();
	}
		
	else if (f.charAt(4) == "1")
		number = "1" + f.charAt(5).toString();
    else if (f.charAt(4) == "2")
		number = "2" + f.charAt(5).toString();
    else
       number = "3" + f.charAt(5).toString();
	//alert(f.charAt(5));
	//alert(number);
		//number = number + charAt(4);
    var flip = "#panel";

    var flipper = flip.concat(number);
    $(flipper).slideToggle("slow");
}

var OOPData = {
	"Dr. Umair Azfar Khan":"<div class=\"jumbotron\"><div class=\"row\" style=\"width:600px;\"><br><div class=\"col-sm-3\"><img src=\"img/umair_pic.jpg\" class=\"img-rounded\" alt=\"Umair Photo\" style=\"width:190px;height:220px;\"></div><div class=\"col-sm-9\"><h2>Dr. Umair Azfar Khan</h2><p>Assistant Professor<br>Department of Computer Science<br>School of Science &amp Engineering</p></div></div></div><div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br><div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Course Brief</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>The course has been created to teach Object Oriented Programming Methodology and Design using C++. The course ensures that the students go through a strict programming regimen through regular assignements and flipped classroom activities. The course requires the students to put in hours of hardwork and practice to ensure that they learn software designing and translating it into meaningful code.</p></div></div><div class=\"row\"><br>\<div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Office hours</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Monday 1000 - 1100 <br> Wednesday 1000 - 1100</p></div></div><div class=\"row\"><br><div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Contact</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Room: C - 121 (Faculty Pod East)<br>E-mail: umair.azfar@sse.habib.edu.pk</p></div></div> </div><br>",
	"Dr. Taj Muhammad Khan":"<div class=\"jumbotron\"><div class=\"row\"><br><div class=\"col-sm-3\"><img src=\"img/Muhammad-Taj-Khan.jpg\" class=\"img-rounded\" alt=\"Taj Photo\" style=\"width:190px;height:220px;\"></div><div class=\"col-sm-9\"><h2>Dr. Muhammad Taj Khan</h2><p>Assistant Professor<br>Department of Computer Science<br>School of Science &amp Engineering</p></div></div></div><div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br><div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Profile</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Dr. Taj believes Habib University has taken a right step in the right direction by providing a platform for the students where they can choose a mixture of courses which suits their natural inclinations. This, he believes, will produce competent and responsible citizens who will help take the nation forward.\n"+"\n"+"His interests revolve around Computer Architecture, Compiler Optimizations and Natural Languages.</p></div></div><div class=\"row\"><br>\<div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Office hours</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Mondays 1430 - 1530<br>Wednesday 0955 – 1055</p></div></div><div class=\"row\"><br><div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Contact</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Room C-217 (Faculty Pod Center)<br>E-mail: taj.khan@sse.habib.edu.pk</p></div></div> </div><br>",
    "Ms. Asma Larik":"<div class=\"jumbotron\"><div class=\"row\"><br><div class=\"col-sm-3\"><img src=\"img/Unknown.jpg\" class=\"img-rounded\" alt=\"Asma Photo\" style=\"width:190px;height:220px;\"></div><div class=\"col-sm-9\"><h2>Ms. Asma Larik</h2><p>Lecturer<br>Department of Computer Science<br>School of Science &amp Engineering</p></div></div></div><div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br><div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Profile</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Asma Sanam Larik is a researcher and  a teacher with a teaching experience of around ten years. She did her Bachelors as well as Masters in Computer Science from National University FAST Karachi. Currently she is pursuing doctoral degree in computer science from Institute of Business Administration (IBA).\n"+"\n"+"Teaching undergraduate student is her passion and she has taught a number of courses including Object Oriented Programming, Data structures, Theory of automata, Compilers, Introduction to Programming, Artificial Intelligence etc . Her areas of interest include Artificial Intelligence, Robotics, Datamining and Computational Intelligence. She has several international publications and participated in many national and international conferences.</p></div></div><div class=\"row\"><br>\<div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Office hours</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Mondays 1000 - 1100<br>Wednesday 1000 – 1100</p></div></div><div class=\"row\"><br><div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Contact</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Room E-110 (Faculty Pod Center)<br>E-mail: asma.larik@sse.habib.edu.pk</p></div></div> </div><br>",
    "Aisha Batool":"<div class=\"jumbotron\"><div class=\"row\"><br><div class=\"col-sm-3\"><img src=\"img/aisha_pic.jpg\" class=\"img-rounded\" alt=\"Aisha Photo\" style=\"width:190px;height:220px;\"></div><div class=\"col-sm-9\"><h2>Aisha Batool</h2><p>Research Assistant<br>Department of Computer Science<br>School of Science &amp Engineering</p></div></div></div><div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br><div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Profile</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Aisha hold a BS in Computer Science from FAST - National University of Computer and Emerging Sciences. She is an undergraduate research assistant in the Computer Science Department at Habib University under the supervision of Dr. Waqar Saleem. She has previously served as an Instructor/Research Fellow at FAST-NUCES for five months. She has a one year software industry experience at ZAAVIA where she worked on Health Care Solutions especially Blood Bank Management System using latest technologies: NodeJS and MongoDB. Her research interests includes Cloud Computing, Human Computer Interaction, among others. She loves exploring & working on latest technologies.</p></div></div><div class=\"row\"><br>\<div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Office hours</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Mondays 1300 - 1400<br>Tuesdays 1300 - 1400<br>Wednesdays 1300 - 1400<br>Thursdays 1300 - 1400</p></div></div><div class=\"row\"><br><div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Contact</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Room N-200 (Faculty Pod North)<br>E-mail: aisha.batool@sse.habib.edu.pk</p></div></div> </div><br>",
    "Ata ur Rehman":"<div class=\"jumbotron\"><div class=\"row\"><br><div class=\"col-sm-3\"><img src=\"img/Ata.jpg\" class=\"img-rounded\" alt=\"Aisha Photo\" style=\"width:190px;height:220px;\"></div><div class=\"col-sm-9\"><h2>Muhammad Ata Ur Rehman</h2><p>Research Assistant<br>Department of Computer Science<br>School of Science &amp Engineering</p></div></div></div><div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br><div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Course Brief</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>The course has been created to teach Object Oriented Programming and Design Methodology using C++. The course ensures that the students go through a strict programming regimen through regular assignments and flipped classroom activities. The course requires the students to put in hours of hard work and practice to ensure that they learn software designing and translating it into meaningful code. As the course ends up with the expectation from the student to come up with a full flashed software (A game for this course) incorporating their object oriented designing and programming skills which ensures their capabilities as ‘the’ objective of this course.</p></div></div><div class=\"row\"><br>\<div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Office hours</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Mondays 1430 - 1600<br>Wednesdays 1430 - 1600<br>Fridays 1000 - 1200</p></div></div><div class=\"row\"><br><div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Contact</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Office W-221-02 (Faculty Pod West)<br>E-mail: ata.rehman@sse.habib.edu.pk</p></div></div> </div><br>",
    "Nadia Nasir":"<div class=\"jumbotron\"><div class=\"row\"><br><div class=\"col-sm-3\"><img src=\"img/Unknown.jpg\" class=\"img-rounded\" alt=\"Nadia Photo\" style=\"width:190px;height:220px;\"></div><div class=\"col-sm-9\"><h2>Nadia Nasir</h2><p>Research Assistant<br>Department of Computer Science<br>School of Science &amp Engineering</p></div></div></div><div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br><div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Profile</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Nadia holds a MS Degree in Computer Science from NED University of Engineering and Technology. She is an undergraduate research assistant in the Computer Science Department at Habib University under the supervision of Dr. Waqar Saleem. She has previously served as an Instructor/Research Fellow at FAST-NUCES for 2.5 years. Her research interests includes Computer Vision and AI. She loves exploring & working on latest technologies.</p></div></div><div class=\"row\"><br>\<div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Office hours</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Tuesdays 1100 - 0100<br>Wednesdays 1000 - 1100<br>Fridays 1200 - 0100<br>Thursdays 1300 - 1400</p></div></div><div class=\"row\"><br><div class=\"col-sm-3\" id=\"courseBriefLeft\"><p>Contact</p></div><div class=\"col-sm-9\" id=\"courseBriefRight\"><p>Office W-221-02 (Faculty Pod West)<br>E-mail: nadia.nasir@sse.habib.edu.pk</p></div></div> </div><br>",
    "Ehsas TAs":"<div class=\"jumbotron\"><div class=\"row\"><br><div class=\"col\"><h2>Ehsas TAs</h2></div><div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br><div class=\"col\" id=\"courseBriefRight\">Office Hours of Ehsas TA can be found on this link: <a href='https://docs.google.com/spreadsheets/d/1Jnc7vlqhmenmKUIDvQ3VhO_JaoHGzLGSy52TiJejC50/edit?usp=sharing' target='_blank'>Ehsas TAs Office Hours</a></div></div><br>",
    "Objectives/Description":"<div class=\"jumbotron\"><div class=\"row\"><br><div class=\"col\"><h2>Objectives/Description</h2></div><div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br><div class=\"col\" id=\"courseBriefRight\"><ul style=\"list-style-type:square\"><li>Motivation for using C/C++ as opposed to other languages like Java, C# and Python.</li><li>The logistics of memory manipulation in C++ (pointers, structs).</li><li>Basic introduction of Objects and how they can help in defining new programming methodologies.</li><li>We will start from defining a simple linked list and slowly make it more complex. We'll show double linked-list insert in place, inserting into a linked list using a double pointer, corner cases of using memory (when we actually need heap allocation), etc.</li><li>Data encapsulation: classes, namespaces, constructors and destructors; virtual functions and destructors; operator overloading and standard input/output.</li><li>Inheritance and polymorphism; templates; standard library containers.</li><li>We will use these topics in creating a working game to give a visual feel of all the programming techniques that we will study in class. Designing will be a major part of the entire activity; hence we will learn UML 2.0 and learn to design our software.</li></ul></div></div><br>",
    "Learning Outcomes":"<div class=\"jumbotron\"><div class=\"row\"><br><div class=\"col\"><h2>Learning Outcomes</h2></div><div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br><div class=\"col\" id=\"courseBriefRight\"><ul style=\"list-style-type:square\"><li>Understand the concept of Object Oriented Programming and apply that into creating their own games and other applications.</li><li>Students will go through rigorous programming assignments and a final semester project to understand how the different modules come together in creating a complete project.</li><li>Usage of header and source files will be learned in order to learn the proper usage of IDEs.</li><li>UML 2.0 will be used in designing the individual projects so that the students put into practice the designs that they have created in a working game.</li></ul></div></div><br>",
	"Requirements/Resources":"<div class=\"jumbotron\"><div class=\"row\"><br><div class=\"col\"><h2>Requirements</h2></div><div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br><div class=\"col\" id=\"courseBriefRight\"><ul style=\"list-style-type:square\"><li>Required text: Bruce Eckel’s <b><a href=\"http://iacs-courses.seas.harvard.edu/courses/cs207/resources/TIC2Vone.pdf\" target='_blank'>Thinking in C++ 2nd Edition</a></b></li><li>Any IDE including <b><a href=\"http://www.codeblocks.org/home\" target='_blank'>Code::Blocks with MinGW</a></b>, <b><a href=\"http://www.bloodshed.net/devcpp.html\" target='_blank'>Dev C++</a></b>, <b><a href=\"https://developer.apple.com/xcode\" target='_blank'>XCode</a></b> or <b><a href=\"https://www.visualstudio.com\" target='_blank'>Visual Studio 2015</a></b>.</li><li>Low level multimedia access library, <b><a href=\"https://www.libsdl.org\" target='_blank'>Simple DirectMedia Layer (SDL 2.0)</a></b>.</li><li>More reading material will be provided through LMS.</li></ul></div></div><br><h2>Resources</h2></div><div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br><div class=\"col\" id=\"courseBriefRight\"><ul style=\"list-style-type:square\"><li>The PDF of the syllabus can be acquired <b><a href=\"resources/CS-224_Syllabus.pdf\" target='_blank'>here</a></b></li><li>The tutorial for SVN instructions for windows can be acquired <b><a href=\"resources/SVN_Instructions_For_Windows.pdf\" target='_blank'>here</a></b></li><li>The tutorial for SVN instructions for Mac OSX can be acquired <b><a href=\"resources/SVN_Instructions_For_MAC_OSX.pdf\" target='_blank'>here</a></b></li><li>The Design Patterns tutorial <b><a href=\"resources/design_pattern_tutorial.pdf\" target='_blank'>document</a></b></li><li>The UML Notation <b>" +
"<a href=\"resources/UMLNotationSummary.pdf\" target='_blank'>summary</a></b></li>" +
"<li>For learning SDL 2.0, we will be taking help from <b><a href=\"http://lazyfoo.net/tutorials/SDL/\" target='_blank'>Lazy Foo's Tutorials</a></b></li>" +
"<li>Part 1 of Setting up SDL 2 on Mac OS X Yosemite can be acquired <b><a href=\"resources/1- Setting up SDL 2 on Mac OS X Yosemite.pdf\" target='_blank'>here.</a></b></li>" +
"<li>Part 2 of Setting up SDL 2 on Mac OS X Yosemite can be acquired <b><a href=\"resources/2- Setting up SDL 2 on XCode.pdf\" target='_blank'>here</a></b></li></li>" +
"<li>Part 3 of Setting up SDL 2 on Mac OS X Yosemite can be acquired <b><a href=\"resources/3- Getting an Image on the Screen.pdf\" target='_blank'>here</a></b></li>" +
"<li>UML creation software <b><a href=\"http://www.umlet.com/umlet_14_2/umlet-standalone-14.2.zip\" target='_blank'>UMLet</a></b></li>" +
"</ul></div></div><br>"	,
    "Grading Procedures":"<div class=\"jumbotron\"><div class=\"row\"><br><div class=\"col\"><h2>Grading Procedures</h2></div><div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br><div class=\"col\" id=\"courseBriefRight\"><ul style=\"list-style-type:square\"><li>Students will be given an assignment every other week that they need to submit by 11:59 pm on the day before next assignment. </li><li>A total of 6 assignments will be given where the weightage of each assignment will be 3% (Rubric will be given to help in evaluating the assignments).\n</li><li>There are going to be no quizzes or exams but that means that strong emphasis will be given to written code, logic and design.</li><li>Students will create group projects and they will need to show periodic advancement to verify their progress and to ask questions if they are stuck. These periodic meetings are mandatory to exhibit that the final project was created by the students.</li><li>The project will be distributed in parts and every part will hold separate marks. A rubric will be provided for the evaluation of each part.\n</li><br><table style=\"width:100%\" id=\"CourseSchedule\"><tr><th>Grade</th><th>Marks</th></tr><tr><td width=\"50%\"><center>A+</center></td><td width=\"50%\"><center>95 - 100</center></td></tr><tr><td width=\"50%\"><center>A</center></td><td width=\"50%\"><center>90 - 94</center></td></tr><tr><td width=\"50%\"><center>A-</center></td><td width=\"50%\"><center>85 - 89</center></td></tr><tr><td width=\"50%\"><center>B+</center></td><td width=\"50%\"><center>80 - 84</center></td></tr><tr><td width=\"50%\"><center>B</center></td><td width=\"50%\"><center>75 - 79</center></td></tr><tr><td width=\"50%\"><center>B-</center></td><td width=\"50%\"><center>70 - 74</center></td></tr><tr><td width=\"50%\"><center>C+</center></td><td width=\"50%\"><center>65 - 69</center></td></tr><tr><td width=\"50%\"><center>C</center></td><td width=\"50%\"><center>60 - 64</center></td></tr><tr><td width=\"50%\"><center>F</center></td><td width=\"50%\"><center>0 - 59</center></td></tr></table><br>" +
	"" +
	"" +
	"<table style=\"width:100%\"><tr><th>Mid Terms (30%)</th><th>Assignments (18%)</th><th>Final Project (52%)</th></tr><tr><td width=\"30%\">2 Mid Terms (In Week 5 and Week 11)</td><td width=\"30%\">60% score needs to be scored to be eligible to work on the Project.</td><td width=\"30%\">60% score needs to be scored to clear the Project.</td></tr><tr><td width=\"30%\">Insufficient score fails the course.</td><td width=\"30%\">You will not be allowed to continue if your progress is not satisfactory.</td><td width=\"30%\">Insufficient score fails the course Irrespective of whether the assignments were cleared\n</td></tr></table></div></div><br>",
    "Attendance Policy":"<div class=\"jumbotron\"><div class=\"row\"><br><div class=\"col\"><h2>Attendance Policy</h2></div><div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br><div class=\"col\" id=\"courseBriefRight\"><ul style=\"list-style-type:square\"><li>Habib University requires that all first and second year students must maintain at least 85% attendance for each class in which they are registered.</li><li>It is required for final year students that they must maintain at least 75% attendance for each class in which they are registered.</li><li>Non-compliance with minimum attendance requirements will result in automatic failure of the course and may require the student to repeat the course when next offered.</li></ul></div></div><br>",
    "Academic Integrity":"<div class=\"jumbotron\"><div class=\"row\"><br><div class=\"col\"><h2>Academic Integrity</h2></div><div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br><div class=\"col\" id=\"courseBriefRight\"><ul style=\"list-style-type:square\"><li>Each student in this course is expected to abide by the Habib University Student Honor Code of Academic Integrity.</li><li>Any work submitted by a student in this course for academic credit will be the student's own work. Scholastic dishonesty shall be considered a serious violation of these rules and regulations and is subject to strict disciplinary action as prescribed by Habib University regulations and policies.</li><li>Scholastic dishonesty includes, but is not limited to, cheating on exams, plagiarism on assignments, and collusion.</li></div></div><br>",
   /* "Course Schedule":"<div class=\"jumbotron\"><div class=\"row\"><br><div class=\"col\"><h2>Course Schedule</h2></div><div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br><div class=\"col\" id=\"courseBriefRight\"><table style=\"width:100%\" id=\"CourseSchedule\"><tr><th>Weeks</th><th>Topics to cover</th></tr><tr><td width=\"30%\">Week 1</td><td width=\"70%\">Introduction to C++, data types, logical operators, conditionals</td></tr><tr><td width=\"30%\">Week 2</td><td width=\"70%\">Loops, Functions, Function Overloading</td></tr><tr><td width=\"30%\">Week 3</td><td width=\"70%\">Pointers, Structures, Classes and Introduction to UML 2.0</td></tr><tr><td width=\"30%\">Week 4</td><td width=\"70%\">Objects, data encapsulation, pointers to objects</td></tr><tr><td width=\"30%\">Week 5</td><td width=\"70%\">Dynamic object creation and deletion</td></tr><tr><td width=\"30%\">Week 6</td><td width=\"70%\">Simple Stack and Queue Implementation</td></tr><tr><td width=\"30%\">Week 7</td><td width=\"70%\">Inheritance, constructors and destructors</td></tr><tr><td width=\"30%\">Week 8</td><td width=\"70%\">Virtual functions and virtual destructors</td></tr><tr><td width=\"30%\">Week 9</td><td width=\"70%\">Polymorphism, functions overloading and overriding</td></tr><tr><td width=\"30%\">Week 10</td><td width=\"70%\">Double Linked List for storing child objects using a base pointer</td></tr><tr><td width=\"30%\">Week 11</td><td width=\"70%\">Copy Constructor, shallow and deep copying, Friend Classes</td></tr><tr><td width=\"30%\">Week 12</td><td width=\"70%\">Standard Template Library</td></tr><tr><td width=\"30%\">Week 13</td><td width=\"70%\">Design Patterns Part 1</td></tr><tr><td width=\"30%\">Week 14</td><td width=\"70%\">Design Patterns Part 2</td></tr><tr><td width=\"30%\">Week 15</td><td width=\"70%\">Project Display & Evaluation</td></tr></table></div></div><br>",*/

    "Course Schedule / Topics":"<div class=\"jumbotron\">" +
    "<div class=\"row\"><br>" +
    "<div class=\"col\">" +
    "<h2>Course Schedule / Topics</h2>" +
    "</div>" + 
	"<div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br>" +
    "<div class=\"col\" id=\"courseBriefRight\">" +

    //Week 01
	"<div id=\"flip1\" class = \"clickable\" onClick='cclick(\"flip1\")' onmouseenter='mouseenter(\"flip1\")' onmouseleave='mouseleave(\"flip1\")' style='font-weight: bold'>Week 01</div>" +
    "<div id=\"panel1\" >" + 
	"<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Introduction to C++</li>" +
	"<li>Data Types</li>" +
	"<li>Function parameters and return statements</li>" +
	"<li>Function Overloading</li>" +
	"<li>Conditionals</li>" +
	"<li>While, Do-While and For Loops</li>" +
	"</div>" +
	"<div style='text-align: center'>" +
	"<a href=\"resources/Week01/umair.zip\" target='_blank'>" +
	"<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week01/asma.zip\" target='_blank'>" +
    "<img src=\"img/MsAsma.png\" alt=\"Ms. Asma Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
	"</div></div>" +

    //Week # 2
	"<div id=\"flip2\" class = \"clickable\" onClick='cclick(\"flip2\")' onmouseenter='mouseenter(\"flip2\")' onmouseleave='mouseleave(\"flip2\")' style='font-weight: bold'>Week 02</div>" +
    "<div id=\"panel2\" >" + 
	"<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Pointers</li>" + 
	"<li>References</li>" + 
	"<li>Passing by Value</li>" + 
	"<li>Passing by Address</li>" + 
	"<li>Passing by Reference</li>" + 
	"<li>Dynamic Memory Allocation and De-allocation</li>" + 
	"</div>" + 
	"<div style='text-align: center'>" +
    "<a href=\"resources/Week02/umair.zip\" target='_blank'>" +
    "<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week02/taj.zip\" target='_blank'>" +
    "<img src=\"img/DrTaj.png\" alt=\"Dr. Taj Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week02/asma.zip\" target='_blank'>" +
    "<img src=\"img/MsAsma.png\" alt=\"Ms. Asma Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "</div></div>" +

        //Week # 3
	"<div id=\"flip3\" class = \"clickable\" onClick='cclick(\"flip3\")' onmouseenter='mouseenter(\"flip3\")' onmouseleave='mouseleave(\"flip3\")' style='font-weight: bold'>Week 03</div>" +
    "<div id=\"panel3\" >" + 
	"<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Arrays</li>" + 
	"<li>Dynamic Arrays</li>" + 
	"<li>Passing Arrays</li>" + 
	"<li>Structures</li>" + 
	"<li>Array of Structure</li>" + 
	"</div>" + 
	"<div style='text-align: center'>" +
    "<a href=\"resources/Week03/umair.zip\" target='_blank'>" +
    "<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week03/asma.zip\" target='_blank'>" +
    "<img src=\"img/MsAsma.png\" alt=\"Ms. Asma Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "</div></div>" +

        //Week # 4
	"<div id=\"flip4\" class = \"clickable\" onClick='cclick(\"flip4\")' onmouseenter='mouseenter(\"flip4\")' onmouseleave='mouseleave(\"flip4\")' style='font-weight: bold'>Week 04</div>" +
    "<div id=\"panel4\" >" + 
	"<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Constructor</li>" + 
	"<li>Destructor</li>" + 
	"<li>Copy Constructor</li>" + 
	"<li>Pointer to Structure and Class</li>" + 
	"<li>Nested Memory De-allocation</li>" + 
	"</div>" + 
	"<div style='text-align: center'>" +
    "<a href=\"resources/Week04/umair.zip\" target='_blank'>" +
    "<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week04/asma.zip\" target='_blank'>" +
    "<img src=\"img/MsAsma.png\" alt=\"Ms. Asma Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\" ></a>" +
    "</div></div>" +

	//Week # 5
	"<div id=\"flip5\" class = \"clickable\" onClick='cclick(\"flip5\")' onmouseenter='mouseenter(\"flip5\")' onmouseleave='mouseleave(\"flip5\")' style='font-weight: bold'>Week 05</div>" +
    "<div id=\"panel5\" >" + 
	"<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Linked List Introduction</li>" + 
	"<li>Stack Implementation</li>" + 
	"<li>Inheritance</li>" + 
	"<li>Base and Child classes and their constructors</li>" + 
	"</div>" + 
	"<div style='text-align: center'>" +
    "<a href=\"resources/Week05/umair.zip\" target='_blank'>" +
    "<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week05/asma.zip\" target='_blank'>" +
    "<img src=\"img/MsAsma.png\" alt=\"Ms. Asma Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "</div></div>" +

        //Week # 6
	"<div id=\"flip6\" class = \"clickable\" onClick='cclick(\"flip6\")' onmouseenter='mouseenter(\"flip6\")' onmouseleave='mouseleave(\"flip6\")' style='font-weight: bold'>Week 06</div>" +
    "<div id=\"panel6\" >" + 
	"<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Queue Implementation</li>" + 
	"<li>Double Linked List</li>" +
	"<li>Circular Linked List</li>" +
	"<li>Base and Child class pointers usage</li>" + 
	"</div>" + 
	"<div style='text-align: center'>" +
    "<a href=\"resources/Week06/umair.zip\" target='_blank'>" +
    "<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week06/taj.zip\" target='_blank'>" +
    "<img src=\"img/DrTaj.png\" alt=\"Dr. Taj Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week06/asma.zip\" target='_blank'>" +
    "<img src=\"img/MsAsma.png\" alt=\"Ms. Asma Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "</div></div>" +

        //Week # 7
	"<div id=\"flip7\" class = \"clickable\" onClick='cclick(\"flip7\")' onmouseenter='mouseenter(\"flip7\")' onmouseleave='mouseleave(\"flip7\")' style='font-weight: bold'>Week 07</div>" +
    "<div id=\"panel7\" >" + 
	"<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Friend Functions</li>" + 
	"<li>Operator Overloading</li>" + 
	"</div>" + 
	"<div style='text-align: center'>" +
    "<a href=\"resources/Week07/umair.zip\" target='_blank'>" +
    "<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week07/taj.zip\" target='_blank'>" +
    "<img src=\"img/DrTaj.png\" alt=\"Dr. Taj Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week07/asma.zip\" target='_blank'>" +
    "<img src=\"img/MsAsma.png\" alt=\"Ms. Asma Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +	"</div></div>" +

        //Week # 8
	"<div id=\"flip8\" class = \"clickable\" onClick='cclick(\"flip8\")' onmouseenter='mouseenter(\"flip8\")' onmouseleave='mouseleave(\"flip8\")' style='font-weight: bold'>Week 08</div>" +
    "<div id=\"panel8\" >" + 
	"<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Friend Functions</li>" + 
	"<li>Friend Classes</li>" + 
	"</div>" + 
	"<div style='text-align: center'>" +
    "<a href=\"resources/Week08/umair.zip\" target='_blank'>" +
    "<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week08/taj.zip\" target='_blank'>" +
    "<img src=\"img/DrTaj.png\" alt=\"Dr. Taj Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week08/asma.zip\" target='_blank'>" +
    "<img src=\"img/MsAsma.png\" alt=\"Ms. Asma Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "</div>" +
    "</div>" +

        //Week # 9
	"<div id=\"flip9\" class = \"clickable\" onClick='cclick(\"flip9\")' onmouseenter='mouseenter(\"flip9\")' onmouseleave='mouseleave(\"flip9\")' style='font-weight: bold'>Week 09</div>" +
    "<div id=\"panel9\" >" + 
	"<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Multiple Inheritance</li>" + 
	"</div>" + 
	"<div style='text-align: center'>" +
    "<a href=\"resources/Week09/umair.zip\" target='_blank'>" +
    "<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week09/asma.zip\" target='_blank'>" +
    "<img src=\"img/MsAsma.png\" alt=\"Ms. Asma Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "</div></div>" +

        //Week # 10
	"<div id=\"flip10\" class = \"clickable\" onClick='cclick(\"flip10\")' onmouseenter='mouseenter(\"flip10\")' onmouseleave='mouseleave(\"flip10\")' style='font-weight: bold'>Week 10</div>" +
    "<div id=\"panel10\" >" + 
	"<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Void Pointer</li>" + 
	"<li>Pointer to Pointer</li>" + 
	"<li>Function Template</li>" + 
	"<li>Class Template</li>" + 
	"</div>" + 
	"<div style='text-align: center'>" +
    "<a href=\"resources/Week10/umair.zip\" target='_blank'>" +
    "<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week10/taj.zip\" target='_blank'>" +
    "<img src=\"img/DrTaj.png\" alt=\"Dr. Taj Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week10/asma.zip\" target='_blank'>" +
    "<img src=\"img/MsAsma.png\" alt=\"Ms. Asma Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "</div></div>" +

        //Week # 11
	"<div id=\"flip11\" class = \"clickable\" onClick='cclick(\"flip11\")' onmouseenter='mouseenter(\"flip11\")' onmouseleave='mouseleave(\"flip11\")' style='font-weight: bold'>Week 11</div>" +
    "<div id=\"panel11\" >" + 
	"<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Priority Queue</li>" + 
	"<li>Standard Template Library</li>" + 
	"</div>" + 
	"<div style='text-align: center'>" +
    "<a href=\"resources/Week11/umair.zip\" target='_blank'>" +
    "<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week11/asma.zip\" target='_blank'>" +
    "<img src=\"img/MsAsma.png\" alt=\"Ms. Asma Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "</div></div>" +

        //Week # 12
	"<div id=\"flip12\" class = \"clickable\" onClick='cclick(\"flip12\")' onmouseenter='mouseenter(\"flip12\")' onmouseleave='mouseleave(\"flip12\")' style='font-weight: bold'>Week 12</div>" +
    "<div id=\"panel12\" >" + 
	"<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Topic 1</li>" + 
	"<li>Topic 2</li>" + 
	"</div>" + 
	"<div style='text-align: center'>" +
    "<a href=\"resources/Week12/umair.zip\" target='_blank'>" +
    "<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week12/asma.zip\" target='_blank'>" +
    "<img src=\"img/MsAsma.png\" alt=\"Ms. Asma Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "</div></div>" +

        //Week # 13
	"<div id=\"flip13\" class = \"clickable\" onClick='cclick(\"flip13\")' onmouseenter='mouseenter(\"flip13\")' onmouseleave='mouseleave(\"flip13\")' style='font-weight: bold'>Week 13</div>" +
    "<div id=\"panel13\" >" + 
	"<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Topic 1</li>" + 
	"<li>Topic 2</li>" + 
	"</div>" + 
	"<div style='text-align: center'>" +
    "<a href=\"resources/Week13/umair.zip\" target='_blank'>" +
    "<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/Week13/asma.zip\" target='_blank'>" +
    "<img src=\"img/MsAsma.png\" alt=\"Ms. Asma Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "</div></div>" +

        //Week 14
	"<div id=\"flip14\" class = \"clickable\" onClick='cclick(\"flip14\")' onmouseenter='mouseenter(\"flip14\")' onmouseleave='mouseleave(\"flip14\")' style='font-weight: bold'>Week 14</div>" +
    "<div id=\"panel14\" >" + 
	"<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Topic 1</li>" + 
	"<li>Topic 2</li>" + 
	"</div>" + 
	"<div style='text-align: center'>" +
    "<a href=\"resources/Week13/umair.zip\" target='_blank'>" +
    "<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Lecture\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "</div></div>" +

/*	"<div id=\"flip15\" class = \"clickable\" onClick='cclick(\"flip15\")' onmouseenter='mouseenter(\"flip15\")' onmouseleave='mouseleave(\"flip15\")' style='font-weight: bold'>Week 15</div>" +
    "<div id=\"panel15\" >" + 
	"<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Topic 1</li>" + 
	"<li>Topic 2</li>" + 
	"</div>" + 
	"<div style='text-align: center'>" + 
	"<a href=\"resources/Week15/Week15.cpp\"><img src=\"img/lecture.png\" alt=\"Lecture Image\" style=\"width:64px;height:64px;\"></a>" + 
	"<a href=\"resources/Week15/Exercise15.txt\"><img src=\"img/exercise.png\" alt=\"Lecture Image\" style=\"width:64px;height:64px;\"></a>" + 
	"<a href=\"resources/Week15/Week15Assignment.zip\"><img src=\"img/assignment.png\" alt=\"Lecture Image\" style=\"width:64px;height:64px;\"></a>" + 
	"</div></div>" +*/
	
	"</ul></div></div><br>",

    /******************************************************************************************************************/

    "Assignments / MidTerms":
    "<div class=\"jumbotron\">" +
    "<div class=\"row\"><br>" +
    "<div class=\"col\">" +
    "<h2>Assignments & MidTerms</h2>" +
    "<h3>Assignments</h3>" +
    "</div>" +
    "<div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br>" +
    "<div class=\"col\" id=\"courseBriefRight\">" +
    "<div id=\"flip1\" class = \"clickable\" onClick='cclick(\"flip1\")' onmouseenter='mouseenter(\"flip1\")' onmouseleave='mouseleave(\"flip1\")' style='font-weight: bold'>Assignment #01</div>" +
    "<div id=\"panel1\" >" +
    "<div style='text-align: center'>" +
    "<a href=\"resources/Assignments/Assignment01.zip\" target='_blank'>" +
    "<img src=\"img/assignment.png\" alt=\"Assignment01\" style=\"width:64px;height:64px;\"></a>" +
    "</div>" +
    "</div>" +

    "<div id=\"flip2\" class = \"clickable\" onClick='cclick(\"flip2\")' onmouseenter='mouseenter(\"flip2\")' onmouseleave='mouseleave(\"flip2\")' style='font-weight: bold'>Assignment #02</div>" +
    "<div id=\"panel2\" >" +
    "<div style='text-align: center'>" +
    "<a href=\"resources/Assignments/Assignment02.zip\" target='_blank'>" +
    "<img src=\"img/assignment.png\" alt=\"Assignment02\" style=\"width:64px;height:64px;\"></a>" +
    "</div>" +
    "</div>" +

    "<div id=\"flip3\" class = \"clickable\" onClick='cclick(\"flip3\")' onmouseenter='mouseenter(\"flip3\")' onmouseleave='mouseleave(\"flip3\")' style='font-weight: bold'>Assignment #03</div>" +
    "<div id=\"panel3\" >" +
    "<div style='text-align: center'>" +
    "<a href=\"resources/Assignments/Assignment03.zip\" target='_blank'>" +
    "<img src=\"img/assignment.png\" alt=\"Assignment03\" style=\"width:64px;height:64px;\"></a>" +
    "</div>" +
    "</div>" +

    "<div id=\"flip4\" class = \"clickable\" onClick='cclick(\"flip4\")' onmouseenter='mouseenter(\"flip4\")' onmouseleave='mouseleave(\"flip4\")' style='font-weight: bold'>Assignment #04</div>" +
    "<div id=\"panel4\" >" +
    "<div style='text-align: center'>" +
    "<a href=\"resources/Assignments/Assignment04.rar\" target='_blank'>" +
    "<img src=\"img/assignment.png\" alt=\"Assignment04\" style=\"width:64px;height:64px;\"></a>" +
    "</div>" +
    "</div>" +

    "<div id=\"flip5\" class = \"clickable\" onClick='cclick(\"flip5\")' onmouseenter='mouseenter(\"flip5\")' onmouseleave='mouseleave(\"flip5\")' style='font-weight: bold'>Assignment #05 / Assignment #06</div>" +
    "<div id=\"panel5\" >" +
    "<div style='text-align: center'>" +
    "<a href=\"resources/Assignments/Assignment05.pdf\" target='_blank'>" +
    "<img src=\"img/assignment.png\" alt=\"Assignment05\" style=\"width:64px;height:64px;\"></a>" +
    "</div>" +
    "</div>" +

    "<h3 style='text-align: center'>MidTerms</h3>" +
    "</div>" +
    "<div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br>" +
    "<div class=\"col\" id=\"courseBriefRight\">" +
    "<div id=\"flip7\" class = \"clickable\" onClick='cclick(\"flip7\")' onmouseenter='mouseenter(\"flip7\")' onmouseleave='mouseleave(\"flip7\")' style='font-weight: bold'>MidTerm # 01</div>" +
    "<div id=\"panel7\" >" +
    "<div style='text-align: center'>" +
    "<a href=\"resources/MidTerms/umair/mid1.zip\" target='_blank'>" +
    "<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Mid1\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/MidTerms/taj/mid1.zip\" target='_blank'>" +
    "<img src=\"img/DrTaj.png\" alt=\"Dr. Taj Mid1\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/MidTerms/asma/mid1.zip\" target='_blank'>" +
    "<img src=\"img/MsAsma.png\" alt=\"Ms. Asma Mid1\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "</div>" +
    "</div>" +

    "<div id=\"flip8\" class = \"clickable\" onClick='cclick(\"flip8\")' onmouseenter='mouseenter(\"flip8\")' onmouseleave='mouseleave(\"flip8\")' style='font-weight: bold'>MidTerm # 02</div>" +
    "<div id=\"panel8\" >" +
    "<div style='text-align: center'>" +
    "<a href=\"resources/MidTerms/umair/mid2.zip\" target='_blank'>" +
    "<img src=\"img/DrUmair.png\" alt=\"Dr. Umair Mid2\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/MidTerms/taj/mid2.zip\" target='_blank'>" +
    "<img src=\"img/DrTaj.png\" alt=\"Dr. Taj Mid2\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "<a href=\"resources/MidTerms/asma/mid2.zip\" target='_blank'>" +
    "<img src=\"img/MsAsma.png\" alt=\"Ms. Asma Mid2\" style=\"width:64px;height:64px;border-style:solid;border-color:black;border-width:2px;\"></a>" +
    "</div>" +
    "</div>" +

    "</ul></div></div><br>",

    /******************************************************************************************************************/
    "Projects Archive":
    "<div class=\"jumbotron\">" +
    "<div class=\"row\"><br>" +
    "<div class=\"col\">" +
    "<h2>Projects Archive</h2>" +
    "<h3>Batch 2015</h3>" +
    "</div>" +
    "<div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br>" +
    "<div class=\"col\" id=\"courseBriefRight\">" +
    "<div id=\"flip1\" class = \"clickable\" onClick='cclick(\"flip1\")' onmouseenter='mouseenter(\"flip1\")' onmouseleave='mouseleave(\"flip1\")' style='font-weight: bold'>Ice Men</div>" +
    "<div id=\"panel1\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Tabish Azam</li>" +
    "<li><a href=\"https://youtu.be/6-p340hhErQ\" target='_blank'>Video</a></li>" +
    "</div>" +
    "</div>" +

    "<div id=\"flip2\" class = \"clickable\" onClick='cclick(\"flip2\")' onmouseenter='mouseenter(\"flip2\")' onmouseleave='mouseleave(\"flip2\")' style='font-weight: bold'>Raahi</div>" +
    "<div id=\"panel2\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Anas Masood</li>" +
    "<li><a href=\"https://youtu.be/Sz01xf_z9fM\" target='_blank'>Video</a></li>" +
    "</div>" +
    "</div>" +

    "<div id=\"flip3\" class = \"clickable\" onClick='cclick(\"flip3\")' onmouseenter='mouseenter(\"flip3\")' onmouseleave='mouseleave(\"flip3\")' style='font-weight: bold'>Street Fighter Adventure</div>" +
    "<div id=\"panel3\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Muhammad Hammad Siddiqui</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=q-Md11jq4CU\" target='_blank'>Video</a></li>" +
    "</div></div>" +
    "" +

    "<h3 style='text-align: center'>Batch 2016</h3>" +
    "</div>" +
    "<div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br>" +
    "<div class=\"col\" id=\"courseBriefRight\">" +
    "<div id=\"flip4\" class = \"clickable\" onClick='cclick(\"flip4\")' onmouseenter='mouseenter(\"flip4\")' onmouseleave='mouseleave(\"flip4\")' style='font-weight: bold'>Arkanoid</div>" +
    "<div id=\"panel4\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Syed Hasan Shozab Abidi, Anabia Alam, Fariha Farooq, Syed Hassan Abbas Naqvi and Lala Rukh</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=7dfn7qj9S_g\" target='_blank'>Video</a></li>" +
    "</div>" +
    "</div>" +

    "<div id=\"flip5\" class = \"clickable\" onClick='cclick(\"flip5\")' onmouseenter='mouseenter(\"flip5\")' onmouseleave='mouseleave(\"flip5\")' style='font-weight: bold'>Cabal</div>" +
    "<div id=\"panel5\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Muhammad Ali Bhutto, Salman Hassan Khan, Roomi Aziz Merchant, Yasir Salim, and Talal Zahid</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=D5ievDVIGw0&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div>" +
    "</div>" +

    "<div id=\"flip6\" class = \"clickable\" onClick='cclick(\"flip6\")' onmouseenter='mouseenter(\"flip6\")' onmouseleave='mouseleave(\"flip6\")' style='font-weight: bold'>Spy Hunter</div>" +
    "<div id=\"panel6\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Ambreen Abidi, Rumsha Siddiqui, Barira Yousuf, Alizar Hassanali Lalani and Ukasha Rafiq</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=19L00Y4V3u4&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip7\" class = \"clickable\" onClick='cclick(\"flip7\")' onmouseenter='mouseenter(\"flip7\")' onmouseleave='mouseleave(\"flip7\")' style='font-weight: bold'>Crappy Bird</div>" +
    "<div id=\"panel7\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Marium Hasan, Fatima Imran, Abdul Junaid, Fatema Quaid Joher and Mohammad Shakaib Saleem</li>" +
    "<li><a href=\"https://www.youtube.com/channel/UCkCXuzpYdQUvxfqV7W37OOg/videos?shelf_id=0&view=0&sort=dd\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip8\" class = \"clickable\" onClick='cclick(\"flip8\")' onmouseenter='mouseenter(\"flip8\")' onmouseleave='mouseleave(\"flip8\")' style='font-weight: bold'>Space Battles</div>" +
    "<div id=\"panel8\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Muhammad Mehdi</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=lOyLGMGbV44&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip9\" class = \"clickable\" onClick='cclick(\"flip9\")' onmouseenter='mouseenter(\"flip9\")' onmouseleave='mouseleave(\"flip9\")' style='font-weight: bold'>Project Final Fight</div>" +
    "<div id=\"panel9\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Hassan Habibullah Sachwani, Mehak Mohammad, Syeda Naeema Hasan, Urwa Fatima and Usman Ahmed</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=BpECGxJ_ccc&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip10\" class = \"clickable\" onClick='cclick(\"flip10\")' onmouseenter='mouseenter(\"flip10\")' onmouseleave='mouseleave(\"flip10\")' style='font-weight: bold'>Mario Raddi</div>" +
    "<div id=\"panel10\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Taha Jawed, Fahad Ahmed Khan, Taimoor Neeshat, Noorullah Farid and Ahmed Raza</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=xiY7o0LpPRw&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip11\" class = \"clickable\" onClick='cclick(\"flip11\")' onmouseenter='mouseenter(\"flip11\")' onmouseleave='mouseleave(\"flip11\")' style='font-weight: bold'>Dave</div>" +
    "<div id=\"panel11\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Muhammad Salman Abbasi, Syed Nouman Hasany, Khubaib Ahmed Hingoro, Syed Ahmad Sohail and Ovais Ahmed Yousufi</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=8J3C0TLOrqQ&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip12\" class = \"clickable\" onClick='cclick(\"flip12\")' onmouseenter='mouseenter(\"flip12\")' onmouseleave='mouseleave(\"flip12\")' style='font-weight: bold'>Apache Attack</div>" +
    "<div id=\"panel12\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Shoaib Ahmed Khan, Syed Furqan Ahmed and Syed Muhammad Haider Raza Rizvi</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=cAtGXyn7N2o&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip13\" class = \"clickable\" onClick='cclick(\"flip13\")' onmouseenter='mouseenter(\"flip13\")' onmouseleave='mouseleave(\"flip13\")' style='font-weight: bold'>Galaga</div>" +
    "<div id=\"panel13\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Ahmed Ali Dodhiya, Mehdi Hussain, Mukesh Kumar, Syed Muhammad Farrukh Moosvi and Syed Safeer Ali Moosvi</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=c3PxF91JWRI&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip14\" class = \"clickable\" onClick='cclick(\"flip14\")' onmouseenter='mouseenter(\"flip14\")' onmouseleave='mouseleave(\"flip14\")' style='font-weight: bold'>Strike Fighter</div>" +
    "<div id=\"panel14\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Muzammil Abbasi, Syed Talal Wasim, Farjad Ahmed, Syed Farid Ahmed and Muhammad Ali Haider Dar</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=BYbvhYMHHWc&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div></div>" +



    
//Nadia====

 "<h3 style='text-align: center'>Batch 2017</h3>" +
    "</div>" +
    "<div class=\"container-fluid bg-3 text-center\"><div class=\"row\"><br>" +
    "<div class=\"col\" id=\"courseBriefRight\">" +
    "<div id=\"flip15\" class = \"clickable\" onClick='cclick(\"flip15\")' onmouseenter='mouseenter(\"flip15\")' onmouseleave='mouseleave(\"flip15\")' style='font-weight: bold'>StellarDefence</div>" +
    "<div id=\"panel15\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Emad Bin Abid, Saman Gaziani, Aiman Khan and Reeba Aslam</li>" +
    "<li><a href=\"https://youtu.be/x0AL6Z0P9ac\" target='_blank'>Video</a></li>" +
    "</div>" +
    "</div>" +

    "<div id=\"flip16\" class = \"clickable\" onClick='cclick(\"flip16\")' onmouseenter='mouseenter(\"flip16\")' onmouseleave='mouseleave(\"flip16\")' style='font-weight: bold'>BreakOut</div>" +
    "<div id=\"panel16\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Aiman Ahmed Moin, Muhammad Ahsan Syed, Muhammad Mujtaba and Muhammad Ismail Khursheed</li>" +
    "<li><a href=\"https://youtu.be/ElBZijBNmnU\" target='_blank'>Video</a></li>" +
    "</div>" +
    "</div>" +

    "<div id=\"flip17\" class = \"clickable\" onClick='cclick(\"flip17\")' onmouseenter='mouseenter(\"flip17\")' onmouseleave='mouseleave(\"flip17\")' style='font-weight: bold'>Bunny Chase</div>" +
    "<div id=\"panel17\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Sumbul Zehra, Anusha Fatima and Rabeea Saleem</li>" +
    "<li><a href=\"https://youtu.be/SjGnfMMnlNk\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip18\" class = \"clickable\" onClick='cclick(\"flip18\")' onmouseenter='mouseenter(\"flip18\")' onmouseleave='mouseleave(\"flip18\")' style='font-weight: bold'>Mario</div>" +
    "<div id=\"panel18\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Muhammad Ali, Faiza Amir, Nisha Shaikh and Ateeb Ahmed</li>" +
    "<li><a href=\"https://youtu.be/pGgJUnk1DyE\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip19\" class = \"clickable\" onClick='cclick(\"flip19\")' onmouseenter='mouseenter(\"flip19\")' onmouseleave='mouseleave(\"flip19\")' style='font-weight: bold'>Chaakuman</div>" +
    "<div id=\"panel19\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Aiman Hasan, Hamza Masroor and Zoha Salani</li>" +
    "<li><a href=\"https://youtu.be/HJNR0u3kHkI\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip20\" class = \"clickable\" onClick='cclick(\"flip20\")' onmouseenter='mouseenter(\"flip20\")' onmouseleave='mouseleave(\"flip20\")' style='font-weight: bold'>TowerDefense</div>" +
    "<div id=\"panel20\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Sameer Anees Jaliawala and Ahsan Qadeer</li>" +
    "<li><a href=\"https://youtu.be/nxycKZMTpA4\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip21\" class = \"clickable\" onClick='cclick(\"flip21\")' onmouseenter='mouseenter(\"flip21\")' onmouseleave='mouseleave(\"flip21\")' style='font-weight: bold'>TrafficRacers</div>" +
    "<div id=\"panel21\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Ubaid Ali Faruqi, Syed Muhammad Hasan and Muhammad Tahir</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=LNXM4GC-JSc\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip22\" class = \"clickable\" onClick='cclick(\"flip22\")' onmouseenter='mouseenter(\"flip22\")' onmouseleave='mouseleave(\"flip11\")' style='font-weight: bold'>Galactic Enforces</div>" +
    "<div id=\"panel22\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Atif Mehmood, Muhammad Furqan Karim, Marina Shehzad and Sarfraz Hussain</li>" +
    "<li><a href=\"https://youtu.be/1DeusIbRJAk\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip23\" class = \"clickable\" onClick='cclick(\"flip23\")' onmouseenter='mouseenter(\"flip23\")' onmouseleave='mouseleave(\"flip23\")' style='font-weight: bold'>Cuphead</div>" +
    "<div id=\"panel23\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Moonis Rasheed, Abeera Tariq, Faizan Dilawar and Bilal Hoda</li>" +
    "<li><a href=\"https://youtu.be/0k6zqbvGwvE\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip24\" class = \"clickable\" onClick='cclick(\"flip24\")' onmouseenter='mouseenter(\"flip24\")' onmouseleave='mouseleave(\"flip24\")' style='font-weight: bold'>Plants vs Zombies</div>" +
    "<div id=\"panel24\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Wahaj Nafees Baig, Talha Javed, Naufil Siddiqui and Tasneem Adnan</li>" +
    "<li><a href=\"https://vimeo.com/244548768\" target='_blank'>Video</a></li>" +
    "</div></div>" +

    "<div id=\"flip25\" class = \"clickable\" onClick='cclick(\"flip25\")' onmouseenter='mouseenter(\"flip25\")' onmouseleave='mouseleave(\"flip25\")' style='font-weight: bold'>Poker</div>" +
    "<div id=\"panel25\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Abdul Rafay Mehboob and Nabiha Shahid</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=ZispgPBy7Mg\" target='_blank'>Video</a></li>" +
    "</div></div>" +

   "<div id=\"flip26\" class = \"clickable\" onClick='cclick(\"flip26\")' onmouseenter='mouseenter(\"flip26\")' onmouseleave='mouseleave(\"flip26\")' style='font-weight: bold'>Bricrumble</div>" +
    "<div id=\"panel26\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Osama Yousuf, Syed Sameer Nadeem, Minhaj Ahmed Moin and Amin Shiraz Gilani</li>" +
    "<li><a href=\"https://youtu.be/T0beiqioVi4\" target='_blank'>Video</a></li>" +
    "</div></div>" +

   "<div id=\"flip27\" class = \"clickable\" onClick='cclick(\"flip27\")' onmouseenter='mouseenter(\"flip27\")' onmouseleave='mouseleave(\"flip27\")' style='font-weight: bold'>FURY - The Raging Seige </div>" +
    "<div id=\"panel27\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Nirmal Advani, Rohan Khan, Muhammad Mursalin Larik and Mudassir Ali Tariq</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=_sJOc5Q7Tv4\" target='_blank'>Video</a></li>" +
    "</div></div>" +

   "<div id=\"flip28\" class = \"clickable\" onClick='cclick(\"flip28\")' onmouseenter='mouseenter(\"flip28\")' onmouseleave='mouseleave(\"flip28\")' style='font-weight: bold'>Alien Invasion</div>" +
    "<div id=\"panel28\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Anumtah Aijaz, Syed Hamza Ali and Fatin Nawaz</li>" +
    "<li><a href=\"https://youtu.be/UtV8rKK7r-I\" target='_blank'>Video</a></li>" +
    "</div></div>" +

 "<div id=\"flip29\" class = \"clickable\" onClick='cclick(\"flip29\")' onmouseenter='mouseenter(\"flip29\")' onmouseleave='mouseleave(\"flip29\")' style='font-weight: bold'>Bomber Man</div>" +
    "<div id=\"panel29\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Ahmed Ali, Sehrish Altaf, Nadia Zubair and Burhanuddin Khuzaima Hakimi</li>" +
    "<li><a href=\"https://youtu.be/aiqmfROjxt4\" target='_blank'>Video</a></li>" +
    "</div></div>" +

 "<div id=\"flip30\" class = \"clickable\" onClick='cclick(\"flip30\")' onmouseenter='mouseenter(\"flip30\")' onmouseleave='mouseleave(\"flip30\")' style='font-weight: bold'>Dragon Ball Adventures</div>" +
    "<div id=\"panel30\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Sami Murtaza, Syed Ahsan Ahmed and Muhammad Haris</li>" +
    "<li><a href=\"https://youtu.be/mvQdDsxfv2o\" target='_blank'>Video</a></li>" +
    "</div></div>" +


 "<div id=\"flip31\" class = \"clickable\" onClick='cclick(\"flip31\")' onmouseenter='mouseenter(\"flip31\")' onmouseleave='mouseleave(\"flip31\")' style='font-weight: bold'>Risk: Global Domination</div>" +
    "<div id=\"panel31\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Mir Mehdi Ali Baqri, Hasan Shakir, Samana Syed and Danyal Admani</li>" +
    "<li><a href=\"https://youtu.be/JecU-TF94Kw\" target='_blank'>Video</a></li>" +
    "</div></div>" +

 "<div id=\"flip32\" class = \"clickable\" onClick='cclick(\"flip32\")' onmouseenter='mouseenter(\"flip32\")' onmouseleave='mouseleave(\"flip32\")' style='font-weight: bold'>Pokémon: Delta Emerald</div>" +
    "<div id=\"panel32\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Hamza Waseem Bajwa, Fiza Shah, Muhammad Shahzaib Alam and Syeda Hafsah Fahim</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=9S0ekGW8Iew\" target='_blank'>Video</a></li>" +
    "</div></div>" +

 "<div id=\"flip33\" class = \"clickable\" onClick='cclick(\"flip33\")' onmouseenter='mouseenter(\"flip33\")' onmouseleave='mouseleave(\"flip33\")' style='font-weight: bold'>Aero Wars</div>" +
    "<div id=\"panel33\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Syed Hamza Azeem, Syed Hasnain Raza, Narjis Zehra and Shariq Ali Shahani</li>" +
    "<li><a href=\"https://youtu.be/VbIYDKXtdAM\" target='_blank'>Video</a></li>" +
    "</div></div>" +

 "<div id=\"flip34\" class = \"clickable\" onClick='cclick(\"flip34\")' onmouseenter='mouseenter(\"flip34\")' onmouseleave='mouseleave(\"flip34\")' style='font-weight: bold'>Air Survivors</div>" +
    "<div id=\"panel34\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Sayyada Sahar Fatima, Syeda Maryam Fatima and Areej Al Medinah</li>" +
    "<li><a href=\"https://youtu.be/Apu5j0ENxqw\" target='_blank'>Video</a></li>" +
    "</div></div>" +

 "<div id=\"flip35\" class = \"clickable\" onClick='cclick(\"flip35\")' onmouseenter='mouseenter(\"flip35\")' onmouseleave='mouseleave(\"flip35\")' style='font-weight: bold'>ZAS Commando</div>" +
    "<div id=\"panel35\" >" +
    "<div>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Syed Zain Rahat Hussain, Muhammad Saad Saleem and Muhammad Ateeb Ahmed</li>" +
    "<li><a href=\"https://youtu.be/CckiUl5b7qI\" target='_blank'>Video</a></li>" +
    "</div></div>" +
    

"</ul></div></div><br>"


/*	"<div class=\"jumbotron\"><div class=\"row\"><br><div class=\"col\"><h2>Archive</h2></div><div class=\"container-fluid bg-3 text-center\">" +
	"<div class=\"row\"><br><div class=\"col\" id=\"courseBriefRight\">" +
	"<div>" +
	"<h3 style='text-decoration: underline'>Batch 2015 Projects</h3>" +
	"<h4>Ice Men</h4>" +
	"<ul style=\"list-style-type:square\">" + 
	"<li>Created by Tabish Azam</li>" +
	"<li><a href=\"https://youtu.be/6-p340hhErQ\" target='_blank'>Video</a></li>" + 
	"</div>" +
	
	"<div>" + 
	"<h4>Raahi</h4>" +
	"<ul style=\"list-style-type:square\">" + 
	"<li>Created by Anas Masood</li>" +
	"<li><a href=\"https://youtu.be/Sz01xf_z9fM\" target='_blank'>Video</a></li>" + 
	"</div>" +
	
	"<div>" + 
	"<h4>Street Fighter Adventure</h4>" +
	"<ul style=\"list-style-type:square\">" + 
	"<li>Created by Muhammad Hammad Siddiqui</li>" +
	"<li><a href=\"https://www.youtube.com/watch?v=q-Md11jq4CU\" target='_blank'>Video</a></li>" + 
	"</div>" +

    "<div>" +
    "<h3 style='text-decoration: underline'>Batch 2016 Projects</h3>" +
    "<h4>Arkanoid</h4>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Syed Hasan Shozab Abidi, Anabia Alam, Fariha Farooq, Syed Hassan Abbas Naqvi and Lala Rukh</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=7dfn7qj9S_g\" target='_blank'>Video</a></li>" +
    "</div>" +


    "<div>" +
    "<h4>Cabal</h4>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Muhammad Ali Bhutto, Salman Hassan Khan, Roomi Aziz Merchant, Yasir Salim, and Talal Zahid</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=D5ievDVIGw0&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div>" +

    "<div>" +
    "<h4>Spy Hunter</h4>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Ambreen Abidi, Rumsha Siddiqui, Barira Yousuf, Alizar Hassanali Lalani and Ukasha Rafiq</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=19L00Y4V3u4&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div>" +

    "<div>" +
    "<h4>Crappy Bird</h4>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Marium Hasan, Fatima Imran, Abdul Junaid, Fatema Quaid Joher and Mohammad Shakaib Saleem</li>" +
    "<li><a href=\"https://www.youtube.com/channel/UCkCXuzpYdQUvxfqV7W37OOg/videos?shelf_id=0&view=0&sort=dd\" target='_blank'>Video</a></li>" +
    "</div>" +

    "<div>" +
    "<h4>Space Battles</h4>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Muhammad Mehdi</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=lOyLGMGbV44&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div>" +

    "<div>" +
    "<h4>Project Final Fight</h4>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Hassan Habibullah Sachwani, Mehak Mohammad, Syeda Naeema Hasan, Urwa Fatima and Usman Ahmed</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=BpECGxJ_ccc&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div>" +

    "<div>" +
    "<h4>Mario Raddi</h4>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Taha Jawed, Fahad Ahmed Khan, Taimoor Neeshat, Noorullah Farid and Ahmed Raza</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=xiY7o0LpPRw&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div>" +

    "<div>" +
    "<h4>Dave</h4>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Muhammad Salman Abbasi, Syed Nouman Hasany, Khubaib Ahmed Hingoro, Syed Ahmad Sohail and Ovais Ahmed Yousufi</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=8J3C0TLOrqQ&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div>" +

    "<div>" +
    "<h4>Apachee Attack</h4>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Shoaib Ahmed Khan, Syed Furqan Ahmed and Syed Muhammad Haider Raza Rizvi</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=cAtGXyn7N2o&feature=youtu.be\" target='_blank'>Video</a></li>" +
	"</div>" +

    "<div>" +
    "<h4>Galaga</h4>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Ahmed Ali Dodhiya, Mehdi Hussain, Mukesh Kumar, Syed Muhammad Farrukh Moosvi and Syed Safeer Ali Moosvi</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=c3PxF91JWRI&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div>" +

    "<div>" +
    "<h4>Strike Fighter</h4>" +
    "<ul style=\"list-style-type:square\">" +
    "<li>Created by Muzammil Abbasi, Syed Talal Wasim, Farjad Ahmed, Syed Farid Ahmed and Muhammad Ali Haider Dar</li>" +
    "<li><a href=\"https://www.youtube.com/watch?v=BYbvhYMHHWc&feature=youtu.be\" target='_blank'>Video</a></li>" +
    "</div>" +

    "</ul></div></div><br>"
    */
}