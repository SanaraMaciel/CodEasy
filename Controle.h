#ifndef ControleH
#define ControleH
#include <iostream>
using namespace std;
#include <string>
using namespace System;
using namespace System::Windows::Forms;
#include "MenuInicial.h"
#include "TelaCodigo.h"
#include "TelaExecucao.h"
#include "Interpretador.h"
#include "TelaExecucaoInterpretador.h"

class Controle
{
private:

public:
	Controle();
	~Controle();
	void controlarExecucao(void);
};

#endif 
