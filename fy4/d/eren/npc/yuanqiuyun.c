#include <ansi.h>

inherit SMART_NPC;
int kill_him();

void create()
{

	set_name("Ԭ����",({"yuan qiuyun","yuan","qiuyun"}));
    	set("title",WHT"����ɽׯ  ׯ��"NOR);
    	set("long", "
���˵�Ȼ���Ǹ����ˣ��Ǹ��������ǵ����ˡ�������Ҳ��������
̬��ȴ��������������������\n");
	set("age",59);
	set("combat_exp", 6000000);
        set("attitude", "friendly");
	
	set("inquiry", ([
             "������" : (: kill_him :),
             "bai tianyu" : (: kill_him :),
       	]));
	
	
	set("reward_npc",8);
	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	       	(: auto_smart_fight(30) :),    
     }) );
	
	auto_npc_setup("xuebin",250,180,0,"/obj/weapon/","fighter_w","dragonstrike-jg",1);
	setup();
	carry_object("/obj/armor/cloth",([	"name": "��Ƥ����",
    						"long": "һ���������Ƥ���ۡ�\n",
    						"value": 100,
    						 ]))->wear();    
}


int kill_him()
{
        object me, another;
        
        me = this_player();
 	if (this_object()->is_fighting()) {
 		tell_object(me,"Ԭ��������û�ջش��㡣\n");
 		return 1;
 		}
        message_vision(CYN"
Ԭ���Ƶ�Ц��ͻȻͣ�٣�Ŀ���к�Ȼ¶���־�֮ɫ��һ�����������ҲͻȻ��
��Ť�����Σ�ʧɫ���������ǰס����״�����ʲô�ˣ���\n"NOR,this_object());
        return 1;
}