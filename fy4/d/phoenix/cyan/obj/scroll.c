#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("����", ({"����", "scroll" }) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("long", "��������д�ţ�\n\n"HIM"����������󸻴�\n\n������������������\n�������š���������\n�������ԡ���������\n������������������\n�������ꡡ��������\n\n"NOR"�߽Ǵ���һ��С�֣���������������������ʱ��\n\n");
	}
    ::init_item();
}

int is_container() { return 1; }

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
