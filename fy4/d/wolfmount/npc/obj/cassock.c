#include <armor.h>

inherit CLOTH;
#include <ansi.h>

void create()
{
        set_name(HIR"��Ƥ����"NOR, ({"blood cassock", "cassock"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
        set("long","һ����Ƥ���ƵĴ�����ģ����������������˺ܶ�ӬͷС�֡�\n");
                set("material", "cloth");
                set("skill", ([
                        "name":                 "cursism",               
                        "exp_required": 100000,                              
                       "sen_cost":             50,        
                    "difficulty":   50,          
                        "max_skill":    40                              
                ]) );
                set("unit", "��");
                set("value", 100);
                set("armor_prop/armor", 10);

        }
        ::init_cloth();
}

