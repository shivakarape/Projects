import java.util.*;
import java.io.*;

class Dupliate
{
    public int DelfileCount;
    public int DelFolderCnt;
    public double savedSpace;

    Dupliate()
    {
        this.DelfileCount = 0;
        this.DelFolderCnt = 0;
    }

    void findDuplicate(File fobj, File[] fsuper)
    {
    
        if(fobj.isDirectory() == true)
        {
            File[] listFd1 = fobj.listFiles();
            if(listFd1.length != 0)
            {
		deleteDuplicate(fsuper, listFd1);
                
                listFd1 = fobj.listFiles();
                for(File tmpobj : listFd1)
                {
                    
                    if(tmpobj.isDirectory() == true)
                    {
                        findDuplicate(tmpobj, listFd1);
                    }
                }
            }
            if(listFd1.length == 0)
            {
		folderDelete(fobj);
            }
        }
    }
////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   deleteDuplicate
//  Input Parameters:   File object, File object
//  Output          :   Integer
//  Description     :   Delete file if file details are same
//  Author          :   Shivanand Aabasaheb karape
//  Date            :   28/07/2023
//
////////////////////////////////////////////////////////////////////////////////////
    int deleteDuplicate(File[] f1, File[] f2)
    {
        Scanner sobj = new Scanner(System.in);

        for(int i = 0; i < f1.length; i++)
        {
            for(int j = 0; j < f2.length; j++)
            {
                if(f1[i].length() == f2[j].length())
                {
                    if((f1[i].getName()).equals(f2[j].getName()))
                    {        
                        if((f1[i].lastModified()) == (f2[j].lastModified()))
                        {
                            fileDelete(f2[j]);
                            break;
                        }
                    }
                }
            }
        }
        return DelfileCount;
    }

    void fileDelete(File fobj)
    {
        if(fobj.isDirectory() == false)
        {
            savedSpace += fobj.length();
            fobj.delete();
            DelfileCount++;
        }
    }

    void folderDelete(File dobj)
    {
        if(dobj.isDirectory() == true)
        {
            savedSpace += dobj.length();
            dobj.delete();
            DelFolderCnt++;
        }
    }
    
}
class DiskSpaceCreator
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);
        
        System.out.print("Enter first Folder path > ");
        String folder = sobj.nextLine();
        File fobj = new File(folder);
        

        Dupliate ifDobj = new Dupliate();

        try
        {
            if(fobj.isDirectory() == true)
                {
                    File[] listFd1 = fobj.listFiles();
                    
                    for(File tmpobj : listFd1)
                    {
                        if(tmpobj.isDirectory() == true)
                        {
                            ifDobj.findDuplicate(tmpobj, listFd1);
                        }
                    }
                }
                System.out.println("Number of Duplicate files deleted are : "+ifDobj.DelfileCount);
                System.out.println("Number of empty folders deleted are : "+ifDobj.DelFolderCnt);
                System.out.println("Memory released in Kbytes : "+(ifDobj.savedSpace/1024));
        }
        catch(Exception obj)
        { 
            System.out.println("ERROR : "+obj);
            return;
        }
    }
}
