#include <ansi.h>
//#include <weapon.h>

inherit COMBINED_ITEM;

void create()
{
	set_name("������", ({ "iron bullet" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
"���Ӫ���о����Ļ�ǹ��װ�"
);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 50);
		set("base_value", 1);
		set("volumn",10);
	}
	set_amount(10);
}
