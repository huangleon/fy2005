#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "wang xian","wang" }) );
        set("gender", "Ů��" );
        set("title", "������ ����");
        set("nickname",HIM"һ����������մ����"NOR);
        set("age", 22);

        set("long", "������һ¥�ĵ��Һ����ˣ���ȶ��ˣ��������֣��Ҽ�������\n");
        set("combat_exp", 270000);
        set("chat_chance", 1);
        set("chat_msg", ({
       		 "��������һЦ����Ƥ������գգ�ۡ�\n",
		}) );
        set("attitude", "friendly");

        set_skill("force", 60);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_skill("zhaixin-claw",70);
        set_skill("cloud-dance",80);
        set_skill("parry",90);
        map_skill("unarmed","zhaixin-claw");
        map_skill("dodge","cloud-dance");
        
        setup();
        carry_object("/d/fugui/npc/obj/w_skirt2")->wear();
		carry_object(__DIR__"obj/sinny2");
}
int accept_fight(object me)
{
        command("say СŮ�����е���������ǧ�����⣬СŮ�Ӹ�����Ҿ������ǡ�\n");
        return 0;
}
