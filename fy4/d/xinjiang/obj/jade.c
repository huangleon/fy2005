#include <armor.h>

inherit NECK;

void create()
{
        set_name("����׹��", ({ "jade", "white jade"}) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����Ө��͸�İ���׹������˵��������ɳĮ�����߿��Ա�а��\n");
                set("unit", "��");
                set("value", 500);
                set("wear_msg", "$N����ذ�һ��$n���ڲ����ϡ�\n");
                set("unwield_msg", "$N����ذ�$n�Ӳ����ϳ���������\n");


        }
        ::init_neck();
}


