#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("������ ������"HIY"���¿�"NOR"��������", ({ "master xiao","master"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "������ ������"HIY"���¿�"NOR"��������(Master xiao)��\n������ȥ��ȴ������ֻ��������ʯ�񣮣���\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
