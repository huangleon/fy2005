#include <armor.h>
inherit MASK;

void create() {
        set_name("��ɫ���", ({ "blackmask"}) );
        set_weight(2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���ɫ������ɴ��\n");
                set("material", "cloth");
                set("unit", "��");
                set("value", 3);
                set("wear_msg", "$N����ذ�$n�������ϡ�\n");
                set("unwield_msg", "$N����ذ�$n�����ϳ���������\n");
        }
        ::init_mask();
}
