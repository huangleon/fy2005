// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�״�ʯ");
        set("long", @LONG
�й������ţ��㷢���Լ���վ��һ��˶������ľ�ʯ֮�¡���ͷ��������
���ʯ���������ɸ��£�ΡȻ�����ڵ�·���֡�ʯ��������һ�����ڵ��ѷ죬
ԼĪ�а���������������ʯ�ʳ������롣�ӷ�϶�п�����ֻ��һƬ��ڣ���
Ȼ����Ƶ�ʯ��ȴ�ǲ�ľ��������������
LONG
        );
	set("exits",([
  		"east" : __DIR__"xiangsi",
  		"west" : __DIR__"liangjie",
	]) );

		set("item_desc", ([
		"�ѷ�" : "�ѷ첢�����������Ǻ�����һƬ�����ǲ�Ҫ��㼷��ȥ�ĺá�\n",
		"��϶" : "�ѷ첢�����������Ǻ�����һƬ�����ǲ�Ҫ��㼷��ȥ�ĺá�\n",
		"��ʯ":	"һ�����ɸ��µľ�ʯ��ʯ��������һ�����ڵ��ѷ졣\n",
	]) );   

	set("outdoors", "xiangsi");

	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}


int do_enter(string arg)
{
	object room, me;
	me = this_player();
	if (!me->query("����B/��˼_����")){
		tell_object(me,"��������ѷ�����ȥ��һͷײ��ʯ���ϣ����û���˹�ȥ��\n");
		return 1;
	}
	if ( me->is_busy() || me->is_fighting()){
		tell_object(me,"��������æ��\n");
		return 1;
	}
	tell_object(me,CYN"������������ͷָ��С������ļ����ѷ�֮�С�\n"NOR);
	room=load_object(__DIR__"bingjing");
	me->move(room);
	return 1;
}


void event_thunder()
{
	object *inv;
	object obj = this_object();
	int i,j,num;

	inv = all_inventory(obj);
	if (!sizeof(inv))
		return;
	set("start",1);
	message_vision(HIY"\n�����ͻȻ��������¡¡���������·���ڵ��߼�����������Ļ֮����\n���������ֲ�ס����֮�ģ�̧ͷ�����Ͽ�ȥ��\n"NOR,inv[0]);
	message_vision(HIR BLK"\nֻ�����ϰ����ڿգ��������裬Ǧ��ɫ���Ʋ㱻˺�������������ơ�\n"NOR,inv[0]);
	message_vision(WHT"\nһ��ѩ���Ĺ�â������ʱ�������ֻ������һʹ����ǰ��һƬãã��ɫ��\n"NOR,inv[0]);
	j = random(sizeof(inv));
	for (i=0;i<sizeof(inv) ; i++)
	{
		inv[i]->start_busy(6);
		if (i == j)
		{
			tell_object(inv[i],HIW"\n���ڰ�âһ�����ƺ������и����Լ�ͷ����ʯ��ֱָ��϶������һ��㱣�\n��ͷ��Ȼ���������㻳���ǲ����Լ��������ۡ�\n"NOR);
			if (!inv[i]->query("����B/��˼_����"))
			{
				num = 1 + random(10);
				inv[i]->set("����B/��˼_����",num);
				log_file("riddle/FATE_LOG",
				sprintf("%s(%s) �õ�����B/��˼_���� "+num+"�� %s \n",
					inv[i]->name(1), geteuid(inv[i]), ctime(time()) ));
			}
		}
		tell_object(inv[i],MAG"\n������������Ӧ��һ����Ȼ�������������ը�죬��ʱ��·�������ѣ�\n����ɰʯ�����ɽ���������������ϣ����ϣ�����\n"NOR);
		tell_object(inv[i],RED"\n����ס˫�ۣ�ſ���ڵأ�ֻ����ɳ��ʯ���׷׸��ϣ�������������\n"NOR);
		inv[i]->set_temp("block_msg/all",1);
		call_out ("recover",10, inv[i]);
	}
	set("start",0);
	return;
}


int recover (object obj)
{
	if (!obj || environment(obj)!= this_object())	return 1;
		
	obj->delete_temp("block_msg/all");
	tell_object(obj, HIG"\n����֮�󣬶��е�����������ȥ����ǰҲ��ʼ���ֳ�һ˿���⡣���Ǳ���\n�����Ե������𣬶������ϵĳ������ŷ����״�ʯ���������µĽ��ۡ�\n\n" NOR);
	return 1;
}	

int	valid_leave(object who, string dir)
{
	object me;
	if (dir == "east" && userp(who))
	{
		tell_object(who,CYN"��С������Ĳ��Ųݾ�������˼������ȥ��\n"NOR);
		who->perform_busy(2);
	}
	return ::valid_leave(who,dir);
}

void init()
{
	object who = this_player();
	add_action("do_enter", "enter");

	/*
	���ͷ����Ѷ�
	*/
	if (NATURE_D->get_weather() == "����")
//		if (this_player()->query("annie/riddle/moonmaster") == 11 && this_player()->query("combat_exp") >= 1400000 )
			if (!query("start"))
				event_thunder();
//				start(who);



}



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
