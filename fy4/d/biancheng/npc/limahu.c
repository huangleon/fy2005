#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
    	set_name("����",({"li mahu","li","mahu"}));
	set("title","�ӻ����ϰ�");
   	set("long","
��������˶������������Ǹ����ֹ۵������ˣ�
ԲԲ���������ۿ���˭����Ц���еġ�\n");
     	set("gender","����");
    	set("age",32);
    	
    	set("combat_exp",2800000);  
    	set("attitude", "friendly");
    	    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
			10: name()+"�е��������˰���ǿ����ٵ���������\n",
        ]) ); 
           	
    	set("chat_chance",1);
    	set("chat_msg",({
		"����Ц���еص�����Ů���ü�����ϴ����ԽϴԽ����ġ���\n",
    	}) );    	    	
    	
    	
	auto_npc_setup("wang",160,150,0,"/obj/weapon/","fighter_w","taiji",1);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
    
}
