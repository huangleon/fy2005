#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
	set_name("ŷ����",({"ouyang ding","ding"}));
	set("long", "�����ָ����֡�԰�����ʾ���Ц�е��������۾�������˹���˵����\n");
	set("title","��������");
	set("age",45);
	set("attitude", "friendly");
	set("combat_exp", 9500000);
	set("reward_npc",20);
			
	set("inquiry", ([
        	"С��" : "�����С�������컹������򶹸����š�",
        	 "ŷ��������" : "�ٺ٣����ֵܿ��Ķ����̡�",
           	 "������¥": "������¥��Ȼ�ǹ���������ඣ������ڲ���ඡ�",
           	 "������": "������¥��Ȼ�ǹ���������ඣ������ڲ���ඡ�",
			"����":	"С��ר��������Զ��������\n",
       	]));
	
	set("chat_chance", 1);
        set("chat_msg", ({
		"ŷ����˵����������������������İ˹�ɽ�����Ķ����洫����ڼ�������ڼ�������\n",
        	
        }) );
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(100) :),    
        }) );
	
	auto_npc_setup("guardian",300,200,0,"/obj/weapon/","fighter_w","jin-gang",2);
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/armor/ribbon",([	"name": "�����ֽ�",
    						"long": "һ�������ֽ�\n",
    						 "value": 2,
    						 ]))->wear();    
	carry_object("/obj/weapon/staff",([	"name": "������",
    						"long": "һ�������ˡ�\n",
    						 "value": 2,
    						 ]))->wield();    
    
}

