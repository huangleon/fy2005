#include <weapon.h>

inherit BLADE;

void create()
{
    set_name("�˵�", ({ "caidao" , "cai dao", "knife" }) ); 
    set_weight(500);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("value", 20);
        set("material", "metal");
        set("long", "�⼣�߰ߵĲ˵���\n");
        set("wield_msg", "$N�ó�һ���⼣�߰ߵ�$n���������С�\n");
        set("unequip_msg", "$N�������е�$n��\n");
    }
    ::init_blade(10);
}
