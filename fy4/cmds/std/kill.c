// kill.c
// Modified by justdoit at Dec 5,2001
// When player type kill,KILL_LOG file will add user id in it.

#include <ansi.h>
inherit F_CLEAN_UP;
int legitimate_kill(object attacker, object victim);

int main(object me, string arg)
{
	object obj;
	string *killer, callname;
	seteuid(getuid());

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
	if (!COMBAT_D->legitimate_kill(me, obj)) {
		if (stringp(obj->query("NO_KILL")))
			return notify_fail(obj->query("NO_KILL"));
		if (stringp(obj->query("NO_PK")))
			return notify_fail(obj->query("NO_PK"));	
		else 
			return notify_fail("���޷��������ˡ�\n");
	}
	
	callname = RANK_D->query_rude(obj);

        if( userp(obj) && environment(obj)->query("no_pk"))
		me->add("vendetta/pker",1);

	if (obj->query("race") != "Ԫ��" && me->query("race") != "Ԫ��")
		message_vision("\n$N����$n�ȵ�����" 
		+ callname + "�����ղ������������һ��\n\n", me, obj);
	else
		message_vision(HIR"\n$N���һ������ʼ��$n����������\n\n"NOR, me, obj);


	me->kill_ob(obj);
	if( !userp(obj) || !userp(me))
		obj->kill_ob(me);
	else {
		obj->fight_ob(me);
		tell_object(obj, HIR "�����Ҫ��" + me->name() 
			+ "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
	}

	return 1;
}


int help(object me)
{
  write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	kill <����>[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ������������ʼ����һ��������ҳ���ɱ���Է���kill �� fight 
���Ĳ�ͬ���˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ���� 
kill ֻ�赥����һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ�
�Ὺʼս����ͨ������Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��

�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬���һ����Ҷ�
�ԣ������û�ж�һ������ʹ�ù� kill ָ�һ�㲻�Ὣ�Է���Ĵ���
��ɱ������Ȼ����ǹ���ۣ�ż��Ҳ�������⣬��������Ǳ��佨�鵽����
����

�������ָ��: fight

�й� fight �� kill �������뿴 'help combat'.

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
 
