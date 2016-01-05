// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
#include <ansi.h>

void create()
{
}


void setup_room_desc(object room,int length, int width,int height, int x, int y,int z) {
	
	int exit_number;
	string name;
	if (z == height)
		name = "��";
	else if (z == 0)
		name = "��";
	else
		name = "��";
	
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

void setup_room_obj(object room,int length, int width, int height,int x, int y,int z)
{
	room->set("x",x);
	room->set("y",y);
	room->set("z",z);
    room->set_max_encumbrance(100000000000);

	room->setup();
}

int destruct_maze()
{
	object user;
	user=find_player(query("mark_ob"));
	if (!user)
		return 0;	// �ȴ�600�����ٺ�ʽ��������
//	message_vision("a"+user->query_temp("maze")->query_owner(),user);
	user->query("private_mazex/maze")->remove_all_players(user->query("private_mazex/maze"),user->query_temp("maze_entry"),"ͻȻ����һ��������Ѱ�ĺ��������ŵ���æ����Թ���\nתͷ��ȥ�������Թ��Ѿ���������Ρ�\n");
	user->query("private_mazex/maze")->refresh_maze();
	return 1;
}

int setup_entry_room()
{
//	add_action("do_out","out");
	return 1;
}

int init()
{
	object boss,user,blocker;
	user=find_player(query("owner"));

	if (query("entry_room"))
		add_action("do_out","out");
	
	if (!user)
		return 0;	// �ȴ����ٺ�ʽ���ã��˼䲻�����κ�npc����
	
	seteuid(getuid());
	if (query("exit_room") && !query("exist"))	// �����Է���setup-exit�e
	{
		boss=new("/d/bashan/npc/mazemaster2");
		if (!boss)
			return notify_fail("Error #13398. Please call wizard.\n");
		set("exist",1);
		boss->invocation(user);
		boss->move(this_object());
	}

	return 1;
}

object check_blocker()
{
	if (query("blocker"))
		if (environment(query("blocker")))
			if (environment(query("blocker")) == this_object())
				return query("blocker");
	return 0;
}

int valid_leave(object me,string dir)
{
	object who;
	if (who=check_blocker())
		return notify_fail(who->name()+"�����ڱؾ�֮·�ϣ����������鷳����ǰ����\n");
    return 1;
}

int do_out()
{
	object me = this_player();
	object room;
	if (!room=me->query_temp("maze_entry"))
//		return notify_fail("Error #13447. Please call wizard.\n");
		return notify_fail("ʲô��\n");
	me->move(room);
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


