// cloth.c
//

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"����Ѫ��͸�Ĳ���"NOR, ({ "cloth piece" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����������Ѫ��͸�Ĳ�����\n");
		set("value", 10);
		set("material", "cloth");
	}
	::init_item();
}
