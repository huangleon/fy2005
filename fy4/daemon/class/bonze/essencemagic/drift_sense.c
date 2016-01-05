// drift_sense.c

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	
	if(me->query("class")!="bonze")
		return notify_fail("ֻ���˹����µĵ��Ӳſ���ʹ����ʶ��ͨ��\n");
	
    if((int) me->query_skill("essencemagic",1) < 90)
                return notify_fail("��ʶ��ͨ��Ҫ90����ʶ��ͨ��\n");
	
	if( me->is_fighting() )
		return notify_fail("ս�����޷�ʹ����ʶ��ͨ��\n");
    
   	if (environment(me)->query("no_fly"))
   		return notify_fail("�˵��޷�ʹ����ʶ��ͨ��\n");
    
    if( me->query("atman") < 100 )
        return notify_fail("�������������\n");

	if( me->is_ghost())
		return notify_fail("����޷�ʹ����ʶ��ͨ��\n"); 	
	if( target )
		return notify_fail("��ʶ��ֻͨ�ܶ��Լ�ʹ�ã�\n");
	write("��Ҫ�ƶ�����һ������ߣ�");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	object ob;

	if( !name || name=="" ) {
		write("��ֹʩ����\n");
		return;
	}

	ob = find_real_living(name);
	if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob)
// the following check start/arrival room.	
		|| environment(ob)->query("no_death_penalty")
		|| environment(ob)->query("no_fly")
		|| environment(ob)->query("no_fly_in")
		|| environment(ob)->query("no_magic") 
		|| environment(me)->query("no_fly")
// all NPCs are non-driftable by default.	
		|| !ob->query("fly_target")
	) {
		write("���޷����ܵ�����˵���������\n");
		write("��Ҫ�ƶ�����һ������ߣ�");
		input_to( (: call_other, __FILE__, "select_target", me :));
		return;
	}
	
	if (stringp(me->query_temp("no_move"))) {
       	tell_object(me, me->query_temp("no_move"));
       	return;
    }
        	
	if( me->is_fighting() ) {
		write("ս�����޷�ʹ����ʶ��ͨ��\n");
		return;
	} else if( me->query("atman") < 100) {
		write("��ʶ��ͨ��Ҫ100��������\n");
		return;
	}

	if(environment(ob)==environment(me)) {
		write("���Ѿ��������ˣ�\n");
		return;
	}	
	me->add("atman", -100);
	message_vision( HIY "$N��ͷ��Ŀ����ʼʩչ��ʶ��ͨ ....\n" NOR, me);
	
	message( "vision", HIY "\nһ��ҫ�۵Ĺ�â��Ȼ��ס" + me->name() 
		+ "���������ᣬ��â����һ����ʧ����Ӱ���٣�\n\n" NOR, environment(me), ({ me }) );
	TASK_D->flying_risk(me);
	me->move(environment(ob));
	message( "vision", HIY "\n�����ǰͻȻ����һ��ҫ�۵Ĺ�â����â�и��ֳ�һ����Ӱ��\n\n" NOR,
		environment(ob), ({ me }) );
	
	
	return;
}
