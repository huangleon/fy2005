#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
        set_name(CYN"֯����װ"NOR, ({"silk cloth", "cloth"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("long", "һ��������ʮ�������ר����֯����װ��\n");
                set("unit", "��");
                set("value", 200);
                set("armor_prop/armor", 5);
        }
	::init_cloth();
}