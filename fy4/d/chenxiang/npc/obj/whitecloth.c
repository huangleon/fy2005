#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name(WHT"��ɫ����"NOR, ({ "white cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
        set("long", "����һ��ѩ�׵����磬ӭ�ŷ��������죬�����쳣��\n");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
