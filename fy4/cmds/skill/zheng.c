//	Silencer@fy4 workgroup
/*L100	��һ�ֳ�����Х��������ս����CDT30����
L150	��������ˮ��*�������������ӣ�������������������20����
L160	��������������ٻ���������ս����ʹ�ã�CDT1����
L170	���ĳ�������*�������м����ӣ�������������������20����
L180	���廢���������л������Թ���һ�У���������æ��һ�غ�
L200	�����������󡻻��������Լ�����ͼ��ס���֣�
		���ɹ�����æ�����غϣ���ʧ����������
		���ؼ����ܣ£գӣٷ����У��غ�Ч���½���Ӱ�죬
L210	������ն�������л�����������һ�У���������æ��һ�غ�
		���⹥������������������
		�����˺�����������л������������ȼ�
		����ɱ�������ܶԷ���������Ӱ��
L220	�����Խ�����* ����Ϊ���˵�ס�����˺���CDT 30���ӣ�
		���������˺�����ת�޵��������ϣ�����������
L230	�������ǌm��ʹ���񻷣�������æ�ң�CDT 15����
L250	��ʮ���������һ������������������Ļ�����CDT 30����
��ʹ�÷����ֱ�Ϊdodge.yi��dodge.er��dodge.san��dodge.si��
dodge.wu��dodge.liu��dodge.qi��dodge.ba��dodge.jiu��dodge.shi
*/

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform_1(object me, object target)
{
    int skill, num, i, duration,title,hate;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
	
	object soldier,*enemy;
	int strategy,leadership;
	int timer;
		
	skill = me->query_skill("strategy",1);

    timer = 1800 - F_ABILITY->check_ability(me,"yi_add")*60;
    duration = me->query("timer/pfm/alert")-time() + timer;
    if ( duration >0) {
		tell_object(me,"�㻹��Ҫ�ȴ�"+(int)(duration/60)+"�������Ҳ����ٴη���һ�ֳ�����\n");
 		return 1;
 	}
 	
    if (ANNIE_D->check_buff(me,"lockfield") >= 1) {
		tell_object(me,"�˵ص��Ʋ������޷�����һ�ֳ�����\n");
		return 1;
	}
	
	if( !me->is_fighting() ){
        tell_object(me,"һ�ֳ�����ֻ����ս���з�����\n");
        return 1;
    }		
	
	if( me->query_temp("max_guard") > 1 ){
    	tell_object(me,"һ�ֳ��������ڷ�����\n");
		return 1;
	}
	
	msg = BGRN + HIY "$N�Ӷ�������ǹ��������������λ�λ�����Ʈҡ����������˲���г�"HIW"һ�ֳ���֮��\n" NOR HIB"
���������У�һ�˺��¡��������죬����$N��ǰ�е������Ѷ����������ˣ���ĩ���Ϻ�\n\n"NOR; 	

  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
  	seteuid(getuid());
	soldier= new("/obj/npc/danei_guard");
	soldier->set("possessed", me);
    soldier->set_leader(me);
      	   	
    soldier->set_name(WHT"��ʿ"NOR,({ "sishi" })); 
	soldier->move(environment(me));	
	soldier->invocation(me, (skill+ me->query_skill("leadership",1)));
		
	if (soldier) {       	
		    enemy = me->query_enemy();
		    if (enemy)
	    	for (i=0;i<sizeof(enemy);i++)
	    	{
	       		hate = enemy[i]->query_hate(me);
	       		enemy[i]->add_hate(soldier, hate);     	
	    	}   	
  			me->remove_all_killer();
        	me->add_temp("max_guard",1);
    }

    me -> set("timer/pfm/alert",time());      	        
    return 1;
}
	
int perform_2(object me, object target)
{
    int skill, num, i, duration;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
		
	skill = me->query_skill("strategy",1);

    duration = me->query("timer/pfm/yue_array")-time() + 10;
	if (duration>0) {
        tell_object(me,"����Ҫ�ȴ�Ƭ�̣�"+ duration +"�룩�����ٴα���󷨡�\n");
        return 1;
    }
        
	if (me->query_temp("guard_count")<2) {
       	tell_object(me, "��Ļ���̫�٣��в�����Ү��\n");
        return 1;
    }
    	
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

int perform_3(object me, object target)
{
        int skill, num, i, duration;
	object *shiwei;
	mapping buff;
	string msg;
	
	int extra, maximum, gcount;
	object recruit;
	
	object *enemy;
		
        	
	skill = me->query_skill("strategy",1);

    duration = me->query("timer/pfm/yue_array")-time() + 10;
	if (duration>0) {
        tell_object(me, "����Ҫ�ȴ�Ƭ�̣�"+ duration +"�룩�����ٴα���󷨡�\n");
        return 1;
    }
    
    maximum = 2;
	if (me->query_skill("leadership",1)>= 250)	maximum = 4;
	else if (me->query_skill("leadership",1)>= 175) maximum = 3;
        	
    gcount=me->query_temp("guard_count");
	if(gcount>=maximum) {
		tell_object(me,"�����ڲ���Ҫ�������������\n",me);
        return 1;
   	}
   	        	
    if (userp(me) && me->is_fighting()) {
       	tell_object(me, "������ս����ʹ��û��Ч���ġ�\n");
        return 1;
    }
    	
    duration = me->query_temp("timer/pfm/gf_san")-time() + 60;
	if (userp(me))
        if (duration>0) {
        	tell_object(me,"�������������ÿ����ֻ������һ�Ρ�\n");
        	return 1;
    }
    
	msg = BGRN + HIY "$N"BGRN + HIY "�Ӷ�������ǹ��������������λ�λ�����Ʈҡ����������˲���г�"HIW"���������֮��\n" NOR YEL"
������������������һ��׳ʿ���˵ذݵ���$N"NOR+YEL"��ǰ������˵��������֮�壬���ˮ����
����$nԸ����ǰЧ��������ɱ�У��������ǡ�\n\n"NOR; 	
  	
  	extra=me->query_skill("strategy",1)+ me->query_skill("leadership",1);
	seteuid(getuid());
	recruit=new("/obj/npc/huwei");
	recruit->invocation(me,extra);
	recruit->move(environment(me));
	
  	message_vision(msg, me, recruit);
  	me->set("timer/pfm/yue_array",time());
  	me->set_temp("timer/pfm/gf_san",time());	 		
	me->add_temp("guard_count",1);
	if (!userp(me))
	{
		enemy = me->query_enemy();
		i = sizeof(enemy);
		while(i--) {
			if( enemy[i] && living(enemy[i]) ) {
				recruit->kill_ob(enemy[i]);
				if( userp(enemy[i]) ) enemy[i]->fight_ob(shiwei);
				else enemy[i]->kill_ob(recruit);
			}
		}
	}
        return 1;
}

int perform_4(object me, object target)
{
    int skill, num, i, duration;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
		
	skill = me->query_skill("strategy",1);

    duration = me->query("timer/pfm/yue_array")-time() + 10;
	if (duration>0) {
        	tell_object(me,"����Ҫ�ȴ�Ƭ�̣�"+ duration +"�룩�����ٴα���󷨡�\n");
        	return 1;
    }
    
	if (me->query_temp("guard_count")<2) {
        	tell_object(me, "��Ļ���̫�٣��в�����Ү��\n");
        	return 1;
    }
    
	msg = BGRN + HIY"$N"BGRN + HIY"�Ӷ�������ǹ��������������λ�λ�����Ʈҡ����������˲���г�"HIW"�ĳ�����֮��\n" NOR; 	
  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
	skill = skill/3;	// 250/3 = 83
		
	if (ANNIE_D->check_buff(me,"array-iron"))
			ANNIE_D->debuff(me,"array-iron");
    
	// Well: SHiwei = shiwei + friend + myself:)
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
				"name":"�������ĳ�������",
				"buff1":"apply/parry",
				"buff1_c":skill,
				"time": 1200,
				"buff_msg": "",
				"disa_type":1,			
			]);
		ANNIE_D->buffup(buff);		
    }
    return 1;
}

int perform_5(object me, object target)
{
        int skill, num, i, duration, mod;
	string msg, name;
	object *env, *huwei, weapon;
	string *poem = ({"�������ָڻ�ս�������ƿ���һϪ����"HIY"��ת��һ����",
"������ˮմ�̴��������빬ͥ�����ܡ�"HIY"����ת��һ����",
"���Ϸ�ֻ���С�󣬱�ԯ���շ����ݡ�"HIY"����ת��һ����",
"���Ľ��߳߳���ʥ��ŭָ�����᲻�ա�"HIY"��ת��һ����",
"������ͷ����ʰ��ɽ�ӡ�"HIY"��ǰת��һ����",
"�������ڣ���"HIY"���ת��һ����"
	});

	skill = me->query_skill("strategy",1);
             
    env = all_inventory(environment(me));
	huwei = filter_array(env, (: living($1) && $1->query("possessed")== $2
		&& $1->query("id")!="bodyguard" && $1->query("id")!="sishi"  :), me);
	if (!sizeof(huwei)) {
		tell_object(me, "��Ļ�������������޷��������廢����ꇡ�\n");
		return 1;
	}
	
	msg = "\n"BGRN + HIY"$N"BGRN + HIY"�Ӷ�������ǹ��������������λ�λ�����Ʈҡ����������˲���г�"HIW"�廢����֮��"NOR HIR" 	

$N"HIR"�����ȵ����������ùᶷţ���Ľ�ֱ�ڱ�����ն����񻹳��ݣ����ʵ�̳�򻧺
����δ�䣬����ڽ�����Ӧ�ͣ�����������\n"NOR;
  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
  	for (i=0;i<sizeof(huwei);i++) {
  		if (huwei[i]->query_temp("is_unconcious") 
  			|| !huwei[i]->is_fighting(target)
  			|| huwei[i]->is_busy())	continue;
  			msg = HIW+poem[i]+ "������ǰֱȡ$n��"HIY"����" + huwei[i]->name()+"��\n"NOR;
  		if (huwei[i]->query("skill")== "spear" || huwei[i]->query("skill")=="hammer") {
  			huwei[i]->add_temp("apply/attack", skill*2);
  			huwei[i]->add_temp("apply/damage", skill);

  			COMBAT_D->do_attack(huwei[i],target, TYPE_PERFORM,msg);

  			huwei[i]->add_temp("apply/attack", -skill*2);
  			huwei[i]->add_temp("apply/damage", -skill);
  			
  			huwei[i]->perform_busy(1);
		}
  	}

	me->perform_busy(1);	
    return 1;
}

	
int main (object me, string arg1)
{
	
	int num,stra,lead,duration;
	string *zheng = ({ "��һ�ֳ�����","��������ˮ��","�������������","���ĳ�������","���廢����ꇡ�",
						"������������","������ն����","�����Խ�����","�������ǌm��","��ʮ�������"});
	int *zheng_r = ({100,150,160,170,180,200,210,220,230,250});
	string arg;
	object obj,target;
	
	if (userp(me))
    if (me->query("family/master_id")!="master yue" 
        || me->query("class")!="official")
        return notify_fail("ֻ�����ɵĵ��Ӳ���ʹ���󷨡�\n");
    
    if (me->is_busy())
    	return notify_fail("��������æ���޷�ʹ���󷨡�\n");
    	
   	if( environment(me)->query("no_fight"))
		return notify_fail("�����޷�ʹ���󷨡�\n");

	if (!arg1)
		return notify_fail("��Ҫʹ����һ���󷨣�\n");

	if (sscanf(arg1,"%d on %s", num, arg)!= 2) {
		num = atoi(arg1);	
		if (num>10 || num <0)
			return notify_fail("����ȷʹ�ø�ʽΪzheng ����(1-10) on ����\n");
	}
	
	if (num>10 || num <0)
		return notify_fail("��ֻ��1-10�֣���ȷʹ�ø�ʽΪzheng ���� on ����\n");

    stra = me->query_skill("strategy",1);
    lead = me->query_skill("leadership",1);
    
    if (stra < zheng_r[num-1] || lead < zheng_r[num-1])
    	return notify_fail(zheng[num-1]+"������Ҫ"+ zheng_r[num-1]+"������������֮����\n");
    	
    if (me->query_skill_mapped("force")!= "manjianghong")
    	return notify_fail(zheng[num]+"��Ҫ�������ķ�Ϊ������\n");
    
    if (arg) {
    	if (!objectp(obj = present(arg, environment(me))))
			return notify_fail("���˲��������Χ��\n");
		if (! obj->is_character())
			return notify_fail("�����һ�㣬�ǲ��������\n");
		if (!living(obj))
			return notify_fail("�����һ�㣬�ǲ��������\n"); 
	}
	
    if( (int)me->query("force") < 50 )    
       	return notify_fail("�ݻ���������Ҫ50��������\n");   	
    if (userp(me))
        	me->add("force", -50);

	// �仯��������Ҫ10���ӵļ��
	duration = me->query("timer/pfm/yue_array")-time() + 10;
	if (duration>0 && num !=1)
       	return notify_fail("����Ҫ�ȴ�Ƭ�̣�"+ duration +"�룩�����ٴα���󷨡�\n");
    
    //	������������Ҫ2������
    if (me->query_temp("guard_count")<2 && num == 5)
       	return notify_fail("��Ļ���̫�٣��в�����Ү��\n");
    
    //	�����Ե���ֻ����ս����ʹ��
    target = obj;
    if (num == 5) {	    	    	
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail(zheng[num-1]+"��Ҫ��ս����ʩչ��Ŀǰ�㲻��ս���У�������ָ���Ķ�����㲢����ս���С�\n");
	}
	
	/*
	env = all_inventory(environment(me));
	huwei = filter_array(env, (: living($1) && $1->query("possessed")== $2
		&& $1->query("id")!="bodyguard" && $1->query("id")!="sishi"  :), me);
	if (!sizeof(huwei)) {
		tell_object(me, "��Ļ�������������޷��������廢����ꇡ�\n");
		return 1;
	}*/
	
	CHANNEL_D->do_sys_channel("sys",sprintf("num= %O, target=%O",num, obj));

	switch (num) {
		case 1:	perform_1(me, target);break;
		case 2: perform_2(me, target);break;
		case 3:	perform_3(me, target);break;
		case 4: perform_4(me, target);break;
		case 5:	perform_5(me, target);break;
/*		case 6: perform_6(me, obj);break;
		case 7:	perform_7(me, obj);break;
		case 8: perform_8(me, obj);break;
		case 9:	perform_9(me, obj);break;
		case 10: perform_10(me, obj);break;	
	*/}
			
/*	
	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, obj)) {
		if (stringp(obj->query("NO_KILL")))
			return notify_fail(obj->query("NO_KILL"));
		if (stringp(obj->query("NO_PK")))
			return notify_fail(obj->query("NO_PK"));	
		else 
			return notify_fail("���޷�͵Ϯ���ˡ�\n");
	}*/
		
    
	return 1;
}


int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	2word[0m
[0;1;37m����������������������������������������������������������������[0m   

���Ѹ�ɮ�����������䵽170�����Ϻ󣬿�ͬʱ�̳��������ԣ�
���ǣ���ʹ��֮ǰ���뾲˼Ƭ�̼��䡣

��ʽ��������2word an+an
���磺	   2word an+ni

ʹ��cast 2word ��ɽ�����ס������ͬʱ�̳���

���ڶ���������˵���ķѵķ�����಻����400����ɵ�����æ��
��಻����4��

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}