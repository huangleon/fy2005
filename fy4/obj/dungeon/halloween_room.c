// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
#include <ansi.h>

void create()
{
}


void setup_room_desc(string owner,object room,int length, int width,int height, int x, int y,int z) {
	object who;
	int exit_number;
	string name;

	who = find_player(owner);

	name = owner+CHINESE_D->chinese_number(z+1)+"��";
	
	if (y == 0)
		name += "��";
	else if (y == width)
		name += "��";
	else
		name += "��";

	if (x == 0)
		name += "��";
	else if (x == length)
		name += "��";
	else
		name += "��";

	exit_number= sizeof(room->query("exits"));
	if (exit_number == 3)
		name += "��";
	else if (exit_number == 2)
	{
		if (random(2))
			name += "·";
		else
			name += "��";
	}
	else
			name += "��";


	room->set("short",HIB BLK+name+NOR);
	room->set("long",@LONG

LONG
	);
	
}

int destruct_maze()
{
	object user;
	user= query("mark_ob");
	if (!user)
		return 0;	// �ȴ�600�����ٺ�ʽ��������
//	message_vision("a"+user->query_temp("maze")->query_owner(),user);
	user->query("private_mazer/maze")->remove_all_players(user->query("private_mazer/maze"),user->query_temp("maze_entry"),"������ߺ�����������������������ѵ�ʱ���ˣ�\n�����ڿ����������ر����(end)�ˡ���\n");
	user->query("private_mazer/maze")->refresh_maze();
	return 1;
}

void setup_room_obj(string owner,object room,int length, int width, int height,int x, int y,int z)
{
	object who,i;
	int file;

	seteuid(getuid());
	who = find_player(owner);

	if (who)
		room->set("long",owner+"���Ϲϲֿ⡣\n");

	room->set("x",x);
	room->set("y",y);
	room->set("z",z);
    room->set_max_encumbrance(100000000000);

	if (!who)
		return;

	room->setup();

	if (room->query("aaaa"))
		return;
	

	room->set("aaaa",1);
	who->add_temp("annie_quest/halloweenx",1);
		
	if (!random(3))
	{
		if (who->query_temp("annie_quest/halloween")< 20)	// �������� :)
			who->add_temp("annie_quest/halloween",1);
		i=new(__DIR__"pumpkin");
		i->move(room);
		i->set("ol",who);
	}
	else
		who->add_temp("annie_quest/halloweenc",1);

}

int setup_entry_room()
{
	return 1;
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


