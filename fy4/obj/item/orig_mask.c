// inherit EQUIP;
#include <armor.h>
inherit MASK;
void create()
{
        set_name("��Ƥ���", ({ "skinmask" }) );
        set_weight(600);
                set("unit", "��");
                set("value", 0);
                set("material", "cloth");
                set("armor_type", "mask");
		set("fakegender", "����");
                set("armor_prop/id", ({"maskman"}) );
                set("armor_prop/name", ({"������"}) );
                set("armor_prop/short", ({"������(maskman)"}) );
	::init_mask();
}
