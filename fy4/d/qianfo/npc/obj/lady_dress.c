// lady_dress.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(MAG"���޳���"NOR, ({ "lady dress", "dress" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ���ֹ��൱ϸ�£�������͸���ĳ���\n");
                set("unit", "��");
                set("value", 200);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("female_only", 1);
        }
        ::init_cloth();
}
