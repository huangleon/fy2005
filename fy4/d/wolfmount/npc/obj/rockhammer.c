#include <ansi.h> 
#include <weapon.h> 
inherit HAMMER;

void create()
{
        set_name( HIB"���˴�"NOR, ({ "wave-hammer" }) );
        set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ����ʽ��׾�Ĵ���������Լһ�ٰ�ʮ� \n");
                set("material", "gold");
                set("rigidity", 200000); 
                set("wield_msg", "$N�������ף�ŭ���л�Ȼ���һ��$n�����˵�������������С�\n");
                set("unwield_msg", "$N�����������е�$n��\n");
        }
        ::init_hammer(20);
}
