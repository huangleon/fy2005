#include <ansi.h>
inherit SMART_NPC;
inherit F_VENDOR;
inherit INQUIRY_MSG;


int kill_him();

void create()
{
    	set_name("������",({"ding laosi","ding","laosi"}));
		set("title","�����ϰ�");
   		set("long","������������Ѿ�ס��ʮ�����ˣ���Ȼ���ⲻ�ã���ǿҲ��ά�ָ����ơ�\n");
     	set("gender","����");
    	set("age",52);
    	    	
    	set("combat_exp",1000000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
             	"�����嶾"   :		(: kill_him :),
             	"������"     :		(: kill_him :),
   		]));
    	
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );

    	set("chat_chance",1);
    	set("chat_msg",({
		"�����ĵ������͹����ʲô����˵��С��һ���쵽����\n",
    	}) );    	    	
    	
        set("vendor_goods", ([
                __DIR__"obj/meal_1":	20,
                __DIR__"obj/meal_2":	20,
                __DIR__"obj/meal_3":	20,
                __DIR__"obj/meal_4":	20,
                __DIR__"obj/meal_5":	20,
        ]) );

    	auto_npc_setup("wang",120,120,0,"/obj/weapon/","fighter_w","dragonstrike",1);
	
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "�Ҳ�Χȹ",
    						"long": "һ�����²��ɵĻҲ�Χȹ�������þ�ûϴ���ˡ�\n",
    						 ]))->wear();  
    
}

void init()
{	
	object ob;
	::init();
	add_action("do_vendor_list", "list");
}

int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
 	if (this_object()->is_fighting()) {
 		tell_object(me,"����������û�ջش��㡣\n");
 		return 1;
 		}
 	if(!me->query("marks/wanma/�ײ�֮��")) {
        	tell_object(me,"������˵��û��˵����������а���ý���\n");
        	return 1;
        }
        message_vision(CYN"$N���Ϻ�Ȼ¶�����䵭�����ص�΢Ц������Ц�ݱ����ó������ϵġ�\n"NOR,this_object());
        message_vision(CYN"$N����Ц�ŵ�������Ȼ��֪���ˣ��Ͳ��������ٻ��ų�ȥ��\n"NOR,this_object());
        another = new(__DIR__"qingzhu");
	another->move(environment(this_object()));
        destruct(ob);
	return 1;
}

void reset(){
        set("vendor_goods", ([
                __DIR__"obj/meal_1":	20,
                __DIR__"obj/meal_2":	20,
                __DIR__"obj/meal_3":	20,
                __DIR__"obj/meal_4":	20,
                __DIR__"obj/meal_5":	20,
        ]) );
}	