#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
    set_name(BLK"������"NOR, ({ "black cloak","cloak" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
        set("long", "һ����ڵ����磬ӭ�ŷ��������졣\n");
        set("armor_prop/armor", 5);
        set("value", 3);
        set("wear_msg", "$Nӭ�������������һ��������һ��$n���������졣\n");
	}
	::init_cloth();
}
