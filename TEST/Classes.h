#ifndef Classes.h

using namespace std;

class minig_fabrik : public IBTCMiner
{
public:
	minig_fabrik()
	{
		money = get_btc();
	};

	float money;
	
	float get_money(){
		while (money<7)
		{
			money +=get_btc();
			system("cls");
			cout << "Your money: " << money;
		};
		money = 15;
		return money;
	};

	byte come_massege[];

	void take_messege(int take_size_mas, byte mass[], int size_1, int size_2)
	{
		come_massege[take_size_mas];
		for (int i = 0; i <= take_size_mas - 1;i++)
		come_massege[i] = mass[i];

		int BIT = 0;

		switch (come_massege[0])
		{
		case 1:
			Coin _COIN;
			_COIN.cost = 0;
			
			for (int i = take_size_mas; i>=1; i--){
				_COIN.cost = _COIN.cost<<BIT | come_massege[i];
				BIT += 8;
			};

			cout << "!!!!!!!!BINGO!!!!!!!!" << "\n" << "WE TAKE A MESSEGE!!!" << "\n" << "It is coin!!!" << "\n" << "COIN.COST= "<<_COIN.cost<<"\n";
			break;

		case 2:
			Helm _HELM;

			for (int i = take_size_mas; i > size_1 + size_2; i--)
			{
				_HELM.size = (size_t)_HELM.size << BIT | come_massege[i];
				BIT += 8;
			};
			for (int i = size_1 + size_2; i > size_1; i--)
			{
				_HELM.cost = _HELM.cost << BIT | come_massege[i];
				BIT += 8;
			};
			for (int i = size_1; i >= 1; i--)
			{
				_HELM.armor = _HELM.armor << BIT | come_massege[i];
				BIT += 8;
			};
				cout << "!!!!!!!!BINGO!!!!!!!!" << "\n" << "WE TAKE A MESSEGE!!!" << "\n" << "It is HELM!!!" << "\n" << "HELM.ARMOUR= " << _HELM.armor << "\n";
				cout << "HELM.COST= " << _HELM.cost << "\n" << "HELM.SIZE= " << _HELM.size << "\n";
			
			break;

		case 3:
			Jug _jug;

			for (int i = take_size_mas; i > size_1 + size_2; i--)
			{
				_jug.R = (size_t)_jug.R << BIT | come_massege[i];
				BIT += 8;
			};
			for (int i = size_1 + size_2; i > size_1; i--)
			{
				_jug.H = (size_t)_jug.H << BIT | come_massege[i];
				BIT += 8;
			};
			for (int i = size_1; i >= 1; i--)
			{
				_jug.cost = _jug.cost << BIT | come_massege[i];
				BIT += 8;
			};
			cout << "!!!!!!!!BINGO!!!!!!!!" << "\n" << "WE TAKE A MESSEGE!!!" << "\n" << "It is JUG!!!" << "\n" << "JUG.COST= " << _jug.cost << "\n";
			cout << "JUG.H= " << _jug.H << "\n" << "JUG.R= " << _jug.R << "\n";

			break;

		case 4:

			Sword _SWORD;

			for (int i = take_size_mas; i > size_1 + size_2; i--)
			{
				_SWORD.height = (size_t)_SWORD.height << BIT | come_massege[i];
				BIT += 8;
			};
			for (int i = size_1 + size_2; i > size_1; i--)
			{
				_SWORD.damage = (size_t)_SWORD.damage << BIT | come_massege[i];
				BIT += 8;
			};
			for (int i = size_1; i >= 1; i--)
			{
				_SWORD.cost = _SWORD.cost << BIT | come_massege[i];
				BIT += 8;
			};
			cout << "!!!!!!!!BINGO!!!!!!!!" << "\n" << "WE TAKE A MESSEGE!!!" << "\n" << "It is SWORD!!!" << "\n" << "SWORD.COST= " << _SWORD.cost << "\n";
			cout << "SWORD.DAMAGE= " <<_SWORD.damage << "\n" << "SWORD.HEIGHT= " << _SWORD.height << "\n";

			break;
		default:
			break;
		}

		
	};
	
	
	struct Jug
	{
		Value cost;
		Size  R;
		Size  H;
	};

	struct Helm
	{
		Value cost;
		Size  size;
		Value armor;
	};

	struct Coin
	{
		Value cost;
	};

	struct Sword
	{
		Value cost;
		Value damage;
		Value height;
	};


};

class shop : public evil::api
{
public:
	shop()
	{
		_coin.cost = 10;

		_helm.armor = 10;
		_helm.cost = 4;
		_helm.size = 3;

		_jug.cost = 5;
		_jug.H = 11;
		_jug.R = 17;

		_sword.cost = 7;
		_sword.damage = 12;
		_sword.height = 6;
	};

	evil::Coin _coin;
	evil::Helm _helm;
	evil::Jug _jug;
	evil::Sword _sword;

	const byte* b; 
	size_t g;     

	void get_raw_rare(func f)
	{
		f(b, g);
	};

	void show()
	{
		
		cout << "1) Coin: "<<_coin.cost<<"\n";
		cout << "2) Helm: " << _helm.cost << "\n";
		cout << "3) Jug: " << _jug.cost << "\n";
		cout << "4) Sword: " << _sword.cost << "\n";
		cout << "Pleas to choose a number of thing and push ENTER" << "\n";
		cin >> g;
	};

	

	void get_test_string(char* ptr /*366 symbols*/)
	{
	
	};
};

#endif