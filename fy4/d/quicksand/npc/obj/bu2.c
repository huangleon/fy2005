// TIE@FY3
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("ϸ����", ({ "huabu" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("for_create_cloth",1);
                set("armor_prop/armor", 8);
		set("long","һ��ӡ��С���İײ��������ֱ���������͸����\n");
		set("max_enchant",4);
                set("base_armor",8);
		set("value",10000);
        }
        ::init_cloth();
}
