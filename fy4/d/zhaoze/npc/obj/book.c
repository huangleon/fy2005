#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(HIR"������Ƥ"NOR, ({ "dragonskin" }));
        set_weight(600);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long",
                "һ�鲼������ɫ����Ƥ\n");
        set("value", 700);
        set("material", "leather");
//      set("no_sell",1);
//	set("no_drop",1);
        set("skill", ([
                "name":                 "yoga", 
                "exp_required": 1000000,                                
                "sen_cost":             10,                            
                "difficulty":   20,             
                "max_skill":    70             
        ]) );
        set("armor_prop/armor",10);
        }
        ::init_cloth();
}

