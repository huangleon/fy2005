#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name("ͷ��", ({ "towel" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ������ͷ�ϵİ�ë��\n");
		set("value", 200);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
    ::init_head();
}
