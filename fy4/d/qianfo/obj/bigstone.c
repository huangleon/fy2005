#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("���ʯ", ({ "blackstone" }) );
        set_weight(760000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���൱���Ĵ��ʯ\n");
                set("value", 3);
                set("material", "iron");
        }
        ::init_hammer(20);
}
