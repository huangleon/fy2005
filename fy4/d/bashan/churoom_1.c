#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���ɾ�ͷ");
        set("long", @LONG
��������㾪��ȥ·�Ѿ����ִ��֦��������ϸ�����ּ�����ķ���΢΢��
������Զ����һƬ�������ǣ����������ǽ�ʵ��ȴ�뿪��ֱ��������Զ������һ��
������������������������Խ��Էɶɣ�ȴҲ�����Σ�ա�
LONG
        );
	set("exits",([
  		"down" : __DIR__"maze2/exit",
	]) );
	// nothing
	set("item_desc", ([
		"����": "�������ٿ������ܽ�ʵ��������Խ�֮�ɶ�(swing)��\n",
		"��": "�������ٿ������ܽ�ʵ��������Խ�֮�ɶ�(swing)��\n",
		"vine": "�������ٿ������ܽ�ʵ��������Խ�֮�ɶ�(swing)��\n",
	]) );
	set("no_fly",1);
	set("vine",1);
	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",100);
	set("outdoors", "bashan");
	setup();
}

void init()
{
	add_action("do_swing","swing");
}

int do_swing(string arg)
{
	object me = this_player(),env=this_object();
	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("��������æ��\n");
	if (!query("vine"))
		return notify_fail("����������Ʈ���ڰ���С�\n");
	
	add("swing",2);
	if (query("swing") == 2)
		message_vision(CYN"$N���˳����٣���˫�ֽ���ץס����������˿�������������\n"NOR,me);
	else
	{
		message_vision(CYN"$Nվ����һ�ߣ�Ҳ��˫�ֽ���ץס���٣���������˿�����\n"NOR,me);
		set("vine",0);
	}

	call_out("do_next",2,me,env);
	me->perform_busy(5);
	return 1;
}

int do_next(object me,object env)
{
	if (!me || environment(me) != env)
		return 0;

	if (query("swing") == 2)
	{
		set("vine",0);
		message_vision(CYN"$N�ʽ�������������������һ�ţ������ֱ����ȥ��\n������������ŶŶŶŶŶŶ����������������\n\n"NOR,me);
		call_out("do_failed",2,me,env);
		return 1;
	}

	add("swing",-1);
	if (query("swing") == 3)
		message_vision(CYN"$N�ʽ�������������������һ�ţ������ֱ����ȥ��\n������������ŶŶŶŶŶŶ����������������\n\n"NOR,me);
	else
		message_vision(CYN"$N������ȥ���ѽߣ�ʹ��������ʱ��������һ�ƣ�\n������������ŶŶŶŶŶŶ����������������\n\n"NOR,me);

	call_out("do_succ",2,me,env);
	return 1;
}

int do_failed(object me,object env)
{
	object room;
	room = find_object(__DIR__"maze2/entry");
	if (!room)
		room = load_object(__DIR__"maze2/entry");
	if (!me || environment(me) != env)
		return 0;
	set("vine",1);
	set("swing",0);
	message_vision(CYN"������·������ȥ�ƾͽߣ�$N˫��һ��������ľ��ֱ׹��ȥ��\n������������ŶŶŶŶŶŶ����������������\n"NOR,me);
	me->move(room);
	message_vision(CYN"\n$Nһ·��ѹ׹������ϸ֦��Ҷ�������ŴӰ����׹��������\n\n"NOR,me);
	me->set_temp("last_damage_from","����ʮ�ɸߵ���������ȥˤ���ˡ�");
	me->receive_wound("kee",3000);
	return 1;
}

int do_succ(object me,object env)
{
	object room;
	room = find_object(__DIR__"churoom_2");
	if (!room)
		room = load_object(__DIR__"churoom_2");
	if (!me || environment(me) != env)
		return 0;
	set("vine",1);
	set("swing",0);
	message_vision(CYN"�������ٵ������������ȥ����\n\n"NOR,me);
	me->move(room);
	message_vision(CYN"�����Թ���������ֱ�Ӷ�����$N˫��һ�ɣ����ȵ������䵽������֮�ϡ�\n\n"NOR,me);
	return 1;
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

