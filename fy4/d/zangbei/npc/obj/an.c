#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("Ƥ�Ƶ��հ�", ({ "tuoan" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","װ�����ձ��������̶�����ļ��ӡ�\n");
                set("material", "lether");
                set("armor_prop/armor", 20);
                set("value",10);
                set("wear_msg","$N�ó�һ���հ������Լ�����һ�ţ����˰��쾢�Ű����̶��á�\n");
                set("unequip_msg","$N��$n������ж�����������ش��˿�����\n");
        }
        ::init_cloth();
}
