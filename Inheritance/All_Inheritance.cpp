
class MITStudent {
protected:
    int rollNo;
    void setRollNo(int no) {
        rollNo = no;
    }
public:
//INLINED
//(As the function is fully defined inside the class)
    void displayRollNo() {
        cout << "Roll No: " << rollNo << endl;
    }
};

class CSEStudent : public MITStudent {
public:
    void setStudentRollNo(int no) {
        setRollNo(no); // Can access protected members of the base class
    }
};

class EEEStudent : protected MITStudent {
public:
    void setStudentRollNo(int no) {
        setRollNo(no); // Can access protected members of the base class
    }
};

class CSEStudent2 : private MITStudent { 
public: 
void setStudentRollNo(int no) { 
setRollNo(no); // Can access inherited members as they are private } 

void showRollNo() { 
displayRollNo(); // Can access inherited members as they are private }
 };



class Watch {
    static int day;
public:
	string model;
    static int x;
	static int year;
	void setDay (int y){
		day = y; }
    	
	static void setX(int n){ //You can use any static class member variable/function or any global variable/function in a static function
		x = n;
	}
	int getYear(){
		return year; }
};

//Here public,private both static can be initialized but in main only public can
int Watch::year;
int Watch::day;


int main() {
    CSEStudent cseStudent;
    cseStudent.setStudentRollNo(101); // Can access public members of the derived class
    cseStudent.displayRollNo(); // Can access public members of the base class

    EEEStudent eeeStudent;
    eeeStudent.setStudentRollNo(102); // Can access public members of the derived class


    CSEStudent2 cseStudent;
    cseStudent.setStudentRollNo(101); // Can access public members of the derived class
    cseStudent.showRollNo(); // Can access public members of the derived class

    Watch o1, o2;
    o1.setDay(1905);
	Watch::year = 1905;
    //static keeps 1 copy no matter how many object.It acts like a seperate entity
    Demo::show(16);


    return 0;
}


