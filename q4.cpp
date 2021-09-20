#include <iostream>
#include <map>
#include <string>
#include <vector>

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

    // Cadastro de usuários
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
            std::cout << "\nUsuário " << u.get_nome() << " cadastrado com sucesso!";
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

    done = false;
    
    // Mecanismo de busca

    std::vector<int> matches;

    while (!done) {

        matches.clear();

        std::string user_input;
        bool found = false;
        auto match = cadastro.begin();

        do {
            std::cout << "\nDeseja buscar por nome ou CPF? [nome/cpf/sair]" << std::endl;
            std::cin  >> user_input;
        }
            while(!std::cin.fail() && user_input != "nome" && user_input != "cpf" && user_input != "sair");
        
        // Sair
        if (user_input == "sair") {
            done = true;
            continue;
        }

        // Busca por nome
        if (user_input == "nome") {
            std::string nome;

            std::cout << "Digite um nome:" << std::endl;
            std::cin  >> nome;

            for (auto itr = cadastro.begin(); itr != cadastro.end(); itr++) {
                if (itr->second.get_nome() == nome) {
                    matches.push_back(itr->first);
                    found = true;
                }
            }
        }

        // Busca por CPF
        if (user_input == "cpf") {
            int cpf;

            std::cout << "Digite um CPF:" << std::endl;
            std::cin  >> cpf;

            if (cadastro.count(cpf)) {
                match = cadastro.find(cpf);
                found = true;
            }
        }

        // Resultado da busca
        if (found) {
            if (user_input == "cpf") {
                std::cout << "\nUsuário encontrado!" << std::endl;
                std::cout << "CPF:  " << match->first << std::endl;
                std::cout << "Nome: " << match->second.get_nome() << std::endl;

                char prompt;
                std::string user_input;

                do {
                    std::cout << "Deseja remover este usuário? [s/n]" << std::endl;
                    std::cin  >> user_input;
                    prompt = user_input[0];
                }
                    while(!std::cin.fail() && prompt != 's' && prompt != 'n');
                
                if (prompt == 's')
                    cadastro.erase(match);
            } if (user_input == "nome") {
                if (matches.size() > 1) {
                    std::cout << "\nMúltiplos usuários encontrados!" << std::endl;
                    for (auto cpf : matches) {
                        match = cadastro.find(cpf);
                        std::cout << "\nCPF:  " << match->first << std::endl;
                        std::cout << "Nome: "   << match->second.get_nome() << std::endl;
                    }
                } else {
                    match = cadastro.find(matches[0]);
                    std::cout << "\nUsuário encontrado!" << std::endl;
                    std::cout << "\nCPF:  " << match->first << std::endl;
                    std::cout << "Nome: "   << match->second.get_nome() << std::endl;
                }
            }
        } else {
            std::cout << "Usuário não encontrado." << std::endl;
        }
    }
}