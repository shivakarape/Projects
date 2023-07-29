import java.util.*;

class Student
{
    public int Rno;
    public String Name;
    public int Age;
    public int Marks;

    public static int Generator;

    static
    {
        Generator = 0;
    }

    public Student(String str, int X, int Y)
    {
        this.Rno = ++Generator;
        this.Name = str;
        this.Age = X;
        this.Marks = Y;
    }

    public void Display()
    {
        System.out.println(this.Rno +" " +this.Name +" " + this.Age +" "+this.Marks);
    }
}

class DBMS
{
    public LinkedList<Student> lobj;

    public DBMS()
    {
        lobj = new LinkedList<Student>();
    }

    public void StartDBMS()
    {
        System.out.println("Customised DBMS started successfully..");
        System.out.println("Table Schema created sucessfully");

        String Query;
        String Tokens[];
        Scanner sobj = new Scanner(System.in);
        int TokensCount = 0;
        while(true)
        {
            System.out.print("Customised DBMS : ");
            Query = sobj.nextLine();

            Tokens = Query.split(" ");

            TokensCount = Tokens.length;

            // Query Parsing like SQL
            if(TokensCount == 1)
            {
                if("exit".equals(Tokens[0]))
                {
                    System.out.println("Thank you for using Customised DBMS...");
                    break;
                }
            }
            else if(TokensCount == 2)
            {}
            else if(TokensCount == 3)
            {}
            else if(TokensCount == 4)
            {
                if("select".equals(Tokens[0]))
                {
                    SelectFrom();
                }
            }
            else if(TokensCount == 5)
            {
                if("select".equals(Tokens[0]))
                {
                    if("MAX".equals(Tokens[1]))
                    {
                        System.out.println("Maximum marks : "+Aggregate_Max());
                    }
                    else if("MIN".equals(Tokens[1]))
                    {
                        System.out.println("Minimum marks : "+Aggregate_Min());
                    }
                    else if("AVG".equals(Tokens[1]))
                    {
                        System.out.println("Average marks : "+Aggregate_Avg());
                    }
                    else if("SUM".equals(Tokens[1]))
                    {
                        System.out.println("Summation of all marks : "+Aggregate_Sum());
                    }
                }
            }
            else if(TokensCount == 6)
            {}
            else if(TokensCount == 7)
            {
                if("insert".equals(Tokens[0]))
                {
                    InsertIntoTable(Tokens[4],Integer.parseInt(Tokens[5]),Integer.parseInt(Tokens[6]));
                }
                else if("delete".equals(Tokens[0]))
                {
                    DeleteFrom(Integer.parseInt(Tokens[6]));
                }
            }

        }
    }

    // insert into table student values(_,_,_)
    public void InsertIntoTable(String name, int age, int marks)
    {
        Student sobj = new Student(name, age, marks);
        lobj.add(sobj);
    }

    // select * from student
    public void SelectFrom()
    {
        System.out.println("Records from the student database are : ");

        for(Student sref : lobj)    // lobj is reference of first element
        {
            sref.Display();
        }
    }

    // select * from student where Rno = 11
    public void SelectFrom(int no)
    {
        System.out.println("Records from the student database are : ");

        for(Student sref : lobj)    // lobj is reference of first element
        {
            if(sref.Rno == no){
                sref.Display();
                break;
            }
        }
    }

    // select * from student where Name = "Rahul"
    public void SelectFrom(String str)
    {
        System.out.println("Records from the student database are : ");

        for(Student sref : lobj)    
        {
            if(str.equals(sref.Name)){
                sref.Display();
                break;
            }
        }
    }

    // select MAX(marks) from student
    public int Aggregate_Max()
    {
        Student temp = lobj.get(0);
        int iMax = temp.Marks;
        for(Student sref : lobj)    // lobj is reference of first element
        {
            if(sref.Marks > iMax){
                iMax = sref.Marks;
            }
        }
        return iMax;
    }

    // select MIN(marks) from student
    public int Aggregate_Min()
    {
        Student temp = lobj.get(0);
        int iMin = temp.Marks;        

        for(Student sref : lobj)    // lobj is reference of first element
        {
            if(sref.Marks < iMin){
                iMin = sref.Marks;
            }
        }
        return iMin;
    }

    // select AVG(marks) from student
    public double Aggregate_Avg()
    {
        int iSum = 0;
        for(Student sref : lobj)    // lobj is reference of first element
        {
            iSum = iSum + sref.Marks;
        }
        return (double)(iSum/(lobj.size()));
    }

    // select SUM(marks) from student
    public int Aggregate_Sum()
    {
        int iSum = 0;
        for(Student sref : lobj)    
        {
            iSum = iSum + sref.Marks;
        }
        return iSum;
    }

    // Delete from student where Rno = 11
    public void DeleteFrom(int no)
    {
        int i = 0;
        for(Student sref : lobj)    
        {
            if(sref.Rno == no)  // travel->getIndex->removeElementAtIndex
            {
                lobj.remove(i);
                break;
            }
            i++;
        }
    }
}

class CustomisedDBMS
{
    public static void main(String arg[])
    {
        DBMS obj = new DBMS();
        obj.StartDBMS();

        // obj.InsertIntoTable("Rahul",23,89);
        // obj.InsertIntoTable("Sagar",26,98);
        // obj.InsertIntoTable("Pooja",20,56);
        // obj.InsertIntoTable("Sayali",30,78);
        // obj.InsertIntoTable("Tejas",29,68);

        // obj.SelectFrom();
        // obj.SelectFrom(4);

        // obj.SelectFrom("Sagar");

        // System.out.println("Maximum Marks : "+obj.Aggregate_Max());
        // System.out.println("Minimum Marks : "+obj.Aggregate_Min());
        // System.out.println("Summation Marks : "+obj.Aggregate_Sum());
        // System.out.println("Average Marks : "+obj.Aggregate_Avg());


        // obj.DeleteFrom(4);
        // obj.SelectFrom();
    }
}

// Insert Query
// Insert into Student values Rahul 23 67
//    0     1     2       3    4     5  6
// No. of tokens : 7
// 

// select Query
// select * from student
//  0     1   2     3
// No. of tokens : 4

// delete from student where Rno = 4
//  0       1    2      3     4  5 6
// No. of tokens : 7

// select Max Age from student
//   0     1   2    3     4
// No. of tokens : 5