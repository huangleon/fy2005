#include <armor.h>
inherit WRISTS;

void create() {
        set_name("Ƥ�ﻤ��", ({ "leather sleeves"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һֻ�Ϻ�СţƤ���Ļ��ۡ�\n");
                set("unit", "ֻ");
                set("value", 50);
                set("wear_msg", "$N��һ��$n�����ֱ��ϡ�\n");
                set("unequip_msg", "$N��$n���ֱ��ϳ���������\n");
        }
        ::init_wrists();
}
