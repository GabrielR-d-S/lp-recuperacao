#include <iostream>
#include <map>
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
    std::map<unsigned long, Usuario> cadastro;
    
    bool done = false;

    while (!done) {

        std::cout << "Insira o CPF do usuário:" << std::endl;
        unsigned long cpf;
        std::cin >> cpf;

        std::cout << "Insira o nome do usuário:" << std::endl;
        std::string nome;
        std::cin >> nome;

        if (cadastro.count(cpf))
            std::cout << "CPF já cadastrado.";
        else {
            Usuario u(nome);
            cadastro.insert({cpf, u});
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

    std::cout << "\nUsuários cadastrados:" << std::endl;
    std::cout << "\tCPF\t\tNOME" << std::endl;
    for (auto itr = cadastro.begin(); itr != cadastro.end(); itr++) {
        std::cout << '\t' << itr->first
                  << '\t' << itr->second.get_nome() << '\n';
    }
}