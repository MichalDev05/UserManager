#include "Application.h"

int main(){

	//Definova vektor(list) userov
	std::vector<Application::User> users;
	users.push_back(Application::User("nimda", "admin", "admin"));

	//Bool, ktoré urèuje, èi applikácia beí
	bool isRunning = true;

	//Main loop
	while (isRunning) {
		//Hlavné menu, berie input 0, 1, 2
		std::cout << "Create User/Login/Exit: 0/1/2" << "\n";
		std::string input;
		std::cin >> input;
		//If podmenky na ohandlovanie menu
		if (input == "0") {
			//Vytvorenie nového usera. Pouívateå musí zada meno a heslo
			std::cout << "Creating New User" << "\n";
			std::string login, password;
			std::cout << "Username:" << "\n";
			std::cin >> login;
			std::cout << "Password:" << "\n";
			std::cin >> password;
			//Vytvorí novéhu usera a vloí ho do vectoru users
			users.push_back(Application::User(login, password));
			//Vráti sa na zaèiatok while loopu
			continue;
		}
		else if (input == "1") {
			//Pouívae¾ sa prihlasuje, kód pre prihlásenie pokraèue po tıchto if podmienkach
			std::cout << "Logging In" << "\n";
		}
		else if (input == "2") {
			//Exitne aplikáciu tım, e nastaví isRunning na false a potom nás continue vráti na zaèiatok while loopu,
			//lene ten sa u nespustí, lebo isRunning je false.
			//Toto isté sa v tomto prípade dá spravi funkciou "break;"
			std::cout << "Exiting" << "\n";
			isRunning = false;
			continue;
		}
		else {
			//Ak user napísal nieèo iné ne 0, 1, 2 vráti nás na zaèiatok
			std::cout << "Wrong Input"  << "\n";
			continue;
		}

		//Pokraèovanie logiu, user musí zada meno a heslo
		std::string login, password;
		std::cout << "Username:" << "\n";
		std::cin >> login;
		std::cout << "Password:" << "\n";
		std::cin >> password;
		
		bool isLoggedIn = false;

		//Prebehneme cez kadého vytvoreného usera a checkeneme, èi sa login informácie zhodujú
		for (int i = 0; i < users.size(); i++)
		{
			//Vytvorenie odkazu na usera vo vektore s indexom i
			Application::User& user = users[i];
			//Vráti, èi sa login informácie zhodujú
			isLoggedIn = user.Login(login, password);
			if (isLoggedIn) {
				//Login je správny, zavolá sa funkcia, ktorá keï vráti 0, vrátime sa na zaèiatok while loopu
				std::cout << "You Are Logged In as " + (std::string)user.GetUsername() << "\n";
				if (LogIn(user) == 0) {
					break;
				}
				

			}
		}
		if (!isLoggedIn) {
			//Ani jeden user sa nezhoduje
			std::cout << "Wrong Login Or Password!!!" << "\n";
		}
		

	}

}

int LogIn(Application::User& user) {
	//Menu usera
	if (user.GetRole() == "admin") {
		std::cout << "Logout/Change Password/Easter Egg: 0/1/2" << "\n";
	}
	else {
		std::cout << "Logout/Change Password: 0/1" << "\n";
	}
	std::string input;
	std::cin >> input;
	if (input == "0") {
		//Logout, vráti 0, èo nás v main funkcii vráti na zaèiatok
		return 0;
	}
	else if (input == "1") {
		//Zmena hesla
		std::string newPassword;
		std::cout << "New Password:" << "\n";
		std::cin >> newPassword;
		//Zavolá funkciu v userovi, ktorá zmení heslo.
		//Ak vráti true, všetko prebehlo v poriadku, èo sa v tomto prípade stane 100%
		if (user.ChangePassword(newPassword)) {
			std::cout << "Password Changed!" << "\n";
		}
		//Vráti nás na zaèiatok tejto funkcie
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