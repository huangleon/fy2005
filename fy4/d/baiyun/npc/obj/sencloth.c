#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name("��������", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 3);
	}
	::init_cloth();
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

