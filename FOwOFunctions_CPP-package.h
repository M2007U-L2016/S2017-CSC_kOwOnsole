#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;





int FOwO_cout_MakeSpace(int Iter, string ExtraTitle)
{
    for(int i = 0; i < Iter ; i++)
    {
        cout << endl;
    }

    cout << ExtraTitle << endl;
    return Iter;
}




int FOwO_cout_Debug(bool DebugSwitch, string Message, bool NextLine)
{
    if(DebugSwitch == true)
    {
        if(NextLine == false)
        {
            cout << Message;
        }
        else
        {
            cout << Message << endl;
        }  
    }

    return 0;
}




//FUNCTION    : FOwO_string_toUpper
//DESC        : to turn any lowercasee letter to an uppercase letter in a string (I tried Toupper, but it is not working, so I get mad and made one myself)
//INPUT ARGS  : InString (the string to be converted, passed by value)
//OUTPUT ARGS : 
//IN/OUT ARGS :
//RETURN      : string, the resulting Uppercase string
string FOwO_string_toUpper(string InString)
{
    string boxString = "";

    for(int i = 0 ; i < InString.length() ; i++)
    {
        char KarPass0 = InString.at(i);
        char KarPass1;

        if(97 <= (int)KarPass0 && (int)KarPass0 <= 122)
        {
            KarPass1 = (char)((int)KarPass0 - 32);
        }
        else
        {
            KarPass1 = KarPass0;
        }

        boxString += KarPass1;
    }

    return boxString;
}





//FUNCTION    : FOwO_string_toLower
//DESC        : to do the opposite of FOwO_string_toUpper, from Upper to Lower
//INPUT ARGS  : InString (the string to be converted, passed by value)
//OUTPUT ARGS : 
//IN/OUT ARGS :
//RETURN      : string, the resulting Lowercase string
string FOwO_string_toLower(string InString)
{
    string boxString = "";

    for(int i = 0 ; i < InString.length() ; i++)
    {
        char KarPass0 = InString.at(i);
        char KarPass1;

        if(65 <= (int)KarPass0 && (int)KarPass0 <= 90)
        {
            KarPass1 = (char)((int)KarPass0 + 32);
        }
        else
        {
            KarPass1 = KarPass0;
        }

        boxString += KarPass1;
    }

    return boxString;
}





//find the Target charracter in the Given String, then return the position of that charracter
//if there is no such charracter in the string, return -1
int FOwO_string_FindCharPos(string Given, char Target)
{
    bool Found = false;
    int ReturnPos = -1;

    for(int i = 0 ; i < Given.length(); i++)
    {
        if((int)(Given.at(i)) == (int)(Target) && Found == false )
        {
            ReturnPos = i;
            Found = true;
        }
    }

    return ReturnPos;
}




//check if the given string, at the given position is the requested char
//is yes, return true, else false
bool FOwO_string_atPosIsChar(string TestSubject, int TargetPos, char TargetChar)
{
    bool ReturnResult;

    if( (int)(TestSubject.at(TargetPos)) == (int)(TargetChar) )
    {
        ReturnResult = true;
    }
    else
    {
        ReturnResult = false;
    }

    return ReturnResult;
}





int FOwO_string_FindCharPosWithDirection(string Given, char Target, int Direction)
{
    bool Found = false;
    int ReturnPos = -1;

    if(Direction == 0)//start from left
    {
        for(int i = 0 ; i < Given.length(); i++)
        {
            if(FOwO_string_atPosIsChar(Given,i,Target) && Found == false )
            {
                ReturnPos = i;
                Found = true;
            }
        }
    }
    else if(Direction == 1)//start from the right
    {
        for(int i = Given.length()-1 ; i > -1 ; i--)
        {
            if(FOwO_string_atPosIsChar(Given,i,Target) && Found == false )
            {
                ReturnPos = i;
                Found = true;
            }
        }
    }
    

    return ReturnPos;
}










//FUNCTION    : FOwO_string_trim
//DESC        : to trim a string, with a starting position and an ending position, if the ending position is way beyond than the length of the string, then the endding position will be ignored
//INPUT ARGS  : 
    //string InString, The string will be trimmed, passed by value
    //int start, the starting position of the trim, first charracter is 0
    //int end, the end position of the trim
//OUTPUT ARGS : 
//IN/OUT ARGS :
//RETURN      : string, the resulting trimmed string
string FOwO_string_trim(string InString, int start, int end)
{
    string resultStr = "";

    for(int i = start ; i < InString.length() && i <= end ; i++)
    {
            resultStr += InString.at(i);
    }

    return resultStr;
}





//FUNCTION    : FOwO_char_toString
//DESC        : to turn a single charracter to a string with that charracter
//INPUT ARGS  : char Kar, the charracter to be converted, passed by value
//OUTPUT ARGS : 
//IN/OUT ARGS :
//RETURN      : string, the resulting string which contains the charracter
string FOwO_char_toString(char Kar)
{
    string boxStr = "";
    boxStr += Kar;
    return boxStr;
}













//FUNCTION    : FOwO_string_isInArray
//DESC        : to check if a given string is in an array, if yes, return 1, else, 0
//INPUT ARGS  : string TestSubject, string StringArray[], int Arraylength
//OUTPUT ARGS : 
//IN/OUT ARGS :
//RETURN      : int returnResult
int FOwO_string_isInArray(string TestSubject, string StringArray[], int Arraylength )
{
    int returnResult = 0;

    for(int i = 0 ; i < Arraylength ; i++)
    {
        if(TestSubject == StringArray[i])
        {
            returnResult = 1;
        }
    }

    return returnResult;

    //WARNING : 
    //"StringArray->length()" does not mean get the length of the array, 
    //StringArray here is a pointer to the first item, 
    //"StringArray->length()" means, get the first item in the array, then get the length of it
}




//FUNCTION    : FOwO_string_isNumber
//DESC        : to check if a string can be interpreted as a number, can be used along with stoi
//INPUT ARGS  : string TestSubject, the string to be tested, passed by value
//OUTPUT ARGS : 
//IN/OUT ARGS :
//RETURN      : int, a result to indicate if the given string can be a number,
    //0 : it cannot be interpreted as a number, string contains non-number charracters xor a charracter that is not a decimal point xor multiple decimal points has been detected 
    //1 : can be interpreted as a positive number
    //2 : can be interpreted as a negative number
    //8 : it is an empty string
int FOwO_string_isNumber(string TestSubject)
{

    //-1: don't know yet 
    //0 : not a number
    //1 : is a positive number
    //2 : is a negative number
    //8 : is an empty string

    bool FLAG_soFarSoGood = true;
    bool FLAG_IsNeg = false;
    int FLAG_hasDecimal = 0;

    int returnResult = -1;
    

    
    

    for(int i = 0 ; i < TestSubject.length() ; i++)
    {
        int TestSubjectKarAscii = (int)(TestSubject.at(i));

        if(i == 0)//is it negative ?
        {
            if ((int)TestSubject.at(0) == 45) //minusSign.ascii = 45
            {
                FLAG_IsNeg = true;
            }
            else if (48 <= TestSubjectKarAscii && TestSubjectKarAscii <=57)//if it is from 0..9
            {
                FLAG_IsNeg = false;
            }
            else
            {
                //it is not an accepted charracter
                FLAG_soFarSoGood = false;
            }
        }
        else //now normal reading
        {
            if(48 <= TestSubjectKarAscii && TestSubjectKarAscii <=57) //if it is from 0..9
            {
                //all good, let returnResult stay
            }
            else if(TestSubjectKarAscii == 46) //it is a period dot
            {
                //first appearance ?
                if(FLAG_hasDecimal == 0)
                {
                    //we are good,
                    FLAG_hasDecimal = 1;
                }
                else //the period appeared again
                {
                    //not a valid decimal number
                    FLAG_soFarSoGood = false;
                }
            }
            else //it reads something else
            {
                FLAG_soFarSoGood = false;
            }
        }
    }

    

    if(FLAG_soFarSoGood == true)
    {
        if (TestSubject.length() == 0){returnResult = 8;}//given string is empty
        else if(FLAG_IsNeg == true){returnResult = 2;} //is negative
        else if(FLAG_IsNeg == false){returnResult = 1;} //is positive
    }
    else
    {
        returnResult = 0;// not a valid number
    }

    return returnResult;
}





//FUNCTION    : FOwO_string_isHexaDc
//DESC        : to check if a string can be interpreted as a base 16 number, 
    //it will return 1 if the given string can be interpreted as a hexadecimal number, 
    //else, 0
//INPUT ARGS  : string TestSubject, the string to be tested, passed by value
//OUTPUT ARGS : 
//IN/OUT ARGS :
//RETURN      : ReturnResult
int FOwO_string_isHexaDc(string TestSubject)
{
    string box1 = FOwO_string_toUpper(TestSubject);
    string OKchars[16] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    int box2 = 404;

    int ReturnResult = 1;
    for(int i = 0;i<TestSubject.length();i++)
    {
        if(FOwO_string_isInArray(FOwO_char_toString(box1.at(i)),OKchars,16) == 0)
        {
            ReturnResult = 0;
        }
    }

    return ReturnResult;
}




//if the string is entirely tabs or whitespace or newline or empty, then return 1, else 0
int FOwO_string_isNaughtyEmpty(string TestSubject)
{
    int ReturnResult = 1; //assume it is empty first

    if(TestSubject == "")
    {
        //duh
        ReturnResult = 1;
    }
    else
    {
        int Arrow = 0;
        while(Arrow < TestSubject.length() && ReturnResult == 1)
        {
            //this time, is it a space or a tab ?
            if(FOwO_string_atPosIsChar(TestSubject,Arrow,' ') || FOwO_string_atPosIsChar(TestSubject,Arrow,'\t') || FOwO_string_atPosIsChar(TestSubject,Arrow,'\n'))
            {
                //yes, we are still safe, keep going
                ReturnResult = 1;
                Arrow++;
            }
            else
            {
                //nope, stop, we hit rock bottom
                ReturnResult = 0;
            }
        }
    }

    return ReturnResult;

}



//FUNCTION    : FOwO_string_removeSubstring_Genocide
//DESC        : to remove a "target" substring from the given string "input", both parameters are passed value.
//INPUT ARGS  : string input, string target
//OUTPUT ARGS : 
//IN/OUT ARGS :
//RETURN      : the resulting string without the targeted substring.
string FOwO_string_removeSubString_Genocide(string input, string target)
{
    string ResultString;

    if(input.length() > target.length())
    {
        //safe strings       //potential target strings, say "apple" // queue
        //d7u5heappl         app              6<---                  5uf7dhejapple48r

        string PlateSafe = "";
        string PlatePotn = "";
        int PlatePotnIndex = -1;
        string PlateQueue = input;

        while(PlateQueue.length() != 0)
        {
            //move first char to potential
            PlatePotn = PlatePotn + PlateQueue.at(0);
            PlateQueue.erase(0,1);

            //cout << "Safe : " << PlateSafe << endl << "Potn : " << PlatePotn << endl << "Queu : " << PlateQueue << endl << endl;

            PlatePotnIndex++; //look at the matching index
            if(target.at(PlatePotnIndex) == PlatePotn.at(PlatePotnIndex))
            {
                //might match up
                if(PlatePotn == target)
                {
                    //gotcha
                    PlatePotn = "";
                    PlatePotnIndex = -1;
                }
                else
                {
                    //wait
                }
            }
            else
            {
                //combo break
                //dump
                PlateSafe = PlateSafe + PlatePotn;
                PlatePotn = "";
                PlatePotnIndex = -1;
            }
        }

        ResultString = PlateSafe + PlatePotn + PlateQueue;
    }
    else
    {
        ResultString = input;
    }

    return ResultString;
}






//FUNCTION    : FOwO_string_forcePrintAscii
//DESC        : to print every charracter in a string as ascii numbers, except the \0 charracter
//INPUT ARGS  : string input
//OUTPUT ARGS : 
//IN/OUT ARGS :
//RETURN      : none
void FOwO_string_forcePrintAscii(string input)
{
    for(int i = 0; i<input.length(); i++)
    {
        cout << "-(" << (int)(input.at(i)) << ")-";
    }
    cout << endl;
}





//FUNCTION    : FOwO_bool_ToInt
//DESC        : It will return a user set int, based on the given bool. If bool is false, return int ResultIfFalse, else if bool is true, the return int ResultIfTrue, else, i.e. bool is not initiallized, return int ResultIfNull
//INPUT ARGS  : bool Given, int ResultIfFalse, int ResultIfTrue, int ResultIfFalse
//OUTPUT ARGS :
//IN/OUT ARGS :
//RETURN      : int ReturnValue
int FOwO_bool_toInt(bool Given, int ResultIfFalse, int ResultIfTrue, int ResultIfNull)
{
    int ReturnValue;

    if(Given == false)
    {
        ReturnValue = ResultIfFalse;
    }
    else if(Given == true)
    {
        ReturnValue = ResultIfTrue;
    }
    else
    {
        ReturnValue = ResultIfNull;
    }

    return ReturnValue;
}





//FUNCTION    : FOwO_Int_toBool
//DESC        : to convertan int, and fuction will return true or false based on the given input and user set condition
//INPUT ARGS  : int Given (the bool to be tested), int IfThisThenFalse (if Given is this, return false), int IfThisThenTrue (if Given is this, then return true)
//OUTPUT ARGS :
//IN/OUT ARGS :
//RETURN      : bool, the converted result
bool FOwO_Int_toBool(int Given, int IfThisThenFalse, int IfThisThenTrue)
{
    bool ReturnValue;

    if(Given == IfThisThenFalse)
    {
        ReturnValue = false;
    }
    else if(Given == IfThisThenTrue)
    {
        ReturnValue = true;
    }
    //else, let it be null

    return ReturnValue;
}





//FUNCTION    : **** unfinished draft function ****
//DESC        :
//INPUT ARGS  :
//OUTPUT ARGS :
//IN/OUT ARGS :
//RETURN      :
int FOwO_String_Base16IntToBase10Int(string Given)
{
    int box = 0;
    return 0;



}




string FOwO_String_BaseToBase(string Given, int InBase, int OutBase)
{
    stringstream Bwuffer;
    Bwuffer.clear();
    string ReturnString = "";

    bool ReadSuccess = false;

    if(InBase == 10 && FOwO_string_isNumber(Given))
    {
        Bwuffer << dec << Given;
        ReadSuccess = true;
    }
    else if(InBase == 16 && FOwO_string_isHexaDc(Given))
    {
        Bwuffer << hex << Given;
        ReadSuccess = true;
    }

    if(ReadSuccess == true)
    {
        if(OutBase == 10)
        {
            Bwuffer >> dec >> ReturnString;
        }
        else if (OutBase == 16)
        {
            Bwuffer >> hex >> ReturnString;
        }
    }

    return ReturnString;

}





//FUNCTION    : **** unfinished draft function ****
//DESC        :
//INPUT ARGS  :
//OUTPUT ARGS :
//IN/OUT ARGS :
//RETURN      :
int FOwO_String_StringToAscii10(string Given, int AsciiSize)
{
    //AsciiSize is 128 by default
    int box = 0;

    for(int i = 0;i<Given.length();i++)
    {
        box = box*AsciiSize + (int)(Given.at(i));
    }

    return box;
}



//chop string, based on the given point, remove the left part or the rght part of the string
//include : to cut away the Target Charracter as well or not ?
//LeftOrRight : cut away the left part or right part
string FOwO_String_Chop(string Given, char CutChar, int include, int LeftOrRight)
{
    int CutPos = FOwO_string_FindCharPos(Given,CutChar);
    string ReturnString = "";

    if(CutPos != -1)
    {
        if(LeftOrRight == 0)//remove Left, i.e. Maintain Right
        {
            if(include == 0)
            {
                ReturnString = FOwO_string_trim(Given,CutPos + 0,Given.length());
            }
            else if(include == 1)
            {
                ReturnString = FOwO_string_trim(Given,CutPos + 1,Given.length());
            }
            else
            {
                ReturnString = "QAQ nope";
            }
        }
        else if(LeftOrRight == 1)//remove Right, i.e. Maintain Left
        {
            if(include == 0)
            {
                ReturnString = FOwO_string_trim(Given,0,CutPos);
            }
            else if(include == 1)
            {
                ReturnString = FOwO_string_trim(Given,0,CutPos-1);
            }
            else
            {
                ReturnString = "QAQ nope";
            }
        }
        else
        {
            ReturnString = "QAQ nope";
        }
    }
    else
    {
        ReturnString = Given;
    }

    

    return ReturnString;
}






//count how many islands, i.e. word count
//output a string without leading spaces and tailing spaces
int FOwO_String_IslandCount(string Given, string& OutString)
{
    int IslandQty = -1;
    string Plate = Given;
    bool IsEmpty_CannotProcess = false;

    //check if the string is naughtyly empty, meaning only whitespace, tabs, newline only
    if(FOwO_string_isNaughtyEmpty(Given) == 0)
    {
        //ok, at least we have something to deal with...

        //trim away leading spaces
        while
        (
            (
                FOwO_string_atPosIsChar(Plate,0,' ') ||
                FOwO_string_atPosIsChar(Plate,0,'\t') ||
                FOwO_string_atPosIsChar(Plate,0,'\n')
            )
            &&
            (
                Plate.length() > 1
            )
        )
        {
            Plate = FOwO_string_trim(Plate,1,Plate.length()-1);
            //cout << "debug : cut head : \"" << Plate << "\"" << endl;
        }

        //trim away tailing spaces
        while
        (
            (
                FOwO_string_atPosIsChar(Plate,Plate.length()-1,' ') ||
                FOwO_string_atPosIsChar(Plate,Plate.length()-1,'\t') ||
                FOwO_string_atPosIsChar(Plate,Plate.length()-1,'\n')
            )
            &&
            (
                Plate.length() > 1
            )
        )
        {
            Plate.pop_back();
            //cout << "debug : cut tail : \"" << Plate << "\"" << endl;
        }

        //now we can start counting islands
        //Initiallize Arrow into the first charracter, which is a land already
        int Arrow = 0;
        bool IWasOnLand = true;
        IslandQty = 1;

        while(Arrow < Plate.length())
        {
            if(IWasOnLand == true)
            {
                if //I Hit Sea
                (
                    FOwO_string_atPosIsChar(Plate,Arrow,' ') ||
                    FOwO_string_atPosIsChar(Plate,Arrow,'\t') ||
                    FOwO_string_atPosIsChar(Plate,Arrow,'\n')
                )
                {
                    //Just went into sea
                    IWasOnLand = false;
                }
                else
                {
                    //I am still on Land
                    //then do nothing
                }
            }
            else //IWasOnSea
            {
                if //I Hit Sea
                (
                    FOwO_string_atPosIsChar(Plate,Arrow,' ') ||
                    FOwO_string_atPosIsChar(Plate,Arrow,'\t') ||
                    FOwO_string_atPosIsChar(Plate,Arrow,'\n')
                )
                {
                    //I am still on Sea
                }
                else
                {
                    //I Hit Land~, Island + 1
                    IWasOnLand = true;
                    IslandQty++;
                }
            }

            Arrow++;
        }

        OutString = Plate;


    }
    else
    {
        //duh... like no words here, so yeah, 0
        IslandQty = 0;
    }

    return IslandQty;
}