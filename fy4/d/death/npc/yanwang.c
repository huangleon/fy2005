inherit NPC;
#include <ansi.h>
void create()
{
        set_name("����ү", ({ "death-god" }) );
        set("long", "����ү˵��������׼�ҿ�����\n");
        set("age", 5100);
        set("nickname", HIR"�������"NOR);
        set("cor", 37);
	set("str",200);
        set("combat_exp", 20000000);
        set("attitude", "peaceful");
        set_temp("apply/attack", 600);
        set_temp("apply/parry", 600);
	set_temp("apply/dodge",600);
	
        set("chat_chance", 1);
        set("chat_msg", ({
		"����ү���������йٵ��˵�ͷ��\n",
		"����ү˵�������ҿ���Ҫ���ص������\n",
		"����ү���������йٵ��˵�ͷ��\n",
		"����ү���������йٵ��˵�ͷ��\n",
		"����ү���������й�˵��������������Ҫ�����ֲ�ֵһ���С�����Ϸ���������\n",
		"����ү���������й�˵�����������������ˣ�Ͷ̥����Ӭ����\n",
		"����ү���������йٵ��˵�ͷ��\n",
		"����ү���������йٵ��˵�ͷ��\n",
        }) );
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 130);
        set_temp("apply/dodge", 70);
        set("inquiry", ([
		"Ͷ̥" : "�źöӣ���������\n",
                "*" : "��ķϻ��湻��ģ��˶����ˣ��컹���ϱ��ϡ�\n",
        ]) );
        setup();
        carry_object("/obj/armor/ghost_cloth")->wear();
}


void unconcious()
{
	return;
}


void die()
{
	return;
}

