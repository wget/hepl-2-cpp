#include "WindowSDLexception.hpp"

//***************************************************************************
//********** Constructeurs **************************************************
//***************************************************************************
WindowSDLexception::WindowSDLexception(void)
{
  message = NULL;
  setMessage("message");
}

WindowSDLexception::WindowSDLexception(const char* m)
{
  message = NULL;
  setMessage(m);
}

WindowSDLexception::WindowSDLexception(const WindowSDLexception &e)
{
  message = NULL;
  setMessage(e.getMessage());
}

//***************************************************************************
//********** Desctructeur ***************************************************
//***************************************************************************
WindowSDLexception::~WindowSDLexception()
{
  if (message) delete[] message;
}

//***************************************************************************
//********** SETTERS ********************************************************
//***************************************************************************
void WindowSDLexception::setMessage(const char* m)
{
  if (m == NULL) return;
  if (message) delete message;
  message = new char[strlen(m)+1];
  strcpy(message,m);
}


//***************************************************************************
//********** GETTERS ********************************************************
//***************************************************************************
char* WindowSDLexception::getMessage() const { return message; }

//***************************************************************************
//********** Methodes d'instance ********************************************
//***************************************************************************

//***************************************************************************
//********** Surcharges d'operateurs ****************************************
//***************************************************************************
