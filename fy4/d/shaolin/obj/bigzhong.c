#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("����", ({ "giant bell" }) );
        set_weight(1000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���ڽ�����̫����䣬���ذ˴����������ԣ���һ��һǧ��\n");
                set("value", 3);
                set("material", "iron");
        }
        init_hammer(200);
}
