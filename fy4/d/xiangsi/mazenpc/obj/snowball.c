#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name(WHT"ѩ��"NOR, ({ "snowball"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ��û�л�����ѩ�顣\n");
		set("unit", "��");
		set("volumn",10);
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(10);
	init_throwing(70);
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
