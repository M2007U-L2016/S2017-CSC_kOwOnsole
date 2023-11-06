#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>

#include <dirent.h>
#include <sys/stat.h>
#include "FOwOFunctions_CPP-package.h"

using namespace std;



//if given path is a directory, then return true
bool kOwOn_path_isDirectory(string GivenPath)
{
    bool ReturnResult;

    struct stat catchStat;

    if( stat(GivenPath.c_str(),&catchStat) == 0 ) //if function stat() is able to put something into catchStat from the given path and retrn 0, then procceed
    {
        ReturnResult = S_ISDIR(catchStat.st_mode);
    }
    else
    {
        ReturnResult = false;
    }

    return ReturnResult;
}

//if given path is a file, then return true
bool kOwOn_path_isFile(string GivenPath)
{
    bool ReturnResult;

    struct stat catchStat;

    if( stat(GivenPath.c_str(),&catchStat) == 0 ) //if function stat() is able to put something into catchStat from the given path and retrn 0, then procceed
    {
        ReturnResult = S_ISREG(catchStat.st_mode);
    }
    else
    {
        ReturnResult = false;
    }

    return ReturnResult;
}







//based on the current pwd, and a single target pwd (no chains of slahes or any crazy . and ..s)
//if the directory exsist, goto that directory and return a DIR of that directory, and change the current pwd to the new directory,
//if the directory doesn't exsist, then do nothing
DIR* kOwOn_action_gotoSingle(string& current_pwd, string target_pwd)
{

    //slash found, reject
    if( FOwO_string_FindCharPosWithDirection(target_pwd,'/',0) > -1 || FOwO_string_atPosIsChar(current_pwd,current_pwd.length()-1,'/'))
    {
        //here we will assume that current_pwd don't have a slash at the end and target_pwd don't have any slashes.  
        return nullptr;
    }
    else
    {
        DIR* dir_try;
        DIR* dir_sure;
        
        if(target_pwd == ".")
        {
            //same level
            dir_try = opendir(current_pwd.c_str());
            if(dir_try != nullptr){
                dir_sure = dir_try;
                current_pwd = current_pwd;
            }else{
                dir_sure = nullptr;
            }
            
        }
        else if (target_pwd == "..")
        {
            //go one level up
            string Plate = current_pwd;
            int slashPosition = FOwO_string_FindCharPosWithDirection(Plate,'/',1); //get slash position  
            Plate = FOwO_string_trim(Plate,0,slashPosition-1); //trim the pwd
            

            dir_try = opendir(Plate.c_str());
            if(dir_try != nullptr){
                dir_sure = dir_try;
                current_pwd = Plate;
            }else{
                dir_sure = nullptr;
                //currentPwd stays the same;
            }  
        }
        else //a normal file name
        {
            //append target name to current_pwd
            string Plate = current_pwd;
            Plate = Plate +  "/" + target_pwd;
            

            dir_try = opendir(Plate.c_str());
            if(dir_try != nullptr){
                dir_sure = dir_try;
                current_pwd = Plate;
            }else{
                dir_sure = nullptr;
                //currentPwd stays the same;
                //this directory does not exist, but could be a file
            }
        }
        return dir_sure;
    }
}