#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>

using namespace std;

void menu();
void InputProfile();
void OutputProfile();
void UpdateProfile();
void TeacherOutput();
void Resources();
void UploadQ();
void DeleteQ(string Q);
void AddAns();
void DelAns(string ans, int x);
void UpdateCheck();
void progress(string lines[], int count);
void alarm();
void data();
void Bio(string& bio);
int getdata();
bool loginUser();
void registerUser();
void getdata2();
void writeAssignmentToFile(const string& filename, string& deadline);
void cgpa();
void getdata3();
void manageRoomBooking(const string& filename);
void uploadRequest();
void findAvailable();
void findMatching();



int main(){
    int cont;
    do{
        menu();
        cout << "Enter your Choice of Function = ";
        cin >> cont;
        switch (cont)
        {
        case 1:{
            getdata();
            break;
        }
        case 2:{
            InputProfile();
            break;
        }
        case 3:{
            OutputProfile();
            break;
        }
        case 4:{
            data();
            break;
        }
        case 5:{
            UpdateProfile();
            break;
        }
        case 6:{
            TeacherOutput();
            break;
        }
        case 7:{
            Resources();
            break;
        }
        case 8:{
            UploadQ();
            break;
        }
        case 9:{
            AddAns();
            break;
        }
        case 10:{
            uploadRequest();
            break;
        }
        case 11:{
            findAvailable();
            break;
        }
        case 12:{
            findMatching();
            break;
        }
        case 13:{
            getdata3();
            break;
        }
        case 14:{
            getdata2();
            break;
        }
        case 15:{
            UpdateCheck();
            break;
        }
        case 16:{
            alarm();
            break;
        }
        case 17:{
            cgpa();
            break;
        }
        case 18:{
            break;
        }
        default:{
            cout << "Enter a Valid Value!" << endl; 
            break;
        }
    }
    system("pause");
    system("clear");
}
while (cont!=18);

cout << "Program excecution complete......";

return 0;
}


void menu(){
	cout << "\n";
    cout << "\t\tSTUDENT SPACE" <<endl;
    cout << "_________________________________________________" << endl <<endl;
    cout << "1. Login\t";
    cout << "2. Add Profile\n";
    cout << "3. Show Profiles\t";
    cout << "4. Enter Bio\n";
    cout << "5. Update Profile\t";
    cout << "6. Show Teacher Profile\n";
    cout << "7. Show Resources\t";
    cout << "8. Ask a Question\n";
    cout << "9. Answer a Question\t";
    cout << "10. Request Project Groupmates\n";
    cout << "11. Find your Project Groupmates\t";
    cout << "12. Find your Study Buddy\n";
    cout << "13. Book a Discussion Room\t";
    cout << "14. Make a Checklist\n";
    cout << "15. Mark Off your Checklist\t";
    cout << "16. Reminder !!!\t";
    cout << "17. Caluculate GPA\n";
    cout << "18. Exit\t" << endl; 
}
void InputProfile(){
	string Name , I_D , Depart , email , Phone;
	int Age;
	char Semester;
	char expert[100];
	
	cin.ignore();
	
	ofstream profile;
	profile.open("D:\\BNU S2\\Programming Lab\\project\\profiles.txt",fstream:: app);
	
	if (profile.is_open())	{
	
	cout << "Enter your Name \t";
	getline (cin,Name);
	profile << "Name:" << Name <<endl;
	
	cout << "\nEnter your Registration ID \t   "; 
	cin >> I_D;
	profile << "Registration ID;" << I_D <<endl;
	
	cout << "\nEnter your Age \t   ";
	cin >> Age;
	profile << "Age:" << Age <<endl;
	
	cout << "\nEnter your Semester \t   ";
	cin >> Semester;
	profile << "Semester:" << Semester <<endl;
	
	cout << "\nEnter your University Department(Abbrv.) \t   ";
	cin >> Depart;
	profile << "Department:" << Depart <<endl;
	
	cout << "\nEnter your Contact Information \n";
	cout << "   Enter your Contact Number = ";
	cin  >> Phone;
	
	while(Phone.length()!=11){
		cout << "   INVALID Enter your Contact Number again = ";
		cin  >> Phone;
	}
	profile << "Phone no:"<< Phone <<endl;
	
	cout <<"\n   Enter your email address = ";
	cin >> email;
	profile << "Email Address:"<< email <<endl;
	
	cin.ignore();
	
	cout << "\nWhat are your Expertise (do not exceed 100 characters) ";
	cin.getline(expert,100);
	profile << "Expertise:"<< expert <<endl;
	
	}
	profile.close();
}
void OutputProfile(){
	cout<<endl<<endl;
	ifstream profile;
	profile.open("D:\\BNU S2\\Programming Lab\\project\\profiles.txt",fstream:: app);
	
	if (profile.is_open()){
		
		cout<<profile.rdbuf();
	}
	profile.close();
	
}
void UpdateProfile(){
	
	string name_search;
	int offset , count=0;
	string namefound;
	
	ifstream profile;
	profile.open("D:\\BNU S2\\Programming Lab\\project\\profiles.txt",fstream:: app);
	
	cout << "Enter your name as entered in your profile = ";
	cin >> name_search;
	
	if (profile.is_open()){
			
		while(!profile.eof()){
			
			getline(profile, namefound);
			count++;
			
			if((offset = namefound.find(name_search,0)) != string::npos){
				
				cout<<"You can update your Profile now..."<<endl<<endl;
				break;
			}
		}
	profile.close();	
	}
	else{
		cout<<"Error, file cannot open...."<<endl;
	}
	
	profile.open("D:\\BNU S2\\Programming Lab\\project\\profiles.txt",fstream:: app);
	
	string lines[100];
	string line;
	int i=0;
	if (profile.is_open()){
		while(getline(profile , line)){
			lines[i]=line;
			i++;
		}
	}
	
	profile.close();
	
	ofstream profiles;
	
	profiles.open("D:\\BNU S2\\Programming Lab\\project\\profiles.txt");
	
	if (profiles.is_open()){
	count--;
	for (int j=0; j<i+1;j++){
		if(j<count || j>count+8){
			profiles << lines[j] << endl;
		}
		
	}	
	}
	profiles.close();
	InputProfile();
}
void TeacherOutput(){
	ifstream teacher;
	teacher.open("D:\\BNU S2\\Programming Lab\\project\\teachers.txt");
	
	if(teacher.is_open()){
		cout << teacher.rdbuf(); 
	}
	else{
		cout<<"Error! can not open file..."<<endl;
	}
	teacher.close();	
}
void Resources()
{
    int ans;
    cout<<"Enter the following numbers for the relevant course resources:"<<endl;
    cout<<"1:Digital Logic Design"<<endl;
    cout<<"2:Financials for IT"<<endl;
    cout<<"3:Programming Fundamentals"<<endl;
    cout<<"4:Probability and Statistics"<<endl;
    cout<<"5:Expository Writing"<<endl;
    cin>>ans;
    if(ans<1 || ans>5)
    {
        cout<<"Enter a valid option from the menu:"<<endl;
        cout<<"Enter the following numbers for the relevant course resources:"<<endl;
        cout<<"1:Digital Logic Design"<<endl;
        cout<<"2:Financials for IT"<<endl;
        cout<<"3:Programming Fundamentals"<<endl;
        cout<<"4:Probability and Statistics"<<endl;
        cout<<"5:Expository Writing"<<endl;
        cin>>ans;
    }
    switch(ans)
    {
        case 1:
        {
            cout<<"Book: Digital Fundamentals (11th Edition) By Thomas L.Floyd";
            break;
        }
        case 2:
        {
            cout<<"Online Resource (Youtube Channel): 'Accounting by Hafiz Imtiaz Ahmad'";
            break;
        }
        case 3:
        {
            cout<<"Book 1: Starting out with C++ From Control Structures through Objects (9th Edition) by Tony Gaddis";
            cout<<"Book 2: C++ Programming From Problem Analysis to Program Design (8th Edition) by D.S Malik";
            break;
        }
        case 4:
        {
            cout<<"Book: Probability & Statistics for Engineers & Scientists (9th Edition) by Ronald E. Walpole , Raymond H. Myers, Sharon L. Myers, Keying Ye";
            break;
        }
        case 5:
        {
            cout<<"In-class Resources: Instructor will provide the relevant documents for this course.";
            break;
        }
    }
}
void UploadQ(){
	
	string Q;
	char res;
	
	ofstream q;
	q.open("D:\\BNU S2\\Programming Lab\\project\\questions.txt",fstream:: app);
	if (q.is_open()){
		cout << "Enter your question = ";
		getline(cin,Q);
		
		q << Q << "?" <<endl;
	}
	q.close();

	cout << "Do you want to delete your question (Y/N) = ";
	cin >> res;
	res=toupper(res);
	
	if (res=='Y'){
		DeleteQ(Q);
	}
	else {
		cout << "Your question was uploaded successfully";
	}	
}
void DeleteQ(string Q){
	
	ifstream myfile;
	myfile.open("D:\\BNU S2\\Programming Lab\\project\\questions.txt");
	
	string lines[500];
	string line, del;
	int offset, count=0;
	
	if (myfile.is_open()){
		
		while (!myfile.eof()){
			
			getline(myfile,del);
			count++;
			if ((offset = del.find(Q,0)) != string::npos){
				break;
			}	
		}
	myfile.close();	
	}
	else{
		cout<<"Error in opening file..."<<endl;
		return;
	}
	
	myfile.open("D:\\BNU S2\\Programming Lab\\project\\questions.txt");
	
	int i=0;
	
	if (myfile.is_open()){
		while (getline(myfile,line)){
			lines[i]=line;
			i++;
		}
	}
	myfile.close();
	
	ofstream delfile;
	delfile.open("D:\\BNU S2\\Programming Lab\\project\\questions.txt" ,ofstream::trunc);
	
	if (delfile.is_open()){
		count--;
		for(int j=0; j<i+1;j++){
			if(j!= count){
				delfile << lines[j] <<endl;
			}
		}
	}
	delfile.close();
}
void AddAns(){
	
	string lines[200];
	string line1,line2;
	string ans;
	int count=0;
	int q, x;
	
	ifstream readfile;
	readfile.open("D:\\BNU S2\\Programming Lab\\project\\questions.txt");
	
	while(getline(readfile,line1)){
		cout << count+1 << ":" << line1 << endl;
		count++;
	}
	readfile.close();
	
	ifstream infile;
	infile.open("D:\\BNU S2\\Programming Lab\\project\\answers.txt");
	count=0;
	while(getline(infile, line2)){
		lines[count]=line2;
		count++;
	}
	
	infile.close();
	
	cout << "Which Question would you like to answer?(enter the index) = ";
	cin >> q;
	
	cin.ignore();
	
	cout <<"\nEnter your answer =";
	getline(cin, ans);
	
	ofstream outfile;
	outfile.open("D:\\BNU S2\\Programming Lab\\project\\answers.txt");
	
	bool written=false;
	
	int i=0;
	
	while(i<=count){
		
		if(i==q){
			outfile << "\t" << ans << endl;
			written=true;
			x=q;
		}
		outfile << lines[i] <<endl;
		i++;
	}
	if(q==i){
		
		outfile << endl;
		outfile << ans;
		written=true;
	}
	
	outfile.close();
	
	char res;
	cout << "Would you like to delete your answer(Y/N) = ";
	cin >> res;
	
	res=toupper(res);
	
	if (res=='Y'){
		
		DelAns(ans,x);
	}	
}
void DelAns(string ans, int x){
	
	string lines[200];
	string line;
	int count=0;
	
	ifstream infile;
	infile.open("D:\\BNU S2\\Programming Lab\\project\\answers.txt");
	
	while(getline(infile,line)){
		
		lines[count]=line;
		count++;
	}
	
	infile.close();
	
	ofstream outfile;
	outfile.open("D:\\BNU S2\\Programming Lab\\project\\answers.txt");
	
	for (int j=0; j<count ; j++){
		
		if (j!=x){
			outfile << lines[j] <<endl;
		}
		
	}
	outfile.close();	
}
void UpdateCheck(){
    string filename;
	char res;
	int count=0 , x;
	string lines[200];
	string line;

    cout << "Enter your assignment file name = ";
    getline(cin,filename);

	ifstream assign;
	assign.open("D:\\BNU S2\\Programming Lab\\project\\"+filename+".txt");
	
	while(getline(assign, line)){
		cout << count << ":" << line <<endl;
		lines[count]=line;
		count++;
	}
	
	assign.close();

	do{
	cout << "Enter the item you want to cross off : ";
	cin >> x;
	
	assign.open("D:\\BNU S2\\Programming Lab\\project\\"+filename+".txt");
	
	int i=0;
	
	while(getline(assign, line)){
		lines[i]=line;
		i++;
	}
	assign.close();
	
	ofstream outfile;
	outfile.open("D:\\BNU S2\\Programming Lab\\project\\"+filename+".txt");
	
	if (outfile.is_open()){
		for (int j =0; j<i+1;j++){
			if (x==j){
				lines[j]+= "[DONE!]";
				
			}
			outfile << lines[j] << endl;
		}
	}
	outfile.close();
	
	cout << "\nDo you want to continue(Y/N) = ";
	cin>>res;
	res=toupper(res);
	}
	while(res=='Y');
    cout <<"Do you want a progress report (Y/N) = ";
    cin >> res;
    res=toupper(res);
    if(res=='Y')
	progress(lines,count);
    else
    return;
}
void progress(string lines[], int count){
	
	ifstream infile;
	infile.open("D:\\BNU S2\\Programming Lab\\project\\assignment.txt");
	if(infile.fail()){
		cout<<"Error! can not open file...";
		return;
	}
	
	int donecount=0;
	string mes="[DONE!]";
	for (int j=0; j<count; j++){
		if(lines[j].find(mes,0) != string::npos){
			donecount++;
		}
	}
	float percent;
	percent = ((double)donecount/count)*100;
	cout << percent << " % work completed" << endl;
	cout << 100- percent << "% work is left";
}
void alarm(){
    time_t now=time(0);
	
	char *dt= ctime(&now);
	string fullform(dt);
	
	string daytext(fullform,8, 2);
	int day= stoi(daytext);

	string yeartext(fullform,20,4);
	int year=stoi(yeartext);

	string monthtext(fullform,4, 3);
	int month;

	if (monthtext=="Jan")
	{
		month=01;
	}
	else if(monthtext=="Feb"){
		month=2;
	}
	else if(monthtext=="Mar"){
		month=3;
	}
	else if(monthtext=="Apr"){
		month=4;
	}
	else if(monthtext=="May"){
		month=05;
	}
	else if(monthtext=="Jun"){
		month=6;
	}
	else if(monthtext=="Jul"){
		month=7;
	}
	else if(monthtext=="Aug"){
		month=8;
	}
	else if(monthtext=="Sep"){
		month=9;
	}
	else if(monthtext=="Oct"){
		month=10;
	}
	else if(monthtext=="Nov"){
		month=10;
	}
	else{
		month=12;
	}
	
	ifstream myfile;
	myfile.open("D:\\BNU S2\\Programming Lab\\project\\deadlines.txt");
	
	if(myfile.fail()){
		cout<<"error";
	}

	string line;
	string assign;
	string deadlinetext;
	int dmonth;
	int dday;
	int dyear;
	while (getline(myfile,line))
	{
		int spacepos=line.find(' ',0);
		assign = line.substr(0,spacepos);
		deadlinetext = line.substr(spacepos+1,10);
		dmonth=stoi(deadlinetext.substr(0,2));
		dday=stoi(deadlinetext.substr(3,2));
		dyear=stoi(deadlinetext.substr(6,4));
		
		if(dday==day && dmonth==month){
		cout<<assign<<" is due today" <<endl;
	}
	}
    myfile.close();
	
}
void data(){
    string line;
    
    ofstream outfile;
    outfile.open("D:\\BNU S2\\Programming Lab\\project\\bio.txt",fstream:: app);
    cout << "Enter your Bio =";
    getline(cin,line);
    outfile << line << endl;
    outfile.close(); 
}
void Bio(string& bio) {

    istringstream iss(bio);
    string word;
    int wordCount = 0;
    int lineWidth = 0; 

    while (iss >> word) {
        if (lineWidth + word.length() > 75) {
            cout << endl;
            lineWidth = 0;
        }
        cout << word << " ";
        lineWidth += word.length() + 1; 

        wordCount++;
    }
    if (wordCount % 15 != 0) {
        cout << endl;
    }
}
int getdata(){
    while (true) {
        int choice;
        cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    cout << "Login successful!" << endl;
                } else {
                    cout << "Login failed. Incorrect username or password." << endl;
                }
                break;
            case 3:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
}
bool loginUser() {
    string username, password, fileUsername, filePassword;
    bool loginSuccess = false;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream infile("users.txt");
    while (infile >> fileUsername >> filePassword) {
        if (username == fileUsername && password == filePassword) {
            loginSuccess = true;
            break;
        }
    }
    infile.close();
    return loginSuccess;
}
void registerUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream outfile;
    outfile.open("users.txt", ios::app); // Open the file in append mode
    outfile << username << " " << password << endl;
    outfile.close();
    cout << "Registration successful!" << endl;
}
void getdata2(){
    int assignmentno = 49;
    char choice;
    string deadline, assignmentnum;

    do {
        cout << "Create a new assignment (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            assignmentnum=assignmentno;
            string filename = "assignment_" + assignmentnum +".txt";
            cout<< "Enter deadline for this assignment in this format (mm/dd/yy): "<<endl;
            cin>>deadline;
            writeAssignmentToFile(filename,deadline);
            assignmentno++;
            ofstream outfile;
            outfile.open("D:\\BNU S2\\Programming Lab\\project\\deadlines.txt",fstream:: app);
            outfile << filename << " " << deadline <<endl;

        } else if (choice == 'n' || choice == 'N') {
            cout << "Exiting the program." << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
        }
    } while (true);
}
void writeAssignmentToFile(const string& filename, string& deadline) {
    ofstream outFile("D:\\BNU S2\\Programming Lab\\project\\" + filename);
    if (!outFile) {
        cout << "Error opening file for writing: " << filename << endl;
        return;
    }

    cout << "Enter the requirements for the assignment (type 'END' to finish):" << endl;
    string requirement;
    cin.ignore();
    while (true) {
        getline(cin, requirement);
        if (requirement == "END") break;
        outFile << requirement << endl;
    }
    outFile.close();
    cout << "Assignment saved to " << filename << " and deadline for this assignment is: "<<deadline<<endl;
}
void cgpa(){
    int select, ncourse;
    float Msum = 0, Qsum = 0, Asum = 0;
    float wMid, wFinal, wQuiz, wAsg, wsum, usquiz, squiz, usmid, smid, usasg, sasg, sfinal, usfinal;
    int nMid, nQuiz, nAsg;
    float cgpa, wpm, wpq, wpa, percent;
    float Totalc = 0;
    float Cavg = 0;

    cout << "Enter 1 to calculate Course Grade." << endl;
    cout << "Enter 2 to calculate CGPA." << endl;
    cin >> select;
    if (select == 2)
    {
        cout << "Enter the total number of courses you have: " << endl;
        cin >> ncourse;
        float course[ncourse]; // Declare array after initializing ncourse

        for (int x = 0; x < ncourse; x++)
        {
            cout << "Enter your percentage in Course " << x + 1 << ": ";
            cin >> course[x];

            Totalc += course[x];
        }

        Cavg = Totalc / ncourse;

        if (85 <= Cavg && Cavg <= 100)
        {
            cout << "Your CGPA is: 4.00";
        }
        else if (81.50 <= Cavg && Cavg <= 84.99)
        {
            cout << "Your CGPA is: 3.67";
        }
        else if (70 <= Cavg && Cavg <= 81.49)
        {
            cout << "Your CGPA is: 3.33";
        }
        else if (74.5 <= Cavg && Cavg <= 77.99)
        {
            cout << "Your CGPA is: 3.00";
        }
        else if (71 <= Cavg && Cavg <= 74.49)
        {
            cout << "Your CGPA is: 2.67";
        }
        else if (67.5 <= Cavg && Cavg <= 70.99)
        {
            cout << "Your CGPA is: 2.33";
        }
        else if (64 <= Cavg && Cavg <= 67.49)
        {
            cout << "Your CGPA is: 2.00";
        }
        else if (60.5 <= Cavg && Cavg <= 63.99)
        {
            cout << "Your CGPA is: 1.67";
        }
        else if (57 <= Cavg && Cavg <= 60.49)
        {
            cout << "Your CGPA is: 1.33";
        }
        else if (50 <= Cavg && Cavg <= 56.99)
        {
            cout << "Your CGPA is: 1.00";
        }
        else if (0.00 <= Cavg && Cavg <= 49.99)
        {
            cout << "Your CGPA is: 0.00";
        }
    }
    else if(select==1)
    {

        cout << "Enter the weightage for Final Exam: ";
        cin >> wFinal;
        cout << "Enter the weightage for Midterm Exam: ";
        cin >> wMid;
        cout << "Enter the weightage for Assignments: ";
        cin >> wAsg;
        cout << "Enter the weightage for Quizzes: ";
        cin >> wQuiz;

        wsum=wFinal+wMid+wQuiz+wAsg;
        if(wsum!=100)
        {
           cout<<"Invalid weightage."<<"\n Make sure it sums upto 100." <<endl;

            cout << "Enter the weightage for Final Exam: ";
            cin >> wFinal;
            cout << "Enter the weightage for Midterm Exam: ";
            cin >> wMid;
            cout << "Enter the weightage for Assignments: ";
            cin >> wAsg;
            cout << "Enter the weightage for Quizzes: ";
            cin >> wQuiz;
        }

        cout << "Enter the total number of Midterm Exams: ";
        cin >> nMid;
        cout << "Enter the total number of Quizzes: ";
        cin >> nQuiz;
        cout << "Enter the total number of Assignments: ";
        cin >> nAsg;

       
        float uscorem[nMid], scorem[nMid];
        float uscoreq[nQuiz], scoreq[nQuiz];
        float uscoreasg[nAsg], scoreasg[nAsg];

        wpm = wMid / nMid;
        wpq = wQuiz / nQuiz;
        wpa = wAsg / nAsg;

        cout << "Enter the Total score of Final Exam: ";
        cin >> sfinal;
        cout << "Enter your score in the Final Exam: ";
        cin >> usfinal;

        for (int i = 0; i < nMid; i++) {
            cout << "Enter the Total score of Midterm " << i + 1 << ": ";
            cin >> smid;
            cout << "Enter your score in Midterm " << i + 1 << ": ";
            cin >> usmid;
            uscorem[i] = usmid;
            scorem[i] = smid;
            Msum += (uscorem[i] / scorem[i]) * wpm;
        }

        for (int j = 0; j < nQuiz; j++) {
            cout << "Enter the Total score of Quiz " << j + 1 << ": ";
            cin >> squiz;
            cout << "Enter your score in Quiz " << j + 1 << ": ";
            cin >> usquiz;
            uscoreq[j] = usquiz;
            scoreq[j] = squiz;
            Qsum += (uscoreq[j] / scoreq[j]) * wpq;
        }

        for (int k = 0; k < nAsg; k++) {
            cout << "Enter the Total score of Assignment " << k + 1 << ": ";
            cin >> sasg; // Corrected from squiz to sasg
            cout << "Enter your score in Assignment " << k + 1 << ": ";
            cin >> usasg;
            uscoreasg[k] = usasg;
            scoreasg[k] = sasg;
            Asum += (uscoreasg[k] / scoreasg[k]) * wpa;
        }

        percent = Msum + Qsum + Asum + (usfinal / sfinal) * wFinal;
        if (85 <= percent && percent <= 100) {
            cout << "Your percentage for this course is:" << percent << endl;
            cout << "Your Course grade is: A";
        }
        if (81.50 <= percent && percent <= 84.99) {
            cout << "Your percentage for this course is:" << percent << endl;
            cout << "Your Course grade is: A-";
        }
        if (70 <= percent && percent <= 81.49) {
            cout << "Your percentage for this course is:" << percent << endl;
            cout << "Your Course grade is: B+";
        }
        if (74.5 <= percent && percent <= 77.99) {
            cout << "Your percentage for this course is:" << percent << endl;
            cout << "Your Course grade is: B";
        }
        if (71 <= percent && percent <= 74.49) {
            cout << "Your percentage for this course is:" << percent << endl;
            cout << "Your Course grade is: B-";
        }
        if (67.5 <= percent && percent <= 70.99) {
            cout << "Your percentage for this course is:" << percent << endl;
            cout << "Your Course grade is: C+";
        }
        if (64 <= percent && percent <= 67.49) {
            cout << "Your percentage for this course is:" << percent << endl;
            cout << "Your Course grade is: C";
        }
        if (60.5 <= percent && percent <= 63.99) {
            cout << "Your percentage for this course is:" << percent << endl;
            cout << "Your Course grade is: C-";
        }
        if (57 <= percent && percent <= 60.49) {
            cout << "Your percentage for this course is:" << percent << endl;
            cout << "Your Course grade is: D+";
        }
        if (50 <= percent && percent <= 56.99) {
            cout << "Your percentage for this course is:" << percent << endl;
            cout << "Your Course grade is: D";
        }
        if (0.00 <= percent && percent <= 49.99) {
            cout << "Your percentage for this course is:" << percent << endl;
            cout << "Your Course grade is: F";
        }
    }
    else
    {
        cout<<"Invalid option."<<endl;
    }
}
void getdata3(){
    string filename = "DiscussionRoom.txt";

    manageRoomBooking(filename);

}
void manageRoomBooking(const string& filename) {

    ifstream file(filename);

    if (!file.is_open()) {

        cout << "Failed to open the file." << endl;
        return;
    }

    cout << "Schedule:" << endl;

    string line;

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();

    int choice;

    cout << "\nWhich room do you want to book? Enter the number: ";
    cin >> choice;

    string room;
    int start, end;

    string status = "Occupied";

    switch (choice) {
        case 1:
            room = "Discussion Room 1";
            break;
        case 2:
            room = "Discussion Room 2";
            break;
        case 3:
            room = "Discussion Room 3";
            break;
        case 4:
            room = "Discussion Room 4";
            break;
        default:
            cout << "Invalid choice.";
            return;

    }

    cout << "Enter start time (hour): ";
    cin >> start;
    cout << "Enter end time (hour): ";
    cin >> end;


    ifstream inFile(filename);

    ofstream outFile("DiscussionRoom_updated.txt");
    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Failed to open the file.\n";
        return;

    }

    bool roomFound = false;

    bool roomUpdated = false;

    while (getline(inFile, line)) {

        if (line.find(room) != string::npos) {
            roomFound = true;
            outFile << line << endl;

            while (getline(inFile, line)) {

                if (line.find("-") != string::npos) {
                    int hyphenPos = line.find("-");
                    int hour = stoi(line.substr(0, hyphenPos));

                    if (hour >= start && hour < end) {
                        outFile << to_string(hour) + " - " + to_string(hour + 1) + " " + status << endl;
                        roomUpdated = true;
                    } else {
                        outFile << line << endl;
                    }
                } else {
                    outFile << line << endl;
                }
            }
            if (!roomUpdated) {
                outFile << to_string(start) + " - " + to_string(end) + " " + status << endl;
            }
        } else {
            outFile << line << endl;
        }
    }

    inFile.close();

    outFile.close();

    cout << "Room successfully booked.\n";

    ifstream updatedFile("DiscussionRoom_updated.txt");

    if (!updatedFile.is_open()) {

        cout << "Failed to open the updated file." << endl;

        return;

    }
    cout << "\nUpdated Schedule:" << endl;
    while (getline(updatedFile, line)) {

        cout << line << endl;

    }
    updatedFile.close();
}
void uploadRequest() {

    ofstream file("requests.txt", fstream :: app);

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    string name, email, requireDetails;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your email: ";
    getline(cin, email);

    cout << "Enter your Project details: ";

    getline(cin, requireDetails);

    file << "Name: " << name << endl;
    file << "Email: " << email << endl;
    file << "Requirement Details: " << requireDetails << endl;

    file << "---------------------------" << endl;

    file.close();
    cout << "Your request has been uploaded successfully." << endl;
}
void findAvailable() {

    ifstream dataFile;

    dataFile.open("dummydata.txt");
    if (!dataFile.is_open()) {

        cout << "Error opening dummydata.txt file!" << endl;
        return;
    }
    string line;
    while (getline(dataFile, line)) {

        int pos = line.find("available");
        if (pos != string::npos) {

            string registration = line.substr(0, pos);
            cout << "Registration Number: " << registration << endl;
        }
    }
    dataFile.close();
}
void findMatching() {

    string word;
    cout << "Enter your requirement for a study partner: ";
    getline(cin, word);


    ifstream profileFile("students1.txt");
    if (!profileFile) {
        cout << "Error opening students1.txt file!" << endl;
        return;

    }

    string line;
    bool found = false;

    cout << "Matching student profiles:" << endl;

    while (getline(profileFile, line)) {

        if (line.find(word) != string::npos) {

            found = true;
            cout << line << endl;

            while (getline(profileFile, line) && !line.empty() && line[0] != '-') {
                cout << line << endl;
            }
            cout << "---------------------------" << endl;
        }
    }

    if (!found) {
        cout << "No matching profiles found." << endl;
    }

    profileFile.close();
}
