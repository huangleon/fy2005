// tea_leaf.c

#include <weapon.h>
inherit WHIP;
void create()
{
        set_name( "����", ({ "chain" }) );
		set("long","һ��ϵ��tie��ӥ�õ�ϸϸ�ĺ�ɫ������
�ƺ������������ġ� \n");
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "steel");
        }
        ::init_whip(10);
}
