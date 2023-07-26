import java.util.*;
import java.io.*;

class Packer
{
    public static void main(String arg[]) throws Exception
    {
        byte Buffer[] = new byte[1024];
        int iRet = 0;
        int packcount = 0;
        Scanner sobj = new Scanner(System.in);

        System.out.println("-----------Marvellous Packer Unpacker----------");
        System.out.println("Packing Activity of the application is started ");

        System.out.print("Enter the name folder which you want  : ");
        String folderName = sobj.nextLine();

        File fobj = new File(folderName);
        String Header = null;

        System.out.print("Enter the name of packed file you want : ");
        String PackFile = sobj.nextLine();
        
        try
        {
            File Packobj = new File(PackFile);
            boolean bRet = Packobj.createNewFile();
            if(bRet == false)
            {
                System.out.println("Unable to create packed file");
                return;
            }

            System.out.println("Packed file gets successfully created in your current directory");
            FileOutputStream outobj = new FileOutputStream(Packobj);
            
            bRet = fobj.isDirectory();
            if(bRet == true)
            {
                File list[] = fobj.listFiles();

                System.out.println("Total number of files found in the directory are : "+list.length);

                for(int i = 0; i < list.length; i++)
                {
                    if((list[i].getName()).endsWith(".txt"))    // Filter by file extension
                    {
                        Header = list[i].getName() +" " +list[i].length();
                        
                        for(int j = Header.length(); j < 100; j++)
                        {
                            Header = Header + " ";
                        }

                        byte bHeader[] = Header.getBytes(); // UniCode to ASCII
                        outobj.write(bHeader,0,bHeader.length); 

                        FileInputStream inobj = new FileInputStream(list[i]);

                        // loop
                        while((iRet = inobj.read(Buffer)) != -1)    // int read(byte[] b);
                        {//           Sorce	Dest
                            outobj.write(Buffer,0,iRet);            // int write(byte[] b, int off, int len);
                        }// Dest        Sorce  Start End

                        System.out.println("File successfully packed with name : "+list[i].getName());
                        inobj.close();
                        packcount++;
                    }
                }
                System.out.println("------------------Packing Summary-------------");
                System.out.println("Total number of files scanned : "+list.length);
                System.out.println("Total number of files packes : "+packcount);

                System.out.println("Thank you for using Marvellous Packer Unpacker");
            }
        }
        catch(Exception obj)
        {
            System.out.println("Exception occured : "+obj);
        }
    }
}
