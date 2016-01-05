/* // Silencer @ FY4 workgroup. Aug.2004
	����¶����dart)��������ó����Ϊ��ɱǿ�У�������Ǳ������
��ҹ���豩��֮����������Ϣ�����������������˿�����������ʵ���
Ϊ��¶������150����*/
// Basically, it does some damage before fight, without aggro.

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	if((int) me->query_skill("ninjitsu",1) < 150)
    	return notify_fail("��¶��Ҫ150����������\n");
	
	if(environment(me)->query("no_death_penalty"))
		return notify_fail("���޷�������ʹ�÷��ڡ�\n");
	if( me->query_temp("ninjitsu_dart"))
       	return notify_fail("�����ھѻ�֮�У����ɷ��ġ���\n");
	if( me->query("atman") < 200 )
		return notify_fail("��Ҫ200���������\n");
        
	write("��Ҫ��ɱ˭��");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	object ob,room,here;
	int lvl,extra,delay,dis,x,y,z;
	int my_exp, your_exp, your_perp, my_skill;
	
	if( !name || name=="" ) {
		write("��ֹ�ѻ���\n");
		return;
	}

	ob = find_player(name);
	if( !ob || !me->visible(ob) || wizardp(ob) )
		ob = find_real_living(name);
	if ( !ob) 
	{
		tell_object(me,"��Ҫ�ѻ��Ķ��󲻴��ڡ�\n");
		return;
	}
	
	if (!COMBAT_D->legitimate_kill(me, ob)) {
		if (stringp(ob->query("NO_KILL"))){
			tell_object(me,ob->query("NO_KILL"));
			return;
		}
		if (stringp(ob->query("NO_PK"))) {
			tell_object(me, ob->query("NO_PK"));
			return;
		}
		else {
			tell_object(me,"�㲻�ܰ�ɱ���ˡ�\n");
			return;
		}
	}
	
	my_exp=me->query("combat_exp");
	your_exp=ob->query("combat_exp");
	
	if (my_exp > 10* your_exp) {
		write("��ɱ��ô��Ķ���̫ʧ����ˡ�\n");
		return;
	}
	
	if( me->query("atman") < 200 ) {
		write("��¶��Ҫ200���������\n");
		return;
	}
	if (userp(me))	me->add("atman", -200);
		
	lvl = me->query_skill("magic");
	
	// (150 + 435)*1.5 = 585 - 1160.. hmm, Ѳ��ר�û���
	
	extra = lvl + F_LEVEL->get_level(me->query("combat_exp"));
	extra = extra + random(extra);
	
	delay = 6;
	
	delay = delay+random(delay);
	
    message_vision( HIY "$N��Ŀ�����ƺ��ڼ�����ʲô����\n" NOR, me);
	
	room=environment(ob);
	if(!room||room->query("no_magic")||room->query("no_fight")) 
	{	
		tell_object(me,HIB"���޷�ȷ�����˵�λ�á�\n"NOR);
		return;
	}
		
	here=environment(me);
	x=room->query("coor/x")-here->query("coor/x");
	y=room->query("coor/y")-here->query("coor/y");
	z=room->query("coor/z")-here->query("coor/z");
	dis=x*x+y*y+z*z;
	if(dis>lvl*2)	// 435* 2 = 870
	{
       	tell_object(me,HIB"�����ʱ�Ĺ��������޷��ѻ����ңԶ�ĵ��ˡ�\n"NOR);
		return;
	}
	me->set_temp("ninjitsu_dart",1);	
	call_out("throwing",delay,me,ob,room,extra);
	extra = COMBAT_D->magic_modifier(me, ob, "kee", extra);
	me->start_busy(delay/2);
	
	return ;
}

int throwing(object me, object ob, object room,int extra)
{	
	string msg;
	int my_exp,your_exp,your_perp, my_skill;
	me->delete_temp("ninjitsu_dart");
	
    message_vision(HIR"$N΢��˫Ŀ�ͺ�һ�������������һö���ڶ�����������㻮�����ա�����\n"NOR,me);
	
	my_exp=me->query("combat_exp");
	your_exp=ob->query("combat_exp");
		
	if(present(ob,room))
	{
        message_vision(HIR"$N��ǰһ����һö���ھ��Ѻ�Х��������\n"NOR,ob);
		if(userp(ob))
			ob->delete_temp("been_darted");
		if (random(your_exp) > random(my_exp *2)
				|| ob->query_temp("been_darted")+300>time())
	        {
			message_vision(HIG"$N�ƺ�����׼��,��ָһ��,ž�ؽ����ڼ�ס.\n"NOR,ob);
			msg=TASK_D->locate_obj(ob,me->query("id"));
			tell_object(ob,"���ݷ��ڵ����ƣ����жϳ���Ϯ�����"+msg+"��\n");		
			tell_object(me,"����,��ķ��ڱ��Է����ˡ�\n");
			return 1;
		}
			
		ob->set_temp("damaged_during_attack",1);
		msg=TASK_D->locate_obj(ob,me->query("id"));
		tell_object(ob,"���ݷ��ڵ����ƣ����жϳ���Ϯ�����"+msg+"��\n");		
		tell_object(me,"������ľѻ��ɹ��ˡ�\n");
		
		ob->receive_wound("kee",extra,me);
		COMBAT_D->report_status(ob);
		ob->set_temp("last_damage_from","����¶������\n");
		ob->set_temp("been_darted",time());
		return 1;
	}
    	message("vision",HIW"һö���ڰ��һ����������ǰ��\n"NOR,room);
    	tell_object(me,"�ǳ��ź�����ľѻ��޹�����������\n");
	return 1;
}
	
	
