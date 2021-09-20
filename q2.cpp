#include <iostream>
#include <vector>
#include <string>

class Usuario {
    std::string nome;
public:
    Usuario(std::string nome) {
        this->nome = nome;
    }

    std::string get_nome() {
        return this->nome;
    }
};

int main() {
    std::vector<Usuario> cadastro;
    
    bool done = false;
    bool nome_existe = false;

    while (!done) {
        nome_existe = false;

        std::cout << "Insira o nome do usuário:" << std::endl;
        std::string nome;
        std::cin >> nome;

        for (auto user : cadastro) {
            if (user.get_nome() == nome) {
                nome_existe = true;
                break;
            }
        }

        if (nome_existe) {
            std::cout << "Usuário já cadastrado.";
        } else {
            Usuario u(nome);
            cadastro.push_back(u);
            std::cout << "Usuário " << u.get_nome() << " cadastrado com sucesso!";
        }

        char prompt;
        std::string user_input;

        do {
            std::cout << " Deseja cadastrar outro usuário? [s/n]" << std::endl;
            std::cin  >> user_input;
            prompt = user_input[0];
        }
            while(!std::cin.fail() && prompt != 's' && prompt != 'n');
        
        if (prompt == 'n')
            done = true;
    }
    
    int counter = 1;
    std::cout << "\nUsuários cadastrados:" << std::endl;
    for (auto user : cadastro) {
        std::cout << counter << ": " << user.get_nome() << std::endl;
        counter++;
    }
}