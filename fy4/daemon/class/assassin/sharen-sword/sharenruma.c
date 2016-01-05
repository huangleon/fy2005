#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int target_perform(object me, object target);

string* where = ({
        "�İ�",        "�ز�",        "��ӭ",        "Ͽ��",        "ͷά",        "�¹�",
        "����",        "̫��",        "����",        "�ػ�",        "�ٺ�",        "ͨ��",
		"����",        "����",        "��Һ",        "����",        "����",        "�ٻ�",
		"��̨",        "����",        "����",
});

int perform(object me, object target)
{
    	string msg;
    	int extra,i,j,lmt,damages,bell;
    	object weapon;
    	object *enemy;
    
    	extra = me->query_skill("sharen-sword",1);
    	if ( extra < 100)
        	return notify_fail("��ɱ�����须������Ҫ100����ɱ�˽�����\n");
        
    	enemy=me->query_enemy();
    	if(!sizeof(enemy))
		return notify_fail("��ɱ�����须ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//    	if (me->query("bellicosity")<=100 && userp(me))
//    		return notify_fail("���ɱ�������ߡ�\n");    
    
    	if (target && me->query_temp("jingxing/concentrate")) {
    		if( !target->is_character()
		|| !me->is_fighting(target) )
			return notify_fail("��ɱ�����须ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 	
	   	target_perform(me,target);
	    	return 1;
    	}
    		
    	if(target)	return notify_fail("��ɱ�����须����Ҫָ��ʹ�ö��󣡣�\n");
    
    	if (me->query_temp("timer/sharen")+20>time() && userp(me) 
    		&& ! me->query_temp("jingxing/concentrate"))
    		return notify_fail("���ɱ�������һ��ʱ��������¾ۼ�������\n");
	
    	weapon = me->query_temp("weapon");
    	if(extra <= 162)
    	{
	        damages = extra/4;
	        msg = HIY"\n$N"+HIY"���Դ󷢣����е�"+ weapon->name()+
	            HIY"��籩������$n"+HIY"����! " NOR;
			message_vision(msg,me,enemy[0]);
	        me->add_temp("apply/attack",damages);
	        me->add_temp("apply/damage",damages);
    	}
    	else
    	{
			damages = extra/4;
	        
//	        msg = HIY"\n$N"+HIY"ɱ����ʢ��ֻ��"+ weapon->name()+
//	            HIY"������������$n"+HIY"ȫ�����ҪѨ�̵�! " NOR;

			msg = HIY"\n$N"+HIY"�Ľ�ʽ��Ȼ������������������Ľ���·����зɾ��ɰʯ��Ю\n������ͬҹ�ɼ��������Х֮��ָ��$n"HIY"������ҪѨ��\n" NOR;

	        message_vision(msg,me,enemy[0]);
	        me->add_temp("apply/attack",damages);
	        me->add_temp("apply/damage",damages);
    	}
    
    	lmt = random(5)+3;
		if (extra>160 && lmt<5) lmt=5;
    	if ( me->query("fy41/jq_sharenruma") ) 
    		lmt = 7;
    		 
    	j=0;
    	for(i=1;i<=lmt;i++)
    	{
	    	if(extra <= 162)
		    	msg =  HIR "��"+chinese_number(i)+"����" NOR;
			else
				msg = HIR+where[(i-1)*3+random(3)]+"��"NOR;
        	COMBAT_D->do_attack(me,enemy[j],TYPE_PERFORM,msg);
        	if (j==sizeof(enemy)-1) j=0;
			else j++;
    	}
    	
    	me->add_temp("apply/attack",-damages);
    	me->add_temp("apply/damage",-damages);
    	
    	me->perform_busy(3);
    	me->set_temp("timer/sharen",time());

/*    	if(extra > 162)			a little too romantic for Jing :)
		{
			msg = MAG"\n����һ����û������$N"MAG"���У���ʱ��ͣ��ֹ�������Ϣ���ղŵ�һ����\n��Ȼ�޴棬�ƺ�ֻ�����һ�����Ρ�\n\n" NOR;
			message_vision(msg,me,enemy[0]);
		}*/

    	return 1;
}


int target_perform(object me, object target)
{
    	string msg;
    	int extra,i,j,lmt,damages,bell;
    	object weapon;
    	object *enemy;
    	    
    	extra = me->query_skill("sharen-sword",1);
    	weapon = me->query_temp("weapon");
    	if(extra <= 162)
    	{
	        damages = extra/4;
	        msg = HIY"$N"+HIY"���Դ󷢣����е�"+ weapon->name()+
	            HIY"��籩������$n"+HIY"����! " NOR;
	        message_vision(msg,me,target);
	        me->add_temp("apply/attack",damages);
	        me->add_temp("apply/damage",damages);
    	}
    	else
    	{
	        	damages = extra/4;
	        
//	        msg = HIY"$N"+HIY"ɱ����ʢ��ֻ��"+ weapon->name()+
//	            HIY"������������$n"+HIY"ȫ�����ҪѨ�̵�! " NOR;
			msg = HIY"\n$N"+HIY"�Ľ�ʽ��Ȼ������������������Ľ���·����зɾ��ɰʯ��Ю\n������ͬҹ�ɼ��������Х֮��ָ��$n"HIY"������ҪѨ��\n" NOR;

			message_vision(msg,me,target);
	        me->add_temp("apply/attack",damages);
	        me->add_temp("apply/damage",damages);
    	}
    	lmt = random(5)+3;
    	if (extra>160 && lmt<5) lmt=5;
    	 
    	for(i=1;i<=lmt;i++)
    	{
        	msg =  HIR "��"+chinese_number(i)+"����" NOR;
        	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);  
    	}
    
    	me->add_temp("apply/attack",-damages);
    	me->add_temp("apply/damage",-damages);  
    
    	if (userp(me)) me->add("bellicosity",-30);
    	
    	if (!me->query("fy41/jq_sharenruma") && userp(me)
    		&& !( wizardp(me) && me->query("fy41/wiz"))
    		)
    	    	me->perform_busy(4);
    	else
    		me->perform_busy(3);
    		
/*    	if(extra > 162)
		{
			msg = MAG"\n����һ����û������$N"MAG"���У���ʱ��ͣ��ֹ�������Ϣ���ղŵ�һ����\n��Ȼ�޴棬�ƺ�ֻ�����һ�����Ρ�\n\n" NOR;
	        message_vision(msg,me,enemy[0]);
		}*/

		return 1;
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
