#include <armor.h>
#include <weapon.h>
inherit DAGGER;
void create()
{
        set_name( "����" , ({ "clasp" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("value", 100);
                set("material", "silver");

                set("armor_prop/armor", 1);
                set("female_only", 1);
                set("wear_msg", "$Nϸ�ĵؽ�һ֧$n���ڷ����ϡ�\n");
                set("wield_msg", "$N��$n�������У�����һ��ذ�ס�\n");
        }
        ::init_dagger(10);
}
