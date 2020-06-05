#ifndef _SpectrumServer_SpectrumServer_h_
#define _SpectrumServer_SpectrumServer_h_

#include <CtrlCore/CtrlCore.h>
#include <CtrlLib/CtrlLib.h>
#include <plugin/pcre/Pcre.h>
#include <Urr/Urr.h>

using namespace Upp;
using namespace std;

#define LAYOUTFILE <SpectrumServer/SpectrumServer.lay>
#include <CtrlCore/lay.h>

class SpectrumServer : public WithSpectrumServerLayout<TopWindow> {
public:
	typedef SpectrumServer CLASSNAME;
	SpectrumServer();
	~SpectrumServer();
	
	void BtnStart();
	
	int mash = 0;
	int type = 0;
	String mess;
};

//String Request(const String& r);
void TCPServer();
void TCPClient();

void UDPServer();
void UDPClient();

//volatile bool work = true;

#endif
