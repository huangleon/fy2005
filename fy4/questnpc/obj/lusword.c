#include <weapon.h>
#include <ansi.h>
inherit SWORD;


void create()
{
        set_name(HIW"���ʽ�"NOR, ({ "sword" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ܱ��Ľ�����û�н��ʡ�\n");
                set("value", 4000);
                set("material", "steel");
        }
        ::init_sword(70);

}
