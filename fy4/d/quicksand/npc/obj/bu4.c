// TIE@FY3
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("��ʲ�", ({ "caibu" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("for_create_cloth",1);
            set("base_armor",4);
            set("material", "cloth");
            set("armor_prop/armor", 4);
    		set("long","һ����ⷪ�������Ĳ��飬�ǳ���飬Ҳ��֪��ʲô���ϡ�\n");
    		set("max_enchant",6);
    		set("value",40000);
        }
        ::init_cloth();
}
