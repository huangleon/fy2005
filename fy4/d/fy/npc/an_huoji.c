#include <ansi.h>
inherit NPC;

void create()
{
    	set_name("��������", ({"huo ji"}) );
    	set("gender", "����" );
    	set("long", "�����������Ļ�ƣ�æʱ�����ϰ��к����ˣ�û�¾����Ű��ٸ��޲���ľ��\n");
    	set("attitude", "friendly");
    	set("age", 25);
    	set("cor", 25);
    	
    	set("combat_exp", 380000);
        
    	set_skill("axe",100);
    	set_skill("unarmed", 100);
    	set_skill("parry", 100);
    	set_skill("dodge", 100);
    	set_skill("move", 100);
    	set_skill("wuche-axe",60);
    	set_skill("puti-steps",100);
    	set_skill("dabei-strike",100);
    	
    	map_skill("unarmed","dabei-strike");
    	map_skill("dodge","puti-steps");
    	map_skill("axe","wuche-axe");
    	map_skill("parry","wuche-axe");
    	
    	setup();
    	carry_object(__DIR__"obj/heicloth")->wear();
    	carry_object(__DIR__"obj/paoaxe")->wield();
}

