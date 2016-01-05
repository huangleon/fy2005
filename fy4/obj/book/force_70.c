#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIR"»ðÁú³àÆ¤"NOR, ({ "dragonskin" }));
        set_weight(600);
        if( clonep() )
        set_default_object(__FILE__);
        else {
	        set("unit", "¼þ");
	        set("long", "Ò»¿é°µºìÉ«²¼ÂúÁÛÆ¬µÄÁúÆ¤¡£\n");
	        set("value", 7000);
	        set("material", "leather");
	
	        set("skill", ([
	                "name":         	"force", 
	                "exp_required": 	1000000,                                
	                "sen_cost":             10,                            
	                "difficulty":   	20,             
	                "max_skill":    	70             
	        ]) );
	        set("armor_prop/armor",10);
        }
        ::init_cloth();
}

