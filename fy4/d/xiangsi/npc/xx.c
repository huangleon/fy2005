// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;

void create()
{
	object obj;
	set_name("����", ({ "xiao xiao", "xiao" }) );
	set("class","moon");
	set("gender", "Ů��" );
	set("age", 25);

	set("nickname",HIG"��������������"NOR);
	set("title","��¹�"NOR);

	set("attitude", "friendly");

	set("long","��������һ�����񣬱�Ŀ��˼��\n");

	set("inquiry",([
       	"����": 	"�ؽ�㣿������ȥ�ˡ�\n",
      	"�": 	"�ߡ���\n",
    	]) );

	set("combat_exp", 4400000);

/*	set_skill("starrain", 200);
	set_skill("throwing", 300);
	map_skill("throwing","starrain");

	set_skill("force", 200);
	set_skill("snowforce", 200);
	map_skill("force","snowforce");

	set_skill("dodge", 200);
	set_skill("move", 200);
	set_skill("stormdance", 140);
	map_skill("dodge","stormdance");
	map_skill("move","stormdance");

	set_skill("unarmed",200);
	set_skill("lingxi-zhi",200);
	map_skill("unarmed","lingxi-zhi");*/
	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(5) :),
     }) ); 		

	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","fengloufeiyan",1);
	set_skill("stormdance", 140);
	setup();

	obj=carry_object(__DIR__"obj/ccloth");
	obj->set("name","֯������");
	obj->delete("long");
	obj->wear();
	carry_object(__DIR__"obj/feidao2")->wield();

}


void die()
{
	ccommand("perform xueyuezhonghua");
//	ccommand("say "+ccommand("perform xueyuezhonghua"));
	::die();
}