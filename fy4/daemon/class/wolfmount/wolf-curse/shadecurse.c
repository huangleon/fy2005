#include <ansi.h>
inherit SSERVER;

int curse(object me, object target)
{
	string msg;
	int damage, extra, dp, duration;
	int i,armor;
	object corp,*enemy,weapon, newweapon,newcloth;
	
	if(me->query("class")!= "wolfmount" )
    		return notify_fail("ֻ����ɽ���Ӳ���ʹ���������䡻\n");
    		
	extra = me->query_skill("wolf-curse", 1);
    if(extra < 150 || me->query_skill("cursism",1) < 150
        	|| me->query_skill("summonwolf",1)<240)
                return notify_fail("�������䡻��Ҫ150������Ѫ��ͽ�ͷ����240����������\n");
                
	// duration = 5mins.
	duration = me->query("timer/pfm/wm_shadecurse")+ 300 -time();
	if (duration>0)
    	return notify_fail("�������䡻��Ҫ"+chinese_number(duration)+"�������ٴ����á�\n");
    	
	
	if(!me->is_fighting())
		return notify_fail("�������䡻ֻ����ս���в���ʹ�á�\n");

	if( target && target != me)
		return notify_fail("�㲻�ܶԱ���ʹ������\n");
        
    if(me->query_temp("figureshade") ) 
       	return notify_fail("��ķ���û���ջأ���\n");
    
    if (me->query_temp("no_move"))		// To prevent some other perform call this marks before.
    	return notify_fail("��ʱ���ʺ�ʹ�÷����䡣\n");
        
	damage = me->query("max_kee")/4;
	damage = (damage < 100) ? 100 : damage;
	
	if(me->query("kee") < damage )
		return notify_fail("�����Ѫ�������������Լ������ˣ�\n");
	me->receive_wound("kee", damage);
	
	msg = HIC "�㰵�����ʹ�������۷�������\n\n" NOR;
	tell_object(me,msg);
    me->set("timer/pfm/wm_shadecurse",time());
        
    me->perform_busy(1);
    me->set_temp("figureshade",1);
    me->save();
	seteuid(getuid());
	corp=new("/obj/npc/shade_curse_figure");
	corp->changeshape(me);
	corp->set("possessed",me);
	
	if(weapon=me->query_temp("weapon"))
	{
		newweapon=new("/obj/weapon/"+weapon->query("skill_type"));
		if (newweapon) {
			newweapon->set("name",weapon->query("name"));
			newweapon->set("id",weapon->query("id"));
			newweapon->move(corp);
			newweapon->set("nodrop_weapon",1);
			newweapon->wield();
		}			
		newcloth=new("/obj/armor/cloth");
		newcloth->move(corp);
		newcloth->wear();		
	}
	
	// ����ͬ���·�
	armor = me->query_temp("apply/armor");
	corp ->add_temp("apply/armor",armor);
	
	corp->set("owner",me);
	corp->move(environment(me));
	
	corp->set("max_kee",corp->query("max_kee")/2);
	corp->full_me();
	
	if(enemy = me->query_enemy())	{
    	i = sizeof(enemy);
    	while(i--) {
	    	if( enemy[i] && living(enemy[i]) ) {
    			enemy[i]->kill_ob(corp);
            	corp->kill_ob(enemy[i]);
        	}         
    	}
	}
	
	me->remove_all_killer();
	me->add("env/invisibility",1);
	me->set_temp("no_move","�㲻���뿪��ķ���\n");
	
	me->start_call_out((: call_other, __FILE__, "remove_effect", me,corp,damage:), 30);
	return 1;
}


void remove_effect(object me,object corp,int damage)
{
	int eff_kee;
	
	if (corp) {
		if (me) {
			tell_object(me, WHT"���ջ�����ķ���\n"NOR);
			me->receive_fulling("kee", damage);
		}
		corp->disappear();		
	}
			
	if (me) {
		if (me->query("env/invisibility")>0)	
			me->add("env/invisibility",-1);
		if( me->query_temp("figureshade"))
			me->delete_temp("figureshade");
		if (me->query_temp("no_move"))
			me->delete_temp("no_move");
	}	
}

