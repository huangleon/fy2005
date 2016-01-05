// L60�� ��Ѫ����ѩ��LOH	cdt 60min

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
        object *mem, *enemy, target;
        int i, extra,duration, fix, add, qidao, dorm, stage;
        string msg, msg1;
        
		if(me->query("class")!="legend" && userp(me))
			return notify_fail("ֻ����ѩɽׯ���Ӳ��ܹ�ʹ�á���Ѫ����\n");

 		qidao = me->query_skill("qidaoforce",1);
 		dorm = me->query_skill("dormancy",1);
 		
 		if(qidao < 60)
			return notify_fail("����Ѫ������Ҫ60��������ķ���\n");
			
 		if(me->query_skill_mapped("force")!="qidaoforce")
 			return notify_fail("����Ѫ����������ķ��Ŀھ���\n"); 	
 	                    
       	// 60mins, feat -20mins, eventually=40min
        fix = 3600;
        add = F_ABILITY->check_ability(me,"juxue_add")*2;
        fix = fix - add *60;
        
        duration = me->query("timer/pfm/tx_juxue")-time()+ fix;
        if (duration>0)
        	return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration/60+1)+"�������Ҳ��ܹ��ٴ�ʹ�þ�Ѫ����\n");
        
        if (!arg)
        	return notify_fail("��Ѫ���Ѿ�����ʹ���ˣ�����Ҫָ������\n");
        
        if (arg) { 
        	if(!objectp(target = present(arg, environment(me))))
				return notify_fail("����û������ˡ�\n");
			if( !target->is_character() || target->is_corpse() )
				return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
        } else
        	target = me;
        			
		if (userp(me) && !COMBAT_D->legitimate_heal(me,target))
			return notify_fail("�㲻�������ʹ�þ�Ѫ����������ɱ���ƣ�\n");
	    
		if(target!= me) {
			mem = me->query_team();
			if (!pointerp(mem) || member_array(target,mem) == -1)
				 return notify_fail("��ֻ�ܸ�ͬһ�����е������ˡ�\n");
		}
	    
	    stage = me->query("scroll/dormancy_juxue")>0?
    			me->query("scroll/dormancy_juxue"): 1;
    
	    switch (stage) {
	    	case 1:		extra  = 2000; 	break;	// L60  qidaoforce
	    	case 2:		extra = 6000; 	break;	// L150 qidaoforce, L250 dormancy
	    	case 3:		extra = 12000; break;	// L150 qidaoforce, L290 dormancy
	    }
	    
	    if (qidao < 150)	    extra = 2000;
	    	    	    	
		msg1 = BRED + HIW"";
		msg = "��Ѫ��";
	
		me->set("timer/pfm/tx_juxue",time());
		target ->receive_fulling("kee",extra, me);
	
		if (target == me )
			message_vision( msg1 + "
$Nʹ��һ��"+msg+"���ֱ۲������������ѵ�ˮ��һ������δ�������ѵ�������
�澭��������ɫ��̷��죬һ��������ȥ�˴�룡\n"NOR,me);
		else
			message_vision( msg1 + "
$Nʹ��һ��"+msg+"���ֱ۲������������ѵ�ˮ��һ������δ�������ѵ���$n
�澭������$n��ɫ��̷��죬һ��������ȥ�˴�룡\n"NOR,me,target);

		if (target!=me)
		if(target->is_fighting()) {
			enemy = target->query_enemy();
			for (i=0;i<sizeof(enemy);i++) {
				if (!enemy[i]->is_fighting(me)) {
					enemy[i]->kill_ob(me);
					me->kill_ob(enemy[i]);
				}
			}	
		}

 		return 1;       
}

int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	juxue <ĳ��>[0m
[0;1;37m����������������������������������������������������������������[0m   

��Ѫ������ѩɽׯ�ؼ�

���ٷ���������ѩɽׯ����ʱʱ�̻�������Ļ���������
����С���˾�Ѫ�ķ���ɬ��������6��������ķ������ڶ�ʱ
���ڻָ���������˵���Ѫֵ������æ��Ӱ�졣

��Ѫ�ɣ��裶��������ķ���˲�����ƣ�����������Ѫ
��Ѫ�ɣɣ���������ᣬ˲�����ƣ�����������Ѫ
��Ѫ�ɣɣɣ���������ᣬ˲�����ƣ�������������Ѫ

��Ѫ����Ҫָ��ʹ�ö��������ָ���Ļ����������ʹ����Ϣ��
��Ѫ��ÿ��������ʹ��һ��

[0;1;37m����������������������������������������������������������������[0m   

HELP
    );
    return 1;
}
