// a skill to set others/self back to death-gate.

#include <ansi.h>
inherit SSERVER;

int curse(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam;
    if(me->query("class")!="wolfmount")
		return notify_fail("ֻ����ɽ���Ӳ���ʹ��������䡻\n");
       
    if(me->query_skill("cursism",1) < 120 || me->query_skill("wolf-curse",1)< 120
        	|| me->query_skill("summonwolf",1)<220)
    	return notify_fail("������䡻��Ҫ120��������Ѫ��ͽ�ͷ����220���Ļ�������\n");

	if((int)me->query("kee") < 1000 )
	return notify_fail("������䡻��Ҫ�ķѣ������������Ѫ��\n");
	write("����ʹ˭��ꣿ");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
	
}

void select_target(object me, string name)
{
	mapping ob_list;
    	object ob,new1;
	string msg;
	object room,corpse;
	string *list;
	object *inv;
	int i,level;
    if( !name || name=="" ) {
    	write("\n��ֹʩ����\n");
        return;
    }

    ob = find_living(name);
	room = environment(me);
	
	if (room->query("no_fly")) {
		tell_object(me,"�˵��޷�ʹ������䡣\n");
		return;
	}
	
	if( !ob  || !present(ob, room)){
		write("\n���������\n");
		return; 
	}	
	if(ob->is_ghost() || ob->is_corpse())		{
		write("\n��ֻ�ܶԻ����¡�����䡻\n");
		return;
	}
	if (!userp(ob)){
	   	write("\n��ֻ�ܶ�����¡�����䡻\n");
	   	return;
    }
    
    if (!ob->team_member(me)) {
    	write("\n��ֻ�������ʹ������䡣\n");
    	return ;
    }
    
    if (me->is_fighting() || ob->is_fighting()){
    	tell_object(me,"ս���в���ʹ������䡣\n");
    	return;
    }
    
    if (ob==me) {
    	tell_object(me,"���Լ���ô��ʹ��������أ�\n");
    	return;
    }
    
    if (stringp(ob->query_temp("no_move"))) {
		tell_object(me,"�����޷��뿪��ǰ������\n");
		return;	
	}		
	
	if (me->query("kee")< 1000 || me->query("eff_kee")<1000)
	{
		tell_object(me,"�����Ѫ̫�ͣ����ô��������Լ�������ˡ�\n");
		return;
	}		    
    if (userp(me))	me->receive_wound("kee",1000);
    if (ob!=me) msg = HIB "\n$N��$n��������������λ���������οࡣ��Ī����ȥ������\n\n" ;
		else msg = HIB "\n$N��������������λ���������οࡣ��Ī����ȥ������\n\n" ;
	
	me->start_busy(2);
	
  	level = me->query_skill("cursism");
	if( random(level)>level/2) 
	{
		if (ob!=me){
			msg +=  "$n��Ȼ����������ͷ��ð��һ��Ũ��Ũ����һ����Ӱ�����ܿ����ʧ�ˡ�\n" NOR;
			message_vision(msg, me,ob);
		}	else 
		{
			msg +=  "$N��Ȼ����������ͷ��ð��һ��Ũ��Ũ����һ����Ӱ�����ܿ����ʧ�ˡ�\n" NOR;
			message_vision(msg, me);
		}

		ob->move("/d/death/gate");
		return;
	}
	else
		msg += "���ʲôҲû�з���\n"NOR;
	
	if (ob !=me) message_vision(msg, me,ob);
		else message_vision (msg,me);
	
}

