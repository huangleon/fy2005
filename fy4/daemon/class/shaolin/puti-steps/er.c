// Silencer@fengyun workgroup	June.2005


#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, num, i, duration,add;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
		
        if (userp(me))
        if (me->query("family/master_id")!="master yue" 
        	|| me->query("class")!="official")
        	return notify_fail("ֻ�����ɵĵ��Ӳ���ʹ�á�������ˮ�󡻡�\n");
        	
	skill = me->query_skill("strategy",1);

	if (me->query_skill("strategy",1) < 150 || me->query_skill("leadership",1)< 150)
		return notify_fail("��������ˮ����Ҫ150��������150������֮����\n");        		
	  
	  
	  add = F_ABILITY->check_ability(me,"3_array_add",3)*4/10;
	       
    duration = me->query("timer/pfm/yue_array")-time() + 10 - add;
		if (duration>0)
        	return notify_fail("����Ҫ�ȴ�Ƭ�̣�"+ duration +"�룩�����ٴα���󷨡�\n");
        
	if (me->query_temp("guard_count")<2)
        	return notify_fail("��Ļ���̫�٣��в�����Ү��\n");
        	
	msg = BGRN + HIY "$N"BGRN + HIY "�Ӷ�������ǹ��������������λ�λ�����Ʈҡ����������˲���г�"HIW"������ˮ֮��\n" NOR; 	
  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
	skill = skill/3;	
		
    if (ANNIE_D->check_buff(me,"array-iron"))
			ANNIE_D->debuff(me,"array-iron");
    
    shiwei = filter_array(all_inventory(environment(me)),
        		(: $1->query("possessed")==$2 && $1->query("id")=="huwei" :),me);
    num = sizeof(shiwei);	
	
	for (i=0; i<num; i++) {
		if (ANNIE_D->check_buff(shiwei[i],"yue_array"))
			ANNIE_D->debuff(shiwei[i],"yue_array");
		buff =
			([
				"caster":me,
				"who": shiwei[i],
				"type":"yue_array",
				"att": "bless",
				"name":"������������ˮ��",
				"buff1":"apply/attack",
				"buff1_c":skill,
				"time": 1200,
				"buff_msg": "",		
				"disa_type":1,	
			]);
		ANNIE_D->buffup(buff);		
        }

        return 1;
}
