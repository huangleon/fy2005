// blackthorn.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("���ս�", ({ "blackthorn sword", "blackthorn", "sword" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"����һ��ͨ����ڵ��ؽ������������˼���ĵ���������\n"
"�����ഫ�ı�������˵��ѽ�ɱ�˲�մѪ����Զ����ɱ����\n");
                set("value", 200);
                set("material", "blacksteel");
                set("wield_msg", "ֻ������쬡���һ����$N�������Ѿ�����һ�Ѻ�������ı�������$n��\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }
        ::init_sword(28);
}
 
