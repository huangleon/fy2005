#include <ansi.h>
inherit NPC;
void create()
{
        set_name("÷���", ({ "mei rujia", "rujia" }) );
        set("long","���·�����ѥ���������źڽ������ᱳ�ŵ�һ����������Ҳ���ں�ɫ�ġ�\n");
    	set("int",50);
	set("dur",25);
	set("con",30);
	set("cor",50);
	set("agi",45);
	set("combat_exp", 900000);
	
	set_skill("dodge",100);
	set_skill("move",100);
	set_skill("jinhong-steps",100);
	set_skill("sharen-sword",100);
	set_skill("sword",120);
	set_skill("parry",120);
	set_skill("force",120);
	map_skill("sword","sharen-sword");
	map_skill("parry","sharen-sword");
	map_skill("dodge","jinhong-steps");
	map_skill("move","jinhong-steps");
	set("chat_chance_combat",50);
	set("chat_msg_combat",	({
		(:perform_action,"sword.sharenruma":),
	}));
	
	setup();

        carry_object("/d/qianfo/npc/obj/black_suit")->wear();
	carry_object("/obj/weapon/sword")->wield();

}

void init()
{
	::init();
       add_action("do_look","look");
}

int do_look(string arg)
{

	if (arg == "figure")
	{
		write("һ����·�����ѥ�ӣ��������źڽ������ᱳ�ŵ�һ�����Ľ��ʶ�\n���ں�ɫ�ġ�\n");
		write("��������վ������·��Ѿ�����ɱ��֮ҹ��Ϊ�塣\n");
		write("��������Լ��ʮ���ꡣ\n");
		write("�书����������"+HIR "��ɲ�"NOR+"�������ƺ����ᡣ\n");
		write("��"+HIG "���������������۷�״̬��"NOR+"\n");
		write("�����ϴ�����\n");
		write("  "+HIC "��"NOR+"ҹ����(Black suit)\n");
		return 1;
	}
	return 0;
}
				
void die()
{
	object ob;
	object *enemy;
	ob = query_temp("last_damage_from");
	if(!ob)
	{ 
		enemy = this_object()->query_enemy();
		ob=enemy[0];
	}
	if(userp(ob)) 	ob->set_temp("marks/killmeirujia",1);
	::die();
}
