// drift_sense.c

#include <ansi.h>

inherit SSERVER;
void move_team(object me,object target);

int conjure(object me, object target)
{
	
	if(me->query("class")!="bonze")
		return notify_fail("ֻ���˹����µĵ��Ӳſ���ʹ����ʶ��ͨ��\n");
	
	if((int) me->query_skill("essencemagic",1) < 170)
        return notify_fail("��Ҫ170����ʶ��ͨ��\n");
	
	if (!me->query("scroll/essencemagic_team_drift"))
		return notify_fail("����ҪѰ�ҵ�ר�ŵľ�������������ؼ���\n");
	
	if (environment(me)->query("no_fly"))
   		return notify_fail("�˵��޷�ʹ����ʶ��ͨ��\n");
	
	if( me->is_fighting() )
		return notify_fail("ս�����޷�ʹ����ʶ��ͨ��\n");
    if( me->query("atman") < 300 )
        return notify_fail("������Ҫ300���������\n");
	if( me->is_ghost())
		return notify_fail("����޷�ʹ����ʶ��ͨ��\n"); 	
	write("��Ҫ�������ƶ�����һ������ߣ�");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	object ob;
	object *team;
	int transported; 
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
// the following is the NEW FLY FLAG, all NPCs are non-driftable by default.	
		|| !ob->query("fly_target")
	) {
		write("���޷����ܵ�����˵����� ....\n");
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
	} else if( me->query("atman") < 300 ) {
		write("������Ҫ300���������\n");
		return;
	}

	me->add("atman", -300);
	
	message_vision( HIY "$N��ͷ��Ŀ����ʼʩչ��ʶ��ͨ ....\n" NOR, me);
	
	if(environment(ob)==environment(me)) {
		write("���Ѿ��������ˣ�\n");
		return;
	}	
	message( "vision", HIY "\nһ��ҫ�۵Ĺ�â��Ȼ��ס" + me->name() 
		+ "���������ᣬ��â����һ����ʧ����Ӱ���٣�\n\n" NOR, environment(me), ({ me }) );
	
	// -> team transport here
        transported = 1;
	if( pointerp(team = me->query_team()) ) {
		for (int i=0; i<sizeof(team); i++) {
			if (!team[i]) continue;
			if (team[i] == me) continue;
			if ( environment(team[i]) != environment(me)) continue;
			if ( !team[i] ||( !me->visible(team[i])) || team[i]->is_ghost()
			   || !team[i]->query("max_atman") || !team[i]->query("atman")
			   || environment(team[i])->query("no_fly")
			   || environment(team[i])->query("no_magic")
			   
			) {
				write("���޷����ܵ�"+team[i]->name()+"������ ....\n");
				continue;
			}
			if (team[i]->is_busy() ||team[i]->is_fighting()
				|| team[i]->query_temp("no_move")) {
				tell_object(team[i],"���ܵ�"+me->name()+"��������٣�������������æ���޷���Ӧ��\n");
				tell_object(me, YEL"\n" + team[i]->name()+"�ƺ�û�п�������Ӧ�����ʶ��Ӧ��\n"NOR);
				continue;
			}

			message_vision(HIY"��Ȼ��һƬҫ�۹�â������$N��Χ������\n\n"NOR,team[i]);	
		        //team[i]->move(environment(ob));
		        team[i]->start_busy(4);
			call_out("move_team",2, me,team[i]);	        
			transported++;
		}
	}
    TASK_D->flying_risk(me);
    me->move(environment(ob));
    me->start_busy(4);
	message( "vision", HIY "\n�����ǰҫ�۵Ĺ�â��������â���ֳ�"+ chinese_number(transported)+ "����Ӱ��\n\n" NOR,
		environment(ob), ({ me }) );
}


void move_team(object me,object target){

	if (!me)	return;	// û��ʩ���ˡ�	
	if (!target) return; 	// ��ô���أ����ǲ�������, busied 	
	message_vision(HIY"$N�ܵ�"+me->name()+"��������٣���ʱ�������ȣ��ѵ�������һ���ط���\n"NOR,target);	
	tell_object(me, target->name()+"��Ӧ����٣���ʶ������\n");    	
	TASK_D->flying_risk(target);
	target->move(environment(me));
}




