#include"battle.h"

#include<iostream>
#include<time.h>

using namespace std;

int battle::n_turn = 0;
int battle::dead_m_count = 0;
int battle::dead_p_count = 0;

battle::battle()
{
	this->n_turn= 0;
}

battle::battle(int p_num,int m_num)
{
	setPNum(p_num);
	setMNum(m_num);
	setTurnLimit();
	setAction_list(getTurnLimit());//��������
}

battle::battle(GeneralPlayer*gp, KnightPlayer*kp, MagicianPlayer*mp, OrcPlayer*op, ZombieMonster*zm, GoblinMonster*gm, JWMonster*jw, int p_num, int m_num)
{
	setPNum(p_num);
	setMNum(m_num);
	setTurnLimit();
	setAction_list(getTurnLimit());//��������
	setPlayers(gp, kp, mp, op);
	setMonsters(zm, gm, jw);
}

void battle::fight()
{
	srand(time(NULL));
	int send_num,attack_num,m_rand;

	GeneralPlayer *g_player;
	AbstractMonster *ab_monster;

	//cout << "turn limit" << getTurnLimit();
	//cout << "size of action list" << sizeof(action_list);

	for (int i = 0; i < getTurnLimit(); i++)
	{
		system("cls");
		n_turn = (i / 2)+1;
		cout << "Turn:" << n_turn << "\n" << endl;

		for (int j = 0; j < getPNum(); j++)
		{
			if (player_condition[j].alive==false)
				dead_p_count++;
		}
		for (int j = 0; j < getMNum(); j++)
		{
			if (monster_condition[j].alive == false)
				dead_m_count++;
		}
		
		if (dead_p_count == getPNum() || dead_m_count == getMNum())//�p�G���@�覺���F�N���X�j��
			break;
		
		if (action_list[i].type == 'p')
		{
			//system("cls");
			cout << "you have players:";
			for (int j = 0; j < getPNum(); j++)
			{
				cout << j + 1 << "." << players[j]->getName() << " ";
			}
			cout << "\nthe players' information are belowed:\n" << endl;
			for (int j = 0; j < getPNum(); j++)
			{
				players[j]->display();
			}
			cout << "please choose the player you want to send:" << endl;
			cin >> send_num;
			while (send_num > getPNum() || player_condition[send_num - 1].alive == false)//���b
			{
				cout << "error !!! player " << send_num << " doesn't exist !!! " << endl;
				cin >> send_num;
			}

			action_list[i] = player_condition[send_num - 1];
			g_player = static_cast<GeneralPlayer*>(action_list[i].instance);

			system("cls");
			cout << "you chose " << g_player->getName() <<"!!!\n" << endl;//��ܩҿ�ܪ����a��T
			cout << "information:" << endl;
			g_player->display();

			cout << "\nthere are " << getMNum() << " monsters :";
			for (int j = 0; j < getMNum(); j++)
			{
				cout << j + 1 << "." << monsters[j]->name << " ";
			}
			cout << "\nthe monsters' information are belowed:\n" << endl;
			for (int j = 0; j < getMNum(); j++)
			{
				monsters[j]->display();
			}

			cout << "please input the monster you want to attack:" << endl;
			cin >> attack_num;
			while (attack_num > getMNum() || monster_condition[attack_num-1].alive==false)//���b
			{
				cout << "error !!! player " << attack_num << " doesn't exist !!! " << endl;
				cin >> attack_num;
			}

			if (g_player->getName() == "knightplayer" || g_player->getName() == "magicianplayer")
			{
				int choice;
				cout << "please input the action you want to do: 1.attack 2.special skill" << endl;
				cin >> choice;
				if(choice==1)
					g_player->attackTo(monsters[attack_num - 1]);
				else if(choice==2)
					g_player->specialSkill();
			}
			else
			{
				g_player->attackTo(monsters[attack_num - 1]);//���a����
			}
			
			if (monsters[attack_num - 1]->getHP() <= 0)//�Y�Ǫ���q<0�A�h�өǪ����Aalive=false
			{
				monster_condition[attack_num - 1].alive = false;
			}

			system("cls");
			for (int j = 0; j < getPNum(); j++)//��ܧ�������
			{
				if(player_condition[j].alive!=false)
					players[j]->display();
			}
			for (int j = 0; j < getMNum(); j++)
			{
				if(monster_condition[j].alive!=false)
					monsters[j]->display();
			}
			system("pause");
		}
		else if (action_list[i].type == 'm')
		{
			//system("cls");
			cout << "monster attack !!! \n" << endl;
			m_rand = rand() % getMNum();//�H����ܩǪ��X��
			action_list[i] = monster_condition[m_rand];
			ab_monster = static_cast<AbstractMonster*>(action_list[i].instance);

			attack_num = rand() % getPNum();//�H����ܪ��a����
			while (player_condition[attack_num].alive == false)
			{
				cout << "error !!! player " << send_num << " doesn't exist !!! " << endl;
				cin >> send_num;
			}
			ab_monster->attackTo(players[attack_num]);

			if (players[attack_num]->getHP() <= 0)//�Y���a��q<0�A�h�Ӫ��a���Aalive=false
			{
				player_condition[attack_num].alive = false;
			}

			for (int j = 0; j < getPNum(); j++)//��ܧ�������
			{
				if (player_condition[j].alive != false)
					players[j]->display();
			}
			for (int j = 0; j < getMNum(); j++)
			{
				if (monster_condition[j].alive != false)
					monsters[j]->display();
			}
			system("pause");
		}
	}
	display_end();
}

void battle::display_end()
{
	system("cls");
	//cout << "dead_m_count" << dead_m_count << endl;
	//cout << "dead_p_count" << dead_p_count << endl;

	cout << "=====result of this compitition=====" << endl;
	if (dead_m_count < getMNum() && dead_p_count < getPNum() && dead_m_count==dead_p_count)
	{
		cout << "\n=======tie=======" << endl;
		for (int i = 0; i < getPNum(); i++)
		{
			players[i]->display();
		}
		for (int i = 0; i < getMNum(); i++)
		{
			monsters[i]->display();
		}
	}
	else if ((dead_m_count < getMNum() && dead_p_count == getPNum()) || (dead_m_count<dead_p_count))
	{
		cout << "\n=======you lose=======" << endl;
		for (int i = 0; i < getPNum(); i++)
		{
			players[i]->display();
		}
		for (int i = 0; i < getMNum(); i++)
		{
			monsters[i]->display();
		}
	}
	else if ((dead_m_count == getMNum() && dead_p_count < getPNum()) || (dead_m_count>dead_p_count))
	{
		cout << "\n=======you win=======" << endl;
		for (int i = 0; i < getPNum(); i++)
		{
			players[i]->display();
		}
		for (int i = 0; i < getMNum(); i++)
		{
			monsters[i]->display();
		}
	}
}

void battle::setAction_list(int TurnLimit)//�H�M�Ǫ�����������
{
	action_list = new character[TurnLimit];

	srand(time(NULL));
	character a;
	bool t;
	t = rand() % 2;//�H�����ͥ��������Oplayer�٬Omonster

	for (int i = 0; i < TurnLimit; i++)
	{
		if (t == 1)
			a.type = 'p';
		else if (t == 0)
			a.type = 'm';

		action_list[i] = a;

		t = !t;//�U�@�ӷ|�M��Ӫ��������O���P
		//cout << action_list[i].type;
	}
}

void battle::setPlayers(GeneralPlayer*gp, KnightPlayer*kp, MagicianPlayer*mp, OrcPlayer*op)//����players�A�Ϫ��a�i�H��ܷQ�n��player
{
	int* p_kind = new int[getPNum()];
	player_condition = new character[getMNum()];
	vector<GeneralPlayer*> _players;

	cout << "you will have " << getPNum() << " players !!!\n" << endl;
	cout << "you have four choices :\n1.general\n2.knight\n3.magician\n4.orc\n" << endl;

	for (int i = 0; i < getPNum(); i++)
	{
		cout << "please input player "<< (i+1) << " you want:" << endl;
		cin >> p_kind[i];
		if (i == 1)
		{
			while (p_kind[i] == p_kind[i-1])
			{
				cout << "can not input same player !!! " << endl;
				cin >> p_kind[i];
			}
		}
		else if (i == 2)
		{
			while (p_kind[i] == p_kind[i - 1] || p_kind[i]==p_kind[i-2])
			{
				cout << "can not input same player !!! " << endl;
				cin >> p_kind[i];
			}
		}
		else if (i == 3)
		{
			while (p_kind[i] == p_kind[i - 1] || p_kind[i] == p_kind[i - 2] || p_kind[i]==p_kind[i-3])
			{
				cout << "can not input same player !!! " << endl;
				cin >> p_kind[i];
			}
		}
	}

	for (int i = 0; i < getPNum(); i++)
	{
		if (p_kind[i] == 1)
		{
			_players.push_back(gp);
		}
		else if (p_kind[i] == 2)
		{
			_players.push_back(static_cast<GeneralPlayer*>(kp));
		}
		else if (p_kind[i] == 3)
		{
			_players.push_back(static_cast<GeneralPlayer*>(mp));
		}
		else if (p_kind[i] == 4)
		{
			_players.push_back(static_cast<GeneralPlayer*>(op));
		}
	}

	this->players = _players;

	for (int i = 0; i < getPNum(); i++)//��l��player_condition�A�ϥ��[�ɸ��n����
	{
		player_condition[i].alive = true;
		player_condition[i].type = 'p';
		player_condition[i].instance = players[i];
	}
}

vector<GeneralPlayer*> battle::getPlayers() const
{
	return players;
}

void battle::setMonsters(ZombieMonster*zm, GoblinMonster*gm, JWMonster*jw) 
{
	srand(time(NULL));
	int* m_kind = new int[getMNum()];
	monster_condition = new character[getMNum()];
	vector<AbstractMonster*> _monsters;

	for (int i = 0; i < getMNum(); i++)
	{
		m_kind[i] = rand() % getMNum() + 1;
		if (i == 1)
		{
			while (m_kind[i] == m_kind[i - 1])
				m_kind[i] = rand() % getMNum() + 1;
		}
		else if (i == 2)
		{
			while (m_kind[i] == m_kind[i - 1] || m_kind[i] == m_kind[i - 2])
				m_kind[i] = rand() % getMNum() + 1;
		}

		if (m_kind[i] == 1)
		{
			_monsters.push_back(static_cast<AbstractMonster*>(zm));
		}
		else if (m_kind[i] == 2)
		{
			_monsters.push_back(static_cast<AbstractMonster*>(gm));
		}
		else if (m_kind[i] == 3)
		{
			_monsters.push_back(static_cast<AbstractMonster*>(jw));
		}
	}

	this->monsters = _monsters;

	for (int i = 0; i < getMNum(); i++)//��l��monster_condition�A�ϥ��[�ɸ��n����
	{
		monster_condition[i].alive = true;
		monster_condition[i].type = 'm';
		monster_condition[i].instance = monsters[i];
	}
}

vector<AbstractMonster*> battle::getMonsters()
{
	return monsters;
}

void battle::setPNum(int playerNum_in)
{
	this->playerNum = playerNum_in;
}

int battle::getPNum()
{
	return playerNum;
}

void battle::setMNum(int monsterNum_in)
{
	this->monsterNum = monsterNum_in;
}

int battle::getMNum()
{
	return monsterNum;
}

void battle::setTurnLimit()
{
	this->turn_limit = this->playerNum * 3 * 2;
}

int battle::getTurnLimit()
{
	return turn_limit;
}

character* battle::getPlayer_condition()
{
	return player_condition;
}
character* battle::getMonster_condition()
{
	return monster_condition;
}