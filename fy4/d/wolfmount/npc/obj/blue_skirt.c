#include <armor.h>

inherit CLOTH;
#include <ansi.h>

void create()
{
        set_name(HIB"��ɫ��ȹ"NOR, ({ "blue skirt", "skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�����ɫ�İ��۳�ȹ�������ż����ӻ�������������һ�ɵ��㡣\n");
                set("unit", "��");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("female_only", 1);
        }
        ::init_cloth();
}

