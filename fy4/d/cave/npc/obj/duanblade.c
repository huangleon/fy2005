#include <weapon.h>

inherit BLADE;
#include <ansi.h>

void create()
{
        set_name(BLK"��ͷ���ŵ�"NOR, ({ "duanmen blade","blade" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ʮ����Ĺ�ͷ����Ѫ����������Ѫ����\n");
                set("value", 100);
		set("rigidity", 2000);
                set("material", "steel");
        }
        ::init_blade(10);
}
