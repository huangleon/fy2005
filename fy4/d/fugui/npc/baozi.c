inherit NPC;
#include <ansi.h>

void create()
{
        int i,amun;

        set_name("�ɱ���", ( { "fei baozi","baozi" }) );
	set("nickname", HIY"��������"NOR);
	set("gender", "����" );
	set("age", 28);
	set("long",
		"������÷�����ø磬�����������������������������ƺ����ⶶ�ӡ�\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ɱ���������ӣ�ʹ�������᣺����������ô�����йɾ�ζ�����Ķ��أ���\n"
        }) );

	set("attitude", "peaceful");
	set("combat_exp", 50000);
        set_skill("unarmed", 50);
        set_skill("dodge", 100);
        set_skill("taiji", 50);
        map_skill("unarmed", "taiji");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}