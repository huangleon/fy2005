//TIE@FY3
#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
void create()
{
	set_name("˧һ��", ({ "shuai yifan","shuai" }) );
	set("gender", "����" );
        set("title","ժ����ʿ     ����");
        set("nickname",HIG"һ������ɽ ̸Цն����"NOR);
        set("quality","good");
	set("age", 55);
	set("int", 30);
	set("per", 30);
	set("fle",40);
	set("cps",35);
	set("dur",40);
        set("long",
"������¸߹ڵİ׷����߱��ǵ���һ������ɽ����ն�����ǵ�������\n"
		);
        set("force_factor", 50);
        set("max_gin", 2800);
        set("max_kee", 3400);
        set("max_sen", 2800);
        set("eff_gin", 3000);
         set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_force", 3000);
        set("force", 3000);

        set("combat_exp", 10000000);
        set("score", 80000);
        set_skill("unarmed", 50);
        set_skill("sword", 220);
        set_skill("force", 90);
        set_skill("move", 270);
        set_skill("literate", 140);
	set_skill("dodge", 100);
	set_skill("siqi-sword", 150);
	set_skill("liuquan-steps", 100);
	set_skill("parry",140);
	map_skill("parry","siqi-sword");
    map_skill("sword", "siqi-sword");
    map_skill("dodge", "liuquan-steps");
	set("chat_chance",10);
	set("chat_msg",({
"˧һ������̾Ϣ��һ��������ϧ�����Ƕ�����ȥ��ֻʣ������ٲ�֮��
�����˼����ˣ�������һ���ܰ�������Խ����ˣ��಻�ɵ��ˡ���\n",
	})	);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.siqi" :),
					(:perform_action,"dodge.liushuichanchan":),
        }) );

	setup();
	carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/qiushui")->wield();
}

