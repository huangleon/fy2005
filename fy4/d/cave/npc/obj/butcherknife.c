#include <weapon.h>

inherit BLADE;
#include <ansi.h>

void create()
{
        set_name(RED"����"NOR, ({ "butcher knife","knife" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���³������е���������ɱ�����������п�����Ȼ����\n���ٿ��ӣ������ɷ����ޱȡ�\n");
                set("value", 500);
		set("rigidity", 2000);
                set("material", "steel");
        }
        ::init_blade(20);
}
