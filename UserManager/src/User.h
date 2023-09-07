#pragma once
#include <string>

namespace Application {
	class User {
	public:
		//Konštruktor, berie meno a heslo, kroré nastaví novému userovi
		User(std::string password, std::string username, std::string role = "user") {
			this->m_Password = password;
			this->m_Username = username;
			this->m_Role = role;
		}

		//Funkcia login, ktorá vráti true ak sa s userom zhodujú login parametre
		bool Login(std::string username, std::string password) {
			return (this->m_Password == password && this->m_Username == username);
		}
		//Funkcia, ktorá vráti meno
		std::string GetUsername() {
			return m_Username;
		}
		//Funkcia, ktorá vráti rolu
		std::string GetRole() {
			return m_Role;
		}
		//Funkcia, ktorá zmení heslo a vždy vráti 1, èo je v main definované ako úspech
		int ChangePassword(std::string password) {
			this->m_Password = password;
			return 1;
		}

	private:
		//Údaje usera
		std::string m_Password;
		std::string m_Username;
		std::string m_Role;
	};
}