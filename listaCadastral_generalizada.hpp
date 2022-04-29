//
//  listaCadastral_generalizada.hpp
//  F6_listaCadastral_generalizada
//
//  Created by Eduardo Bouhid Neto on 22/09/21.
//

#ifndef listaCadastral_generalizada_generalizada_hpp
#define listaCadastral_generalizada_generalizada_hpp

#include <stdio.h>


#include <stdio.h>
#include <string>

using namespace std;

typedef struct Node
{
    string info;
    Node* dir;
    Node* esq;
}Node;

class listaCadastral_generalizada{
private:
    Node* header;
    Node* P;
    Node* anterior;
public:
    listaCadastral_generalizada();
    ~listaCadastral_generalizada();
    void pegaOPrimeiro(listaCadastral_generalizada* l, string* x, bool* temElemento);
    void pegaOProximo(listaCadastral_generalizada* l, string* x, bool* temElemento);
    bool Vazia();
    bool Cheia();
    string infoDeP(listaCadastral_generalizada* l, Node* P, bool* ok);
    bool estaNaLista(listaCadastral_generalizada* l, string x, Node** P);
    void insereADireitaDeP(listaCadastral_generalizada* l, Node* P, string x, bool* ok);
    void removeP(listaCadastral_generalizada* l, Node* P, bool* ok);
    Node* getHeader();
};
#endif /* listaCadastral_generalizada_generalizada_hpp */
