// tao_2.c

inherit NPC;

void create()
{
        set_name("��ɽʹ��", ({ "taoist guard", "guard" }) );
        set("gender", "����");
        set("age", 32);
        set("long","��ɽʹ�������幬�Ļ�������һ���ɫ�ĵ��ۡ�\n");
        
        set("combat_exp", 50000);
        set("score", 200);

        set("class", "taoist");
	set("fly_target",1);

        set("atman", 1200);
        set("max_atman", 1200); 
        
        set("pursuer", 1);

        set("inquiry", ([
                "�����ķ�": 
"�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
        ]) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "invocation" :),
        }) );

        create_family("���幬", 7, "����");

        set_skill("literate", 50);
        set_skill("magic", 30);
        set_skill("move", 30);
        set_skill("force", 30);
        set_skill("spells", 60);
        set_skill("unarmed", 50);
        set_skill("sword", 60);
        set_skill("parry", 60);
        set_skill("dodge", 40);
        set_skill("gouyee", 60);
        set_skill("taoism", 70);
        set_skill("necromancy", 50);    
        set_skill("snowshade-sword",50);
        set_skill("tenderzhi",30);
	set_skill("notracesnow",50);
	
	map_skill("force", "gouyee");
	map_skill("unarmed","tenderzhi");
	map_skill("dodge","notracesnow");
	map_skill("spells", "necromancy");
        map_skill("parry","snowshade-sword");
        map_skill("sword","snowshade-sword");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);

        setup();

        add_money("coin", 30);
        carry_object(__DIR__"obj/sword1")->wield();
	carry_object(__DIR__"obj/tcloth")->wear();
}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="���幬" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say ���幬���ͱ��ɵ��˹��С�");
        return 0;
}
 

int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
//		command("say ok");
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}

