// short_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("�̽�", ({ "short sword", "sword" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);
                set("material", "iron");
                set("long",
                        "һ�Ѵ�������Ķ̽������ֲ����ò������˺ü�Ȧ�Է�ֹ�������֡�\n");
        }
        init_sword(15, SECONDARY);
}
