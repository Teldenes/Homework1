#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Student{

    std::string index;
    std::string name;
    std::string surname;
    std::vector<float> grades;
public:
    Student(){}

    Student(std::string n, std::string s, std::vector<float> g, std::string i)
    {
        name = n;
        surname = s;
        grades = g;
        index= i;
    }

    void set_name(std::string n)
    {
        name = n;
    }

    std::string get_name()
    {
        return name;
    }

    void set_surname(std::string s)
    {
        surname = s;
    }

    std::string get_surname()
    {
        return surname;
    }

    void set_index(std::string i)
    {
     if(i.size()==5 || i.size()==6)
      {
       index = i;
      }
    }

    float mean_grade()
    {
        std::cout << "calculating grade for " << name << std::endl;
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return sum/ grades.size();
    }

    bool add_grade(float grade)
    {
        if(grade >= 2.0 && grade <= 5.0){
            grades.push_back(grade);
            return true;
        }
        return false;
    }

    void display()
     {
      cout<<"Name and Surname: "<<name<<" "<<surname<<endl;
      cout<<"Album number : "<<index<<endl;
      cout<<"Grades: ";
      for(auto it=grades.begin(); it != grades.end(); it++)
       {
        cout<<*it<<", ";
       }
      cout<<endl;
     }

    bool pass()
     {
      int strikes=0;
      for(auto i : grades)
       {
        if(grades[i]<=2.0)
         {
          strikes++;
         }
       }
      if(strikes>=2)
       {
        return false;
       }
      else
       {
        return true;
       }
     }

};

class Complex{

 float re_part;
 float im_part;

 public:
 Complex(){}

 Complex(float r, float i)
 {
  re_part = r;
  im_part = i;
 }

 Complex(float r)
 {
  re_part = r;
 }

// Complex(float i)
// {
//  im_part = i;
// }

 void set_re(float i)
  {
   re_part = i;
  }

 int get_re()
  {
   return re_part;
  }

 void set_im(float i)
  {
   im_part = i;
  }

 int get_im()
  {
   return im_part;
  }

 void print()
  {
   if(re_part!=0.0)
    {
     cout<<re_part;
    }
   if(im_part != 0.0)
    {
     if(im_part>0.0)
      {
       cout<<"+"<<im_part<<"i";
      }
     else
      {
       cout<<im_part<<"i";
      }
    }
   cout<<endl;
  }

 Complex add(Complex a)
  {
   Complex placeholder((re_part+a.re_part), (im_part+a.im_part));
   return placeholder;
  }


};

int main()
{

    Student student2 {"iman", "es", {0.0,2.1}, "271910"};
    student2.add_grade(3.5);
    student2.add_grade(3.5);

    student2.display();

    cout<<student2.pass()<<endl;

    Complex a(1.0, -2.0); // creates 1-2i
    Complex b(3.14); // creates 3.14
    a.print();
    b.print();


    b.set_im(-5);

    Complex c = a.add(b);

    c.print(); // prints 4.14-7i



    return 0;
}
