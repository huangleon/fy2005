#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string forceskill,msg;
		int extra, exp_bonus, stage, kee;
		int tmp;
		object weapon;
	
		if (me->query("family/master_id") != "master yue" || me->query("class")!="official")
			return notify_fail("�����������������ɵ��ӵľ��С�\n");
	
		weapon=me->query_temp("weapon");
 		extra = me->query_skill("yue-spear",1);
		tmp = me->query_skill("manjianghong",1);
    	    	
    	if (extra < 160 ||tmp < 150 )
    		return notify_fail("��������������Ҫ160����������ƽǹ����150�����������ķ���\n");
    	
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
	        	return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	    
	    
	    // SCROLL ADVANCE PERFORM, 
	    stage = me->query("scroll/yue-spear_juechufengsheng");
	    
	    switch (stage) {
	    	case 0:
	    	case 1:	kee = 60;  break;	
	    	case 2:	kee = 70;  break;		// L90
	       	case 3:	kee = 80; break;			// L100
	     }
	      
	      kee += F_ABILITY->check_ability(me,"3_jcfs_add",3);
	        
        if (me->query("kee") > me->query("max_kee") *kee/100)
        	return notify_fail("������������ֻ����������Ѫֵ����"+kee+"������ʱ����ʹ�á�\n");
        
        // atk 180, dmg 480
        
   		me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", tmp*3);
        msg = HIW  "\n$N"HIW"���һ����˫��ץסǹ������Ȼ��š���ݱۣ������ǹ��ֱ��$n"HIW"���ţ���\n" NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
   		me->add_temp("apply/attack", -extra);    
        me->add_temp("apply/damage", -tmp*3);
        me->perform_busy(2); 
        return 1;
}
