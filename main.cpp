
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <ctime>
#include <cmath>

#include <fstream>

#include <sys/stat.h>
#include <bits/stdc++.h>
#include <dirent.h>

#include "FOwOFunctions_CPP-package.h"
#include "kOwOnsoleFunctions_CPP-packages.h"
 
using namespace std;

int main ()
{
    //prepare configs
    string USER_CommandLine_RAW = "";

    string USER_CommandLine_Chunk0 = ""; //to accept command line from user
    string USER_CommandLine_Chunk1 = "";
    string USER_CommandLine_Chunk2 = "";
    string USER_CommandLine_Chunk3 = "";

    string USER_CommandLine_Chunk4 = ""; //to accept command line from user
    string USER_CommandLine_Chunk5 = "";
    string USER_CommandLine_Chunk6 = "";
    string USER_CommandLine_Chunk7 = "";


    string KONS_ConsoleName_Report = "\033[1;32mkOwOnsole : \033[0m";
    string KONS_ConsoleName_Failed = "\033[1;31mkQAQnsole : \033[0m";
    string KONS_ConsoleName_Prompt = "\033[1;34mkOwOnsole > \033[0m";
    

    stringstream KONS_Bwuffer;
    KONS_Bwuffer.clear();

    string USER_CurrentDirectory;

    //print welcome, and ask for initial address
    cout << KONS_ConsoleName_Prompt << "enter starting path : ";
    cin >> USER_CurrentDirectory;
    cin.ignore();


    //here, no "." or ".." are accepted
    if(FOwO_string_FindCharPos(USER_CurrentDirectory,'.') > -1)
    {
        cout << "kQAQnsole : start directory cannot contain \".\" or \"..\", force halt" << endl;
        return 0;
    }

    //does the directory exsist ? if yes, then open, otherwise, force halt;
    DIR* KONS_dirPtrTest = opendir(USER_CurrentDirectory.c_str()); //we use this to test if a directory exsist
    DIR* KONS_dirPtrSure; //we use this to maintain current directories
    if(KONS_dirPtrTest == nullptr)
    {
        cout << "\033[1;31mkQAQnsole : directory not found, force halt\033[0m" << endl;
        return 0;
    }
    else
    {
        KONS_dirPtrSure = KONS_dirPtrTest;
        cout << KONS_ConsoleName_Report << "hint : if you have no idea how to use this thing, use the command : \"kon:help\"" << endl << endl;
    }

    
    //now we have a starting address, now Konsole mode
    while(USER_CommandLine_Chunk0 != "kon:close" && USER_CommandLine_Chunk0 != "kn:xx" && USER_CommandLine_Chunk0 != "kx")
    {
        KONS_Bwuffer.clear();

        USER_CommandLine_Chunk0 = "";
        USER_CommandLine_Chunk1 = "";
        USER_CommandLine_Chunk2 = "";
        USER_CommandLine_Chunk3 = "";

        USER_CommandLine_Chunk4 = "";
        USER_CommandLine_Chunk5 = "";
        USER_CommandLine_Chunk6 = "";
        USER_CommandLine_Chunk7 = "";

        //interpret command entries
        cout << KONS_ConsoleName_Prompt;
        getline(cin,USER_CommandLine_RAW);
        KONS_Bwuffer << USER_CommandLine_RAW;
        KONS_Bwuffer >> USER_CommandLine_Chunk0 >> USER_CommandLine_Chunk1 >> USER_CommandLine_Chunk2 >> USER_CommandLine_Chunk3 >> USER_CommandLine_Chunk4 >> USER_CommandLine_Chunk5 >> USER_CommandLine_Chunk6 >> USER_CommandLine_Chunk7;

        //short hand translations

        if     (USER_CommandLine_Chunk0 == "kn:ck" || USER_CommandLine_Chunk0 == "kk"){USER_CommandLine_Chunk0 = "kon:chunk";}
        else if(USER_CommandLine_Chunk0 == "kn:cn" || USER_CommandLine_Chunk0 == "kc"){USER_CommandLine_Chunk0 = "kon:clean";}
        else if(USER_CommandLine_Chunk0 == "kn:hp" || USER_CommandLine_Chunk0 == "kh"){USER_CommandLine_Chunk0 = "kon:help";}
        else if(USER_CommandLine_Chunk0 == "dr:mk" || USER_CommandLine_Chunk0 == "dm"){USER_CommandLine_Chunk0 = "dir:make";}
        else if(USER_CommandLine_Chunk0 == "dr:gt" || USER_CommandLine_Chunk0 == "dg"){USER_CommandLine_Chunk0 = "dir:goto";}
        else if(USER_CommandLine_Chunk0 == "dr:ls" || USER_CommandLine_Chunk0 == "dl"){USER_CommandLine_Chunk0 = "dir:list";}
        else if(USER_CommandLine_Chunk0 == "dr:pk" || USER_CommandLine_Chunk0 == "dp"){USER_CommandLine_Chunk0 = "dir:peek";}
        else if(USER_CommandLine_Chunk0 == "dr:wh" || USER_CommandLine_Chunk0 == "dw"){USER_CommandLine_Chunk0 = "dir:where";}
        else if(USER_CommandLine_Chunk0 == "fl:mk" || USER_CommandLine_Chunk0 == "fm"){USER_CommandLine_Chunk0 = "file:make";}
        else if(USER_CommandLine_Chunk0 == "fl:cp" || USER_CommandLine_Chunk0 == "fc"){USER_CommandLine_Chunk0 = "file:copy";}
        else if(USER_CommandLine_Chunk0 == "fl:pr" || USER_CommandLine_Chunk0 == "fp"){USER_CommandLine_Chunk0 = "file:print";}
        else if(USER_CommandLine_Chunk0 == "tl:rd" || USER_CommandLine_Chunk0 == "tr"){USER_CommandLine_Chunk0 = "tool:rand";}
        else if(USER_CommandLine_Chunk0 == "tl:dc" || USER_CommandLine_Chunk0 == "td"){USER_CommandLine_Chunk0 = "tool:dice";}
        else if(USER_CommandLine_Chunk0 == "tl:cl" || USER_CommandLine_Chunk0 == "tc"){USER_CommandLine_Chunk0 = "tool:calc";}



        //now do the real thing

        if     (USER_CommandLine_Chunk0 == "kon:chunk")
        {
            cout << KONS_ConsoleName_Report;
            cout << "Chunk0 : " << USER_CommandLine_Chunk0;
            cout << " , Chunk1 : " << USER_CommandLine_Chunk1;
            cout << " , Chunk2 : " << USER_CommandLine_Chunk2;
            cout << " , Chunk3 : " << USER_CommandLine_Chunk3;
            cout << " , Chunk4 : " << USER_CommandLine_Chunk4;
            cout << " , Chunk5 : " << USER_CommandLine_Chunk5;
            cout << " , Chunk6 : " << USER_CommandLine_Chunk6;
            cout << " , Chunk7 : " << USER_CommandLine_Chunk7;
            cout << endl;
        }
        else if(USER_CommandLine_Chunk0 == "kon:clean")
        {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
        }
        else if(USER_CommandLine_Chunk0 == "kon:help")
        {
            cout << KONS_ConsoleName_Report << "here is the manual of kOwOnsole :" << endl << endl;

            fstream ReaderOwO;
            ReaderOwO.open("kOwOnsoleManual.txt",ios::in);
            if(!ReaderOwO)
            {
                cout << "\033[1;32mkQAQnsole : oh wait... MANUAL IS MISSING\033[0m" << endl;
                ReaderOwO.close();
            }
            {
                ReaderOwO.seekg(0L,ios::beg);
                string linecatch = "";
                while(getline(ReaderOwO,linecatch))
                {
                    cout << linecatch << endl;
                }
                ReaderOwO.close();
            }
        }
        else if(USER_CommandLine_Chunk0 == "dir:make")
        {
            if(USER_CommandLine_Chunk1 != "")
            {
                string RAWCommand = "";

                if(USER_CommandLine_Chunk2 == "" || USER_CommandLine_Chunk2 == "lx")
                {
                    RAWCommand = "mkdir " + USER_CurrentDirectory + "/" + USER_CommandLine_Chunk1;
                }
                else if(USER_CommandLine_Chunk2 == "wn")
                {
                    RAWCommand = "md " + USER_CurrentDirectory + "/" + USER_CommandLine_Chunk1;
                }

                int FLAG = system(RAWCommand.c_str());

                if(FLAG == 0)
                {
                    cout << KONS_ConsoleName_Report << "made folder : " << USER_CommandLine_Chunk1 << endl;
                }
                else
                {
                    cout << "\033[1;32mkQAQnsole : failed to make folder\033[0m" << endl; 
                }
            }
            else
            {
                cout << "\033[1;32mkO_Onsole : bruh ... what\'s the file name?\033[0m" << endl;
            }
        }
        else if(USER_CommandLine_Chunk0 == "dir:goto")
        {
            if( USER_CommandLine_Chunk1 == "")
            {
                cout << "\033[1;32mkQAQnsole : where ???\033[0m" << endl;
            }
            else
            {   
                string Plate = USER_CommandLine_Chunk1; //the remaining part of the given relative address
                string ReadHead = "";

                //are there any neighbouring slashes
                size_t DoubleSlashPos = Plate.find("//");
                if(DoubleSlashPos != string::npos)
                {
                    //given target relative address chain has double slashes
                    //reject
                    cout << "\033[1;32mkQAQnsole : given relative address has double slashes, will not proceed\033[0m" << endl;
                }
                else if (Plate == "/")
                {
                    cout << "\033[1;32mkO_Onsole : bruh ...\033[0m" << endl;
                }
                else
                {
                    //we are safe

                    //remove heading slahes (if there is one)
                    if(FOwO_string_atPosIsChar(Plate,0,'/') && Plate.length() > 1){ Plate = FOwO_string_trim(Plate,1,Plate.length()-1); }
                    //remove tailing slashes (if there is one)
                    if(FOwO_string_atPosIsChar(Plate,Plate.length()-1,'/') && Plate.length() > 1){Plate = FOwO_string_trim(Plate,0,Plate.length()-1);}


                    while(Plate.length() > 0)
                    {
                        //get the first tiny segment
                        
                        //get the slash position
                        int slashPosition = FOwO_string_FindCharPos(Plate,'/');

                        //start trimming
                        if(slashPosition > -1) //if a slash can be found
                        {
                            ReadHead = FOwO_string_trim(Plate,0,slashPosition-1);
                            Plate = FOwO_string_trim(Plate,slashPosition+1,Plate.length()-1);
                        }
                        else
                        {
                            //no more slash can be found
                            ReadHead = Plate;
                            Plate = "";
                        }
                        

                        //can we go there ? if yes, let's go, if no, ignore, continue
                        KONS_dirPtrTest = kOwOn_action_gotoSingle(USER_CurrentDirectory,ReadHead);
                        if( KONS_dirPtrTest != nullptr )
                        {
                            KONS_dirPtrSure = KONS_dirPtrTest;
                        }
                        else
                        {
                            cout << "\033[1;31mkOoOnsole : no such directory : \033[0m" << ReadHead << endl;
                            //KONS_dirPtrSure will remain the same
                        }
                    }

                    cout << KONS_ConsoleName_Report << "new path : " << USER_CurrentDirectory << endl;
                }
            }
        }//for command choice
        else if(USER_CommandLine_Chunk0 == "dir:list" || USER_CommandLine_Chunk0 == "dir:peek")
        {

            DIR* KONS_dirPtrClone;
            string KONS_PrintDirectory;

            if(USER_CommandLine_Chunk0 == "dir:list" || USER_CommandLine_Chunk0 == "dr:ls" )
            {
                KONS_dirPtrClone = opendir(USER_CurrentDirectory.c_str());
                KONS_PrintDirectory = USER_CurrentDirectory;
            }
            else if(USER_CommandLine_Chunk0 == "dir:peek" || USER_CommandLine_Chunk0 == "dr:pk")
            {
                KONS_dirPtrClone = opendir((USER_CurrentDirectory + "/" + USER_CommandLine_Chunk1).c_str());
                KONS_PrintDirectory = USER_CurrentDirectory + "/" + USER_CommandLine_Chunk1;
            }

            struct dirent* dirEntPtr; //this will be a pointer pointing to a file

            if(KONS_dirPtrClone != nullptr)
            {

                struct stat fileInfos; //we will use this to collect file infos
                

                cout << KONS_ConsoleName_Report << KONS_PrintDirectory << endl;

                cout << "|                                                        File Name |     Type |     size |        Time Created |       Time Modified |" << endl;
                cout << "|------------------------------------------------------------------|----------|----------|---------------------|---------------------|" << endl;
                while( (dirEntPtr = readdir(KONS_dirPtrClone)) != nullptr) //readdir will return a pointer to a file and dirEntPtr will catch it
                {
                    //we use this to get other infos of a file
                    stat((KONS_PrintDirectory + "/" + dirEntPtr->d_name).c_str(),&fileInfos);

                    //here we can get the dates
                    time_t stat_date_c_time = fileInfos.st_ctime;
                    time_t stat_date_m_time = fileInfos.st_mtime;
                    char stat_date_c_cstr[100];
                    char stat_date_m_cstr[100];
                    strftime(stat_date_c_cstr,sizeof(stat_date_c_cstr),"%Y-%m-%d %H:%M:%S",localtime(&stat_date_c_time));
                    strftime(stat_date_m_cstr,sizeof(stat_date_m_cstr),"%Y-%m-%d %H:%M:%S",localtime(&stat_date_m_time));

                    //here we can get the size
                    off_t stat_size = fileInfos.st_size;

                    //get name type
                    string stat_name = string(dirEntPtr->d_name);
                    string stat_type = "";
                      

                    //if it has a file type, not any weird directories at all
                    if(stat_name != "." && stat_name != ".." && stat_name.length() > 2)
                    {
                        int stat_dotPos = FOwO_string_FindCharPosWithDirection(stat_name,'.',1);

                        if(stat_dotPos > -1)
                        {
                            //does has a file extension
                            stat_type = FOwO_string_trim(stat_name,stat_dotPos+1,stat_name.length()-1);
                        }
                        else
                        {
                            stat_type = "";
                        }
                    }
                    else
                    {
                        stat_type = "";
                    }


                    if
                    (
                        (
                            (USER_CommandLine_Chunk0 == "dir:list" || USER_CommandLine_Chunk0 == "dr:ls" ) && (USER_CommandLine_Chunk1 == "" || stat_name.find(USER_CommandLine_Chunk1) != string::npos)
                        )
                        ||
                        (
                            (USER_CommandLine_Chunk0 == "dir:peek" || USER_CommandLine_Chunk0 == "dr:pk" ) && (USER_CommandLine_Chunk2 == "" || stat_name.find(USER_CommandLine_Chunk2) != string::npos)
                        )
                    )//if there are no more search arguments or it matches the search arguments
                    {
                        cout <<  "| " << setw(64) << left << stat_name;
                        cout << " | " << setw(8) << left << stat_type;
                        cout << " | " << setw(8) << right << stat_size;
                        cout << " | " << setw(10) << stat_date_c_cstr;
                        cout << " | "<< setw(10) << stat_date_m_cstr;
                        cout << " |" << endl;
                    }
                    
                }

                closedir(KONS_dirPtrClone);
            }
            else
            {
                cout << KONS_ConsoleName_Report << "no such directory" << endl;
            }
            
        }
        else if(USER_CommandLine_Chunk0 == "dir:where")
        {
            cout << KONS_ConsoleName_Report << "Current path : " << USER_CurrentDirectory << endl;
        }
        else if(USER_CommandLine_Chunk0 == "file:make")
        {
            if(USER_CommandLine_Chunk1 != "")
            {
                //do we have a file like that already ?

                fstream ReaderOwO;
                ReaderOwO.open(USER_CurrentDirectory + "/" + USER_CommandLine_Chunk1,ios::in);

                if(ReaderOwO)
                {
                    //we already have a file like this, don't need to make a new file
                }
                else
                {
                    //nope, time to make a new file
                    fstream WriterOwO;
                    WriterOwO.open(USER_CurrentDirectory + "/" + USER_CommandLine_Chunk1,ios::out);
                    WriterOwO.close();
                }
            }
        }
        else if(USER_CommandLine_Chunk0 == "file:copy")
        {
            if(USER_CommandLine_Chunk1 == "" || USER_CommandLine_Chunk2 == "")
            {
                cout << KONS_ConsoleName_Failed << "what are the file names ?" << endl;
            }
            else if ( USER_CommandLine_Chunk1 == "/" || USER_CommandLine_Chunk2 == "/")
            {
                cout << KONS_ConsoleName_Failed << "these names are not accepted" << endl;
            }
            else if ( USER_CommandLine_Chunk1.find("//") != string::npos || USER_CommandLine_Chunk2.find("//") != string::npos )
            {
                cout << KONS_ConsoleName_Failed << "double slashes found, will not proceed" << endl;
            }
            else
            {
                string Path_src_abs = USER_CurrentDirectory;
                string Path_src_plt = USER_CommandLine_Chunk1;
                string Path_src_readhead;
                string Path_src_ready = "";

                string Path_des_abs = USER_CurrentDirectory;
                string Path_des_plt = USER_CommandLine_Chunk2;
                string Path_des_readhead;
                string Path_des_ready = "";

                while(Path_src_plt.length() > 0 && Path_src_ready == "")
                {
                    //get a tiny segment
                    //get the slash position
                    int slashPosition = FOwO_string_FindCharPos(Path_src_plt,'/');

                    //start trimming
                    if(slashPosition > -1) //if a slash can be found
                    {
                        Path_src_readhead = FOwO_string_trim(Path_src_plt,0,slashPosition-1);
                        Path_src_plt = FOwO_string_trim(Path_src_plt,slashPosition+1,Path_src_plt.length()-1);
                    }
                    else
                    {
                        //no more slash can be found
                        Path_src_readhead = Path_src_plt;
                        Path_src_plt = "";
                    }

                    //can we go there ?
                    //according to the function, if we can go there, then let's go there
                    //if no, stay there
                    KONS_dirPtrTest = kOwOn_action_gotoSingle(Path_src_abs, Path_src_readhead);
                    if( KONS_dirPtrTest != nullptr )
                    {
                        //it is a directory, ok
                        //current directory updating has been handled by the kOwOnsole Function
                    }
                    else if ( kOwOn_path_isFile(Path_src_abs + "/" + Path_src_readhead) == true)//no such directory, //could be a file
                    {
                        //it is an existing file, this is the one
                        Path_src_ready = Path_src_abs + "/" + Path_src_readhead;
                    }

                }

                while(Path_des_plt.length() > 0 && Path_des_ready == "")
                {
                    //get a tiny segment
                    //get the slash position
                    int slashPosition = FOwO_string_FindCharPos(Path_des_plt,'/');

                    //start trimming
                    if(slashPosition > -1) //if a slash can be found
                    {
                        Path_des_readhead = FOwO_string_trim(Path_des_plt,0,slashPosition-1);
                        Path_des_plt = FOwO_string_trim(Path_des_plt,slashPosition+1,Path_des_plt.length()-1);
                    }
                    else
                    {
                        //no more slash can be found
                        Path_des_readhead = Path_des_plt;
                        Path_des_plt = "";
                    }

                    //can we go there ?
                    //according to the function, if we can go there, then let's go there
                    //if no, stay there
                    KONS_dirPtrTest = kOwOn_action_gotoSingle(Path_des_abs, Path_des_readhead);
                    if( KONS_dirPtrTest != nullptr )
                    {
                        //it is a directory, ok
                        //current directory updating has been handled by the kOwOnsole Function
                    }
                    else if ( kOwOn_path_isFile(Path_des_abs + "/" + Path_des_readhead) == true)//no such directory, //could be a file
                    {
                        //it is an existing file, this is the one
                        Path_des_ready = Path_des_abs + "/" + Path_des_readhead;
                    }
                    else if ( KONS_dirPtrTest == nullptr)//not a directory, not an exsisting file, then is an imaginary target file
                    {
                        Path_des_ready = Path_des_abs + "/" + Path_des_readhead;
                    }
                    
                }

                //because it is a directory, this ready part didn't get the ready address, now assign
                if( Path_src_ready == "" ){ Path_src_ready = Path_src_abs; }
                if( Path_des_ready == "" ){ Path_des_ready = Path_des_abs; }

                //now just to confirm that we got the right thing
                cout << KONS_ConsoleName_Report << "src : " << Path_src_ready << endl;
                cout << KONS_ConsoleName_Report << "des : " << Path_des_ready << endl;



                bool okCanProceed_src = false;
                bool okCanProceed_des = false;



                if(kOwOn_path_isFile(Path_src_ready) == true)
                {
                    okCanProceed_src = true;
                }
                else
                {
                    okCanProceed_src = false;
                    //don't have a file to copy, halt
                    cout << KONS_ConsoleName_Failed << "given directory is not a file to copy, will not proceed : " << Path_src_ready << endl;
                }


                if(kOwOn_path_isDirectory(Path_des_ready) == true)
                {
                    //is a directory, attach
                    Path_des_ready = Path_des_ready + "/" + Path_src_readhead;
                }



                //is there a file like this already exists ? check
                bool FLAG_des_repeat_exist_done = false;

                while(FLAG_des_repeat_exist_done == false)
                {
                    fstream ReaderOwO;
                    ReaderOwO.open(Path_des_ready);
                    if(ReaderOwO)
                    {
                        //yup, there is a file like this, confirm overwrite or make a new file with a new name ?
                        cout << KONS_ConsoleName_Report << "requested destination file already exists, cancle copy (*) ? new name (1) ? overwrite (2) ?" << endl;
                        
                        int USER_TempInput;
                        cout << KONS_ConsoleName_Prompt << "insert choice : ";
                        cin >> USER_TempInput;

                        if(USER_TempInput == 1)
                        {
                            //new name
                            //get slashPosition
                            int slashPosition = FOwO_string_FindCharPosWithDirection(Path_des_ready,'/',1);
                            string slashLSide = FOwO_string_trim(Path_des_ready,0,slashPosition-1);
                            //string slashRSide = FOwO_string_trim(Path_des_ready,slashPosition+1,Path_des_ready.length()-1);
                            string USER_newfileName = "";

                            cout << KONS_ConsoleName_Prompt << "new file name : ";
                            cin >> USER_newfileName;

                            Path_des_ready = slashLSide + "/" + USER_newfileName;
                            
                            cout << KONS_ConsoleName_Report << "here are the 2 updated paths :" << endl;
                            cout << KONS_ConsoleName_Report << "src : " << Path_src_ready << endl;
                            cout << KONS_ConsoleName_Report << "des : " << Path_des_ready << endl;
                        }
                        else if(USER_TempInput == 2)
                        {
                            //overwrite
                            FLAG_des_repeat_exist_done = true;
                            okCanProceed_des = true;
                        }
                        else
                        {
                            //cancel copy
                            FLAG_des_repeat_exist_done = true;
                            okCanProceed_des = false;
                        } 
                    }
                    else
                    {
                        FLAG_des_repeat_exist_done = true;
                        okCanProceed_des = true;
                    }
                    ReaderOwO.close();
                }


                //now start copying
                if( okCanProceed_src == true && okCanProceed_des == true )
                {
                    cout << KONS_ConsoleName_Report << "copied file :" << endl;
                    cout << KONS_ConsoleName_Report << "src : " << Path_src_ready << endl;
                    cout << KONS_ConsoleName_Report << "des : " << Path_des_ready << endl;

                    fstream ReaderOwO;
                    fstream WriterOwO;

                    ReaderOwO.open(Path_src_ready,ios::in);
                    WriterOwO.open(Path_des_ready,ios::out);


                    if(ReaderOwO && WriterOwO)
                    {
                        ReaderOwO.seekg(0L,ios::beg);
                        WriterOwO.seekp(0L,ios::beg);
                        string ReaderGetLine = "";

                        while(getline(ReaderOwO,ReaderGetLine))
                        {
                            WriterOwO << ReaderGetLine << endl;
                        }
                    }

                    ReaderOwO.close();
                    WriterOwO.close();
                }
                
            }
        }//end command choice
        else if(USER_CommandLine_Chunk0 == "file:print")
        {
            if(USER_CommandLine_Chunk1 == "")
            {
                cout << KONS_ConsoleName_Failed << "print what ?" << endl;
            }
            else
            {
                string KONS_PrintDirectory = USER_CurrentDirectory;
                string Plate = USER_CommandLine_Chunk1;
                string ReadHead = "";

                size_t DoubleSlashPos = Plate.find("//");
                if(DoubleSlashPos != string::npos)
                {
                    //given target relative address chain has double slashes
                    //reject
                    cout << "\033[1;32mkQAQnsole : given relative address has double slashes, will not proceed\033[0m" << endl;
                }
                else if (Plate == "/")
                {
                    cout << "\033[1;32mkO_Onsole : bruh ...\033[0m" << endl;
                }
                else
                {
                    //we are safe, traverse

                    //remove heading slahes (if there is one)
                    if(FOwO_string_atPosIsChar(Plate,0,'/') && Plate.length() > 1){ Plate = FOwO_string_trim(Plate,1,Plate.length()-1); }
                    //remove tailing slashes (if there is one)
                    if(FOwO_string_atPosIsChar(Plate,Plate.length()-1,'/') && Plate.length() > 1){Plate = FOwO_string_trim(Plate,0,Plate.length()-1);}

                    while(Plate != "")
                    {
                        //get the slash position
                        int slashPosition = FOwO_string_FindCharPos(Plate,'/');

                        //start trimming
                        if(slashPosition > -1) //if a slash can be found
                        {
                            ReadHead = FOwO_string_trim(Plate,0,slashPosition-1);
                            Plate = FOwO_string_trim(Plate,slashPosition+1,Plate.length()-1);
                        }
                        else
                        {
                            //no more slash can be found
                            ReadHead = Plate;
                            Plate = "";
                        }


                        //can we go there ? if yes, let's go, if no, ignore, continue
                        KONS_dirPtrTest = kOwOn_action_gotoSingle(KONS_PrintDirectory,ReadHead);
                        if( KONS_dirPtrTest != nullptr )//is a directory
                        {
                            //lets go
                            //KONS_PrintDirectory has beenn updated by function
                        }
                        else if( kOwOn_path_isFile(KONS_PrintDirectory + "/" + ReadHead) ) //we have hit a file?
                        {
                            //this is the file we want to print:
                            KONS_PrintDirectory = KONS_PrintDirectory + "/" + ReadHead;
                        }
                        else
                        {
                            cout << "\033[1;31mkOoOnsole : no such directory or file : \033[0m" << ReadHead << endl;
                            //KONS_dirPtrSure will remain the same
                        }


                    }

                    if( kOwOn_path_isFile(KONS_PrintDirectory) )
                    {


                        //need to make sure spacing string
                        if((USER_CommandLine_Chunk2 == "ascii::dec" || USER_CommandLine_Chunk2 == "ascii::hex") && USER_CommandLine_Chunk3 == "")
                        {
                            cout << KONS_ConsoleName_Prompt << "just incase, no spacing string detected, how many spaces you want in the space string" << endl;

                            int USER_Input_int = 0;
                            string USER_Input_string = "";
                            stringstream Bwuffer;
                            Bwuffer.clear();

                            cin >> USER_Input_string;

                            if(FOwO_string_isNumber(USER_Input_string))
                            {
                                Bwuffer << USER_Input_string;
                                Bwuffer >> USER_Input_int;
                            }
                            else
                            {
                                USER_Input_int = -1;
                            }
                            
                            if(USER_Input_int < 0)
                            {
                                cout << "\033[1;31mkUwUnsole : welp... since you are being naughty, I'll just stick with the default : 1 space\033[0m" << endl;
                                USER_CommandLine_Chunk3 = " ";
                            }
                            else
                            {
                                USER_CommandLine_Chunk3 = "";
                                for(int i = 0 ; i < USER_Input_int ; i++)
                                {
                                    USER_CommandLine_Chunk3 = USER_CommandLine_Chunk3 + " ";
                                }
                            }
                        }


                        cout << KONS_ConsoleName_Report << "now printing : " << KONS_PrintDirectory << endl << endl;

                        fstream ReaderOwO;
                        ReaderOwO.open( KONS_PrintDirectory,ios::in );
                        if(ReaderOwO)
                        {
                            ReaderOwO.seekg(0L,ios::beg);
                            string lineCatch = "";

                            while(getline(ReaderOwO,lineCatch))
                            {
                                if(USER_CommandLine_Chunk2 == "")
                                {
                                    cout << lineCatch << endl;
                                }
                                else if(USER_CommandLine_Chunk2 == "ascii::dec")
                                {
                                    for(int i = 0 ; i < lineCatch.length() ; i++)
                                    {
                                       cout << setfill('0') << dec << (int)(lineCatch.at(i)) << USER_CommandLine_Chunk3 << setfill(' ') ;
                                    }
                                    cout << "13" << endl;
                                }
                                else if(USER_CommandLine_Chunk2 == "ascii::hex")
                                {
                                    for(int i = 0 ; i < lineCatch.length() ; i++)
                                    {
                                       cout << setfill('0')  << hex << (int)(lineCatch.at(i)) << USER_CommandLine_Chunk3 << dec << setfill(' ');
                                    }
                                    cout << "0D" << endl;
                                }

                                
                            }

                            ReaderOwO.close();
                        }
                    }
                }



                

            }
        }
        else if(USER_CommandLine_Chunk0 == "tool:rand")
        {
            //Chunk1 : iter
            //Chunk2 :: Num0
            //Chunk3 :: Num1

            if( FOwO_string_isNumber(USER_CommandLine_Chunk1) && FOwO_string_isNumber(USER_CommandLine_Chunk2) && FOwO_string_isNumber(USER_CommandLine_Chunk3))
            {
                //step 1 : read number

                stringstream Bwuffer;

                int lineCatch_c1;
                int lineCatch_c2;
                int lineCatch_c3;

                Bwuffer.clear();
                Bwuffer << USER_CommandLine_Chunk1;
                Bwuffer >> lineCatch_c1;
                Bwuffer.clear();
                Bwuffer << USER_CommandLine_Chunk2;
                Bwuffer >> lineCatch_c2;
                Bwuffer.clear();
                Bwuffer << USER_CommandLine_Chunk3;
                Bwuffer >> lineCatch_c3;
                Bwuffer.clear();

                //interpret and get ready for calculations

                int iter;
                int NumLarge;
                int NumSmall;

                if      (lineCatch_c2 < lineCatch_c3){NumSmall = lineCatch_c2 ; NumLarge = lineCatch_c3 ;}
                else if (lineCatch_c2 > lineCatch_c3){NumLarge = lineCatch_c2 ; NumSmall = lineCatch_c3 ;}
                else    {NumLarge = lineCatch_c2 ; NumSmall = lineCatch_c2;}

                if      (lineCatch_c1 < 1){iter = 1;}
                else    {iter = lineCatch_c1 ;}

                //give random
                srand((int)time(0));
                for(int i = 0 ; i < iter ; i++)
                {
                    cout << KONS_ConsoleName_Report << rand()%(NumLarge - NumSmall + 1) + NumSmall << endl;
                }

            }
        }
        else if(USER_CommandLine_Chunk0 == "tool:dice")
        {
            if(USER_CommandLine_Chunk1 != "")
            {
                //here we will treat Chunk2 as a list of int separated by commas
                //each int represents the dice

                string Plate = USER_CommandLine_Chunk1;
                string ReadHead = "";
                stringstream Bwuffer;

                int Dice_FullNumber;
                int Dice_RollNumber;
                int Dice_TotalFull = 0;
                int Dice_TotalRoll = 0;

                //remove any spaces and dots
                Plate = FOwO_string_removeSubString_Genocide(Plate," ");
                Plate = FOwO_string_removeSubString_Genocide(Plate,".");

                //remove heading and tailing commas
                if(FOwO_string_atPosIsChar(Plate,0,','))
                {
                    Plate = FOwO_string_trim(Plate,1,Plate.length()-1);
                }
                if(FOwO_string_atPosIsChar(Plate,Plate.length()-1,','))
                {
                    Plate.pop_back();
                }

                //if we have any double commas, reject
                if( Plate.find(",,") != string::npos )
                {
                    cout << KONS_ConsoleName_Failed << "given dice list has neighbouring commas, will not proceed" << endl;
                }
                else
                {
                    cout << KONS_ConsoleName_Report << endl;
                    cout << "| dice | roll |" << endl;
                    cout << "|------|------|" << endl;

                    srand((int)time(0));
                    while(Plate != "")
                    {
                        //get small segment
                        int ComaPosition = FOwO_string_FindCharPos(Plate,',');

                        if(ComaPosition < 0)
                        {
                            //no comma, bring in the whole thing
                            ReadHead = Plate;
                            Plate = "";
                        }
                        else
                        {
                            ReadHead = FOwO_string_trim(Plate,0,ComaPosition-1);
                            Plate = FOwO_string_trim(Plate,ComaPosition+1,Plate.length()-1);
                        }

                        if(FOwO_string_isNumber(ReadHead))//if ReadHead can be interpreted as a number
                        {
                            Bwuffer.clear();
                            Bwuffer << ReadHead;
                            Bwuffer >> Dice_FullNumber;
                            Bwuffer.clear();

                            Dice_RollNumber = rand()%Dice_FullNumber + 1;
                            Dice_TotalFull = Dice_TotalFull + Dice_FullNumber;
                            Dice_TotalRoll = Dice_TotalRoll + Dice_RollNumber;

                            cout << "| " << setw(4) << right << Dice_FullNumber << " | " << setw(4) << right << Dice_RollNumber << " |" << endl;
                        }
                    }
                    cout << "|------|------|" << endl;
                    cout << "| totl |      |" << endl;
                    cout << "|------|------|" << endl;
                    cout << "| " << setw(4) << right << Dice_TotalFull << " | " << setw(4) << right << Dice_TotalRoll << " |" << endl;
                }
            }
        }
        else if(USER_CommandLine_Chunk0 == "tool:calc")
        {
            stringstream Bwuffer;

            if(USER_CommandLine_Chunk1 == "+" || USER_CommandLine_Chunk1 == "*")
            {
                //Chunk2 is going to be a list of numbers separated by commas
                string Plate = USER_CommandLine_Chunk2;
                string ReadHead = "";

                long double ReadHeadFloat;
                long double Total;

                if(USER_CommandLine_Chunk1 == "+"){Total = 0;}
                else if(USER_CommandLine_Chunk1 == "*"){Total = 1;}

                //remove heading and tailing commas
                if(FOwO_string_atPosIsChar(Plate,0,','))
                {
                    Plate = FOwO_string_trim(Plate,1,Plate.length()-1);
                }
                if(FOwO_string_atPosIsChar(Plate,Plate.length()-1,','))
                {
                    Plate.pop_back();
                }

                //if we have any double commas, reject
                if( Plate.find(",,") != string::npos )
                {
                    cout << KONS_ConsoleName_Failed << "given number list has neighbouring commas, will not proceed" << endl;
                }
                else
                {
                    //while loop addition/multiplication
                    while(Plate != "")
                    {
                        //get small segment
                        int ComaPosition = FOwO_string_FindCharPos(Plate,',');

                        if(ComaPosition < 0)
                        {
                            //no comma, bring in the whole thing
                            ReadHead = Plate;
                            Plate = "";
                        }
                        else
                        {
                            ReadHead = FOwO_string_trim(Plate,0,ComaPosition-1);
                            Plate = FOwO_string_trim(Plate,ComaPosition+1,Plate.length()-1);
                        }

                        if(FOwO_string_isNumber(ReadHead))//if ReadHead can be interpreted as a number
                        {
                            Bwuffer.clear();
                            Bwuffer << ReadHead;
                            Bwuffer >> ReadHeadFloat;
                            Bwuffer.clear();

                            if(USER_CommandLine_Chunk1 == "+"){Total = Total + ReadHeadFloat;}
                            if(USER_CommandLine_Chunk1 == "*"){Total = Total * ReadHeadFloat;}
                        }
                    }

                    cout << KONS_ConsoleName_Report << Total << endl;
                }
            }
            else if(
                USER_CommandLine_Chunk2 == "-" || 
                USER_CommandLine_Chunk2 == "/" ||
                USER_CommandLine_Chunk2 == "^" ||
                USER_CommandLine_Chunk2 == "rt" ||
                USER_CommandLine_Chunk2 == "!"
            )
            {
                long double Num0;
                long double Num1;

                if(FOwO_string_isNumber(USER_CommandLine_Chunk1) && FOwO_string_isNumber(USER_CommandLine_Chunk3))
                {
                    Bwuffer.clear();
                    Bwuffer << USER_CommandLine_Chunk1;
                    Bwuffer >> Num0;
                    Bwuffer.clear();
                    Bwuffer << USER_CommandLine_Chunk3;
                    Bwuffer >> Num1;
                    Bwuffer.clear();

                    long double Total;

                    if(USER_CommandLine_Chunk2 == "-")
                    {
                        Total = Num0 - Num1;
                    }
                    else if(USER_CommandLine_Chunk2 == "/")
                    {
                        Total = Num0 / Num1;
                    }
                    else if(USER_CommandLine_Chunk2 == "^")
                    {
                        Total = pow(Num0,Num1);
                    }
                    else if(USER_CommandLine_Chunk2 == "rt")
                    {
                        Total = pow(Num1,1/Num0);
                    }
                    else if(USER_CommandLine_Chunk2 == "!")
                    {
                        Total = 1;

                        for(int i = 1;i <= Num0;i++)
                        {
                            Total = Total * i;
                        }
                    }

                    cout << KONS_ConsoleName_Report << Total << endl;
                }
                else
                {
                    cout << KONS_ConsoleName_Failed << "unable to interpret number or operator" << endl;
                }
            }
            
        }

        cout << endl;
    }

    return 0;
}



