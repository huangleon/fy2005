#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("���Ϻ���", ({ "old monk", "monk" }) );
	set("gender", "����" );
	set("age", 62);
	set("class","shaolin");
	set("nickname",HIR"һָ��Ǭ��"NOR);
    set("vendetta_mark","shaolin");
	        
    create_family("������", 18, "��ɮ");
	set("long",	"ר�����и����书����ɮ.\n");
       set("chat_chance", 1);
       set("chat_msg", ({
                name()+"���׿�˼������ħ�ʣ�һ�Բ�������\n",
                name()+"ͻȻ������ͷ���૵�����Ҳ����Ҳ������\n",
                name()+"��Ҫ�ӱ�������֮�ϣ���ͻȻͣ��������\n",

        }) );

	set("attitude", "peaceful");
	
	set("combat_exp", 4000000);

	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",170,160,0,"/obj/weapon/","fighter_w","yiyangzhi2",1);
	setup();
	carry_object(__DIR__"obj/monklao_cloth")->wear();
	carry_object(__DIR__"obj/ironfist")->wield();
}
