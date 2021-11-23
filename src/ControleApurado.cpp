#include "ControleApurado.h"

ControleApurado::ControleApurado()
{
    //ctor
}

ControleApurado::~ControleApurado()
{
    //dtor
}

void ControleApurado::controleApurado(){
    int opcao;
    double saque;
    while (true){
        system("cls");
        cout << "Apurado: R$ " << apurado << endl;
        cout << "Voce deseja sacar o dinheiro:" << endl;
        cout << "[1] SIM - [0] SAIR" << endl;
        cin >> opcao;
        if (opcao){
            cout << "Digite o saque: R$ ";
            cin >> saque;
            if (saque > apurado || saque < 0){
                cout << "Nao foi possivel realizar operacao." << endl;
                usleep(DELAY);
            }else{
                apurado -= saque;
            }
        }else{
            salvarApurado();
            return;
        }
        salvarApurado();
    }
}

void ControleApurado::salvarApurado(){
    ofstream arq = ofstream("apurado.txt", ios::out | ios::trunc);
    if (!arq.is_open()){
        cout << "Falha ao salvar o apurado." << endl;
        usleep(DELAY);
        return;
    }

    arq << apurado;
    arq.close();
}

void ControleApurado::carregarApurado(){
    cout << "Carregango apurado..." << endl;
    ifstream arq = ifstream("apurado.txt");
    if (!arq.is_open()){
        cout << "Falha ao carregar o apurado." << endl;
        usleep(DELAY);
        return;
    }

    arq >> apurado;
    arq.close();
    cout << "Apurado carregado." << endl;
    usleep(DELAY);
}
