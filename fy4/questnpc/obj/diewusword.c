#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIY"���轣"NOR, ({ "diesword","sword" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��һ�����糤�Ķ̽����������ǲʵ������ͼ����\n");
                set("value", 90000);
                set("material", "steel");
        }
        ::init_sword(75);

}
