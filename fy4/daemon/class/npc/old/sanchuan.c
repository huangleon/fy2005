// Silencer@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
int stone_done(object me, object caster);
int perform(object me, object target)
{
        int skill;
		mapping buff;	
	
        if (userp(me))
        	return notify_fail("�˼��Ѿ���������\n");
        	
        if(me->query("class")!="fugui")
    		return notify_fail("ֻ�и���ɽׯ���Ӳ���ʹ��������ըɽ�䡹�ľ�����\n");

       skill = me->query_skill("henglian",1);
		if(skill < 160) 
		return notify_fail("����ըɽ����Ҫ160���ĺ�������\n");
        
        if(!target) target = me;
        if( target != me ) 
        	return notify_fail("��ֻ�ܽ�����ըɽ�������Լ������ϡ�\n");
        
        if( ANNIE_D->check_buff(me,"ironup"))
        	return notify_fail("���Ѿ���ʩչ���ƵĻ������ˡ�\n");
        
        if (me->is_fighting())
		return notify_fail("����ըɽ���޷���ս����ʹ�á�\n");	
		
        if (me->query_skill_mapped("force")!="skyforce")
        	return notify_fail("������Ψ�б̿��ķ�����Ч��\n");
        	
        if( me->query("force") < 300 )     
        	return	notify_fail("����ըɽ����Ҫ300���������\n");
		if (userp(me))	me->add("force", -300);
	       
	me->set_temp("pfm/fg_sanchuan",5);
	
	buff =
		([
			"caster":me,
			"who":	me,
			"type": "ironup",
			"att": "bless",
			"name": "����������ըɽ��",
			"buff1":"apply/iron-cloth",
			"buff1_c":skill/2,
			"time":  300,
			"buff_msg":WHT"$Nȫ���½��Ȼ�޷��Զ���ȴ��ȫû��һ˿���죡��\n" NOR,
			"warn_msg":"",
			"finish_function": (: stone_done :),
		]);
	ANNIE_D->buffup(buff);
    	if(me->is_fighting() ) me->perform_busy(3);
    	return 1;
}


int stone_done(object me, object caster){
	me->delete_temp("pfm/fg_sanchuan");
	return 1;
}