#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("ѩ��", ({"mud","mud_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�ѿ�����ϡ�õ���ͣ������������������\n");
		set("unit", "��");
		set("base_value", 1000);
		set("item_damaged",1);
		set("base_unit", "��");
		set("base_weight", 3);
		set("lore",1);
		set("volumn",1);
	}
	set_amount(10);
	init_throwing(100);
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
