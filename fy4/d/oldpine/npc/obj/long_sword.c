// long_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("����", ({ "long sword", "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5);
                set("material", "iron");
                set("long",
                        "һ�Ѵ�������ĳ��������ֲ����ò������˺ü�Ȧ�Է�ֹ�������֡�\n");
        }
        init_sword(25);
}
