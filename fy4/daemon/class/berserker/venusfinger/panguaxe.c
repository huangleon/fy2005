// Pango-Axe
// annie 10.2003

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, myexp, hisexp,flag;
	object weapon;

	extra = me->query_skill("venusfinger",1) ;
	if (extra < 40) 
		return notify_fail("��Ҫ40������ָ������ʹ�����̹Ÿ�����\n");
	if (me->query("force") < 200)
		return notify_fail("�������������ʹ�����̹Ÿ�����\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���̹Ÿ���ֻ�ܶ�ս���еĶ���ʹ�ã�\n");
	
	weapon = target->query_temp("weapon");

	if (!weapon)
		return notify_fail("����û��ʹ������������ʹ�����̹Ÿ�����\n");
	
	if (weapon->query("nodrop_weapon"))
		return notify_fail("��������������޷���ϵġ�\n");

	if (userp(me))
		me->add("force",-200);
	
	message_vision(WHT"\n$N"WHT"ͻȻ������Ĵָʳָ��������������������ʣ�����Ҳ����������\n\n"NOR,me,target);
	me->perform_busy(2);
	call_out("do_pangoaxe",1,me,target,weapon);
	return 1;
}

int do_pangoaxe(object me,object target,object weapon)
{
	string msg;
	int extra, myexp, hisexp,flag;
	if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
		return 0;
	if(!present(weapon,target)||weapon->query("equipped")!="wielded") {
		me->set("timer/pfm/venusfinger_fail",time());		// a mark used by NPCs. 
		return 0;
	}
	myexp  = me->query("combat_exp");
	hisexp = target->query("combat_exp");
	
	if( (userp(target) || random(hisexp) < random(myexp*2)) && weapon)	
	{
		message_vision(
		WHT "\n\n$N"WHT"�������һ������Ӱһ�Σ�ʳָէȻ��������ͬ��Խ��ǧ���ʱ��һ�㣬����"+ 
		weapon->name()+  WHT"֮�ϡ�\n����ֻ����һ����������Ƶľ���ը����"+weapon->name()+WHT"������������Ƭ�������컨���ɢ������\n\n" NOR, me,target);

		weapon->unequip();
		if(weapon->query("owner"))
		{
			weapon->set("orig_name", weapon->query("name"));
			weapon->set("weapon_prop/damage",1);
		}
		else
			weapon->set("weapon_prop",0);
		target->reset_action();
		weapon->set("name","�ϵ���" + weapon->query("name"));
		weapon->set("item_damaged", 1);
		weapon->set("value",0);
		weapon->save();

	}
	else {
		message_vision(	WHT "\n$N����Ѱ���Ż��ᣬҧ��ҧ��������ָ�����ɿ���\n\n" NOR, me,target);
		me->set("timer/pfm/venusfinger_fail",time());		// a mark used by NPCs. 
	}
	return 1;
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
