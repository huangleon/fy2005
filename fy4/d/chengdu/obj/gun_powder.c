#include <ansi.h>
//#include <weapon.h>

inherit COMBINED_ITEM;

void create()
{
	set_name("�ڻ�ҩ", ({ "gun powder" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
"�������ӪרΪ��ǹ�����õĻ�ҩ������ء���ơ�ľ̿�����ǡ
���ô���"
);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 5);
		set("base_value", 1);
		set("volumn",10);
	}
	set_amount(10);
}
