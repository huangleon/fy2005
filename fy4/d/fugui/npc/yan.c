#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("����", ({ "yan qi", "yan" }) );
        set("long","
���ߵ����������������е���С�������������۾���СС���죬
Ц������ʱ�����������ѣ�����Ц��ʱ�������������ͱ��
���������ɫҲ�׵ķ��࣬���������е㲻���׽���\n");
        set("attitude", "heroism");
        create_family("����ɽׯ",7,"��ׯ��");
    	set("gender","Ů��");
	
		set("age",24);
        set("per",40);
        set("class","legend");
        
        set("chat_chance",1);
        set("chat_msg", ({
        "���߶��Žţ��޺޵õ������Ǹ�ǧ���Ĵ��ӣ���ʱ��ȴ��ʲôţƢ������......\n\n��������ò��������ߵĽ�ҩ����...��...������Ǻ�ѽ����\n",
                                })  );
        set("inquiry",  ([
            "����·" : "��ͷ�ִ���Ϲ�ֱ��ְ׳յ���ţ��������������ɡ�\n",
            "��̫ƽ" : "���ֵ����˳����ߵĳ����߶������û��ҩ����.....��...\n",
            "����" : "���ó�����绹�Ǻ�ϲ�������ӵģ����������ϴ�����ǲ��ǡ�\n",
                ])                      );
        
//        set("perform_busy_d", "legend/dodge/fall-steps/luoyeqiufeng");
		set("perform_busy_u", "legend/unarmed/meihua-shou/meihai");
		set("perform_weapon_attack", "legend/sword/diesword/caidiekuangwu");
		set("perform_buff_1", "legend/force/qidaoforce/juqi");
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );
        
        set("combat_exp", 2400000);

        set_skill("unarmed", 160);
        set_skill("force",100);
        set_skill("parry",180);
        set_skill("dodge", 140);
        set_skill("move",200);
        set_skill("sword",160);
        set_skill("diesword",200);
        set_skill("fall-steps",150);
        set_skill("qidaoforce",100);
   	
   		map_skill("unarmed","qidaoforce");     
        map_skill("sword","diesword");
        map_skill("dodge","fall-steps");
        map_skill("force","qidaoforce");
        map_skill("parry","diesword");
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}

void init()
{
	::init();
       add_action("do_look","look");
}

int do_look(string arg)
{

	if (arg == "yan" || arg == "yan qi")
	{
		write("���ߵ����������������е���С�������������۾���\n");
		write("СС���죬Ц������ʱ�����������ѣ�����Ц��ʱ��\n");
		write("�����������ͱ�����������ɫҲ�׵ķ��࣬���������е㲻���׽���\n");
		write("��������Լ��ʮ���ꡣ\n");
		write("�书����������"+BLU "����һ��"NOR+"�������ƺ����ᡣ\n");
		write("��"+HIG "���������������۷�״̬��"NOR+"\n");
		write("�����ϴ�����\n");
		write("  "+HIC "��"NOR+"����(Cloth)\n");
		write("  "+HIC "��"NOR+"����(Sword)\n");
		return 1;
	}
	return 0;
}

int accept_object(object me, object ob)
{
	object lin;
	if(ob->query("name") == "���ƿ" && ob->query("liquid/name")=="�������Ľ�ҩ")
	{
		me->set_temp("marks/���ƿ",1);
		me->perform_busy(3);
		if (lin=present("lin taiping",environment(this_object()))) {
			
			message_vision("���߷�����̫ƽ������ҩ����������̫ƽ����.......\n\n",me);
			message_vision(RED"$N���ۡ���һ���³�һ��ں�Ѫ������������ЩѪɫ����\n\n"NOR, lin); 
			command("touch " + me->query("id"));
			
			REWARD_D->riddle_done( me, "�����̫ƽ", 50, 1);
			
			if (me->query("class") == "fugui")
			  	command("say ��λ" + RANK_D->query_respect(me)+ "���������л����������������ѧ���ˣ�\n");         
	    } else 
			command("say ��л��λ" + RANK_D->query_respect(me)+ "�Ľ�ҩ��\n");
		
		return 1;
	}
	
	else
	       	tell_object(me,"����˵�����ⲻ������Ҫ�ġ�\n");
        	return 0;      
}
