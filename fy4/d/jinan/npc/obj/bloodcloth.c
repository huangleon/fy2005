// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
    set_name(HIR"����Ѫ�յĽ���"NOR, ({ "cloth","jin cloth" }) );
    set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "���Ǽ��߹�Ľ���������Ѿ�����Ѫ��������\n");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	::init_cloth();
}
