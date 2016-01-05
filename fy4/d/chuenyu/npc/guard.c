#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��Ժ", ({ "castle guard", "guard" }) );
        set("long", "���Ǻ��ɱ��Ļ�Ժ\n");
        set("attitude", "heroism");
        set("pursuer", 1);
        set("str", 27);
        set("combat_exp", 10000);

        set("chat_chance", 30);
        set("chat_msg", ({
		"��Ժ�ȵ����󵨵���˽����լ���õ����\n",	
                (: random_move :),
        }) );

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "��Ժ�ȵ�����������ץС��ѽ��\n",
        }) );

        set_skill("unarmed", 20);
        set_skill("sword", 30);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("move", 100);

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/sword2")->wield();
}

void init()
{
        object ob;
        ::init();
        if(interactive(ob = this_player()) && !is_fighting() ) {
		kill_ob(ob);
        }
}
 
