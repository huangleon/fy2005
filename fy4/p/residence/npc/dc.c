#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
      set_name("��è", ({ "totoro" }) );
    set("title", "���ֵ�");
	set("race","Ұ��");
	setup();
}

int init()
{
	int i = random(3);
	switch (i)
	{
	case 0:
		set_temp("condition_type",CYN" <������>"NOR);
		break;
	case 1:
		set_temp("condition_type",CYN" <˯����>"NOR);
		break;
	case 2:
		set_temp("condition_type",CYN" <��ʳ��>"NOR);
		break;
	}
}
/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/

