#include "Application.h"

int main(){

	//Definova� vektor(list) userov
	std::vector<Application::User> users;
	users.push_back(Application::User("nimda", "admin", "admin"));

	//Bool, ktor� ur�uje, �i applik�cia be��
	bool isRunning = true;

	//Main loop
	while (isRunning) {
		//Hlavn� menu, berie input 0, 1, 2
		std::cout << "Create User/Login/Exit: 0/1/2" << "\n";
		std::string input;
		std::cin >> input;
		//If podmenky na ohandlovanie menu
		if (input == "0") {
			//Vytvorenie nov�ho usera. Pou��vate� mus� zada� meno a heslo
			std::cout << "Creating New User" << "\n";
			std::string login, password;
			std::cout << "Username:" << "\n";
			std::cin >> login;
			std::cout << "Password:" << "\n";
			std::cin >> password;
			//Vytvor� nov�hu usera a vlo�� ho do vectoru users
			users.push_back(Application::User(login, password));
			//Vr�ti sa na za�iatok while loopu
			continue;
		}
		else if (input == "1") {
			//Pou��va�e� sa prihlasuje, k�d pre prihl�senie pokra�ue po t�chto if podmienkach
			std::cout << "Logging In" << "\n";
		}
		else if (input == "2") {
			//Exitne aplik�ciu t�m, �e nastav� isRunning na false a potom n�s continue vr�ti na za�iatok while loopu,
			//len�e ten sa u� nespust�, lebo isRunning je false.
			//Toto ist� sa v tomto pr�pade d� spravi� funkciou "break;"
			std::cout << "Exiting" << "\n";
			isRunning = false;
			continue;
		}
		else {
			//Ak user nap�sal nie�o in� ne� 0, 1, 2 vr�ti n�s na za�iatok
			std::cout << "Wrong Input"  << "\n";
			continue;
		}

		//Pokra�ovanie logiu, user mus� zada� meno a heslo
		std::string login, password;
		std::cout << "Username:" << "\n";
		std::cin >> login;
		std::cout << "Password:" << "\n";
		std::cin >> password;
		
		bool isLoggedIn = false;

		//Prebehneme cez ka�d�ho vytvoren�ho usera a checkeneme, �i sa login inform�cie zhoduj�
		for (int i = 0; i < users.size(); i++)
		{
			//Vytvorenie odkazu na usera vo vektore s indexom i
			Application::User& user = users[i];
			//Vr�ti, �i sa login inform�cie zhoduj�
			isLoggedIn = user.Login(login, password);
			if (isLoggedIn) {
				//Login je spr�vny, zavol� sa funkcia, ktor� ke� vr�ti 0, vr�time sa na za�iatok while loopu
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
		//Logout, vr�ti 0, �o n�s v main funkcii vr�ti na za�iatok
		return 0;
	}
	else if (input == "1") {
		//Zmena hesla
		std::string newPassword;
		std::cout << "New Password:" << "\n";
		std::cin >> newPassword;
		//Zavol� funkciu v userovi, ktor� zmen� heslo.
		//Ak vr�ti true, v�etko prebehlo v poriadku, �o sa v tomto pr�pade stane 100%
		if (user.ChangePassword(newPassword)) {
			std::cout << "Password Changed!" << "\n";
		}
		//Vr�ti n�s na za�iatok tejto funkcie
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