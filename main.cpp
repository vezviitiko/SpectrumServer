#include "SpectrumServer.h"

SpectrumServer* dlgp;

extern volatile bool work;
extern std::string globallmess;
extern Mutex globallmess_busy;
extern volatile double numbermess;
extern volatile double numberSentmess;
/*
void TCPServer(){
	TcpSocket server;
	
	String versionServer = "2.8";
	String passServer = "1dfgdf23";
	
	if ( !server.Listen ( 3000 , 5 ) )
	{
		Cerr() << "Unable to initialize server socket!\n";
		//SetExitCode ( 1 );
		return;
	}
	
	Cerr() << "Socket started, waiting for requests...\n";
	
	try{
		while(!Thread::IsShutdownThreads()) {
			TcpSocket s;
			s.WhenWait = [=]
			{
				Cerr() << "0000 \n";
				
				if(Thread::IsShutdownThreads()){
					Cerr() << "333 \n";
					throw Exc("Thread is shut down.");
					}
					
					
			};
			Cerr() << "1111 \n";
			
			if (numbermess > numberSentmess){
				Cerr()<<"mess !!!!!!!!!!!!!!!!\n";
				globallmess_busy.Enter();
				String mess;
				mess = globallmess;
				numberSentmess+=1;
				globallmess_busy.Leave();
				
				Cerr()<<"mess| "<<mess<<" |\n";
				s.Put(mess);
			}
			
				Cerr() << "wwww \n";
				String w = s.GetLine();
				Cerr() << w <<"\n";
				
				RegExp r0("<main>(CONNECT)</main><ver>(.*)</ver><pass>(\\s*[A-Za-z0-9^ \n]*)</pass>");
				
				if(r0.Match(w)){
					for(int i = 0; i < r0.GetCount(); i++)
						Cerr() << r0[i] << '\n';
					
					// проверка версий
					if (r0[1] == versionServer){
						//GuiLock __ ;
						//dlgp->log = "Версии совпадают";
						Cerr()<< "Версии совпадают "<<"\n";
						
						// проверка пароля
						if (r0[2] == passServer){
							//GuiLock __ ;
							//dlgp->log = "Пароли совпадают";
							Cerr()<< "Пароли совпадают "<<"\n";
							// все данные совпадают - отправка сообщения
							s.Put("<main>Authentication approved</main>\n");
							}
						else{
							//GuiLock __ ;
							//dlgp->log = "Пароли НЕ совпадают";
							Cerr()<< "Пароли НЕ совпадают "<<"\n";
							
							s.Put("<main>Password is incorrect</main>\n");
							}
						}
					else{
						//GuiLock __ ;
						//dlgp->log = "Версии НЕ совпадают";
						Cerr()<< "Версии НЕ совпадают "<<"\n";
						
						s.Put("<main>Version is incorrect</main>\n");
						}
					
				}
			}
			
			// отправка сообщения если оно уже лежало на сервере
			Cerr()<<"mess !!!!!!!!!!!!!!!!\n";
			globallmess_busy.Enter();
			String mess;
			mess = globallmess;
			numberSentmess+=1;
			globallmess_busy.Leave();
			
			Cerr()<<"mess| "<<mess<<" |\n";
			Cerr()<<"Сообщение отправляется\n";
			s.Put(mess);
			Cerr()<<"Сообщение отправлено\n";
		}
		
		
		
		
		/*
		Cerr() << "Initialize server socket!\n";
		LOG ( "Initialize server socket!\n" );
		String q_str;
		if ( s.Accept ( server ) )
			{
			String input;
			for(;;){
				Cerr()<<"input !!!!!!!!!!!!!!!!\n";
				for(;;){
					
					Cerr()<<"mess input input"<<"\n";
					globallmess_busy.Enter();
					String mess;
					mess = globallmess;
					globallmess_busy.Leave();
					s.Put(mess);
					input = AsString(s.Get(1));
					if (input == "\n")
					{
						break;
					}
					else
					{
						q_str += AsString(input);
					}
				}
				
				Cerr()<< "q_str: " <<q_str<<"\n";
				
				RegExp r0("<main>(CONNECT)</main><ver>(.*)</ver><pass>(\\s*[A-Za-z0-9^ \n]*)</pass>");
				
				if(r0.Match(q_str)){
					for(int i = 0; i < r0.GetCount(); i++)
						Cerr() << r0[i] << '\n';
					
					// проверка версий
					if (r0[1] == versionServer){
						GuiLock __ ;
						dlgp->log = "Версии совпадают";
						Cerr()<< "Версии совпадают "<<"\n";
						
						// проверка пароля
						if (r0[2] == passServer){
							GuiLock __ ;
							dlgp->log = "Пароли совпадают";
							Cerr()<< "Пароли совпадают "<<"\n";
		
							// все данные совпадают - отправка сообщения
							
							s.Put("<main>Authentication approved</main>\n");
							
							
						}
						else{
							GuiLock __ ;
							dlgp->log = "Пароли НЕ совпадают";
							Cerr()<< "Пароли НЕ совпадают "<<"\n";
							
							s.Put("<main>Password is incorrect</main>\n");
						}
					}
					else{
						GuiLock __ ;
						dlgp->log = "Версии НЕ совпадают";
						Cerr()<< "Версии НЕ совпадают "<<"\n";
						
						s.Put("<main>Version is incorrect</main>\n");
					}
					
				}
				Cerr()<<"mess !!!!!!!!!!!!!!!!\n";
				globallmess_busy.Enter();
				String mess;
				mess = globallmess;
				globallmess_busy.Leave();
			
				Cerr()<<"mess "<<mess<<"\n";
				s.Put(mess);
				}
			}*/
/*	}
	
	catch(const Exc& e) {
		RLOG(e);
	}
}*/
/*
SpectrumServer::SpectrumServer()
{
	dlgp = this;
	CtrlLayout(*this, "ТЕСТ СЕРВЕР");
	Zoomable().Sizeable();
	
	btNorm1.WhenAction = [=] {
		type = 1;
		mash = 1;
		BtnStart();
	};
	btNorm2.WhenAction = [=] {
		type = 1;
		mash = 2;
		BtnStart();
	};
	btNorm3.WhenAction = [=] {
		type = 1;
		mash = 3;
		BtnStart();
	};
	btNorm4.WhenAction = [=] {
		type = 1;
		mash = 4;
		BtnStart();
	};
	btOpa1.WhenAction = [=] {
		type = 2;
		mash = 1;
		BtnStart();
	};
	btOpa2.WhenAction = [=] {
		type = 2;
		mash = 2;
		BtnStart();
	};
	btOpa3.WhenAction = [=] {
		type = 2;
		mash = 3;
		BtnStart();
	};
	btOpa4.WhenAction = [=] {
		type = 2;
		mash = 4;
		BtnStart();
	};
	btPre1.WhenAction = [=] {
		type = 3;
		mash = 1;
		BtnStart();
	};
	btPre2.WhenAction = [=] {
		type = 3;
		mash = 2;
		BtnStart();
	};
	btPre3.WhenAction = [=] {
		type = 3;
		mash = 3;
		BtnStart();
	};
	btPre4.WhenAction = [=] {
		type = 3;
		mash = 4;
		BtnStart();
	};
	
}	Cerr() << "2222 \n";
			
			if(s.Accept(server)) {
				Cerr() << "wwww \n";
				String w = s.GetLine();
				Cerr() << w <<"\n";
				
				RegExp r0("<main>(CONNECT)</main><ver>(.*)</ver><pass>(\\s*[A-Za-z0-9^ \n]*)</pass>");
				
				if(r0.Match(w)){
					for(int i = 0; i < r0.GetCount(); i++)
						Cerr() << r0[i] << '\n';
					
					// проверка версий
					if (r0[1] == versionServer){
						//GuiLock __ ;
						//dlgp->log = "Версии совпадают";
						Cerr()<< "Версии совпадают "<<"\n";
						
						// проверка пароля
						if (r0[2] == passServer){
							//GuiLock __ ;
							//dlgp->log = "Пароли совпадают";
							Cerr()<< "Пароли совпадают "<<"\n";
							// все данные совпадают - отправка сообщения
							s.Put("<main>Authentication approved</main>\n");
							}
						else{
							//GuiLock __ ;
							//dlgp->log = "Пароли НЕ совпадают";
							Cerr()<< "Пароли НЕ совпадают "<<"\n";
							
							s.Put("<main>Password is incorrect</main>\n");
							}
						}
					else{
						//GuiLock __ ;
						//dlgp->log = "Версии НЕ совпадают";
						Cerr()<< "Версии НЕ совпадают "<<"\n";
						
						s.Put("<main>Version is incorrect</main>\n");
						}
					
				}
			}
			
			// отправка сообщения если оно уже лежало на сервере
			Cerr()<<"mess !!!!!!!!!!!!!!!!\n";
			globallmess_busy.Enter();
			String mess;
			mess = globallmess;
			numberSentmess+=1;
			globallmess_busy.Leave();
			
			Cerr()<<"mess| "<<mess<<" |\n";
			Cerr()<<"Сообщение отправляется\n";
			s.Put(mess);
			Cerr()<<"Сообщение отправлено\n";
		}
		
		
		
		
		/*
		Cerr() << "Initialize server socket!\n";
		LOG ( "Initialize server socket!\n" );
		String q_str;
		if ( s.Accept ( server ) )
			{
			String input;
			for(;;){
				Cerr()<<"input !!!!!!!!!!!!!!!!\n";
				for(;;){
					
					Cerr()<<"mess input input"<<"\n";
					globallmess_busy.Enter();
					String mess;
					mess = globallmess;
					globallmess_busy.Leave();
					s.Put(mess);
					input = AsString(s.Get(1));
					if (input == "\n")
					{
						break;
					}
					else
					{
						q_str += AsString(input);
					}
				}
				
				Cerr()<< "q_str: " <<q_str<<"\n";
				
				RegExp r0("<main>(CONNECT)</main><ver>(.*)</ver><pass>(\\s*[A-Za-z0-9^ \n]*)</pass>");
				
				if(r0.Match(q_str)){
					for(int i = 0; i < r0.GetCount(); i++)
						Cerr() << r0[i] << '\n';
					
					// проверка версий
					if (r0[1] == versionServer){
						GuiLock __ ;
						dlgp->log = "Версии совпадают";
						Cerr()<< "Версии совпадают "<<"\n";
						
						// проверка пароля
						if (r0[2] == passServer){
							GuiLock __ ;
							dlgp->log = "Пароли совпадают";
							Cerr()<< "Пароли совпадают "<<"\n";
		
							// все данные совпадают - отправка сообщения
							
							s.Put("<main>Authentication approved</main>\n");
							
							
						}
						else{
							GuiLock __ ;
							dlgp->log = "Пароли НЕ совпадают";
							Cerr()<< "Пароли НЕ совпадают "<<"\n";
							
							s.Put("<main>Password is incorrect</main>\n");
						}
					}
					else{
						GuiLock __ ;
						dlgp->log = "Версии НЕ совпадают";
						Cerr()<< "Версии НЕ совпадают "<<"\n";
						
						s.Put("<main>Version is incorrect</main>\n");
					}
					
				}
				Cerr()<<"mess !!!!!!!!!!!!!!!!\n";
				globallmess_busy.Enter();
				String mess;
				mess = globallmess;
				globallmess_busy.Leave();
			
				Cerr()<<"mess "<<mess<<"\n";
				s.Put(mess);
				}
			}*/
/*	}
	
	catch(const Exc& e) {
		RLOG(e);
	}
}*/

SpectrumServer::SpectrumServer()
{
	dlgp = this;
	CtrlLayout(*this, "ТЕСТ СЕРВЕР");
	Zoomable().Sizeable();
	
	btNorm1.WhenAction = [=] {
		type = 1;
		mash = 1;
		BtnStart();
	};
	btNorm2.WhenAction = [=] {
		type = 1;
		mash = 2;
		BtnStart();
	};
	btNorm3.WhenAction = [=] {
		type = 1;
		mash = 3;
		BtnStart();
	};
	btNorm4.WhenAction = [=] {
		type = 1;
		mash = 4;
		BtnStart();
	};
	btOpa1.WhenAction = [=] {
		type = 2;
		mash = 1;
		BtnStart();
	};
	btOpa2.WhenAction = [=] {
		type = 2;
		mash = 2;
		BtnStart();
	};
	btOpa3.WhenAction = [=] {
		type = 2;
		mash = 3;
		BtnStart();
	};
	btOpa4.WhenAction = [=] {
		type = 2;
		mash = 4;
		BtnStart();
	};
	btPre1.WhenAction = [=] {
		type = 3;
		mash = 1;
		BtnStart();
	};
	btPre2.WhenAction = [=] {
		type = 3;
		mash = 2;
		BtnStart();
	};
	btPre3.WhenAction = [=] {
		type = 3;
		mash = 3;
		BtnStart();
	};
	btPre4.WhenAction = [=] {
		type = 3;
		mash = 4;
		BtnStart();
	};
	
}



//TCP
/*
GUI_APP_MAIN
{
	LOG("start");
	numbermess = 0;
	numberSentmess = 0;
	//Thread t;
	//t.Run(callback(TCPServer));
	Thread t1;
	t1.Start ( TCPServer );
	//Thread().Start ( TCPServer );
	Ctrl::ProcessEvents();
	Thread t2;
	t2.Start ( TCPClient );
	{
		SpectrumServer sps;
		sps.Run();
	}
	Ctrl::ProcessEvents();
	LOG("finish");
	work = false;
	quick_exit ( 0 );
}
*/

GUI_APP_MAIN
{
	LOG("start");
	numbermess = 0;
	numberSentmess = 0;
	Thread t1;
	t1.Start ( UDPServer );
	{
		SpectrumServer sps;
		sps.Run();
	}
	Ctrl::ProcessEvents();
	LOG("finish");
	work = false;
	quick_exit ( 0 );
}
