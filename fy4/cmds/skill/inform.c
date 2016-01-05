// - by neon
#include <ansi.h>
inherit F_CLEAN_UP;
void move_team(object me,object ob);
int main(object me, string arg)
{
	string what, who;
	object ob, *team, beggar;
	int i, delay;
	object where = environment(me);
        if ( me->query("class")!="beggar" )
          	return notify_fail("ֻ��ؤ����Ӳ��ܷɸ봫�飡\n");

	if ( (int)me->query_skill("begging",1)<185)
	{
		return notify_fail("�ɸ봫��������Ҫ185������֮����\n");
	}
	
	if( !arg ) return
		notify_fail("ָ���ʽ��inform <ĳ��> \n");

	// Only two 
	beggar= present("beggar courier",environment(me));
//	write (sprintf("%O\n",beggar));
	if (!beggar)
		return notify_fail("����û��ؤ����ʹ���޷��ɸ봫�顣\n");
	
	if (!beggar->query("inform_target"))	
		return notify_fail("����û��ؤ�����ʹ���޷��ɸ봫�顣\n");
		
	if(me->is_busy())
		return notify_fail("����������æ��\n");

	if(me->query_temp("inform_in_progress") )
		return notify_fail("����Ÿ����ڽ������ѣ�\n");

	
	if( !pointerp(team = me->query_team()) )  
		return notify_fail("�㲢û���κζ��ѣ�\n");
		
	ob = find_player(arg);
	if (!ob || ob == me) return notify_fail("��Ҫ�ɸ봫���˭��\n");
	for ( i=0; i<sizeof(team); i++) {
		if (team[i]==ob ) break;
	}
	if (i == sizeof(team)) return notify_fail("�ɸ벻�ܴ��������������ˡ�\n");
// Now start to summon 
	if (environment(ob) == environment(me)) 
		return notify_fail(ob->name() + "�Ѿ���������ˣ�\n");

	if (me->query("gin")<500)
		return notify_fail("�ɸ봫����Ҫ�ķ�500�㾫����\n");
	if (userp(me))	me->receive_damage("gin",500);
        
    message_vision("$N��������˪������ؤ���ߵ��Ｘ�䡣\n", me);
    message_vision(WHT"$N��Ȼһ���֣�һֻ��ɫ���Ÿ��ڿն������������з���Զ����\n"NOR, beggar);
    me->set_temp("inform_in_progress", 1);
	
	if (environment(ob)->query("no_fight") ||environment(ob)->query("no_magic")
		|| environment(ob)->query("no_fly") || environment(ob)->query("no_death_penalty")) {
		message_vision(WHT"\n���ǣ��Ÿ���Զ��������һ������ַɻ�$N���\n"NOR, me);	
		me->delete_temp("inform_in_progress", 1) ;
		write("�Ÿ��޷�������Ķ��ѣ�\n");
		return 1;
	}
	
	if (ob->is_busy() || ob->is_fighting() || ob->is_ghost() ) {
		message_vision(WHT"\n���ǣ��Ÿ���Զ��������һ������ַɻ�$N���\n"NOR, me);	
		me->delete_temp("inform_in_progress", 1);
		write(ob->name()+"�ƺ�û�п����������Ÿ롣\n");
		return 1;
	}
	
	message_vision(WHT"һֻ��ɫ���Ÿ��Ȼ��������$Nͷ�����·ɶ���һ����������Զ����ȥ��\n$N��ɫһ�ݣ�����չ���Ṧ��׷��ɸ��ȥ��\n"NOR, ob);	
    tell_object(ob, "\n ... \n��ӿ�Ų������Ÿ�ָ������ǰ������\n");    	
	ob->start_busy(2);
	me->start_busy(2);
	call_out("move_team",3, me,ob); 	
	return 1;	
}


void move_team(object me, object ob){
	
	if (!ob||!me) return;
	message_vision(WHT"�Ÿ뻮��һ����ɫ�Ļ��ߣ��ɻص�$N���"YEL"$n�ں���ҴҸϵ���\n"NOR, me, ob);	
	ob->move(environment(me));
	me->delete_temp("inform_in_progress", 1);
}


int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	inform <����>[0m
[0;1;37m����������������������������������������������������������������[0m   

�ɸ봫�飬����һ��ؤ��ר�õ�ָ����Ժ������ѵİ�����
�ɸ봫����Ҫ185��������֮����������ؤ����ʹ���ʹ�á�

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
