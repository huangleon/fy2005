#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIG"��ˮ��"NOR, ({ "qiushui sword","sword" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѱ�����ˮ�ĳ�����\n");
                set("value", 40000);
                set("material", "steel");
        }
        ::init_sword(60);

}
