// icy_girth.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
    set_name(HIR"������"NOR, ({ "red girth", "girth" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "����һ���ʺ���Ѫ��������\n");
		set("value", 700);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	::init_waist();
}
