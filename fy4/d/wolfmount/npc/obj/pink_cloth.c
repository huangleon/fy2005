#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("ǳ�����", ({ "pink cloth", "cloth" }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long","����ۺ�ɫ�ĳ����������ż�ֻ��ȵ������������һ�ɵ��㡣\n");
        set("unit", "��");
        set("value", 0);
        set("material", "cloth");
        set("armor_prop/armor", 1);
        set("female_only", 1);
    }
    ::init_cloth();
}

