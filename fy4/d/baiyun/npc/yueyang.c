#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({ "yue yang", "yue" }) );
        set("long","����ͻ����ᣬ���Ӣ�������ϣ����ż��ְ������ִ��ż���Ұ����\n�۾��ڵ÷������������촽�Եúܼ�ǿ�����̡�\n");
        set("attitude", "heroism");
        set("title", "���뽭��");
        set("per", 25);

        set("combat_exp", 80000);

        set_skill("unarmed", 100);
        set_skill("spear", 70);
        set_skill("yue-spear", 50);
        set_skill("parry", 70);
        set_skill("dodge",50);
        set_skill("move", 100);
		set_skill("force",100);
		set_skill("puti-steps",40);
		set_skill("manjianghong",80);
		
		map_skill("force","manjianghong");
		map_skill("dodge","puti-steps");
        map_skill("spear", "yue-spear");
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "����������һ���޼ʵĴ󺣣��ս���ȭͷ��ĬĬ����һ��Ҫ���������ã�\n",
	}) );
    	set("chat_chance_combat", 10);
    	set("chat_msg_combat", ({
        (: perform_action, "spear.zonghengtianxia" :),
	}) );

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/egg");
        carry_object(__DIR__"obj/by_spear")->wield();
}
