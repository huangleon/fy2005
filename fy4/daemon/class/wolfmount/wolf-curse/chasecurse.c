#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
	string msg;
	int damage,level,perp;
	object ob, room;

	if(me->query("class")!="wolfmount")
    	return notify_fail("ֻ����ɽ���Ӳ���ʹ������ɱ�䡻\n");
	level=(int)me->query_skill("wolf-curse",1);
        
    if( (level < 100 || me->query_skill("cursism", 1) < 100)
    		|| me->query_skill("summonwolf",1)<200)
    		return notify_fail("����ɱ�䡻��Ҫ100������Ѫ��ͽ�ͷ����200����������\n");
    	
	if(!target) return notify_fail("������˭�������ͷ��\n");
	room=environment(target);
	if(room!=environment(me)) 
		return notify_fail("������˭����ɱ�䣿\n");
	
	if ( environment(me)->query("no_fly") || environment(target)->query("no_fly"))
		return notify_fail("�˵ز���ʹ����ɱ�䡣\n");

    if (userp(target))
       	return notify_fail("��ɱ�䲻������������ϡ�\n");
	
	if(!target->is_character() || target->is_corpse())
		return notify_fail("��ֻ�����������ɱ�䡣\n");
	
	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, target)) {
		if (stringp(target->query("NO_KILL")))
			return notify_fail(target->query("NO_KILL"));
		if (stringp(target->query("NO_PK")))
			return notify_fail(target->query("NO_PK"));	
		else 
			return notify_fail("�㲻�����������ɱ�䡣\n");	
	}
	
	if (domain_file(file_name(environment(target)))=="eren2")
		return notify_fail("���˾���̫�ߣ��޷�����ɱ�䡣\n");
	
	if((int)me->query("kee") < 100 )
		return notify_fail("�����Ѫ������\n");
	me->receive_damage("kee",100);
	
	me->start_busy(2);
	if(random(me->query("combat_exp"))>target->query("combat_exp")/4)
	{
		me->set_temp("chase_target",target);
		target->set_temp("chaser",me);
		tell_object(me,WHT"���Ѿ��ɹ��Ķ�"+target->name()+"������ɱ֮�䡣\n"NOR);
		return 1;
	}
	else return notify_fail(WHT"�����ڲ���������ʧ���ˡ�\n"NOR);
}
		
		