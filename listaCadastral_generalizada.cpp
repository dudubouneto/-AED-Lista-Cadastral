//
//  listaCadastral_generalizada.cpp
//  F6_listaCadastral_generalizada
//
//  Created by Eduardo Bouhid Neto on 22/09/21.
//

#include "listaCadastral_generalizada.hpp"
#include <iostream>

listaCadastral_generalizada::listaCadastral_generalizada()
{
    Node* firstNode = new Node();
    firstNode->dir = firstNode;
    firstNode->esq = firstNode;
    this->header = firstNode;
}

listaCadastral_generalizada::~listaCadastral_generalizada(){delete this->header;}

void listaCadastral_generalizada::pegaOPrimeiro(listaCadastral_generalizada *l, string *x, bool *temElemento)
{
    if (l->Vazia()) {
        *temElemento = false;
    } else {
        *temElemento = true;
        l->P = l->header->dir;
        l->anterior = NULL;
        *x = l->header->dir->info;
    }
}

void listaCadastral_generalizada::pegaOProximo(listaCadastral_generalizada *l, string *x, bool *temElemento)
{
    if (l->P->dir == l->header) {
        *temElemento = false;
    } else {
        *temElemento = true;
        l->anterior = l->P;
        l->P = l->P->dir;
        *x = l->P->info;
    }
}

bool listaCadastral_generalizada::Vazia()
{
    if (this->header->dir == this->header){
        return true;
    } else {
        return false;
    }
}

bool listaCadastral_generalizada::Cheia()
{
    return false;
}

void listaCadastral_generalizada::insereADireitaDeP(listaCadastral_generalizada *l, Node *P, string x, bool *ok)
{
    if (Vazia()){
        *ok = true;
        Node* novoNode = new Node;
        novoNode->info = x;
        novoNode->dir = l->header;
        novoNode->esq = l->header;
        l->header->dir = novoNode;
        l->header->esq = novoNode;
    } else if (!l->Cheia()) {
        *ok = true;
        //Criando o novo node e configurando-o
        Node* novoNode = new Node;
        novoNode->info = x;
        novoNode->dir = P->dir;
        novoNode->esq = P;
        P->dir = novoNode;
        novoNode->dir->esq = novoNode;
    } else {
        *ok = false;
    }
}

void listaCadastral_generalizada::removeP(listaCadastral_generalizada *l, Node *P, bool *ok)
{
    //Funciona tipo uma "busca" por x...
    if (P == NULL) {
        *ok = false;
    } else {
        *ok = true;
            P->dir->esq = P->esq;
            P->esq->dir = P->dir;
            delete P;
    }
}
bool listaCadastral_generalizada::estaNaLista(listaCadastral_generalizada *l, string x, Node** pX)
{
    string elem;
    bool temElemento;
    bool jaAchou = false;
    l->pegaOPrimeiro(l, &elem, &temElemento);
    while (temElemento && !jaAchou) {
        if (elem == x) {
            jaAchou = true;
            *pX = (l->P);
        } else {
            pegaOProximo(l, &elem, &temElemento);
        }
    }
    return jaAchou;
}

Node* listaCadastral_generalizada::getHeader()
{
    return this->header;
}
