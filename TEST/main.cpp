#include <iostream>
#include "btc_miner.h"
#include "api.h"
#include "Classes.h"

using namespace std;

void get_thing(const byte* type_thing, const size_t WHAT);

minig_fabrik a; 
shop         b; 

byte selection;

int main(int arg, char* args[])
{
	a.get_money();
	
	cout << "Do you want to buy somesing?" << "\n" << "We have:" << "\n";
	b.show();
	
	void(*ptr_get_thing)(const byte*, const size_t) = &get_thing; //pointer on function

	b.get_raw_rare(*ptr_get_thing);

	system("pause");
	return 0;
}

void get_thing(const byte* type_thing, const size_t WHAT) //function
{
	int BIT = 0;

	switch (WHAT)
	{
	case 1:
		if (a.money > b._coin.cost){
			a.money -= b._coin.cost;

			system("cls");
			
			const int massege_byte = sizeof(b._coin) + 1;
			
			byte massege[massege_byte] = { 0 };
			
			massege[0] = 1;
			for (int i = 1; i < massege_byte; i++){
				massege[i] = massege[i] | b._coin.cost>>BIT;
				BIT += 8;
			};
			a.take_messege(massege_byte, massege, 0, 0);
		};

		break;
	case 2:
		if (a.money > b._helm.cost)
		{
			a.money -= b._helm.cost;

			const int massege_byte = sizeof(b._helm) + 1;

			byte massege[massege_byte] = { 0 };
			massege[0] = 2;

			int size_armour = sizeof(b._helm.armor);
			int size_cost = sizeof(b._helm.cost);

			for (int i = 1; i < massege_byte; i++)
			{
				if (i <= size_armour){
					massege[i] = massege[i] | b._helm.armor >> BIT;
				};
				if (i > size_armour && i <=size_armour+size_cost)
					massege[i] = massege[i] | b._helm.cost >> BIT;
				if (i > size_armour+size_cost)
					massege[i] = massege[i] | (size_t)b._helm.size >> BIT;
				BIT += 8;
			};


			a.take_messege(massege_byte, massege, size_armour, size_cost);
		};
		break;
	case 3:
		if (a.money > b._jug.cost)
		{
			a.money -= b._jug.cost;

			const int massege_byte = sizeof(b._jug) + 1;

			byte massege[massege_byte] = { 0 };
			massege[0] = 3;

			int size_cost = sizeof(b._jug.cost);
			int size_H = sizeof(b._jug.H);

			for (int i = 1; i < massege_byte; i++)
			{
				if (i <= size_cost){
					massege[i] = massege[i] | b._jug.cost >> BIT;
				};
				if (i > size_cost && i <= size_cost + size_H)
					massege[i] = massege[i] | (size_t)b._jug.H >> BIT;
				if (i > size_cost + size_H)
					massege[i] = massege[i] | (size_t)b._jug.R >> BIT;
				BIT += 8;
			};


			a.take_messege(massege_byte, massege, size_cost, size_H);

		};

		break;
	case 4:
		if (a.money > b._sword.cost)
		{
			a.money -= b._sword.cost;

			const int massege_byte = sizeof(b._sword) + 1;

			byte massege[massege_byte] = { 0 };
			massege[0] = 4;

			int size_cost = sizeof(b._sword.cost);
			int size_damage = sizeof(b._sword.damage);

			for (int i = 1; i < massege_byte; i++)
			{
				if (i <= size_cost){
					massege[i] = massege[i] | b._sword.cost >> BIT;
				};
				if (i > size_cost && i <= size_cost + size_damage)
					massege[i] = massege[i] | (size_t)b._sword.damage >> BIT;
				if (i > size_cost + size_damage)
					massege[i] = massege[i] | (size_t)b._sword.height >> BIT;
				BIT += 8;
			};


			a.take_messege(massege_byte, massege, size_cost, size_damage);

		};
		break;
	default:
		cout << "mistake"<<"\n";
		break;
	}
};
