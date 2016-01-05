// inquiryd.c
// Created by Annihilator@ES2 (01-19-95)

// This function handles the default inquiry between ppls and npcs to
// make npc more talktive. This is the '<me> ask <ob> about <topic>'
// case.

#include <ansi.h>

int parse_inquiry(object me, object ob, string topic)
{
	switch( topic ) {
		case "name":
			message_vision( CYN "$N��$n�ʵ�������" + RANK_D->query_respect(ob)
				+ "���մ�����\n" NOR, me, ob);
			return 1;
		case "here":
			message_vision(CYN "$N��$n�ʵ�����λ" + RANK_D->query_respect(ob)
				+ "��" + RANK_D->query_self(me) + "�����󷽱��أ���֪������Щʲ��������飿\n" NOR,
				me, ob);
			return 1;
		case "rumor" : 
		case "rumors":
			message_vision(CYN "$N��$n�ʵ�����λ" + RANK_D->query_respect(ob)
				+ "����֪�����û����˵ʲ����Ϣ��\n" NOR, me, ob);
			return 1;
		default:
			return 0;
	}
}
