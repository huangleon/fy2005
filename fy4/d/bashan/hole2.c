#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���±�");
        set("long", @LONG
�в���ʱ���˲ȹ��ĺۼ�����ʧ����������ǰ��һС�Σ��ͼ�ɽ���Ѿ����˾�
ͷ���ۼ�ǰ���Ǹ����£���Ȼ��·���ߡ�����������������ɽ�����������ƣ�����
���ɣ��±��ϲ�ľ������
LONG
        );
	set("exits",([
  		"southup" : __DIR__"hole1",
	]) );
	set("no_fly",1);
	set("item_desc", ([
		"����": "����ʮ�ֶ��ͣ��±��ϲ�ľ����������м���ʯͷͻ����\n",
		"��": "����ʮ�ֶ��ͣ��±��ϲ�ľ����������м���ʯͷͻ����\n",
		"cliff": "����ʮ�ֶ��ͣ��±��ϲ�ľ����������м���ʯͷͻ����\n",
	]) );
	set("coor/x",-40);
	set("coor/y",200);
	set("coor/z",180);
	set("outdoors", "bashan");
	setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	object me = this_player(),env=this_object();
	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");
	if (arg != "cliff" && arg != "down" && arg != "��" && arg != "����")
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("��������æ��\n");
	
	message_vision(CYN"$N��ɽ������ȥ������\n"NOR,me);
	call_out("do_climbdown",2,me,env);
	me->perform_busy(3);
	return 1;
}

int do_climbdown(object me,object env)
{
	object room;
	room = find_object(__DIR__"hole3");
	if (!room)
		room = load_object(__DIR__"hole3");
	if (!me || environment(me) != env)
		return 0;
	tell_object(me,CYN"��ץ��ͻ���ʯ�飬С����������£�����\n"NOR,me);
	me->move(room);
	message_vision(CYN"$N�����Ĵ�ɽ��������������\n"NOR,me);
	return 1;
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
