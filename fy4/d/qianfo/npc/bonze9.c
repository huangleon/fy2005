
inherit SMART_NPC;

void create()
{
        set_name("����", ({ "yunlin" }) );
        set("gender", "����" );
        set("class", "bonze");
	set("title","�˹��������ֱ���ʦ");
        set("age", random(40)+20);

        set("long", "�����˹��������������������ֱ���ʦ��\n");
        set("combat_exp", 7000000);
        set("attitude", "friendly");
               
        set("chat_chance", 1);
        set("chat_msg", ({
                "����˵�������������\n",
        }) );
        set("inquiry", ([
		"����" : "�����ں�԰��\n",
		"master" : "�����ں�԰��\n",
	]));
	
	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	
    	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","healer",1);
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
        carry_object("/obj/weapon/staff",([	"name": "��Ħ��",
    						"long": "һ����ҵ����ȡ�\n",
    						 ]))->wield();    
}

int accept_fight(object me)
{
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
}
