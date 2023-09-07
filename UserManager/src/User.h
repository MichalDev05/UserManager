#pragma once
#include <string>

namespace Application {
	class User {
	public:
		User(std::string password, std::string username, std::string role = "user") {
			this->m_Password = password;
			this->m_Username = username;
			this->m_Role = role;
		}

		bool Login(std::string username, std::string password) {
			return (this->m_Password == password && this->m_Username == username);
		}

		std::string GetUsername() {
			return m_Username;
		}

		std::string GetRole() {
			return m_Role;
		}

		int ChangePassword(std::string password) {
			this->m_Password = password;
			return 1;
		}

	private:
		std::string m_Password;
		std::string m_Username;
		std::string m_Role;
	};
}