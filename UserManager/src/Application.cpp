#include "Application.h"

int main(){

	std::vector<Application::User> users;
	users.push_back(Application::User("nimda", "admin", "admin"));

	bool isRunning = true;

	while (isRunning) {
		std::cout << "Create User/Login/Exit: 0/1/2" << "\n";
		std::string input;
		std::cin >> input;

		if (input == "0") {
			std::cout << "Creating New User" << "\n";
			std::string login, password;
			std::cout << "Username:" << "\n";
			std::cin >> login;
			std::cout << "Password:" << "\n";
			std::cin >> password;

			users.push_back(Application::User(login, password));
			continue;
		}
		else if (input == "1") {
			std::cout << "Logging In" << "\n";
		}
		else if (input == "2") {
			std::cout << "Exiting" << "\n";
			isRunning = false;
			continue;
		}
		else {
			std::cout << "Wrong Input"  << "\n";
			continue;
		}

		std::string login, password;
		std::cout << "Username:" << "\n";
		std::cin >> login;
		std::cout << "Password:" << "\n";
		std::cin >> password;
		
		bool isLoggedIn = false;

		for (int i = 0; i < users.size(); i++)
		{
			Application::User& user = users[i];
			isLoggedIn = user.Login(login, password);
			if (isLoggedIn) {
				std::cout << "You Are Logged In as " + (std::string)user.GetUsername() << "\n";
				if (LogIn(user) == 0) {
					break;
				}
				

			}
		}
		if (!isLoggedIn) {
			std::cout << "Wrong Login Or Password!!!" << "\n";
		}
		

	}

}

int LogIn(Application::User& user) {
	if (user.GetRole() == "admin") {
		std::cout << "Logout/Change Password/Easter Egg: 0/1/2" << "\n";
	}
	else {
		std::cout << "Logout/Change Password: 0/1" << "\n";
	}
	std::string input;
	std::cin >> input;

	if (input == "0") {
		return 0;
	}
	else if (input == "1") {
		std::string newPassword;
		std::cout << "New Password:" << "\n";
		std::cin >> newPassword;

		if (user.ChangePassword(newPassword)) {
			std::cout << "Password Changed!" << "\n";
		}
		LogIn(user);
	}
	else if (input == "2" && user.GetRole() == "admin") {
		std::cout << "You Found Me!" << "\n";
		LogIn(user);
	}
	else {
		std::cout << "Wrong Input" << "\n";
		LogIn(user);
	}
}