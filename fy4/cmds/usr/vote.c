// vote.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
#include <ansi.h>
#include <vote.h>
inherit F_CLEAN_UP;

int main(object me, string arg) {
	string who,what;
	string msg;
	object victim;
	int result;
	int diff;
	
	seteuid(getuid());
	if((int)me->query("mud_age") < NEW_PERIOD) {
		return notify_fail("�㻹û�е���ͶƱ����ͣ�\n");
	}	
	if((int)me->query("level") < NEW_LEVEL) {
		return notify_fail("����վ�涨��ҵȼ�����ﵽ"+NEW_LEVEL+"��\n");
	}
	if(!arg) {
		return notify_fail("ָ���ʽ��vote <what> on <who>\n");
	}
	if(sscanf(arg,"%s on %s",what,who)	!= 2) {
		return notify_fail("ָ���ʽ��vote <what> on <who>\n");
	}
	if(!objectp(victim = find_player(who)) || !userp(victim)) {
		return notify_fail("�ף��������������\n");
	}
	if(me==victim) {
		return notify_fail("�㲻����Ͷ�Լ���Ʊ��\n");
	}
	if(wizardp(victim)) {
		return notify_fail("�㲻���԰�����/�����κ�Ȩ����\n");
	}
	log_file("VOTE",sprintf("%s:%s(%s)[%s] vote %s on %s(%s)\n",
			ctime(time()),me->name(1),me->query("id"),
			query_ip_number(me),
			what,victim->name(1),victim->query("id")));	
	switch(what) {
		case "kickout":
			result = VOTE_D->add_vote(me,what,who);
			if(!result) {
				return notify_fail("�Ѿ����˴������ߵ�����Ͷ��Ʊ�ˣ�\n");
			}
			if((diff = KICKOUT_NO - result) > 0) {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)ͶƱ����%s(%s)������Ƶ�Ȩ��������%sƱ��",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id"),
						chinese_number(diff)));
			} else {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)ͶƱ����%s(%s)������Ƶ�Ȩ�������ͨ����",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id")));
				victim->set("kickout_time",time());
				victim->save();
				victim->ccommand("quit");
				seteuid(ROOT_UID);
				if (victim)	destruct(victim);
				VOTE_D->matter_finalized(what,who);
			}
			break;
		case "chblk":
			if(victim->query("chblk_on")) {
				return notify_fail("��/���Ѿ���������ʹ�ù���Ƶ����Ȩ����\n");
			}
			result = VOTE_D->add_vote(me,what,who);
			if(!result) {
				return notify_fail("�Ѿ����˴������ߵ�����Ͷ��Ʊ�ˣ�\n");
			}
			if((diff = CHBLK_NO - result) > 0) {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)ͶƱ����%s(%s)ʹ�ù���Ƶ����Ȩ��������%sƱ��",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id"),
						chinese_number(diff)));
			} else {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)ͶƱ����%s(%s)ʹ�ù���Ƶ����Ȩ�������ͨ����",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id")));
				victim->set("chblk_on",1);
				victim->save();
				VOTE_D->matter_finalized(what,who);
			}
			break;
		case "chnoblk":
			if(!victim->query("chblk_on")) {
				return notify_fail("��/��û�б�������ʹ�ù���Ƶ����Ȩ����\n");
			}
			result = VOTE_D->add_vote(me,what,who);
			if(!result) {
				return notify_fail("�Ѿ����˴������ߵ�����Ͷ��Ʊ�ˣ�\n");
			}
			if((diff = CHNOBLK_NO - result) > 0) {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)ͶƱ����%s(%s)ʹ�ù���Ƶ����Ȩ��������%sƱ��",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id"),
						chinese_number(diff)));
			} else {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)ͶƱ����%s(%s)ʹ�ù���Ƶ����Ȩ�������ͨ����",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id")));
				victim->delete("chblk_on");
				victim->save();
				VOTE_D->matter_finalized(what,who);
			}
			break;
		default:
			return notify_fail("ָ���ʽ��vote <what> on <who>\n");
			break;
	}
	return 1;
}

int help(object me) {
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	vote <what> on <who>[0m
[0;1;37m����������������������������������������������������������������[0m   

����ָ�����������û�й�����Ա���ߵ�ʱ��������
Υ�������������˵ģ���Ҫ������������㹻Ʊ���ſ�����Ч��

����<what>�����������е�һ�

kickout:	���������Ƶ�Ȩ������Ҫʮ��Ʊ��
chblk:		����ʹ�ù���Ƶ����Ȩ������Ҫ��Ʊ��
chnoblk:	����ʹ�ù���Ƶ����Ȩ������Ҫ��Ʊ��

ע�����е�ͶƱ����м�¼����������ͶƱ����һ���������
���շ����������ã�

[0;1;37m����������������������������������������������������������������[0m
HELP);
	return 1;
}
