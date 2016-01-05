// fight.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 06/28/2001 by Daniel Q. Yu.
//

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target;
	seteuid(getuid());
	
	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("���빥��˭��\n");
	
	if( !wizardp(me) && environment(me)->query("no_fight") && !obj->query("practice_dummy"))
		return notify_fail("�����ֹս����\n");

	if( !obj->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");

	if( obj->is_fighting(me) )
		return notify_fail("���ͣ����ͣ����ͣ�\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "�Ѿ��޷�ս���ˡ�\n"); 

	if(obj==me)	return notify_fail("�㲻�ܹ����Լ���\n");
	if( userp(obj) ){
		if((object)obj->query_temp("pending/fight")!=me ) {
			message_vision("\n$N����$n˵����" 
				+ RANK_D->query_self(me) 
				+ me->name() + "�����"
				+ RANK_D->query_respect(obj) 
				+ "�ĸ��У�\n\n", me, obj);
			if( objectp(old_target = me->query_temp("pending/fight")) )
				tell_object(old_target, YEL + me->name() + "ȡ���˺�����Ե���ͷ��\n" NOR);
			me->set_temp("pending/fight", obj);
			tell_object(obj, YEL "�����Ը��ͶԷ����б��ԣ�����Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� fight ָ�\n" NOR);
			write(YEL "��춶Է�������ҿ��Ƶ���������ȶԷ�ͬ����ܽ��б��ԡ�\n" NOR);
			return 1;
		} else {
			message_vision("\n$N����$n˵����" 
					+ RANK_D->query_self(me) 
					+ me->name() 
					+ "�����" + RANK_D->query_respect(obj) 
					+ "�ĸ��У�\n\n", me, obj);
			me->fight_ob(obj);
			obj->fight_ob(me);
		}
	} else {
		if( obj->query("can_speak") ) {
			message_vision("\n$N����$n˵����" 
					+ RANK_D->query_self(me) 
					+ me->name() + "�����"
					+ RANK_D->query_respect(obj) 
					+ "�ĸ��У�\n\n", me, obj);
			if( !userp(obj) && !obj->accept_fight(me) ) {
				tell_object(me,"������" + obj->name() + "��������������\n");
				return 1;
			} else {
				me->fight_ob(obj);
				obj->fight_ob(me);
			}
		} else {
			if (!COMBAT_D->legitimate_kill(me, obj)) {
				if (stringp(obj->query("NO_KILL")))
					return notify_fail(obj->query("NO_KILL"));
			}
			message_vision("\n$N���һ������ʼ��$n����������\n\n", me, obj);
			me->fight_ob(obj);
			obj->kill_ob(me);
		}
	}
	return 1;
}
int help(object me)
{
  write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	 fight <����>[0m
[0;1;37m����������������������������������������������������������������[0m   
 
���ָ��������һ������ֽ̡������ǡ��д����ա���������ʽ��ս��
�����ǵ㵽Ϊֹ����˲������������ǲ��������е�NPC ��ϲ����ܣ���
�������ʱ����ı���Ҫ��ᱻ�ܾ���Ҫע����ǣ���ʹ�ڱ����У�ż��
Ҳ���г��ֹ��ض���������֮����
 
�������ָ��: kill

PS. ����Է���Ը����������ս������Ȼ���������� kill ָ�ʼ
	ս�����й� fight �� kill �������뿴 'help combat'.

[0;1;37m����������������������������������������������������������������[0m   

HELP
    );
    return 1;
}
 
