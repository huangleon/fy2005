
#include <ansi.h>

inherit NPC;
void goto_batdao(object ob);
void create()
{
    	set_name("������", ({ "gao yanan", "gao" }));
    	set("long", "����ĸ�����һ������խ�䣬�Ե�Ӣ������������һ˫���������ӿ���۾���\n" );
	set("title", "��ɽ�� ��ʮ�ߴ�����");
 	set("gender", "Ů��");
	set("age", 18);
	set("class","huashan");
	
	set("combat_exp", 1200000);
	
	set("attitude", "friendly");
    	set("chat_chance", 1);
	set("chat_msg", ({
		"�������������������ʦ������������ע������ʲô����\n", 
		"�����е��������������Ϊʲô�ܲ�����Ů�����棿��\n", 
	}) );
 	
 	set_skill("unarmed", 175);
	set_skill("move", 180);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("force", 180);
	set_skill("sword", 150);
	set_skill("hanmei-force",100);
	set_skill("zhaixin-claw",100);
	set_skill("qingfeng-sword", 100);
	set_skill("anxiang-steps", 100);
	
	map_skill("force","hanmei-force");
	map_skill("unarmed","zhaixin-claw");
	map_skill("move", "anxiang-steps");
	map_skill("parry", "qingfeng-sword");
	map_skill("sword", "qingfeng-sword");
    map_skill("dodge", "anxiang-steps");

	setup();
    	carry_object(__DIR__"obj/gcloth",
    	([ 	"name" 	:	"����",
    		"long"	:	"����ɫ��С�ӡ�"		])
    	)->wear();
    	carry_object("/obj/weapon/sword")->wield();

}
