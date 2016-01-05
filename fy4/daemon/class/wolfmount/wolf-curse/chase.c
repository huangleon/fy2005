// chase.c

#include <ansi.h>

inherit SSERVER;

int curse(object me, object target)
{
	string targetname;
	object room,ob;
	int skill,atman,perp;
	
	if(me->query("class")!="wolfmount")
    		return notify_fail("ֻ����ɽ���Ӳ���ʹ������ɱ�䡻\n");
	
	if( me->is_fighting() )
		return notify_fail("ս�����޷�ʹ����ɱ�䣡\n");
 
    if( (skill=me->query_skill("wolf-curse",1)) < 100 || me->query_skill("cursism",1)< 100)
    	    return notify_fail("��ɱ����Ҫ������������Ѫ��ͽ�ͷ����\n");

	if ( environment(me)->query("no_fly"))
		return notify_fail("�˵ز���ʹ����ɱ�䡣\n");
	
	if (stringp(me->query_temp("no_move")))
       	return notify_fail(me->query_temp("no_move"));
        	
	if( me->is_ghost())
		return notify_fail("����޷�ʹ����ɱ�䣡\n"); 	
	
	if( !(ob=me->query_temp("chase_target")))
		return notify_fail("��û���¹���ɱ�����������ɱ������Ѿ����ˡ�\n");
	
	if(! ob->is_character())
		return notify_fail("׷��������������ǲ��Ǿ��ú����ģ�\n"); 
	
	if( ob->is_ghost())
		return notify_fail("�˹���;���㲻��׷�٣�\n"); 
	
	if (	environment(ob)->query("no_fight")
		||environment(ob)->query("no_magic")
		||environment(ob)->query("no_death_penalty") 
		|| environment(ob)->query("no_fly"))
			return notify_fail("�Ǹ��ط������ܵ�����ı�����\n");
	
	if (me->query_temp("in_chase"))
		return notify_fail("���Ѿ���׷�ٶԷ���");
	
	if( me->query("kee") <= 100 )
                return notify_fail("�����Ѫ������\n");
	me->receive_damage("kee", 100);
	
	if( random(me->query("combat_exp")/20*skill) <ob->query("combat_exp"))
	{
		 message_vision( HIW "$N��ɫ��Ȼ�����������дʣ���ʲô��Ҳû������\n" NOR, me);
		 return notify_fail("��Ľ�ͷ��������������\n");	
	}
			
	message_vision( HIW "$N��ɫ��Ȼ�����������дʣ���Ӱ������ģ������ ....\n" NOR, me);
	me->set_temp("in_chase");
	room = environment(ob);
	me->start_busy(2);

	me->start_call_out( (: call_other, __FILE__, "iam_coming", me,ob,room:), 6);
	return 1;
}


void iam_coming(object me,object ob,object room)
{
	
	string id_enemy;
	int eff_shen,shen,skill;
	if (me->is_ghost()) {
		tell_object(me,YEL"����ô���˹��ˣ������޷�׷���˵ģ�\n"NOR); 
		me->delete("in_chase");
		return;
	} 
	
	if (me->is_fighting()|| me->is_busy()){
		tell_object(me,YEL"���ܵ�ǣ�ƣ��޷�����\n"NOR);
		me->delete("in_chase");
		return;
	}
	
	TASK_D->flying_risk(me);	
	me->move(room);	
	message( "vision", HIW "\n��Ȼһ�����̴ӵ���ð����"+me->query("name")+"�������г��֣�\n\n" NOR,
		room, ({ me }) );
	if ( environment(ob) != environment(me)) {
		tell_object(me,HIW"̫��ϧ��,"+ob->name()+"�մ������뿪.\n"NOR);
		return;
	}
	me->delete("in_chase");
	me->start_busy(2);
}	

