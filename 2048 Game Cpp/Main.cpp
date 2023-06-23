#include<iostream>
#include<time.h>
#include<cstdlib>
#include<iomanip>
#include<fstream>
#include<Windows.h>
#include<string>


using namespace std;

WORD GetConsoleTextAttribute(HANDLE hCon);
void MENU_Roofcolor(string a);
void MENU_Centercolor(string a);
void MENU_Basecolor(string a);
void MENU_Start_View();
void Start_up_View();
void Menu_Page();
void Control_Page();
char Get_Operation_Key(char& Operational_Key);
void Game_Page();
void Instruction_Page();
void Credits_Page();
int Foundation_Array[4][4];
int Row_wise_Movement[] = { 1,0,-1,0 };
int Column_wise_Movement[] = { 0,1,0,-1 };
int Score = 0, New_Score = 0;
void Score_Read();
void Score_Write();
void Add_New_Block();
bool End_Game(int a[4][4]);
void Game_Over();
void New_Game();
bool Can_Move(int line, int column, int nextline, int nextcolumn);
void Movement_Control(int direction);
int Block_Place_Specifier[15];

ifstream read;
ofstream write;

int main()
{
	Menu_Page();

	system("pause");
	return 0;
}
/////////////////////////////////////////////////////////Color Function
WORD GetConsoleTextAttribute(HANDLE hCon)
{
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}
///////////////////////////////////////////////////////// 2048 top color
void MENU_Roofcolor(string a)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 86);
	cout << a;
}
//////////////////////////////////////////////////////// 2048 center color
void MENU_Centercolor(string a)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 95);
	cout << a;
}
//////////////////////////////////////////////////////// 2048 bottom color
void MENU_Basecolor(string a)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 89);
	cout << a;
}
//////////////////////////////////////////////////////// menu page start and end line color and appeareance
void MENU_Start_View()
{
	for (int x = 0; x < 40; x++)
	{
		MENU_Roofcolor("=");
		Sleep(10);
		MENU_Centercolor("=");
		Sleep(5);
		MENU_Basecolor("=");
	}
}
/////////////////////////////////////////////////////// other pages start and end line appeareance
void Start_up_View()
{
	for (int x = 0; x < 60; x++)
	{
		cout << "=";
		Sleep(5);
		cout << "=";
	}
}
/////////////////////////////////////////////////////// first page on program start and options provided
void Menu_Page()
{
	system("COLOR 5F");
	MENU_Start_View();
	cout << "\n\n\n\n\n";
	MENU_Roofcolor("\t\t\t\t _________    _________     ___         ___     _________ \n");
	MENU_Roofcolor("\t\t\t\t|_______  |  |  _____  |   |   |       |   |   |  _____  |\n");
	MENU_Roofcolor("\t\t\t\t        | |  | |     | |   |   |       |   |   | |     | |\n");
	MENU_Centercolor("\t\t\t\t _______| |  | |     | |   |   |_______|   |   | |_____| |\n");
	MENU_Centercolor("\t\t\t\t| ________|  | |     | |   |___________    |   |  _____  |\n");
	MENU_Centercolor("\t\t\t\t| |          | |     | |               |   |   | |     | |\n");
	MENU_Basecolor("\t\t\t\t| |_______   | |_____| |               |   |   | |_____| |\n");
	MENU_Basecolor("\t\t\t\t|_________|  |_________|               |___|   |_________|\n\n\n\n\n");
	int Select_Option;
	MENU_Basecolor("\t\t\t\t\t\tPress 1 ====>> Play\n");
	MENU_Roofcolor("\t\t\t\t\t\tPress 2 ====>> High Score\n");
	MENU_Centercolor("\t\t\t\t\t\tPress 3 ====>> Instructions\n");
	MENU_Basecolor("\t\t\t\t\t\tPress 4 ====>> Credits\n");
	MENU_Roofcolor("\t\t\t\t\t\tPress 5 ====>> Quit\n\n\n");
	MENU_Centercolor("\t\t\tPlease, Insert Your Desired Option\n\n");
	MENU_Start_View();
	cout << "\t\t\t\t\t";
	cin >> Select_Option;
	MENU_Start_View();
	system("cls");
	int Return_Option;
	switch (Select_Option)
	{
	case 1:
		Control_Page();
		cout << "\n\n\t\t\tPress 1 ==>> Return To Main Menu\n";
		cin >> Return_Option;
		if (Return_Option == 1)
		{
			system("cls");
			Menu_Page();
		}
		break;
	case 2:
		system("color 6f");
		Start_up_View();
		cout << "\n\n\n\n\t\t\t\t\t\t";
		cout << "High Score : ";
		Score_Read();
		cout << "\n\n\n";
		Start_up_View();
		cout << "\n\n\t\t\tPress 1 ==>> Return To Main Menu\n";
		cin >> Return_Option;
		if (Return_Option == 1)
		{
			system("cls");
			Menu_Page();
		}
		break;
	case 3:
		Instruction_Page();
		cout << "\n\n\t\t\tPress 1 ==>> Return To Main Menu\n";
		cin >> Return_Option;
		if (Return_Option == 1)
		{
			system("cls");
			Menu_Page();
		}
		break;
	case 4:
		Credits_Page();
		cout << "\n\n\t\t\tPress 1 ==>> Return To Main Menu\n";
		cin >> Return_Option;
		if (Return_Option == 1)
		{
			system("cls");
			Menu_Page();
		}
		break;
	case 5:
		system("color 6f");
		Start_up_View();
		cout << "\n\n\n\t\t\t\t\t\tThank You!\n\n\n";
		Start_up_View();
		break;
	default:
		system("color 4f");
		cout << "\t\t\t\t\t\tInvalid Option \n"
			<< "\t\t\t\t\tPlease! Insert Correct Option\n";
		cout << "\n\n\t\t\tPress 1 ==>> Return To Main Menu\n";
		cin >> Return_Option;
		if (Return_Option == 1)
		{
			system("cls");
			Menu_Page();
		}
		break;
	}
}
/////////////////////////////////////////////////////// after every move addition of 2 in new position
void Add_New_Block()
{
	int	count = 0, x, i;
	srand(time(0));
	for (i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (!Foundation_Array[i][j]) {
				Block_Place_Specifier[count++] = i;
				Block_Place_Specifier[count++] = j;
			}
	if (count) {
		x = rand() % count;
		if (x % 2 == 0)
		{
			Foundation_Array[Block_Place_Specifier[x]][Block_Place_Specifier[x + 1]] = 2;

		}
		else      Foundation_Array[Block_Place_Specifier[x - 1]][Block_Place_Specifier[x]] = 2;
	}
}
/////////////////////////////////////////////////////// getting command from user and operating accordingly 
char Get_Operation_Key(char& Operational_Key) {

	while (true) {

		bool pressed = false;

		if (GetAsyncKeyState(VK_LEFT) & 0x8000 != 0) {
			Operational_Key = 'a';
			pressed = true;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 != 0) {
			Operational_Key = 'd';
			pressed = true;
		}
		else if (GetAsyncKeyState(VK_UP) & 0x8000 != 0) {
			Operational_Key = 'w';
			pressed = true;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000 != 0) {
			Operational_Key = 's';
			pressed = true;
		}
		else if (GetAsyncKeyState(VK_END) & 0x8000 != 0) {
			Operational_Key = 'n';
			pressed = true;
		}
		else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000 != 0) {
			Operational_Key = 'q';
			pressed = true;
		}
		else  if (GetAsyncKeyState(VK_SPACE) & 0x8000 != 0) {
			Operational_Key = 'p';
			cout << "\n\n\n\t\t\t\tGame Paused\n";
			pressed = true;
		}
		else  if (GetAsyncKeyState(VK_RETURN)) {
			Operational_Key = 'r';
			pressed = true;
		}

		if (pressed) {
			break;
		}
	}
	return Operational_Key;
}
/////////////////////////////////////////////////////// page that is basicaaly controls all the operatoions of the game
void Control_Page()
{
	Score_Read();
	char Operational_Key, Direction_Control[128], Present_Key;
	Direction_Control['a'] = 3;
	Direction_Control['s'] = 0;
	Direction_Control['d'] = 1;
	Direction_Control['w'] = 2;
	srand(time(0));
	New_Game();
	while (true)
	{
		Game_Page();

		Get_Operation_Key(Operational_Key);
		if (Operational_Key == 'n')
		{
			New_Game();
		}
		else if (Operational_Key == 'q')
		{
			break;
		}
		else if (Operational_Key == 'p')
		{
			do {
				Get_Operation_Key(Operational_Key);
				continue;
			} while (Operational_Key != 'r');
		}
		else
		{
			Present_Key = Direction_Control[Operational_Key];
			Movement_Control(Present_Key);
		}
		if (!End_Game(Foundation_Array))
		{
			Game_Over();
			break;
		}
		system("cls");
	}
}
/////////////////////////////////////////////////////// table and score appeareance on console 
void Game_Page()
{
	system("color 3f");
	cout << "\n\n\n";
	cout << " ______ ______ ______ ______" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "|      |      |      |      |" << endl;
		for (int j = 0; j < 4; j++)
		{
			if (Foundation_Array[i][j] == 0)
			{
				cout << "|" << "      ";
			}
			else
			{
				int Remainder, Value_holder;
				int k;
				Value_holder = Foundation_Array[i][j];
				for (k = 0; Foundation_Array[i][j] != 0; k++)
				{

					Remainder = Foundation_Array[i][j] % 10;
					Foundation_Array[i][j] /= 10;
				}
				Foundation_Array[i][j] = Value_holder;
				if (k == 1)
				{
					cout << "|   " << Foundation_Array[i][j] << "  ";
				}
				if (k == 2)
				{
					cout << "|  " << Foundation_Array[i][j] << "  ";
				}
				if (k == 3)
				{
					cout << "| " << Foundation_Array[i][j] << "  ";
				}
				if (k == 4)
				{
					cout << "| " << Foundation_Array[i][j] << " ";
				}
			}
		}
		cout << "|" << endl;
		cout << "|______|______|______|______|" << endl;

	}
	cout << "\n\n\n\t\t\tScore : " << Score-4 << endl;
	cout << "\t\t\tHigh Score: " << New_Score << endl;
	if (Score > New_Score)
	{
		New_Score = Score;
		Score_Write();
	}
	
}
/////////////////////////////////////////////////////// when user waants to start new game
void New_Game()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Foundation_Array[i][j] = 0;
		}
	}
	Add_New_Block();
}
/////////////////////////////////////////////////////// when all the blocks of table are filled and no more moves are allowed
bool End_Game(int a[4][4])
{
	bool Verify_1 = false, Verify_2 = false;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] == 0)
			{
				Verify_1 = true;
				break;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i + 1][j] == a[i][j] || a[i][j + 1] == a[i][j])
			{
				Verify_2 = true;
				break;
			}
		}
	}

	if (Verify_1 == true || Verify_2 == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/////////////////////////////////////////////////////////////////////////game over massage
void Game_Over()
{
	system("cls");
	system("Color 3F");
	Start_up_View();
	cout << "\n\n\n";
	cout << "    >===>          >>       >=>       >=> >=======>           >===>      >=>         >=> >=======> >======>     \n";
	cout << "  >>    >=>       >>=>      >> >=>   >>=> >=>               >=>    >=>    >=>       >=>  >=>       >=>    >=>   \n";
	cout << " >=>             >> >=>     >=> >=> > >=> >=>             >=>        >=>   >=>     >=>   >=>       >=>    >=>   \n";
	cout << " >=>            >=>  >=>    >=>  >=>  >=> >=====>         >=>        >=>    >=>   >=>    >=====>   >> >==>      \n";
	cout << " >=>   >===>   >=====>>=>   >=>   >>  >=> >=>             >=>        >=>     >=> >=>     >=>       >=>  >=>     \n";
	cout << "  >=>    >>   >=>      >=>  >=>       >=> >=>               >=>     >=>       >===>      >=>       >=>    >=>   \n";
	cout << "   >====>    >=>        >=> >=>       >=> >=======>           >===>            >=>       >=======> >=>      >=> \n";
	cout << "\n\n\n";
	Start_up_View();
}
/////////////////////////////////////////////////////////////////////// saving score and showing on console
void Score_Read()
{
	read.open("result.txt");

	if (read.is_open())
	{
		while (read.good())
		{
			read >> New_Score;
			cout << New_Score;
		}

		read.clear();
		read.seekg(0);

		read.close();
	}
	else
	{
		cout << "Failed to open the file." << endl;
	}
}
void Score_Write()
{
	write.open("result.txt");
	write << New_Score;
	write.close();
}
/////////////////////////////////////////////////////////////////////// move availability check
bool Can_Move(int line, int column, int nextline, int nextcolumn)
{
	if (nextline < 0 || nextline >= 4 || nextcolumn < 0 || nextcolumn >= 4 ||
		Foundation_Array[line][column] != Foundation_Array[nextline][nextcolumn] && Foundation_Array[nextline][nextcolumn] != 0)
	{
		return false;

	}
	return true;
}
////////////////////////////////////////////////////////////////////// moves of the game are control in this block of code and score addition
void Movement_Control(int direction)
{
	int Move_Allowed, i, j, nexti, nextj;
	do
	{
		Move_Allowed = 0;
		for (i = 0; i >= 0 && i < 4; i++)
		{
			for (j = 0; j >= 0 && j < 4; j++)
			{
				nexti = i + Row_wise_Movement[direction], nextj = j + Column_wise_Movement[direction];
				if (Foundation_Array[i][j] && Can_Move(i, j, nexti, nextj))
				{
					if (Foundation_Array[nexti][nextj] == Foundation_Array[i][j])
					{
						Score += Foundation_Array[nexti][nextj] + Foundation_Array[i][j];
					}
					Foundation_Array[nexti][nextj] += Foundation_Array[i][j];
					Foundation_Array[i][j] = 0;
					Move_Allowed = 1;
				}
			}
		}
	} while (Move_Allowed);
	Add_New_Block();
}////////////////////////////////////////////////////////////////////// instruction page of game controls
void Instruction_Page()
{
	system("COLOR 8F");
	Start_up_View();
	cout << endl;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 143);
	cout << setw(52) << setfill('(') << " ";
	SetConsoleTextAttribute(hConsole, 128);
	cout << "( INSTRUCTIONS )";
	SetConsoleTextAttribute(hConsole, 143);
	cout << left;
	cout << setw(52) << setfill(')') << " ";
	cout << endl << endl;
	SetConsoleTextAttribute(hConsole, 128);
	cout << right;
	cout << setw(55) << setfill('$') << " ";
	SetConsoleTextAttribute(hConsole, 135);
	cout << "{ TO PLAY )";
	SetConsoleTextAttribute(hConsole, 128);
	cout << left;
	cout << setw(54) << setfill('$') << "  ";
	cout << endl << endl;
	SetConsoleTextAttribute(hConsole, 139);
	cout << right;
	cout << "\t\t\t\t\t      New Game  =====>> Press \"END\"\n";
	cout << "\t\t\t\t   ";
	cout << setw(52) << setfill('_') << " " << endl << endl;
	SetConsoleTextAttribute(hConsole, 142);
	cout << "\t\t\t\t\t     Quit Game  =====>> Press \"ESCAPE\"\n";
	cout << "\t\t\t\t   ";
	cout << setw(52) << setfill('_') << " " << endl << endl;
	SetConsoleTextAttribute(hConsole, 139);
	cout << "\t\t\t\t\t    Pause Game  =====>> Press \"SPACE\"\n";
	cout << "\t\t\t\t   ";
	cout << setw(52) << setfill('_') << " " << endl << endl;
	SetConsoleTextAttribute(hConsole, 142);
	cout << "\t\t\t\t\t   Resume Game  =====>> Press \"ENTER\"\n";
	cout << "\t\t\t\t   ";
	cout << setw(52) << setfill('_') << " " << endl << endl;
	SetConsoleTextAttribute(hConsole, 139);
	cout << "\t\t\t\t\t   Up_Movement  =====>> Press \"UP_ARROW\"\n";
	cout << "\t\t\t\t   ";
	cout << setw(52) << setfill('_') << " " << endl << endl;
	SetConsoleTextAttribute(hConsole, 142);
	cout << "\t\t\t\t\t  Down_Movement =====>> Press \"DOWN_ARROW\"\n";
	cout << "\t\t\t\t   ";
	cout << setw(52) << setfill('_') << " " << endl << endl;
	SetConsoleTextAttribute(hConsole, 139);
	cout << "\t\t\t\t\tRight_Movement  =====>> Press \"RIGHT_ARROW\"\n";
	cout << "\t\t\t\t   ";
	cout << setw(52) << setfill('_') << " " << endl << endl;
	SetConsoleTextAttribute(hConsole, 142);
	cout << "\t\t\t\t\tLeft_Movement   =====>> Press \"LEFT_ARROW\"\n";
	Start_up_View();
	Start_up_View();
}
/////////////////////////////////////////////////////////////////////// creadit page
void Credits_Page()
{
	system("COLOR 4F");
	Start_up_View();
	cout << endl << endl;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 71);
	cout << setw(51) << setfill('(') << " ";
	SetConsoleTextAttribute(hConsole, 67);
	cout << "( ====>>> CREDITS )";
	SetConsoleTextAttribute(hConsole, 71);
	cout << left;
	cout << setw(50) << setfill(')') << " ";
	cout << endl << endl;
	SetConsoleTextAttribute(hConsole, 79);
	cout << right;
	cout << setw(53) << setfill('$') << " ";
	SetConsoleTextAttribute(hConsole, 67);
	cout << "{ CREATED BY )";
	SetConsoleTextAttribute(hConsole, 79);
	cout << left;
	cout << setw(53) << setfill('$') << "  ";
	cout << endl << endl;
	SetConsoleTextAttribute(hConsole, 78);
	cout << "\t\t\t\t\tN A M E:\n";
	SetConsoleTextAttribute(hConsole, 79);
	cout << "\t\t\t\t\t\tM U H A M M A D\n\t\t\t\t\t\t  M U N E E B\n\t\t\t\t\t\t      U R\n\t\t\t\t\t\t  R E H M A N\n";
	SetConsoleTextAttribute(hConsole, 78);
	cout << "\t\t\t\t   R O L L  N O:\n";
	SetConsoleTextAttribute(hConsole, 75);
	cout << "\t\t\t\t\t\t     2 0 F \n\t\t\t\t\t\t       -\n\t\t\t\t\t\t    0 2 1 0\n";
	SetConsoleTextAttribute(hConsole, 78);
	cout << "\t\t\t\t  S E C T I O N:\n";
	SetConsoleTextAttribute(hConsole, 71);
	cout << "\t\t\t\t\t\t  B S ( C S )\n\t\t\t\t\t\t       -\n\t\t\t\t\t\t      1 A\n";
	SetConsoleTextAttribute(hConsole, 78);
	cout << "\t\t\t\t  C O N T A C T:\n";
	SetConsoleTextAttribute(hConsole, 71);
	cout << "\t\t\t\t\t\t  f 2 0 0 2 1 0 \n\t\t\t\t\t\t   @ g m a i l \n\t\t\t\t\t\t    . c o m\n\n\n\n";
	Start_up_View();
	Start_up_View();
}
