#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
    	set_name("�｣",({"sun jian","sun"}));
	set("title",HIR"�������"NOR);
   	set("long","
�｣��ò���ã�Ũü���ۣ����ϵ�Ƥ����ɹ������ͭɫ�����۾��������
ʱ���������ȥ�����ˣ�Ҳû������ȥ�����ˡ��������ֱ������｣�磬
���������⡰�硱���е�Ů���������Ծ��Լ������硱��ȥ��������Ը��
������մ��һ��һ��Ů��������Ҳ��������һ���������壬���㽫�Լ���
�ϵ��·������������˴�Ҳ������ϧ��\n");
     	
     	set("gender","����");
     	set("group","juyuan");
     	
    	set("age",32); 	 	
	
		set("reward",5);
    	set("combat_exp",7200000);  
    	set("attitude", "friendly");
    	    	
    	set("inquiry", ([
 			"�ϲ�": "�ϲ������Ҹ��ס�\n",
 			"�ϲ�": "�ϲ������Ҹ��ס�\n",	
   		]));
    	
//    	set("death_msg",CYN"\n$N��Ц�ŵ�������ȫ��ȥ���ɣ���������á���\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"\n�｣Ҳ����վ��̫���ˣ������Ե��е㲻�ͷ���\n",
    	}) );    	    	
    	
		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_u","huidashi",1);
	
		setup();
    	carry_object("/obj/armor/surcoat",([	"name": WHT"����Ƥ����"NOR,
    						"long": "һ������Ƥ����\n",
    						"value": 200, 
    						 ]))->wear();  
    	carry_object("/obj/armor/cloth")->wear();					   
 
}

void init() {
    	::init();
    	add_action("do_answer","answer");
}


int do_answer(string arg)
{
    	switch (arg) {
    		case "���㴨":
    		case "lv xiangchuan": 	command("say �ã���ȥ�ɣ�\n");
        				this_player()->set_temp("zangbei/see_lv",1);
        				break;
    		case "�ϲ�":
    		case "����": 		command("say �Ҹ���������æ�����������ɡ�\n");
    					break;
    		case "sun jian":
    		case "�｣":		if (this_player()->query("gender")=="Ů��" && this_player()->query("age")<40
    						&& this_player()->query("age")>16)
    						message_vision(CYN"$N�պ�һЦ�������ڲ���ʱ�򣬵��Ұ�������°����˰ɡ���\n"NOR,this_object());
    					else message_vision(CYN"$N��Ц������������ƽ�������Һ��£�\n"NOR,this_object());
    					break;
    		case "½����":
    		case "lu mantian":
    		case "����":
    		case "han tang":	command("say ��������æ�����������ɡ�\n");
    					break;
    		default:		command("say ����û������ˡ�\n");
    	}
    	return 1;		
}