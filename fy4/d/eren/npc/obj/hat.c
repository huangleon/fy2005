#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name("��ñ", ({ "hat" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ�����ñ����������ϵ�����\n");
		set("value", 2000);
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
    ::init_head();
}
