// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;
int take_effect(object me, int skill);

int exert(object me, object target, int amount)
{
	object *team, *team1;
	int i, skill, num, duration;
	mapping buff;

	if (me->query("class")!= "beggar")
		return notify_fail("ֻ��ؤ����Ӳ������á���Ԫ����\n");
		
	skill = me->query_skill("huntunforce",1);
	if (skill < 150 || me->query_skill("begging",1)<150 )
		return notify_fail("����Ԫ����������Ҫ150�����繦������֮����\n");
	
	duration = me->query("timer/pfm/gb_hunyuan")-time() + 900;
    if (duration>0)
    	return notify_fail("�㻹��Ҫ�ȴ�"+(duration)+"�������Ҳ����ٴ�ʹ�á���Ԫ����\n");
	
	me->start_busy(2);
	
	message_vision(HIW "$N�����Ԫ���������������������ڣ������ս���\n" NOR, me);
    me->set("timer/pfm/gb_hunyuan",time());
        	
	call_out("take_effect", 2, me, skill);
	return 1;
}


int	take_effect(object me, int skill) {
	
	object *team1, *team;
	int i, num;
	
	if (!me || me->is_ghost())	return 1;
		
	team1 = me->query_team();
	
	skill = skill * (100 + 5*F_ABILITY->check_ability(me,"hunyuan_add"))/100;
	// with 50% ability --> 4500 kee, 900 force
	// 150*20 = 3000 kee, 150*4 = 600 force
	
	if (me->query_skill("begging",1) < 180 || !team1) {
		if (me->query("kee")< me->query("max_kee"))
			me->receive_fulling("kee", skill * 20, me);		
		if (me->query("force") + skill *4 < 2* me->query("max_force"))
			me->add("force", skill *4);
		else
			me->set("force", 2* me->query("max_force"));
		me->force_status_msg("force");
		tell_object(me,YEL"��е�һ����������ɢ������ٺ������ƾ��Ѻ��˼��ɡ�\n"NOR);
	}else {	
		team = filter_array(team1,(: present($1,environment($2)) :),me);
		num = sizeof(team);	
		for (i=0; i<num; i++) {
			if (team[i]->query("kee")< team[i]->query("max_kee"))
				team[i]->receive_fulling("kee", skill * 20, me);
			if (team[i]->query("force") + skill*4 < 2*team[i]->query("max_force"))
				team[i]->add("force", skill*4);
			else
				team[i]->set("force",2* team[i]->query("max_force"));
			tell_object(team[i],YEL"��е�һ����������ɢ������ٺ������ƾ��Ѻ��˼��ɡ�\n"NOR);
			team[i]->force_status_msg("force");
		}
    }
	return 1;	
}
