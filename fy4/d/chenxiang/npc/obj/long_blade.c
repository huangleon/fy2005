#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("����", ({ "long blade","blade" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѳ����ĵ��������ĳߣ������֡�\n");
                set("value", 200);
		set("rigidity", 2000);
                set("material", "steel");
        }
        ::init_blade(15);
}
