#include <Core/Core.h>
#include "SpectrumServer.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

volatile bool work = true;

std::string globallmess;
Mutex globallmess_busy;

volatile double numbermess;
volatile double numberSentmess;

SpectrumServer::~SpectrumServer()
{
	work = false;
	Break();
}


char* loadFile(char* filename) {
    //cout << endl << "Loading file: " << filename << endl;
	Cerr()<<"Loading file:  "<<filename<<"\n";
    
    char *contents;
    ifstream file(filename, ios::in|ios::binary|ios::ate);
    if (file.is_open())
    {
        int size = file.tellg();
        contents = new char [size];
        file.seekg (0, ios::beg);
        file.read (contents, size);
        file.clear();
        file.close();
    }
    //printf("contents: %s\n", contents);
        
    //Cerr()<<"contents = "<<contents<<"\n";
    std::cout.write( contents, file.tellg() );
	std::cout.flush();
    Cerr() << "finished loading " << filename << "\n";
    return contents;
}

void SpectrumServer::BtnStart(){
	LOG("startBtnStart");
	if ( work )
	{
		//String mess;
		
		int arrSpectr[100];
		for (int i = 0; i < 100; i++) {
			arrSpectr[i] = 0;
		};
		int zna1 = 0;
		int zna2 = 0;
		int zna3 = 0;
		int zna4 = 0;
		
		Cerr() << AsString(GetSysTime()) <<"\n";
				// формирование отпраки сообщения
				// данные
				// мощность
				int power;
				// направление движения автомобиля
				String editdir;
				//int i = rand() % 3; // генератор случайного напрвления
				//String lf;
				
				
				//char dataPath[];
				char dataPath1[] = "/home/comis/upp/MyApps/SocketServer/imcar1.jpg";
				char dataPath2[] = "/home/comis/upp/MyApps/SocketServer/imcar2.jpg";
				char dataPath3[] = "/home/comis/upp/MyApps/SocketServer/imcar3.jpg";
				char dataPath4[] = "Фото отсутствует";
				char *datafile;// = loadFile(dataPath1);
				
				if (mash == 1){
					//lf = LoadFileBOM("/home/comis/upp/MyApps/SocketServer/imcar1.png");
					//lf = LoadFile("/home/comis/upp/MyApps/SocketServer/imcar1.png");
					editdir = "Вперед";
					//dataPath = "/home/comis/upp/MyApps/SocketServer/imcar1.jpg";
					
					datafile = loadFile(dataPath1);
				}
				else if (mash == 2){
					//lf = LoadFileBOM("/home/comis/upp/MyApps/SocketServer/imcar2.png");
					//lf = LoadFile("/home/comis/upp/MyApps/SocketServer/imcar2.png");
					editdir = "Повторот на лево";
					//dataPath = "/home/comis/upp/MyApps/SocketServer/imcar2.jpg";
					
					datafile = loadFile(dataPath2);
				}
				else if (mash == 3){
					//lf = LoadFile("/home/comis/upp/MyApps/SocketServer/imcar3.png");
					//lf = LoadFile("/home/comis/upp/MyApps/SocketServer/imcar3.jpg");
					//dataPath = "/home/comis/upp/MyApps/SocketServer/imcar3.jpg";
					
					datafile = loadFile(dataPath3);
					//lf = Encode64(lf);
					editdir = "Назад";
					
				}
				else if (mash == 4){
					//lf = LoadFile("/home/comis/upp/MyApps/SocketServer/imcar3.png");
					
					//lf = "Фото отсутствует";
					editdir = "Данных нет";
					//dataPath = "Фото отсутствует";
					
					//datafile = loadFile(dataPath4);
					//datafile = "Фото отсутствует"
					Cerr()<<"D9\n";
				};
				if (type == 1){
					power = rand() % 50;
				}
				else if (type == 2){
					power = rand() % 80+100;
				}
				else if (type == 3){
					power = rand() % 50+50;
				}
				
				//RDUMP(lf);
				
				
				//datafile.lenght
				
				
				
				//Cerr() << "1 " <<lf.GetLength() << "\n";
				//lf = Encode64(lf);
				//Cerr() << "2 " <<lf.GetLength()<< "\n";
				// генератор точек спектра
				//int *arrSpectr = nullptr;
				//arrSpectr = new int [100];
				
				//int arrSpectr[100];
				
				zna1 = rand() % 10+3;
				zna2 = rand() % 51+30;
				zna3 = rand() % 31+20;
				zna4 = rand() % 45+25;
				
				for (int i = 0; i < 100; i++) {
					if (i < 13){
						arrSpectr[i] = zna1;
					}
					else if (i < 25){
						arrSpectr[i] = zna2;
					}
					else if (i < 45){
						arrSpectr[i] = zna1;
					}
					else if (i < 55){
						arrSpectr[i] = zna2;
					}
					else if (i < 60){
						arrSpectr[i] = zna1;
					}
					else if (i < 75){
						arrSpectr[i] = zna3;
					}
					else if (i < 80){
						arrSpectr[i] = zna1;
					}
					else if (i < 85){
						arrSpectr[i] = zna4;
					}
					else if (i < 90){
						arrSpectr[i] = zna1;
					}
					else if (i < 95){
						arrSpectr[i] = zna4;
					}
					else {
						arrSpectr[i] = zna1;
					}
				}
				
				
				//Cerr() << "mash:	" << mash << "\n";
				//Cerr() << "power:	" << power << "\n";
				//Cerr() << "editdir:	" << editdir << "\n";
				//mess = "<main><dateTime>" + AsString(power) + "</dateTime><power>" + AsString(power) + "</power><dir>" + editdir + "</dir>";
				
				Cerr()<<"D10\n";
				// test
				editdir = AsString(1);
				mess = "<main><power>" + AsString(power) + "</power><dir>" + editdir + "</dir>";
				
				mess += "<spectrum>";
				for (int i = 0; i < 100; i++) {
					mess += AsString(arrSpectr[i]) + "/";
				}
				Cerr()<<"D11\n";
				
				
				//std::string myString(datafile, sizeof(datafile));
				
				string s;
				stringstream ss;
				Cerr()<<"D11_1\n";
				ss << datafile;
				Cerr()<<"D11_2\n";
				s = ss.str();
				
				
				Cerr()<<"D11_3\n";
				mess += "</spectrum><img>" + s + "</img>";
				
				
				Cerr()<<"D12\n";
				//s.Put(mess);
				//RDUMP(lf.GetLength());
				//Cerr() << "# image_st@#\n";
				//Cerr() << lf.GetLength();
				mess += "</main>";
				mess += "\n";
				Cerr() << "\n mess \n";
				Cerr() << mess.GetLength();
		
				globallmess_busy.Enter();
				globallmess = mess;
				numbermess+=1;
				//RDUMP(numbermess);
				//DUMP(numbermess);
				//RLOG(numbermess);
				//LOG(numbermess);
				globallmess_busy.Leave();
			
				//Request(mess);
				
				RDUMP(mess.GetLength());
				Cerr() << "\n mess \n";
				Cerr() << mess.GetLength();
				Cerr() << "finBtnStart\n";
				LOG("finBtnStart");
		
	}
}
