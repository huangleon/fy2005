// command disabled by silencer. 3/6/2003
// Meaningless and can cause possible bugs.

#include <ansi.h>
inherit F_CLEAN_UP;

int legitimate_kill(object attacker, object victim);

int main(object me, string arg)
{
	object obj;
	string *killer, callname;
	object *t;
	int i;

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼ս����\n");

	if( !arg )
		return notify_fail("����ɱ˭��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if(obj==me)
		return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

	if (userp(me))
	if (!legitimate_kill(me, obj)) {
		if (stringp(obj->query("NO_KILL")))
			return notify_fail(obj->query("NO_KILL"));
		if (stringp(obj->query("NO_PK")))
			return notify_fail(obj->query("NO_PK"));	
		else 
			return notify_fail("���޷��������ˡ�\n");
	}
	
	if( userp(me) && userp(obj) && !environment(obj)->query("no_death_penalty"))
   	log_file( "KILL_LOG", sprintf("(%s)%s used kill on %s\n", 
   			ctime(time()), 
   			me->query("name")+"("+me->query("id")+")", 
   			obj->query("name")+"("+obj->query("id")+")"));
   			
	callname = RANK_D->query_rude(obj);
        t = me->query_team();
	if(sizeof(t) <=1)
		return notify_fail("�����ڲ�û�вμ��κζ�������ֻ��һ���ˡ�(use kill)\n");
	if( userp(obj) )
		return notify_fail("������ɲ����Ըĵ������۹ѵĶ�ϰ��\n");

		
	for(i=0;i<sizeof(t);i++)
	if( t[i])
	if( environment(me) != environment(t[i]))
		return notify_fail("��Ա�����ڳ���(use kill)\n");		
	message_vision("\n$N����$n�ȵ�����" + callname + "�����ղ��������������ǻ��\n\n", me, obj);
        for(i=0;i<sizeof(t);i++)
	{
		if(t[i]){
			if (COMBAT_D->legitimate_kill(t[i], obj)) {;
				t[i]->set_temp("ttarget",obj->query("id"));
				t[i]->kill_ob(obj);
				obj->kill_ob(t[i]);
			}
		}
	}
	return 1;
}

// There is a similiar fuction in combatd.c
int legitimate_kill(object attacker, object victim) {
	if (userp(attacker) && (victim -> query("NO_KILL") || victim -> query("NO_PK")))
		return 0;
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : teamkill <����>
 
���ָ������Ķ�����������һ�����
�������ָ��: team,fight,kill

HELP
    );
    return 1;
}
 
