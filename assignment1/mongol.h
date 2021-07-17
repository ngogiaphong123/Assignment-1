//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);// DONE
string findRoute(const string input3);
string decodeVfunction(const string A, const string B); //DONE
string findBetrayals(const string input5[], const int N5); // DONE
int attack(const string input6[]); // DONE 
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////
struct infOfPerson{
    char ten;
    int diem;
};
string reverseStringa(string& str)
{
    string tempString = str;
    int indexPos = 0;
    for (int x = tempString.length() - 1; x >= 0; x--)
    {
        str[indexPos] = tempString[x];
        indexPos++;
    }
    return str;
}
string thdString(string str)
{
    string result="";
    for(size_t i = 0 ;i<str.length();i++)
    {
        if(i%3!=0)
        {
            result+=str[i];
        }
    }
    for(size_t i = 0 ;i<result.length();i++)
    {
        for(size_t j=i+1;j<result.length();j++)
        {
            if(result[i]>=result[j])
            {
                swap(result[i],result[j]);
            }
        }
    }
    return result;
}
string vuaString(string s)
{
    string temp = s;
    string result = s;
    if(s.length()%2==1)
    {
        reverseStringa(s);
        for(size_t i = 0 ; i < result.length();i++)
        {
            if(result[i]<s[i]) 
            {
                result[i]=s[i];
            }
        }
        return result;
    }
    else 
    {
        for(size_t i=0 ; i < s.length();i=i+2)
        {
            swap(s[i],s[i+1]);
        }
        reverseStringa(s);
        for(size_t i = 0 ; i < s.length();i++)
        {
            if(result[i]<s[i])
            {
                result[i]=s[i];
            }
        }
        return result;
    }
}
string binaryToDecmimal(string& str)
{
    string temp;
    for (size_t i = 0; i < str.length(); i++)
    {
        temp = str.substr(i, 2);
        if (temp == "00")
            str.replace(i, 2, "0");
        if (temp == "01")
            str.replace(i, 2, "1");
        if (temp == "10")
            str.replace(i, 2, "2");
        if (temp == "11")
            str.replace(i, 2, "3");
    }
    return str;
}
string decimalToString(string& str)
{
    int numZeroInString=0,
        numOneInString=0,
        numTwoInString=0,
        numThreeInString=0;
    string charZero[7]={"K","E","F","G","H","I","J"};
    string charOne[7]={"R","L","M","N","O","P","Q"};
    string charTwo[7]={"Y","#","T","U","V","W","X"};
    string charThree[7]={"D","@","A","S","Z","B","C"};
    for( size_t i = 0 ;i<str.length();i++)
    {
        if(str[i]=='0'){numZeroInString++;}
        if(str[i]=='1'){numOneInString++;}
        if(str[i]=='2'){numTwoInString++;}
        if(str[i]=='3'){numThreeInString++;}
        if(str[i]==' ' || i==str.length()-1 )
        {
            if(numZeroInString!=0 && i!=str.length()-1)
            {
                str.replace(i-numZeroInString,numZeroInString+1,charZero[numZeroInString%7]);
                numZeroInString=0;
                i=0;
            }
            if(numOneInString!=0 && i!=str.length()-1)
            {
                str.replace(i-numOneInString,numOneInString+1,charOne[numOneInString%7]);
                numOneInString=0;
                i=0;
            }
            if(numTwoInString!=0 && i!=str.length()-1)
            {
                str.replace(i-numTwoInString,numTwoInString+1,charTwo[numTwoInString%7]);
                numTwoInString=0;
                i=0;
            }
            if(numThreeInString!=0 && i!=str.length()-1)
            {
                str.replace(i-numThreeInString,numThreeInString+1,charThree[numThreeInString%7]);
                numThreeInString=0;
                i=0;
            }
            if(numZeroInString != 0&& i==str.length()-1)
            {
                str.replace(i+1-numZeroInString,numZeroInString,charZero[numZeroInString%7]);
                numZeroInString=0;
                i=0;
            }
            if(numOneInString !=0 && i==str.length()-1)
            {
                str.replace(i+1-numOneInString,numOneInString,charOne[numOneInString%7]);
                numOneInString=0;
                i=0;
            }
            if(numTwoInString !=0 && i==str.length()-1)
            {
                str.replace(i+1-numTwoInString,numTwoInString,charTwo[numTwoInString%7]);
                numTwoInString=0;
                i=0;
            }
            if(numThreeInString !=0 && i==str.length()-1)
            {
                str.replace(i+1-numThreeInString,numThreeInString,charThree[numThreeInString%7]);
                numThreeInString=0;
                i=0;
            }
        }
    }
    return str;
}
string speciallyChanging(string& str)
{
    string temp = "";
    int count = 0;
    if (str == "@" || str == "#") str.erase(0, 1);
    if (str[str.length() - 1] == '@' || str[str.length() - 1] == '#') str.erase(str.length() - 1, 1);
    for (size_t i = 0; i < str.length(); i++)
    {
        count = 0;
        if (str[i] == '#')
        {
            for (size_t j = i + 1; j < str.length(); j++)
                if (str[j] == '#' || str[j] == '@')
                {
                    count++;
                }
            if (count == 0)
            {
                if (str[str.length() - 1] == 'Z') str += "A";
                else
                {
                    str += str[str.length() - 1] + 1;
                }
            }
            else if (count != 0)
            {
                for (size_t j = i + 1; j < str.length(); j++)
                {
                    if (str[j] == '@' || str[j] == '#')
                    {
                        if (str[j - 1] == 'Z')
                        {
                            temp = "A";
                            str.insert(j, temp);
                            i = j;
                            break;
                        }
                        else
                        {
                            temp = str[j - 1] + 1;
                            str.insert(j, temp);
                            i = j;
                            break;
                        }
                    }
                }
            }
        }
        if(str[i] == '@')
        {
            string temp="";
            count = 0;
            for(size_t j=i+1; j < str.length(); j++)
            {
                if(str[j] != '@'&& str[j] != '#') 
                {
                    count=j;
                    temp+=str[j];
                }
                else break;
            }
            reverseStringa(temp);
            str.replace(i+1,count-i,temp);
            i=count;
        }
    }
    for(size_t i= 0 ; i < str.length(); i++)
    {
        if(str[i]=='@'||str[i]=='#')
        str.erase(i,1);
    }
    return str;
}
string dichChuoiBLan(string& s, int n, int B, char t)
{
	B =B%n;
	if (t == 't')
		for (int i = 0; i < B; i++)
			for (int j = 0; j < n - 1; j++)
				swap(s[j], s[j + 1]);
	else if(t=='p')
		for (int i = 0; i < B; i++)
			for (int j = n - 1; j > 0; j--)
				swap(s[j], s[j - 1]);
  return s;
}
char bienDoiKyTu(char a,int n)
{
    n = n%4;
    if (n==0) return a;
    if(a == 'U')
    {
        switch(n)
        {
            case 1 : 
            {
                return 'D';
                break;
            }
            case 2 : 
            {
                return 'L';
                break;
            }
            case 3 : 
            {
                return 'R';
                break;
            }
        }
    }
    else if(a == 'D')
    {
        switch(n)
        {
            case 1 : 
            {
                return 'L';
                break;
            }
            case 2 : 
            {
                return 'R';
                break;
            }
            case 3 : 
            {
                return 'U';
                break;
            }
        }
    }
    else if(a == 'L')
    {
        switch(n)
        {
            case 1 : 
            {
                return 'R';
                break;
            }
            case 2 : 
            {
                return 'U';
                break;
            }
            case 3 : 
            {
                return 'D';
                break;
            }
        }
    }
    else if(a == 'R')
    {
        switch(n)
        {
            case 1 : 
            {
                return 'U';
                break;
            }
            case 2 : 
            {
                return 'D';
                break;
            }
            case 3 : 
            {
                return 'L';
                break;
            }
        }
    }
    return a;
}
int countSubString(const string &str , const string &substr)
{
    string temp=str;
    int count = 0;
    while(temp.find(substr) != string::npos)
    {
        count++;
        temp=temp.substr(temp.find(substr),substr.length());
    }
    return count;
}
string stringResult(int n)
{
    string s=" V(";
    string result;
    int count =0 ;
    for(int i=0; i<n ; i++)
    {
        count++;
        result.insert(i,s);
    }
    result+="0";
    for(int i= 0; i < n; i++) result+=")";
    return result;
}
void swap5(infOfPerson &x , infOfPerson &y)
{
    infOfPerson t=x;
    x=y;
    y=t;
}
int calcZero(string s)
{
    int count = 0;
    for(int i = 0; i < 10;i++)
    {
        if(s[i] == '0') count++;
    }
    return count;
}
bool isTwoElement(string s)
{
    int count = 0;
    for(int i = 0; i < 10;i++)
    {
        if(s[i] == '2') count++;
    }
    if (count == 0) return false;
    return true;
}
string reverseString (string str)
{
    string tempString=str;
    int indexPos=0;
    for (int x=tempString.length()-1;x>=0;x--)
    {
        str[indexPos]=tempString[x];
        indexPos++;
    }
    return str;
}
string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
    int vua=0;
    int thd=0;
    for(int i=0 ; i < NID ; i++)
    {
        string temp=ID[i];
        if(temp.substr(0,3)=="VUA") vua++;
        for(size_t j = 1 ; j < temp.length() ;j ++)
        {
            if(temp.substr(j,3)=="THD") thd++;
        }
    }
    string newInput1[N1];
    for(int i=0 ; i < N1;i++)
    {
        newInput1[i]=input1[i];
    }
    for(int i=0; i < N1;i++)
    {
        binaryToDecmimal(newInput1[i]);
        decimalToString(newInput1[i]);
        speciallyChanging(newInput1[i]);
    }
    string result="";
    for(int i = 0 ; i < N1 ; i++)
    {
        if(vua==0 && thd==0) result+=newInput1[i]+ " ";
        else if (vua==1 && thd==0)
        {
            string temp=vuaString(newInput1[i]);
            result+=temp+ " ";
        }
        else if(vua==0 && thd==1)
        {
            string temp=thdString(newInput1[i]);
            result+=temp + " ";
        }
    }
    result.pop_back();
    return result;
}
int decode(const string A, const string B)
{
    if(B.length()==0) return 0;
    int count = 0; 
    string temp=A;
    while(temp.find(B) != string::npos)
    {
        count++;
        temp=temp.substr(temp.find(B)+B.length());
    }
    return count;
}
string findRoute(const string input3)
{
    string X="";
    string Y="";
    string s=input3;
    int n=s.length();
    string tempN= "", 
           tempB= "";
    for(int i = 0; i < n ; i++)
    {
        if(s[i] ==' ')
        {
            tempN=s.substr(0,i);
            s=s.substr(i+1);
            break;
        }
    }
    for(int i = 0; i < n ; i++)
    {
        if(s[i] ==' ')
        {
            tempB=s.substr(0,i);
            s=s.substr(i+1);
            break;
        }
    }
    int newN=stoi(tempN), 
        newB=stoi(tempB),
        sLen=s.length(),
        numChanges=0;
    if(newB > 0 ) dichChuoiBLan(s,sLen,newB,'p');
    else if(newB < 0) 
    {
        newB=-newB;
        dichChuoiBLan(s,sLen,newB,'t');
    }
    for(int i=0; i < sLen ; i++)
    {
        numChanges=abs(newN-2*i);
        s[i]=bienDoiKyTu(s[i],numChanges);
    }
    for(int i=0;i<sLen;i++)
    {
        cout << s[i];
    }
    int x=0,
        y=0;
    for(int i=0; i < sLen ; i++)
    {
        switch(s[i])
        {
            case 'U' : 
            {
                y++;
                break;
            }
            case 'D' :
            {
                y--;
                break;
            }
            case 'L' :
            {
                x--;
                break;
            }
            case 'R' :
            {
                x++;
            }
        }
    }
    X=to_string(x);
    Y=to_string(y);
    string result="(";
    result+=X;
    result+=",";
    result+=Y;
    result+=")";
    return result;
    return "You can remove this return";
}
string decodeVfunction(const string A, const string B)
{
    if(A=="0" || B=="0") return "0";
    int nA=A.length(),
        nB=B.length(), 
        countVA=0, 
        countVB=0, 
        count=0;
    string result="";
    for(int i = 0; i < nA ; i++)
    {
        if(A[i]=='V') countVA++;
    }
    for(int i = 0; i < nB ; i++)
    {
        if(B[i]=='V') countVB++;
    }
    count=countVA*countVB;
    result=stringResult(count);
    result=result.substr(count);
    return result;
}
string findBetrayals(const string input5[], const int N5)
{
    string result="";
    infOfPerson person[26];
    for(int ch='A'; ch<='Z';ch++)
    {
        person[ch-'A'].ten=ch;
    }
    for(int i=0; i < 26; i++)
    {
        person[i].diem=0;
    }
    for(int i= 0; i < N5; i++)
    {
        string input=input5[i];
        for(int j=0 ; j < 6 ; j++)
        {
            switch(input[j])
            {
                case 'A' : 
                    person[0].diem+=6-j;
                    break;
                case 'B' : 
                    person[1].diem+=6-j;
                    break;
                case 'C' : 
                    person[2].diem+=6-j;
                    break;
                case 'D' : 
                    person[3].diem+=6-j;
                    break;
                case 'E' : 
                    person[4].diem+=6-j;
                    break;
                case 'F' : 
                    person[5].diem+=6-j;
                    break;
                case 'G' : 
                    person[6].diem+=6-j;
                    break;
                case 'H' : 
                    person[7].diem+=6-j;
                    break;
                case 'I' :
                    person[8].diem+=6-j;
                    break;
                case 'J' : 
                    person[9].diem+=6-j;
                    break;
                case 'K' : 
                    person[10].diem+=6-j;
                    break;
                case 'L' : 
                    person[11].diem+=6-j;
                    break;
                case 'M' : 
                    person[12].diem+=6-j;
                    break;
                case 'N' : 
                    person[13].diem+=6-j;
                    break;
                case 'O' : 
                    person[14].diem+=6-j;
                    break;
                case 'P' : 
                    person[15].diem+=6-j;
                    break;
                case 'Q' : 
                    person[16].diem+=6-j;
                    break;
                case 'R' : 
                    person[17].diem+=6-j;
                    break;
                case 'S' : 
                    person[18].diem+=6-j;
                    break;
                case 'T' : 
                    person[19].diem+=6-j;
                    break;
                case 'U' : 
                    person[20].diem+=6-j;
                    break;
                case 'V' : 
                    person[21].diem+=6-j;
                    break;
                case 'W' : 
                    person[22].diem+=6-j;
                    break;
                case 'X' : 
                    person[23].diem+=6-j;
                    break;
                case 'Y' : 
                    person[24].diem+=6-j;
                    break;
                case 'Z' : 
                    person[25].diem+=6-j;
                    break;
            }
        }
    }
    for(int i=0;i<25;i++) 
        for(int j=i+1;j<26;j++)
        {
            if(person[i].diem >= person[j].diem) 
            swap5(person[i], person[j]);
        }
    for(int i= 25 ; i >= 23  ; i--)
    {
        result+=person[i].ten;
    }
    return result;
    return "!23";
}
int attack(const string input6[])
{
    int ZeroInEachRow[10];
    bool existTwoInString[10];
    int mostZero=0;
    int max=ZeroInEachRow[0];
    int count = 0;
    for(int i = 0; i < 10; i++)
    {
        ZeroInEachRow[i]=calcZero(input6[i]);
        existTwoInString[i]=isTwoElement(input6[i]);
    }
    for(int i = 0 ; i < 10; i++)
    {
        if(existTwoInString[i]==true)
        {
            ZeroInEachRow[i]=0;
            count++;
        }
    }
    if(count==10) return -1;
    for(int i = 0; i < 10; i++)
    {
        if(ZeroInEachRow[i]>=max) 
        {
            max=ZeroInEachRow[i];
            mostZero=i;
        }
    }
    return mostZero;
}
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
    string input7Temp=input7Str;
    string n7;
    for(size_t i = 0 ; i < input7Temp.length(); i++)
    {
        if(input7Temp[i]==' ')
        {
            n7=input7Temp.substr(0,i);
            input7Temp=input7Temp.substr(i+1);
            break;
        }
    }
    string v;
    for(size_t i = 0; i<input7Temp.length() ; i++)
    {
        if(input7Temp[i]==' ')
        {
            v=input7Temp.substr(0,i);
            input7Temp=input7Temp.substr(i+1);
            break;
        }
    }
    string I;
    for(size_t i = 0 ; i < input7Temp.length(); i++)
    {
        if(input7Temp[i]==' ')
        {
            I=input7Temp.substr(0,i);
            input7Temp=input7Temp.substr(i+1);
            break;
        }
    }
    string J=input7Temp;
    int N7=stoi(n7),
        V=stoi(v),
        i=stoi(I),
        j=stoi(J);
    /*-------------------------------*/
    string newInput7[k];
    for(int i = 0 ; i < k ; i++)
    {
        newInput7[i]=input7Matrix[i];
    }
    
    /*-------------------------------*/
    long long int theUnityMatrix[N7][N7];
    for(int i = 0 ; i < N7 ; i++)
    {
        for(int j=0; j < N7; j++)
        {
            if(i==j) theUnityMatrix[i][j]= 1; // Tao ma tran don vi
            else theUnityMatrix[i][j]=0;
        }
    }
    /*-------------------------------*/
    long long int resultMatrix[N7][N7];
    long long int temp[N7][N7];
    for(int i = 0 ; i <  k ; i++)
    {
        /*-------------------------------*/
        for(int j = 0; j < N7 ;j++)
            for(int h=0;h < N7; h++)
            {
                temp[j][h]=stoi(newInput7[i]);
                size_t spaceChars=newInput7[i].find(" ");
                if(spaceChars != string::npos)
                {
                    newInput7[i].erase(0,spaceChars+1);
                }
            }
        /*-------------------------------*/
        for(int t = 0 ; t < N7 ; t++)
            for(int y=0; y < N7 ; y++)
            {
                resultMatrix[t][y]=0;
                for(int k = 0; k < N7; k++)
                resultMatrix[t][y]=resultMatrix[t][y]+(theUnityMatrix[t][k]*temp[k][y])%V;
            }
        for(int p = 0 ; p < N7 ; p++)
        {
            for(int o = 0; o < N7 ; o++)
            {
                theUnityMatrix[p][o]=resultMatrix[p][o];
            }
        }
    }
    while(resultMatrix[i][j] < 0 )
    {
        resultMatrix[i][j]+=V;
    }
    return resultMatrix[i][j]%V;
}
#endif /* MONGOL_H */
