// TIE@FY3
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("����Ƥ", ({ "dragon skin","skin" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "leather");
                set("for_create_cloth",1);
                set("armor_prop/armor", 20);
		set("long","ɳ����������Ƥ�������커�׵���ѡ���ϡ�\n");
		set("max_enchant",6);
                set("base_armor",15);
		set("value",100000);
        }
        ::init_cloth();
}
