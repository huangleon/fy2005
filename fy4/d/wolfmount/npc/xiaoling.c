#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��С��", ({"xiaoling"}) );
        set("gender", "Ů��" );
        set("nickname", HIG "����"NOR);
        set("long", "�����ú���㣬���߿���ĳ�ȹ��ÿ��һ������¶����������\n");
 	set("attitude", "friendly");

	set("age", 15+random(5));

        set("combat_exp", random(100000)+100000);

        create_family("��ɽ", 1, "���Ĵ�����");
        set_skill("blade", 40+random(10));
        set_skill("parry", 40+random(10));
        set_skill("dodge", 40+random(10));
        set_skill("move", 40+random(10));
        set("chat_chance", 1);
        set("chat_msg", ({
		"��С�ῴ�����������ˣ�͵͵����˵����������ϣ�������Ұ���ܵ�\n������������ɱ����\n",
        }) );

        setup();
        carry_object(__DIR__"obj/skirt")->wear();
        if (!random(3))
        	carry_object(__DIR__"obj/conch");
}
