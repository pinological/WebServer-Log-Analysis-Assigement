#include <iostream>
#include <fstream>
#include <thread>
#include <map>

using namespace std;
int Mongolia=0,Bangladesh=0,Singapore=0,Usa=0,Russia=0,Brazil=0,Norway=0,Netherlands=0,Nepal=0,Windows=0,Ubuntu=0,Chrome=0, Firefox=0;
int fortime0 = 0,fortime1 = 0, fortime2 = 0,fortime3 = 0,fortime4 = 0,fortime5 = 0,fortime6 = 0,fortime7 = 0,fortime8 = 0,fortime9 = 0,fortime10 = 0,fortime11 = 0,fortime12 = 0,fortime13 = 0,fortime14 = 0,fortime15 = 0,fortime16 = 0,fortime17 = 0,fortime18 = 0,fortime19 = 0,fortime20 = 0,fortime21 = 0,fortime22 = 0,fortime23 = 0,fortime24 = 0;
void checkfiledata(string data){
    std::map<string, string> Iplocation = {
    { "180.149.125.175", "Mongolia" },
    { "43.251.85.96", "Bangladesh" },
    { "195.123.237.209", "Singapore" },
    { "205.185.126.200", "UnitedStates" },
    { "209.141.32.217", "UnitedStates" },
    { "45.146.164.110", "Russia" },
    { "178.238.8.65", "Netherlands" },
    { "209.141.48.78", "UnitedStates" },
    { "144.126.133.142", "UnitedStates" },
    { "189.60.107.182", "Brazil" },
    { "193.242.145.12", "Russia" },
    { "84.209.139.0", "Norway" },
    { "34.106.29.52", "UnitedStates" },
    { "192.241.198.203", "UnitedStates" },
    { "205.185.126.200", "UnitedStates" },
    { "134.66.77.89", "Nepal" },};

    for (auto& x: Iplocation) {  
    if(data == x.first){
        if(x.second == "Mongolia"){
            Mongolia++;
        }
        else if (x.second == "Bangladesh")
        {
            Bangladesh++;
        }
        else if (x.second == "Singapore")
        {
            Singapore++;
        }
        else if (x.second == "UnitedStates")
        {
            Usa++;
        }
        else if (x.second == "Russia")
        {
            Russia++;
        }
        else if (x.second == "Brazil")
        {
           Brazil++;
        }
        else if (x.second == "Netherlands")
        {
            Netherlands++;
        }
        else if (x.second == "Norway")
        {
            Norway++;
        }
           else if (x.second == "Nepal")
        {
            Nepal++;
        }
    }
    }
    if(data == "Ubuntu"){
        Ubuntu++;
    }
    else if(data == "Windows"){
        Windows++;
    }
    else if(data == "Chrome"){
        Chrome++;
    }
     else if(data == "Firefox"){
        Firefox++;
    }
    
}

void checkfiledatatime(string data){
    if(data == "2021:00"){
        fortime0 ++;
    }
    else if (data == "2021:01")
    {
        fortime1++;
    }
     else if (data == "2021:02")
    {
        fortime2++;
    }
     else if (data == "2021:03")
    {
        fortime3++;
    }
     else if (data == "2021:04")
    {
        fortime4++;
    }
     else if (data == "2021:05")
    {
        fortime5++;
    }
     else if (data == "2021:06")
    {
        fortime6++;
    }
     else if (data == "2021:07")
    {
        fortime7++;
    }
     else if (data == "2021:08")
    {
        fortime8++;
    }
     else if (data == "2021:09")
    {
        fortime9++;
    }
     else if (data == "2021:10")
    {
        fortime10++;
    }
     else if (data == "2021:11")
    {
        fortime11++;
    }
     else if (data == "2021:12")
    {
        fortime12++;
    }
     else if (data == "2021:13")
    {
        fortime13++;
    }
     else if (data == "2021:14")
    {
        fortime14++;
    }
     else if (data == "2021:15")
    {
        fortime15++;
    }
     else if (data == "2021:16")
    {
        fortime16++;
    }
     else if (data == "2021:17")
    {
        fortime17++;
    }
     else if (data == "2021:18")
    {
        fortime18++;
    }
     else if (data == "2021:19")
    {
        fortime19++;
    }
     else if (data == "2021:20")
    {
        fortime20++;
    }
     else if (data == "2021:21")
    {
        fortime21++;
    }
     else if (data == "2021:22")
    {
        fortime22++;
    }
     else if (data == "2021:23")
    {
        fortime23++;
    }
  
    
    

}



int main(){
string myText;
ifstream MyReadFile("access1.log");

while (getline (MyReadFile, myText)) {
    string temp = "";
    for(int i = 0;i<myText.size();i++){
        int num = 0;
        if(!isspace(myText[i])){
            temp += myText[i];
        }
        else{
            std::thread t1(checkfiledata,temp);
            std::thread t2(checkfiledatatime,temp);
            t1.join();
	        t2.join();
            temp = "";
        }
    }
    
}

MyReadFile.close();

ofstream MyFile("loginfo.json");
  MyFile <<"{"<<"\n";
  MyFile <<"\"country\" : [{\"Mongolia\":"<<Mongolia<<"},{\"Bangladesh\":"<<Bangladesh<<"},{\"Singapore\":"<<Singapore<<"},{\"UnitedStates\":"<<Usa<<"},{\"Russia\":"<<Russia<<"},{\"Brazil\":"<<Brazil<<"},{\"Netherlands\":"<<Netherlands<<"},{\"Norway\":"<<Norway<<"},{\"Nepal\":"<<Nepal<<"}],"<<'\n';
  MyFile <<"\"operatingSys\" : [{\"Ubuntu\":"<<Ubuntu<<"},{\"Windows\":"<<Windows<<"}],"<<'\n';
  MyFile <<"\"WebBrowser\" : [{\"Chrome\":"<<Chrome<<"},{\"Firefox\":"<<Firefox<<"}],"<<'\n';
  MyFile <<"\"Timeuser\" : [{\"time00\":"<<fortime0<<"},{\"time01\":"<<fortime1<<"},{\"time02\":"<<fortime2<<"},{\"time03\":"<<fortime3<<"},{\"time04\":"<<fortime4<<"},{\"time05\":"<<fortime5<<"},{\"time06\":"<<fortime6<<"},{\"time07\":"<<fortime7<<"},{\"time08\":"<<fortime8<<"},{\"time09\":"<<fortime9<<"},{\"time10\":"<<fortime10<<"},{\"time11\":"<<fortime11<<"},"<<'\n';
  MyFile <<"{\"time12\":"<<fortime12<<"},{\"time13\":"<<fortime13<<"},{\"time14\":"<<fortime14<<"},{\"time15\":"<<fortime15<<"},{\"time16\":"<<fortime16<<"},{\"time17\":"<<fortime17<<"},{\"time18\":"<<fortime18<<"},{\"time19\":"<<fortime19<<"},{\"time20\":"<<fortime20<<"},{\"time21\":"<<fortime21<<"},{\"time22\":"<<fortime22<<"},{\"time23\":"<<fortime23<<"}]"<<'\n';
  MyFile <<"}"<<"\n";

  // Close the file
  MyFile.close();



return 0;
}