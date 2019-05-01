#include <iostream>
#include <cstdlib>
#include "CIFRADO_TRAMA.hpp"

using namespace std;

int
cipherData (int Rondas)
{
  int numero = 0;
  int Trama[20];
  int Tramacopi[20];
  int conteo = 1;
  
  cout<<"Trama:   { ";

  for (int i = 0; i < 20; i++)
    {
      numero = rand () % 500;
      Trama[i] = numero;

      cout << Trama[i]<<" " ;

    }
  cout<<"}";
  cout << "\n";

  while (Rondas > 0)
    {

      for (int a = 0; a < 20; a++)
	 {
	  if (a == 0)
	    {
	      Tramacopi[a] = Trama[19] - Trama[1];

	    }

	  if (a == 19)
	    {
	      Tramacopi[a] = Trama[18] + Trama[0];
	      break;


	    }

	  if (a > 0 && a < 19)
	    {
	      if (!(a % 2))
		{
		  Tramacopi[a] = Trama[a - 1] - Trama[a + 1];
		}
	      else
		{
		  Tramacopi[a] = Trama[a - 1] + Trama[a + 1];
		}

	    }



	  

	 }
	 
	 cout<<"Ronda "<<conteo<<": { ";

      for (int b = 0; b < 20; b++)
	 {
	  Trama[b] = Tramacopi[b];
	  cout << Trama[b]<<" ";
	  

	 }
	 cout<<"}";
	 cout<<"\n";


      Rondas--;
      conteo++;

    }
    




}
