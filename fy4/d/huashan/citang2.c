// annie. 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "�ķϵ�����");
        set("long", @LONG
����������˻ҳ���һЩ��λ���ҵض�����̨�ϣ���ֻ��̨�������������̨
�ϡ�������տյģ������������������������Ǻ���ᣲ��������ƺ��½�����
������������ӡ�кܶ����ҵĽ�ӡ�� 
LONG
        );
    set("exits", ([ 
		"west" : __DIR__"citang1",
	]));

	set("item_desc", ([
 		"ᣲ�" : "�������ĺ�ɫᣲ��ĸ������������������������գ��㲻�����ƿ�����������ʲô��
�����������������\n",	
 		"curtain" : "�������ĺ�ɫᣲ��ĸ�������������������������,�㲻�����ƿ�����������ʲô��
�����������������\n",
 	]) );  
	set("objects", ([
		__DIR__"obj/shentai" : 1, 
	]));
    set("indoors", "huashan");
	set("coor/x",-5);
	set("coor/y",15);
	set("coor/z",-10);
	setup();
}

void init(){
	add_action("do_open", "open");
	add_action("do_search", "search");
}

int do_open(string arg)
{
	object player,kumei;
	player = this_player();
	if(arg != "ᣲ�" && arg != "curtain") {
		return 0;
	}
	if ( player->query("marks/�ҳ�") == 1 
			|| player->query("marks/�ҳ�") == -1)
	{
		message_vision("$N�ƿ�ᣲ��������������һ����ɫ��Ӱ�ӹ����ֺ���ֻ�ǻþ���\n",player);
		if (query("gotone"))	// *cat
		{
			tell_object(player,"ᣲ��Ļ������ƺ��и�ʲô����������΢�⡣\n");
			if (!REWARD_D->riddle_check(player,"��������") 
				&& !REWARD_D->check_m_success(player,"��������"))
				REWARD_D->riddle_set(player,"��������",1);
			player->set_temp("annie/demon_suu",1);
		}
		return 1;
	}
	if (!REWARD_D->riddle_check(player,"����ëŮ��") 
		&& !REWARD_D->check_m_success(player,"����ëŮ��"))
		REWARD_D->riddle_set(player,"����ëŮ��",1);
	kumei = new(__DIR__"npc/kumei.c");
	kumei->move(this_object());
	message_vision("$N�����ƿ�ᣲ��� \n\n\n",player);
	message_vision(HIB"��Ȼᣲ�����һ�£�$N��ǰ����Ȱ����һ��$n�� \n\n\n"NOR,player,kumei);

	kumei->apprentice_me(player);
	return 1;
}


int do_search(string arg)
{
	object player,kumei;
	player = this_player();
	if(arg != "ᣲ�" && arg != "curtain") {
		return notify_fail("��Ҫ��ʲô��\n");
	}
	if (player->is_busy())
	{
		return notify_fail("��������æ�úܣ�û��������\n");
	}
	if ( REWARD_D->riddle_check(player,"��������") == 1 
		|| REWARD_D->riddle_check(player,"��������") == 2)
	{
		message_vision("$N�ƿ�ᣲ�����ᣲ��µĻ�����һ��������\n",player);
		if (query("gotone") && !random(5))	// *cat
		{
			kumei = new(__DIR__"obj/bottle2");
			if (kumei->move(player))
			{
				tell_object(player,"���ڳ�����������һ��СС����ƿ��\n");
				REWARD_D->riddle_set(player,"��������",2);
				delete("gotone");
			}
			else
				tell_object(player,"���ڳ�����������ʲô����������һ�¾ͻ�����������ġ�\n");
		}
		else
		{
			tell_object(player,"��ʲôҲû���ҵ���\n");
		}
		player->start_busy(2);
		return 1;
	}
	return notify_fail("��ʲôҲû���ҵ���");
}


void reset()
{
	object shui;
    ::reset();
	if (!random(4))	
		set("gotone",1);	// *cat
}
