#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("������",({"zang yizi","zang"}));
    set("title","��������");
	set("long", "һ�����ҵĵ��ˣ���������ͨ��ǣ�˫üб�����ޣ�һ�����ؽ����������¡�\n");
	set("age",57);
	set("gender","����");
	set("combat_exp", 6300000);
		
	set("reward_npc", 5);

	set("inquiry", ([
        	"������" : "������ǵ�һ���Ҵ�����˹ȵ��������ˡ�\n",
        	"���˹�" : "ʮ�����ɢ��ɢ�������������˹�����̫ƽ���ˡ�\n",
      	]));
	
		
	set("chat_chance", 1);
        set("chat_msg", ({
        	"������̾�������������Ե��������书֮ǿǿ�����£�ƶ���������ţ�
������һ������������������\n",	
        }) );

	set("win_msg",CYN"������˵������֮�£�Ҳֻ���������ܵ���������һ����\n"NOR);
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        	(: auto_smart_fight(30) :),    
       }) );
	
	auto_npc_setup("guardian",200,170,0,"/obj/weapon/","fighter_w","softsword",1);
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/zsword")->wield();
	
}


