inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(YEL"������"NOR , ({ "rou zongzi" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  		set("long", RED"�������ա�\n"NOR);
        	set("unit", "ֻ");
        	set("lore",1);
        	set("value", 1);
		set("food_remaining", 1);
		set("food_supply", 1);
		set("material", "food");
	}
	::init_item();
}


int finish_eat()
{
	mapping buff;
	object me = this_player();
	int amount;
	string msg;
	
	if (ANNIE_D->check_buff(me,"quest_atk") || ANNIE_D->check_buff(me,"quest_magic"))	// it won't show up..just eat it.
		return notify_fail("��ζ���档\n"); 
					
	msg = HIY "���������!��!\n"NOR;
/*	
	buff =
		([
			"caster": me,
			"who":   me,
			"type": "gks",
			"att":	"bless",
			"name":	"��õ�嶹ɳ�±�",
			"buff1": "kee",
			"buff1_c":1333,
			"buff2": "gin",
			"buff2_c":1888,
			"buff3": "sen",
			"buff3_c":1666, 
			"time":  43200 ,
			"buff_msg": msg,
			"disa_msg": "",
			"special_func":1,
		]);
*/		
		buff =
		([
			"caster": me,
			"who":  me,
			"type": "quest_atk",
			"att":	"bless",
			"name":	"������",
			"buff1":"apply/quest_atk",	// used in dodge/parry_attack in combatd.
			"buff1_c":20,
			"time":  43200 ,
			"buff_msg": msg,
			"special_func":0,
		]);
    ANNIE_D->buffup(buff);    
    me->perform_busy(1);  
    destruct(this_object());
  	return 1;
}
