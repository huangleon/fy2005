inherit SMART_NPC;
#include <ansi.h>
 
void create()
{
	set_name(HIW"������"NOR, ({ "whitecloth man", "man" }) );
	set("gender", "����" );
	set("age", 32);
	set("class","yinshi");
	set("long","
����ˬˬ��һ������ѣ��������ŵ�һ��Ц�����ټ����������°��һ��Ц
�ۣ�Ц���л��·�ʱ�а���Ʈ��������ԶԶ����ô��һ����ơ� \n");
    	set("combat_exp", 8000000);
	set("attitude", "friendly");
	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"������Ц���������˽�������ã����Ͻ��а���������\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","thunderwhip",1);
    	
	setup();
	carry_object("/obj/armor/cloth", 
		([	"name"  :       HIW"����"NOR ,
			"long" : "��ɫ�������ɾ�ƽ����û��һ˿�ۺۡ�"])
		)->wear();
	carry_object("/obj/weapon/whip", 
		([	"name"  :       MAG"��˿���"NOR ,
			"long" : "һ�����Ӳӵĳ��ޡ�",
			"value": 1,
			]))->wield();
}
