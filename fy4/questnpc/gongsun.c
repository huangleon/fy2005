#include <ansi.h>
#include <combat.h>

inherit NPC;

void do_fight();
object offensive_target(object me);
void create()
{
	set_name("�������", ({ "gongsun daniang" }) );
	set("gender", "Ů��" );
	set("title", "�߲�����  ��Ь��");
	set("nickname",HIW"�������ķ�"NOR);
    set("age", 58);
	set("int", 65);
	set("per", 5);
	set("str", 50);
	set("fle", 50);
	set("dur", 42);
	set("cor", 60);
	set("agi",80);
    set("long",
"һ�������糯ϼ���߹���ʺ󣬴�Լ����Ů�������Ů�ˡ�\n
�����������ϴ����·��������˼����еģ��������ϵ��߲����ѡ�\n
��ӯӯ�߹��������ϵ��߲������޷��Զ�  ��������ǧ�����ʴ����衣\n");
        set("force_factor", 120);
        set("max_force",9000);
	set("force",9000);

        set("combat_exp", 10000000);
        set("score", -90000);
        set_skill("unarmed", 220);
        set_skill("throwing", 200);
        set_skill("force", 300);
        set_skill("parry", 450);
        set_skill("literate", 110);
	set_skill("dodge", 350);
	set_skill("demon-force", 250);
	set_skill("demon-strike",300);
	set_skill("demon-steps",200);
	
		
	map_skill("force", "demon-force");
	map_skill("unarmed","demon-strike");
	map_skill("dodge","demon-steps");
	map_skill("move","demon-steps");
	map_skill("throwing","tanzhi-shentong");
	set("chat_chance",1);
	set("chat_msg",({
		"����������������������һ����������ʹ����  ��ĩ����ʤ�����ҡ���\n",
		"�������������Ⱦ�Ҫ���ȾƵ��·��� �Ƚ�Ҳ�ô��Ƚ����·���\n��Ϊ�·�Ҳ����Ӱ���˵����飬Ҳ��ΪŮ��������ϲ�����·�����\n",
		})	
	);
      
	setup();
/*	carry_object(__DIR__"obj/grey_cloth")->wear();
	carry_object(__DIR__"obj/owl_shoes")->wear();
	carry_object(__DIR__"obj/fried_nuts")->wield();
  */      
}

/*
void heart_beat()
{
	::heart_beat();
	if(is_fighting())
		smart_fight();
}

smart_fight() {
	
}
*/


	