#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(BLU"��������"NOR, ({ "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ױ���ɫ�ĳ��ۣ�Ӻ�ݻ���\n");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        ::init_cloth();
}
