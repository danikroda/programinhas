#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// ------------------- Classe Atendente -------------------
class Atendente {
private:
    string login;
    string senha;

public:
    Atendente(string l, string s) : login(l), senha(s) {}

    bool autenticar(string l, string s) {
        return (login == l && senha == s);
    }

    string getLogin() {
        return login;
    }
};

// ------------------- Classe Cliente -------------------
class Cliente {
public:
    string nome;
    string cpf;

    Cliente(string nome, string cpf) : nome(nome), cpf(cpf) {}
};

// ------------------- Classe Quarto -------------------
class Quarto {
public:
    string tipo;
    double valorDiaria;
    bool reservado;

    Quarto(string tipo, double valor) : tipo(tipo), valorDiaria(valor), reservado(false) {}
};

// ------------------- Classe Hotel -------------------
class Hotel {
public:
    string localidade;
    map<string, Quarto> quartos;

    Hotel(string localidade) : localidade(localidade) {
        quartos["Solteiro"] = Quarto("Solteiro", 200.0);
        quartos["Duplo"] = Quarto("Duplo", 300.0);
        quartos["Casal"] = Quarto("Casal", 350.0);
        quartos["Triplo"] = Quarto("Triplo", 450.0);
        quartos["Quádruplo"] = Quarto("Quádruplo", 550.0);
    }

    bool verificarDisponibilidade(string tipo) {
        return !quartos[tipo].reservado;
    }

    void reservarQuarto(string tipo) {
        quartos[tipo].reservado = true;
    }

    double getValorDiaria(string tipo) {
        return quartos[tipo].valorDiaria;
    }
};

// ------------------- Classe Reserva -------------------
class Reserva {
public:
    Hotel* hotel;
    Cliente cliente;
    string tipoQuarto;
    int numDiarias;
    string dataCheckin;
    double desconto;

    Reserva(Hotel* hotel, Cliente cliente, string tipoQuarto, int dias, string data, double desc)
        : hotel(hotel), cliente(cliente), tipoQuarto(tipoQuarto), numDiarias(dias), dataCheckin(data), desconto(desc) {}

    double calcularTotal() {
        double valor = hotel->getValorDiaria(tipoQuarto) * numDiarias;
        return valor * (1.0 - desconto);
    }

    double calcularEntrada() {
        return calcularTotal() / 3.0;
    }

    void confirmarReserva() {
        hotel->reservarQuarto(tipoQuarto);
    }

    void imprimirResumo() {
        cout << "Reserva confirmada para " << cliente.nome << " - CPF: " << cliente.cpf << endl;
        cout << "Hotel: " << hotel->localidade << " | Tipo de Quarto: " << tipoQuarto << endl;
        cout << "Data de Check-in: " << dataCheckin << " | Diárias: " << numDiarias << endl;
        cout << "Valor total: R$" << calcularTotal() << " | Entrada: R$" << calcularEntrada() << endl;
    }
};

// ------------------- Classe SistemaReserva -------------------
class SistemaReserva {
private:
    vector<Atendente> atendentes;
    vector<Hotel> hoteis;

public:
    SistemaReserva() {
        atendentes.push_back(Atendente("atendente1", "senha1"));
        atendentes.push_back(Atendente("atendente2", "senha2"));
        atendentes.push_back(Atendente("atendente3", "senha3"));
        atendentes.push_back(Atendente("atendente4", "senha4"));

        hoteis.push_back(Hotel("Jericoacoara"));
        hoteis.push_back(Hotel("Canoa Quebrada"));
        hoteis.push_back(Hotel("Cumbuco"));
    }

    Atendente* login(string l, string s) {
        for (auto& a : atendentes) {
            if (a.autenticar(l, s)) return &a;
        }
        return nullptr;
    }

    Hotel* selecionarHotel(string localidade) {
        for (auto& h : hoteis) {
            if (h.localidade == localidade) return &h;
        }
        return nullptr;
    }
};

int main() {
    SistemaReserva sistema;
    string login, senha;
    cout << "Login: ";
    cin >> login;
    cout << "Senha: ";
    cin >> senha;

    Atendente* atendente = sistema.login(login, senha);
    if (!atendente) {
        cout << "Acesso negado." << endl;
        return 0;
    }

    cout << "Acesso permitido! Bem-vindo, " << atendente->getLogin() << endl;

    string nome, cpf, localidade, tipoQuarto, data;
    int dias;
    double desconto = 0.0;

    cout << "Nome do cliente: ";
    cin >> nome;
    cout << "CPF: ";
    cin >> cpf;
    cout << "Localidade (Jericoacoara/Canoa Quebrada/Cumbuco): ";
    cin >> localidade;
    cout << "Tipo de quarto: ";
    cin >> tipoQuarto;
    cout << "Número de diárias: ";
    cin >> dias;
    cout << "Data de check-in: ";
    cin >> data;

    cout << "Aplicar desconto? (s/n): ";
    char d;
    cin >> d;
    if (d == 's') desconto = 0.1;

    Hotel* hotel = sistema.selecionarHotel(localidade);
    if (!hotel || !hotel->verificarDisponibilidade(tipoQuarto)) {
        cout << "Quarto indisponível!" << endl;
        return 0;
    }

    Cliente cliente(nome, cpf);
    Reserva r(hotel, cliente, tipoQuarto, dias, data, desconto);
    r.confirmarReserva();
    r.imprimirResumo();

    return 0;
}
