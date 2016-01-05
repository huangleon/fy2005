// Silencer@fengyun workgroup	June.2005
// Paragon: 10 times +3*170=510 kee, with ability = 660 kee

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
	int level,i, skill, duration, amount1;
	object *enemy, *mem;
	
	if(me->query("class")!="wolfmount")
		return notify_fail("ֻ����ɽ���Ӳ��ܡ����Ǿ�����\n");

	level = me->query_skill("wolf-force",1);
	if (level<170 || me->query_skill("summonwolf",1)< 250) 
		return notify_fail("�����Ǿ�����Ҫ170�������ķ���250����������\n");
	
	if(!target ) target=me;
	if (target != me)
		return notify_fail("�����Ǿ���ֻ����������\n");
		
	if (target->query_temp("pfm/wolf-force/paragon"))
		return notify_fail("���Ѿ���ʹ�á����Ǿ����ˡ�\n");
	
	// duration = 20mins.
	duration = me->query("timer/pfm/wm_paragon")+ 1200 -time();
	if (duration>0)
    	return notify_fail("�����Ǿ�������Ԫ����Ҫ"+chinese_number(duration/60)+"���Ӻ�����ٴ����á�\n");
	
	if( (int)me->query("force") < 200 )
		return notify_fail("ʹ�á����Ǹ��塻��Ҫ��������������\n");
	if (userp(me)) me->add("force", -200);
	
	message_vision(BRED+HIW"
$NĿ��ͻ��ȫ������˳����ɫ�����������Ƥ����Ҳͻ�ر�Ϊ�Ϻ죬ȫ��
�����ѱ�����ȼ���������������Ϲ�ħ��Ҫ���˶��ɣ�\n"NOR, me);

	amount1 = level *3 * (100 + F_ABILITY->check_ability(me,"paragon_add")*3)/100;
	call_out("fillup",6,me,10,0,amount1);        
    
    me->set_temp("pfm/wolf-force/paragon", 1);
	me->set("timer/pfm/wm_paragon",time());
	return 1;

}


void fillup (object me, int total, int count, int amount)
{
	if (!me)	return;
		
	if(++count>=total)
	{
		tell_object(me,YEL"��������ķ������Ǿ�������ϡ�\n"NOR);
		me->delete_temp("pfm/wolf-force/paragon");
		return;
	}
	else {
		me->receive_fulling("kee", amount,me);
		me->status_msg("kee");
		message_vision(WHT"$N����ľ����֮���������������ķε�Х��������\n"NOR,me);
		call_out("fillup",6,me,total,count, amount);
	}
	return ;
}


