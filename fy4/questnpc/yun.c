// taolord.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({ "master yun", "master", "yun" }) );
        set("nickname", HIW"̫����"NOR);
        set("gender", "����");
        set("age", 69);
        set("long",
"�������ǵ����䵱����ʯ���ʦ�壬һ��̫�������������¡�\n"
);                
        set("combat_exp", 8000000);
        set("score", 50000);

        set("class", "taoist");

        set("str", 35);
        set("int", 33);
        set("cor", 45);
        set("cps", 30);
        set("spi", 30);
		set("fle",	45);

        set("force", 4000);
        set("max_force", 4000);
        set("force_factor", 50);
		set("max_gin",2800);
		set("max_sen",2800);

         set("inquiry", ([
                "̫������": 
"̫���������ؾ���������һ���������֡�\n",
        ]) );

        set("apprentice_available", 1);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chanzijue" :),
					(:perform_action,"unarmed.nianzijue":),
        }) );

        create_family("�䵱��", 56, "����");

        set_skill("literate", 100);
        set_skill("force", 180);
        set_skill("move", 120);
        set_skill("unarmed", 140);
        set_skill("sword", 150);
        set_skill("parry", 150);
        set_skill("dodge", 200);
        set_skill("changelaw", 120);
        set_skill("taiji-sword", 150);
	set_skill("taijiforce", 140);
	set_skill("taiji", 120);
	set_skill("five-steps", 200);
	map_skill("spells","qixing");
        map_skill("parry", "taiji-sword");
        map_skill("sword", "taiji-sword");
        map_skill("literate", "changelaw");
        map_skill("force", "taijiforce");
        map_skill("unarmed", "taiji");

        setup();

	carry_object("/obj/weapon/sword")->wield();
        carry_object(__DIR__"obj/taocloth")->wear();
        carry_object(__DIR__"obj/taohat")->wear();
}

