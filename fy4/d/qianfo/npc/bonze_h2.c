#include <ansi.h>
inherit NPC;


void create()
{
        set_name("�޴ϴ�ʦ", ({ "hui cong", "huicong" }) );
        set("gender", "����" );
        set("class", "bonze");
	set("title","�˹����»��ֱ���ʦ");
	set("long","
�޴ϴ�ʦ���ױ����˹����³��ң���ʮ������Ǳ����ѧ����δ��������һ����
������ѧ�伮����֪��Ϊ�㲩����\n");
        set("age", 89);
        set("combat_exp", 10000000);
        set("attitude", "friendly");

        set("chat_chance", 1);
        set("chat_msg", ({

        }) );
        set("inquiry", ([

	]));
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}

int accept_fight(object me)
{
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
}
