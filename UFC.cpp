#include <iostream>
#include <vector>
using namespace std;

class lutadores
{
private:
    string nome;
    string nacionalidade;
    int idade;
    float real, peso;
    string caracter;
    int vitorias, derrotas, empates;

public:
    string getNome() { return nome; }
    void setNome(string nome) { this->nome = nome; }

    string getNacionalidade() { return nacionalidade; }
    void setNacionalidade(string nacionalidade) { this->nacionalidade = nacionalidade; }

    int getIdade() { return idade; }
    void setIdade(int idade) { this->idade = idade; }

    float getPeso() { return peso; }
    void setPeso(float peso) { this->peso = peso; }

    float getReal() { return real; }
    void setReal(float real) { this->real = real; }

    string getCaracter() { return caracter; }
    void setCaracter(string caracter) { this->caracter = caracter; }

    int getVitorias() { return vitorias; }
    void setVitorias(int vitorias) { this->vitorias = vitorias; }

    int getDerrotas() { return derrotas; }
    void setDerrotas(int derrotas) { this->derrotas = derrotas; }

    int getEmpates() { return empates; }
    void setEmpates(int empates) { this->empates = empates; }

    void apresenta(const vector<lutadores *> &lutadoresArray)
    {
        for (size_t i = 0; i < lutadoresArray.size(); i++)
        {
            cout << "Lutador " << i + 1 << ":" << endl;
            cout << "Nome: " << lutadoresArray[i]->getNome() << endl;
            cout << "Idade: " << lutadoresArray[i]->getIdade() << endl;
            cout << "Vitórias: " << lutadoresArray[i]->getVitorias() << endl;
            cout << "-----------------------------------" << endl;
        }
    }

    void ganhouLuta()
    {
        vitorias++; 
    }

    lutadores(string nome, string nacionalidade, int idade, float peso, string caracter, int vitorias, int derrotas, int empates)
    {
        this->nome = nome;
        this->nacionalidade = nacionalidade;
        this->idade = idade;
        this->peso = peso;
        this->caracter = caracter;
        this->vitorias = vitorias;
        this->derrotas = derrotas;
        this->empates = empates;
    }

    ~lutadores() {}
};

int main()
{
    vector<lutadores *> lutadoresArray;

    lutadoresArray.push_back(new lutadores("Shamil Abdurakhimov", "Russo", 43, 119, "Determinado", 10, 0, 1));
    lutadoresArray.push_back(new lutadores("Carlos", "Brasileiro", 28, 80.0, "Focado", 12, 2, 0));

    for (int i = 0; i < 2; i++)
    {
        lutadoresArray[0]->apresenta(lutadoresArray);
    }

  
    cout << "\nShamil Abdurakhimov ganhou uma luta!" << endl;
    lutadoresArray[0]->ganhouLuta(); 

  
    for (int i = 0; i < 2; i++)
    {
        lutadoresArray[0]->apresenta(lutadoresArray);
    }

   
    for (lutadores *lutador : lutadoresArray)
    {
        delete lutador;
    }

    return 0;
}
