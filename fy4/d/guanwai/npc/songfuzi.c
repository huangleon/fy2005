inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
    	set_name("���Ϸ���", ({ "song fuzi","song" }) );
    	set("gender", "����" );
    	set("age", 99 );
    	set("title", HIG "��������"NOR);
	set("long",
        	"һ���׷��Բԣ���Ŀ�����ƺ���ʱ�����ܵ��µ����ߡ���ż��˫Ŀ\n���������̾�����һ�������˰㡣\n");
	set("attitude", "friendly");
    	set("combat_exp", 500000);
        set("chat_chance", 1);
        set("chat_msg", ({
  		"���Ϸ���������̧��ͷ����������һ�ۡ�\n",
                }) );
	set("per",30);
    	set("vendor_goods", ([
               __DIR__"obj/xuezhi":50,
               __DIR__"obj/sanyecao":50,
               __DIR__"obj/qisehua":50,
	]) );
    
    	set_skill("fall-steps",100);
    	set_skill("unarmed",100);
    	set_skill("dodge",100);
    	set_skill("parry",100);
    	set_skill("meihua-shou",50);
    	map_skill("unarmed","meihua-shou");
    	map_skill("dodge","fall-steps");
	setup();
    	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	::init();
        add_action("do_vendor_list", "list");
}

