// waiter.c
inherit SMART_NPC;
#include <ansi.h>
inherit F_VENDOR;

void create()
{
 	set_name("���³���", ({ "devil waiter","waiter" }) );
        set ("nickname",HIR"�˳�"NOR);
        set ("title","������ �ֶ����");
	set("gender", "����" );
    	set("age", 52);
	set("long","
û����֪�����˵��������������س�������������ʮ��Ķ������ɵ������֣�
Ҳû��֪������ʲô��ֻ֪�����ǰ��³��˷ֶ�֮�е�Ψһ��һ�����ˣ���
�������Ҳֻ�й�����ɱ��������ˡ�\n");
	set("attitude", "friendly");
	
    set("combat_exp", 4000000);
    set("attitude", "friendly");
    set("reward_npc", 1);
	set("difficulty", 2);
        
        set("class","bat");
                
        set_skill("unarmed", 150);
        set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("blade",150);
    	set_skill("bat-blade",200);
	set_skill("meng-steps",150);
	set_skill("move",200);
	set_skill("blade",150);
	set_skill("lingxi-zhi",150);
	set_skill("force",180);
	set_skill("wuzheng-force",200);
	map_skill("force","wuzheng-force");
	map_skill("dodge","meng-steps");
	map_skill("move","meng-steps");
	map_skill("blade","bat-blade");
	map_skill("parry","bat-blade");
	map_skill("unarmed","lingxi-zhi");
	
		set("perform_busy_d", "bat/dodge/meng-steps/huanyinqianchong");
		set("perform_weapon_attack","bat/blade/bat-blade/shiwanshenmo");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "���³��������������ϵ�Ѫ�������������ӣ��૵���������ƺ�û���ˣ�\n��ȥŪЩ���ʵĲ��ǡ���\n",
        "���³����з����۾�������һ�ۣ�ҹ�ɰ��Ц�������ʳ��������������\n�ٺ٣���ζ�����ϡ�\n",
        }) );

   	set("rank_info/respect", "�˳�");
	set("vendor_goods", ([
        __DIR__"obj/renroubao" : 5,
        __DIR__"obj/bloodleg" : 5,
	]) );
	setup();
	
    	carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/butcherknife")->wield();
        if (!random(5)) carry_object(__DIR__"obj/stone_2");
}

void init()
{	
	object ob;
	::init();
	add_action("do_vendor_list", "list");
}

void reset(){
		set("vendor_goods", ([
    	    __DIR__"obj/renroubao" : 5,
        	__DIR__"obj/bloodleg" : 5,
		]) );
}