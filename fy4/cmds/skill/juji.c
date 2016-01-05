#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int main(object me, string arg)
{
	object obj;
	int skill, i, count, myexp, yourexp, lvl;
	string gender,msg;
	
	if (me->query("class")!="beggar")
		return notify_fail("ֻ��ؤ����Ӳ���ʹ��͵Ϯ��\n");
	
	lvl = me->query_skill("begging",1);
	if (lvl < 90)
		return notify_fail("�ѻ�������Ҫ90��������֮����\n");
		
	if (environment(me)->query("no_fight"))
		return notify_fail("�����ֹս����\n");

	if (! arg || ! objectp(obj = present(arg, environment(me))))
		return notify_fail("����͵Ϯ˭��\n");

	if (! obj->is_character())
		return notify_fail("�����һ�㣬�ǲ��������\n");

	if (obj->is_fighting(me))
		return notify_fail("���Ѿ���ս�����ˣ�����͵Ϯ��\n");

	if (!living(obj))
		return notify_fail(obj->name() + "���Ѿ������ˣ��㻹�õ���͵Ϯ��\n"); 

	if (obj == me)
		return notify_fail("͵Ϯ�Լ�������ô�벻����\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, obj)) {
		if (stringp(obj->query("NO_KILL")))
			return notify_fail(obj->query("NO_KILL"));
		if (stringp(obj->query("NO_PK")))
			return notify_fail(obj->query("NO_PK"));	
		else 
			return notify_fail("���޷�͵Ϯ���ˡ�\n");
	}
		
	if (me->is_busy())
		return notify_fail("����æ�ţ�����͵Ϯ��\n");

	if (obj->query_temp("juji_alert")+ 60 > time())
		return notify_fail("�Է������ڸ߶Ⱦ���֮�У��޷�͵Ϯ�ɹ���\n");	
		
	gender = obj->query("gender")=="����" ? "��" : "��";
	
	tell_object(me, CYN"�������ߵ�"+obj->name()+CYN"���󣬷���������Ȼ��"+gender+"��ȥ��"NOR);
	tell_object(obj, BLU"������Ȼ����һ����Ӱ��ٿȻ���㷢�𹥻���\n" NOR);
	
	message("vision",CYN""+me->name()
		+CYN"�����ߵ�"+obj->name()+CYN"���󣬷���������Ȼ��"
		+obj->name()+CYN"��ȥ��" NOR, environment(me), ({me, obj}));

	skill = me->query_skill("betting",1);
	myexp = me->query("combat_exp");
	yourexp = obj->query("combat_exp");
	
	count = me->query_agi()/10;
//	me->ccommand("kill "+obj->get_id());
	
	me->kill_ob(obj);
	obj->kill_ob(me);
	i = 0;
	
	if ( myexp/2 + random(myexp*4) <  yourexp)
	{
		message_vision(YEL"$N��֪��ʱȴ��ת����$n�����$n���˸��ա�\n"NOR,obj,me);
	} else
	{
		while (count--) { 
			if (me->is_busy())	continue;
			msg = BLU"��Ӱ�зɳ���"+chinese_number(i+1)+"��\n"NOR;
			me->add_temp("apply/damage",lvl);
			COMBAT_D->do_attack(me,obj,TYPE_PERFORM,msg);
			me->add_temp("apply/damage",-lvl);
			i++;
		}
	}
	
	me->perform_busy(1);
	if (obj)
		obj->set_temp("juji_alert",time());
	return 1;
}


int help(object me)
{
  write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	juji <����>[0m
[0;1;37m����������������������������������������������������������������[0m   
 
�ѻ�����ʵ���ǳ��˲�����͵Ϯ��Ϊؤ�����ר�á��ѻ��ĳɹ�����
�ѻ��ߵľ�����أ��ѻ�����=�����ٶ�/10

�ѻ�������Ҫ90��������֮����

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
