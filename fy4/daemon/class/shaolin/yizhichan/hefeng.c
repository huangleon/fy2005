// ��Ŀ����Լ����������Hate�嵽��ͣ����Լ���Hate����Ϊzen*20

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string msg;
    int extra, i, num, hate, duration, timer;
	string name;
	object weapon, *enemy;
		
    if(me->query("class")!="shaolin")
	return notify_fail("�ͷ������־���������ô���ܻ�ʹ�أ�\n");

    extra = me->query_skill("yizhichan",1);
    if(extra<140) return notify_fail("�ͷ���Ҫ140����һָ����Ϊ��\n");

    timer = 600 - F_ABILITY->check_ability(me,"hefeng_add")*20;	
    duration = me->query("timer/pfm/sl_hefeng")+timer-time();
	if (duration>0)
    	return notify_fail("���ͷ硻��Ҫ"+chinese_number(duration)+"�������ٴ�ʹ�á�\n");
    
    if( !target ) target = offensive_target(me);
    if( !target
      ||      !target->is_character()
      ||      !me->is_fighting(target) )
	return notify_fail("�ͷ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	weapon = target->query_weapon();
	if (objectp(weapon))	name = weapon->query("name");
	else					name = "����";

    message_vision(BBLU + YEL"
���ϻ�Ҷ������Ʈ�����ε���������������������ϣ��������˷磬�ͷ硣

����һֻ��ָ��

$N"NOR+BBLU + YEL"����ָ������$n"+name+NOR+BBLU + YEL"�ϣ��������ڻ�����һ�����ᡣ

�紵ҶƮ��������ˮ�С�

��ֻ�黨һ�����ָ����"+name+ NOR+BBLU + YEL"�ϣ�Ȼ���ֻ������ջ�ȥ��

��������һ�仰��

"NOR+BBLU+HIY"�������ӷ�"NOR"\n\n",me,target);

	me->set("timer/pfm/sl_hefeng",time());
	enemy = target->query_enemy();
    num = sizeof(enemy);
    if (!enemy || num<1)	return 1;
	      
    for (i=0;i< num; i++){
    	if ( !enemy[i])			continue;
    	hate = target->query_hate(enemy[i]);
    	if (hate<10 && enemy[i]!=me)	continue;
    	target->add_hate(enemy[i], -hate + 10);
    	if (enemy[i]==me)	target->add_hate(me, me->query_skill("zen",1)*20);
    }	
       
    return 1;        
}     
