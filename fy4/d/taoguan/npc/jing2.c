inherit SMART_NPC;

void create()
{
        set_name("����ʦ̫", ({ "qingyi" }) );
        set("gender", "Ů��");
        set("title","���幬  ����������");
        set("age", 42);
        set("long","����ԭ�Ƕ����Ƴ���ǰ������Ѿ�����Ѹ��涡���ƶ����ˡ�\n");
        set("combat_exp", 6400000);
        set("score", 200);
        set("class", "taoist");
		set("altitude","friendly");
        set("inquiry", ([
                "�����ķ�": "�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
        ]) );
        set("fy41/sq_bolt_1",1);

        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );
    	
		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","necromancy",1);
        setup();    
		carry_object(__DIR__"obj/s_skirt")->wear();
}


