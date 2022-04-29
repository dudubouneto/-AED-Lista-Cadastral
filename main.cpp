//
//  main.cpp
//  F6_listaCadastral_generalizada
//
//  Created by Eduardo Bouhid Neto on 22/09/21.
//
//

#include <iostream>
#include "listaCadastral_generalizada.hpp"

void imprime(listaCadastral_generalizada* l);
listaCadastral_generalizada* uniao(listaCadastral_generalizada* l1, listaCadastral_generalizada* l2);
listaCadastral_generalizada* interseccao(listaCadastral_generalizada* l1, listaCadastral_generalizada* l2);
using namespace std;

void manipulaLista(listaCadastral_generalizada* lista)
{
    bool deuCerto;
    string nome;
    //"Interface"
    int controle = 0;
    while (controle != 4) {
        cout << "O que deseja fazer?" << endl;
        cout << "1. Adicionar um nome no inicio da lista" << endl;
        cout << "2. Adicionar um nome a direita de algum elemento presente" << endl;
        cout << "3. Remover um nome da lista" << endl;
        cout << "4. Encerrar a manipulação" << endl;
        cin >> controle;
        std::cin.ignore(256,'\n');
        switch (controle) {
            case 1:
                cout << "Digite o nome a ser adicionado: ";
                getline(cin, nome);
                lista->insereADireitaDeP(lista, lista->getHeader(), nome, &deuCerto);
                if (deuCerto) {
                    cout << "Operacao feita com sucesso." << endl ;
                    cout << "A lista se encontra assim: " << endl;
                    imprime(lista);
                    cout << endl;
                } else {
                    cout << "Erro na operacao." << endl;
                }
                break;
            case 2:
                {cout << "Digite o nome a ser adicionado: ";
                getline(cin, nome);
                string nomeAEsquerda;
                Node* pAEsquerda;
                cout << "Digite o nome a direita de que deseja adicionar \"" << nome << "\": ";
                getline(cin, nomeAEsquerda);
                //Buscando o elemento de "referencia" para a inserção do nome
                if (lista->estaNaLista(lista, nomeAEsquerda, &pAEsquerda)) {
                    //Realizando a inserção
                    lista->insereADireitaDeP(lista, pAEsquerda, nome, &deuCerto);
                    if (deuCerto) {
                        cout << "Operacao feita com sucesso!" << endl;
                    } else {
                        cout << "Erro na operacao" << endl;
                    }
                } else {
                    cout << "Erro; Elemento nao encontrado." << endl;
                }
                    cout << "A lista encontra-se assim: " << endl;
                    imprime(lista);
                break;}
            case 3:
                cout << "Digite o nome a ser removido: ";
                getline(cin, nome);
                Node* target;
                if (lista->estaNaLista(lista, nome, &target)) {
                    lista->removeP(lista, target, &deuCerto);
                    if (deuCerto) {
                        cout << "Operacao feita com suceso.\nA lista se encontra assim: " << endl;
                        imprime(lista);
                        cout << endl;
                    } else {
                        cout << "Erro na operacao." << endl;
                    }
                } else {
                    cout << "Erro; Elemento nao encontrado" << endl;
                }
                break;
            case 4:
                cout << "Encerrando a manipulacao. " << endl;
                break;
            default:
                cout << "Codigo invalido; tente novamente, por favor." << endl;
                break;
        }
    }
}


int main() {
    //Criando e manipulando as listas cadastrais
    listaCadastral_generalizada* lista1 = new listaCadastral_generalizada();
    listaCadastral_generalizada* lista2 = new listaCadastral_generalizada();
    cout << "===MANIPULACAO DA PRIMEIRA LISTA===" << endl;
    manipulaLista(lista1);
    cout << "===MANIPULACAO DA SEGUNDA LISTA===" << endl;
    manipulaLista(lista2);
    int controle = 0;
    while (controle != 3) {
        cout << "Qual operacao deseja fazer?: " << endl;
        cout << "1. Uniao entre das duas listas" << endl;
        cout << "2. Interseccao das duas listas" << endl;
        cout << "3. Encerrar a manipulação" << endl;
        cin >> controle;
        switch (controle) {
            case 1:
                {listaCadastral_generalizada* uni = uniao(lista1, lista2);
                imprime(uni);
                    break;}
            case 2:
                {listaCadastral_generalizada* intersec = interseccao(lista1, lista2);
                imprime(intersec);
                break;}
            case 3:
                cout << "Encerrando a manipulacao." << endl;
                break;
            default:
                cout << "Codigo invalido; Tente novamente." << endl;
                break;
        }
    }
    return 0;
}

void imprime(listaCadastral_generalizada* l) {
    //Pegando elementos sucessivamente até chegarmos ao último
    bool temElemento;
    string elem;
    l->pegaOPrimeiro(l, &elem, &temElemento);
    if (temElemento) {
        cout << "(INICIO) | ";
        while (temElemento) {
            cout << elem + " | ";
            l->pegaOProximo(l, &elem, &temElemento);
            //std::fflush(stdin);
        }
        cout << "(FIM)" << endl;
    } else {
        cout << "(LISTA VAZIA)" << endl;
        }
}

listaCadastral_generalizada* uniao(listaCadastral_generalizada* l1, listaCadastral_generalizada* l2)
{
    //Criando a lista "conjunta"
    listaCadastral_generalizada* listaUnida = new listaCadastral_generalizada();
    bool temElemento, deuCerto;
    string elem;
    Node* nodeAux;
    //Adicionando os elementos de l2 à lista
    l2->pegaOPrimeiro(l2, &elem, &temElemento);
    while (temElemento) {
        listaUnida->insereADireitaDeP(listaUnida, listaUnida->getHeader(), elem, &deuCerto);
        l2->pegaOProximo(l2, &elem, &temElemento);
    }
    //Adicionando os elementos de l1 à lista (se já não tiverem sido adicionados)
    l1->pegaOPrimeiro(l1, &elem, &temElemento);
    while (temElemento) {
        if (!(listaUnida->estaNaLista(listaUnida, elem, &nodeAux))) {
            listaUnida->insereADireitaDeP(listaUnida, listaUnida->getHeader(), elem, &deuCerto);
        }
        l1->pegaOProximo(l1, &elem, &temElemento);
    }
    return listaUnida;
}

listaCadastral_generalizada* interseccao(listaCadastral_generalizada* l1, listaCadastral_generalizada* l2)
{
    //Criando a lista com o resultado
    listaCadastral_generalizada* intersec = new listaCadastral_generalizada();
    //Pegando elementos de l1 e vendo se eles também estão em l2
    Node* pAux;
    bool temElemento, deuCerto;
    string elem;
    l1->pegaOPrimeiro(l1, &elem, &temElemento);
    while (temElemento) {
        if (l2->estaNaLista(l2, elem, &pAux)) {
            intersec->insereADireitaDeP(intersec, intersec->getHeader(), elem, &deuCerto);
        }
        l1->pegaOProximo(l1, &elem, &temElemento);
    }
    return intersec;
}
