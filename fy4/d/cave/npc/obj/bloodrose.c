#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(HIR"��Ѫ�ĺ�õ��"NOR, ({ "blood rose", "rose" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������ŵĺ�õ�壬��������������һ�ε���Ѫ��\n");
                set("unit", "��");
                set("value", 100);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");

                set("female_only", 1);

        }
        ::init_head();
}
