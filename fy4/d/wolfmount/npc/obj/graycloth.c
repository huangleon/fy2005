#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("����", ({"gray cloth", "cloth"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("long", "һ���Ұ��Ĳ��ۣ���������һ˿����Ҳû�У�\n");
                set("unit", "��");
                set("value", 200);
                set("armor_prop/armor", 5);
        }
        ::init_cloth();
}
