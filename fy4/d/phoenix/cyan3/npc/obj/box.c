
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("��ʯ��", ({ "box", "stone box"}) );
    set_weight(800);
    if (clonep())
    	set_default_object(__FILE__);
    else {
		set("unit", "��");
		set("long", "һ������ɫ��Сʯ�С���������Ű�����(open)��\n");
    	set("value", 500);
    }
	::init_item();
}

void init()
{
   add_action("do_open","open");
}

int do_open(string arg)
{
	object me, ob, item;
	
	me = this_player();
	ob = this_object();
    	if( !arg || arg != "box" ) {
    		return notify_fail("��Ҫ��ʲô��\n");
    	}
		message_vision("$N���Ŵ�Сʯ�У�С������һ����ʯͷ����˿������\n", me);
		return 1;
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
