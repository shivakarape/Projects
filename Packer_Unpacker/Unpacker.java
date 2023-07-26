import java.util.*;
import java.io.*;

class Unpacker
{
    public static void main(String arg[]) throws Exception
    {
        
        Scanner sobj = new Scanner(System.in);
        byte Header[] = new byte[100];
        int iRet = 0;
        String HeaderStr;
        String Tokens[];
        int iCount = 0;

        System.out.println("-----------Marvellous Packer Unpacker----------");
        System.out.println("Unacking Activity of the application is started ");

        System.out.println("Enter the file Name which contains the packed data");
        String PackFile = sobj.nextLine();

        try
        {       
        File Packobj = new File(PackFile);

        FileInputStream inobj = new FileInputStream(Packobj);

        while((iRet = inobj.read(Header,0,100)) > 0)
        {

            HeaderStr = new String(Header);
            System.out.println(HeaderStr);

            Tokens = HeaderStr.split(" ");

            File newfileobj = new File(Tokens[0]);
            newfileobj.createNewFile();

            FileOutputStream outobj = new FileOutputStream(newfileobj);
            int FileSize = Integer.parseInt(Tokens[1]);
            byte Buffer[] = new byte[FileSize]; // String to Integer conversion
            
            inobj.read(Buffer,0,FileSize);
            outobj.write(Buffer,0,FileSize);

            System.out.println("File succesfully extracted with name : "+Tokens[0]);
            iCount++;

        }
        System.out.println("------------------Packing Summary-------------");
        System.out.println("Total number of files extracted : "+iCount);
        
        }
        catch(Exception eobj)
        {
            System.out.println("Exception : "+eobj);
        }

    }
}