#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int kill_him();

void create()
{
    	set_name("�´���",({"chen daguan","chen","daguan"}));
	set("title","����е��ϰ�");
   	set("long","
���˰װ׵��������Ϻ��񶼴���΢Ц�������ǳ���е��ϰ帣���˳´��ġ�
����û���˱������������⣬Ҳû���˱���������Ե�ˡ�\n");
     	set("gender","����");
    	set("age",52);
    	 	
    	set("combat_exp",2000000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
             	"�����嶾"	:	(: kill_him :),
             	"�ɻ���"	:		(: kill_him :),
   		]));
    	
    	set("chat_chance",1);
    	set("chat_msg",({
			"�´���˵����С��ĳ����Ӧ�о��С���\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",150,160,0,"/obj/weapon/","fighter_w","taiji",1);
	
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "˿����",
    						"long": "�����ط����Ƕഩ���������˿������ȴ�ܺ�����\n",
    						 "value":	1,
    						 ]))->wear();    
    
}


int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
 	if (this_object()->is_fighting()) {
 		tell_object(me,"�´�������û�ջش��㡣\n");
 		return 1;
 		}
        if(!me->query("marks/wanma/�ײ�֮��")) {
        	tell_object(me,"�´���˵��û��˵����������а���ý���\n");
        	return 1;
        }
        
        message_vision(CYN"$N���Ϻ�Ȼ¶�����䵭�����ص�΢Ц������Ц�ݱ����ó������ϵġ�\n"NOR,this_object());
        message_vision(CYN"$N����Ц�ŵ�������Ȼ��֪���ˣ��Ͳ��������ٻ��ų�ȥ��\n"NOR,this_object());
        another = new(__DIR__"caihua");
	another->move(environment(this_object()));
        destruct(ob);
	return 1;
}