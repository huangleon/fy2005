#include <ansi.h>
inherit NPC;


void create()
{
        set_name("��ջ�ϰ�", ({ "lao ban","owner" }) );
        set("long","һ���ʷ����ֵ������ˡ�");
        set("attitude", "friendly");

        set("combat_exp", 100000);

	set_skill("unarmed",150);
	set_skill("parry",150);
	set_skill("dodge",150);
	
	set("inquiry", ([
                "���³���":	"���¿�ջ���������������³�����\n",
                "di qinglin" : 	"С��ү��ס��¥�������\n",
                "������" : 	"С��ү��ס��¥�������\n",
                "����" : 	"��������������ͷ��Ů����\n",
                "���" : 	"���������Ĳ�ͷ�������ƻ�һ�ٰ�ʮ���������Ĵ󰸡�\n",
                "yang" : 	"���������Ĳ�ͷ�������ƻ�һ�ٰ�ʮ���������Ĵ󰸡�\n",
                "yang zheng" : 	"���������Ĳ�ͷ�������ƻ�һ�ٰ�ʮ���������Ĵ󰸡�\n",
        ]));
	
        set("chat_chance", 1);
        set("chat_msg", ({
		"�ϰ���Ź�̨̾������˵�ͷ��ô�õ��ˣ���ô���ǽ��ڴ���أ�\n"
        }) );
			
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
