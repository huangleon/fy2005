
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(MAG"��Ԩڤ��"NOR, ({ "gift from hell", "gift"}) );
    set_weight(800);
    if (clonep())
    	set_default_object(__FILE__);
    else {
		set("unit", "��");
		set("real", "demon");
		set("long", "һ������ɫ���ֹ���Ʒ��\n");
    	set("value", 50);
    }
	::init_item();
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
