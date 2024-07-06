#include "heap.hpp"

Heap::Heap(int maxsize) {
    data = new int[maxsize];
    tamanho = 0;
}

Heap::~Heap() {
    delete[] data;
}

int Heap::GetAncestral(int i){
    return (i-1)/2;
}
int Heap::GetSucessorEsq(int i){
    return 2 * i + 1;
}
int Heap::GetSucessorDir(int i){
    return 2 * i + 2;
}

bool Heap::Vazio()
{
    return tamanho == 0;
}

void Heap::Inserir(int x) {

    data[tamanho] = x;

    HeapifyPorBaixo(tamanho);

    tamanho++;
        
    
}

int Heap::Remover()
{
    if (Vazio())
        throw "O Heap está vazio";

    int temp = data[0]; tamanho--;

    if(!Vazio())
    {
        data[0] = data[tamanho];

        HeapifyPorCima(0);
    }    
    return temp;
}


void Heap::HeapifyPorBaixo(int posicao)
{
    int atual = posicao, 
    ancestral = GetAncestral(posicao);

    if (atual > 0 && data[atual] < data[ancestral])
    {
        int temp = data[atual];
        data[atual] = data[ancestral];
        data[ancestral] = temp;

        HeapifyPorBaixo(ancestral);
    }   
}


void Heap::HeapifyPorCima(int posicao)
{
    int atual = posicao, menor,
    esquerda = GetSucessorEsq(atual),
    direita = GetSucessorDir(atual);

    if (esquerda >= tamanho)
        return;

    else if (direita >= tamanho)
        menor = esquerda;

    else menor = data[esquerda] < data[direita] ? esquerda : direita;

    if (data[atual] > data[menor])
    {
        int temp = data[atual];
        data[atual] = data[menor];
        data[menor] = temp;

        HeapifyPorCima(menor);
    }

}