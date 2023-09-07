#pragma once
#include <string>

namespace Application {
	class User {
	public:
		//Kon�truktor, berie meno a heslo, kror� nastav� nov�mu userovi
		User(std::string password, std::string username, std::string role = "user") {
			this->m_Password = password;
			this->m_Username = username;
			this->m_Role = role;
		}

		//Funkcia login, ktor� vr�ti true ak sa s userom zhoduj� login parametre
		bool Login(std::string username, std::string password) {
			return (this->m_Password == password && this->m_Username == username);
		}
		//Funkcia, ktor� vr�ti meno
		std::string GetUsername() {
			return m_Username;
		}
		//Funkcia, ktor� vr�ti rolu
		std::string GetRole() {
			return m_Role;
		}
		//Funkcia, ktor� zmen� heslo a v�dy vr�ti 1, �o je v main definovan� ako �spech
		int ChangePassword(std::string password) {
			this->m_Password = password;
			return 1;
		}

	private:
		//�daje usera
		std::string m_Password;
		std::string m_Username;
		std::string m_Role;
	};
}