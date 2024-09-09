// two arguments template
template<class T1, class T2>
void copy (T1 a[], T2 b[], int n){
for (int i = 0; i < n; ++i)
a[i] = b[i];

}
main(){
char c[50] = {‘a’, ‘b’, ‘d’, ‘e’, ‘f’};
int i[50] = {10, 20 30, 40, 50};
float f[50] = {1.1, 2.2, 3.3, 4.4, 5.5};
copy (i, f, 5); // ok, but loss of data
copy (c, f, 5); // ok, but loss of data
copy (f, i, 5); // ok, int to float
copy (f, c, 5); // ok, char to float
}




//////////////EXAMPLE 1///////////
class Complex {
    	double real, img;
        public:
        	setValues(double r, double i){
                	real = r;		
                    img = i;	}
            friend Complex add(Complex, Complex);
        };
        
        Complex add(Complex a, Complex b){
                	Complex res;	
                    res.setValues(a.real + b.real, a.img + b.img)
                return res;
            }
int main(){
    	Complex a, b;
	    a.setValues(3.55, 2.18);
        b.setValues(5.99, 4.94);
        Complex ans = add(a, b);
          }


/////////////EXAMPLE 2//////////////////
class Teacher; 
class Student{
	string department;
public:
	… … … 
	bool sameDepartment(Teacher teacher);
};
class Teacher{
	string department;
public:
	… … … 
    string getDepartment(){		return department;}
    friend bool Student::sameDept(Teacher tch);
};
bool Student::sameDepartment(Teacher teacher){
	if(teacher.getDepartment() == department)
		return true;
	else return false;
}


int main(){	Student ob1, ob2;
	ob1.setDepartment("CSE");
    ob2.setDepartment("EECE");
	cout<<ob1.sameDepartmentStd(ob2)<<endl;
    Teacher tch;
    tch.setDepartment("CSE");
	cout << ob1.sameDept(tch) <<endl;
    }


///////////////EXAMPLE 3///////////////
class A {	
    friend class B;	//Friendship is strictly a one-one relationship between the 2 classes

    int Aries;
    };
    
class B {
    friend class C;	
    int Taurus;
    };
class C {	
    int Leo;	
    void Capricorn() {
        A a; 
        B b;		
        a.Aries = 0;//Friendship is not transitive; C is not a friend of A
		
        b.Taurus = 0;//Class C is friend of B; C has access to B’s private variables
	
        }
    };

class D : public C {	
    void Gemini() {		
        B b;		
        b.Taurus = 0;	//Friendship is not inherited; D is not a friend of B

        }
    };
class E : public B {	
    void Scorpio() {		
        C c;		
        c.Leo = 0;//Friendship is not inherited; E is not a friend of C
	}
        }; 
