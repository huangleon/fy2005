#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name(HIG"���˴�"NOR, ({ "cactus needle","needle" }) );
	set_weight(35);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����������ժ�µ����ɫ���롣\n");
		set("unit", "��");
		set("base_unit","��");
		set("wield_msg", "$N��$n�������е�������\n");
		set("level_required",50);
		set("material", "bone");
		set("volumn",10);
	}
	set_amount(10);
	::init_throwing(65);
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
