#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("ʯĥ��", ({ "giant mo" }) );
        set_weight(600000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ʯĥ�̣�˶�����󣬾�˵��������ɮ��
����ʳ������������ĥ����ĥ��\n");
                set("value", 3);
                set("material", "iron");
        }
        init_hammer(650);
}
